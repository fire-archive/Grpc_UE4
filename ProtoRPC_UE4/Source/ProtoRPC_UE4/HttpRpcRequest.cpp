// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "ProtoRPC_UE4PrivatePCH.h"

#include "HttpRpcRequest.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf//message.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/util/type_resolver_util.h>
#include <google/protobuf/util/windows_util.h>

DEFINE_LOG_CATEGORY_STATIC(HttpRpcRequestLog, Log, All);
#define LOCTEXT_NAMESPACE "HttpRpcRequest"

using google::protobuf::Closure;
using google::protobuf::Descriptor;
using google::protobuf::DescriptorPool;
using google::protobuf::Message;
using google::protobuf::MethodDescriptor;
using google::protobuf::RpcController;
using google::protobuf::Message;
using google::protobuf::MethodDescriptor;
using google::protobuf::util::JsonOptions;
using google::protobuf::util::JsonToBinaryString;
using google::protobuf::util::NewTypeResolverForDescriptorPool;
using google::protobuf::util::Status;
using google::protobuf::util::TypeResolver;

static const char kTypeUrlPrefix[] = "type.googleapis.com";
static std::string GetTypeUrl(const Descriptor* message) {
	return std::string(kTypeUrlPrefix) + "/" + message->full_name();
}

const FString HttpRpcRequest::kContentTypeJson = "application/json";
const FString HttpRpcRequest::kContentTypeBinary = "application/x-protobuf";
const FString HttpRpcRequest::kContentTypeASCII = "application/x-protobuf-text";

HttpRpcRequest::HttpRpcRequest(
	HttpRpcRequestStrategy RequestStrategy, TypeResolver* ProtoTypeResolver, int64 RequestId, const FString& ServiceUri,
	const MethodDescriptor* Method, RpcController* Controller, const Message* Request, Message* Response, Closure* Done)
	: callState_(Method, Controller, Request, Response, Done),
	  httpRequest_(FHttpModule::Get().CreateRequest()),
	  requestId_(RequestId),
	  typeResolver_(ProtoTypeResolver),
	  requestStrategy_(RequestStrategy) {
	httpRequest_->SetVerb(TEXT("POST"));
	httpRequest_->SetURL(ServiceUri);
	httpRequest_->SetHeader("X-Request-ID", FString::Printf(TEXT("%u"), RequestId));
	httpRequest_->SetHeader("X-Method", FString(Method->name().c_str()));
}

HttpRpcRequest::~HttpRpcRequest() {

}

bool HttpRpcRequest::Init() {
	bool serializedOk;
	if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_JSON) {
		serializedOk = SerializeAsJSON();
	}
	else if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_PROTOASCII) {
		serializedOk = SerializeAsProtoASCII();
	}
	else if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_PROTOBINARY) {
		serializedOk = SerializeAsProtoBinary();
	}
	else {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Invalid HTTP request strategy"));
		callState_.GetController()->SetFailed("Invalid HTTP request strategy");
		return false;
	}

	if (!serializedOk) {
		return false;
	}

	httpRequest_->OnProcessRequestComplete().BindRaw(this, &HttpRpcRequest::onHttpRequestCompleted);
	return true;
}

bool HttpRpcRequest::SerializeAsProtoASCII() {
	std::string* textString = nullptr;
	google::protobuf::util::windows::SerializeToTextString(*callState_.GetRequest(), &textString);
	if (textString == nullptr) {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Failed to serialize to text"));
		callState_.GetController()->SetFailed("Text serialization failed");
		return false;
	}
	httpRequest_->SetContentAsString(FString(textString->c_str()));
	//UE_LOG(HttpRpcRequestLog, Display, TEXT("ascii_serialized: %s"), *FString(textString->c_str()));
	google::protobuf::util::windows::DeleteString(textString);
	httpRequest_->SetHeader("Content-Type", kContentTypeASCII);
	return true;
}

bool HttpRpcRequest::SerializeAsProtoBinary() {
	std::string* binaryString = nullptr;
	google::protobuf::util::windows::SerializeToBinaryString(*callState_.GetRequest(), &binaryString);
	if (binaryString == nullptr) {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Failed to serialize to binary"));
		callState_.GetController()->SetFailed("Binary serialization failed");
		return false;
	}
	httpRequest_->SetContentAsString(FString(binaryString->c_str()));
	google::protobuf::util::windows::DeleteString(binaryString);

	httpRequest_->SetHeader("Content-Type", kContentTypeBinary);
	return true;
}

bool HttpRpcRequest::SerializeAsJSON() {
	FString stringBuffer;
	{
		std::string* jsonString = nullptr;
		{
			JsonOptions jsonOptions;
			jsonOptions.always_print_primitive_fields = true;
			jsonOptions.add_whitespace = true;
			Status status = google::protobuf::util::windows::SerializeToJsonString(
				typeResolver_,
				GetTypeUrl(callState_.GetRequest()->GetDescriptor()),
				callState_.GetRequest()->SerializeAsString(),
				&jsonString,
				jsonOptions);
			if (!status.ok() || jsonString == nullptr) {
				UE_LOG(HttpRpcRequestLog,
					Error,
					TEXT("Failed to serialize to json (%s)"),
					*FString(status.error_message().ToString().c_str()));
				callState_.GetController()->SetFailed("JSON serialization failed");
				return false;
			}
		}
		stringBuffer = FString(jsonString->c_str());
		google::protobuf::util::windows::DeleteString(jsonString);
	}

	httpRequest_->SetContentAsString(stringBuffer);
	httpRequest_->SetHeader("Content-Type", kContentTypeJson);
	return true;
}

bool HttpRpcRequest::Execute() {
	if (!httpRequest_->ProcessRequest()) {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("ProcessRequest failed"));
		callState_.GetController()->SetFailed("ProcessRequest failed");
		return false;
	}
	return true;
}

void HttpRpcRequest::onHttpRequestCompleted(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
	if (!bWasSuccessful) {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("HTTP request failed"));
		callState_.GetController()->SetFailed("HTTP request failed");
	} else {
		const int responseCode = response->GetResponseCode();
		if (responseCode != 200) {
			if ((responseCode >= 300) && (responseCode < 400)) {
				// TODO(san): Handle redirects.
				callState_.GetController()->SetFailed("Unsupported redirect");
			} else {
				UE_LOG(HttpRpcRequestLog, Error, TEXT("HTTP response code %d (%s)"), response->GetResponseCode(), *response->GetContentAsString());
				callState_.GetController()->SetFailed("Bad HTTP response code");
			}
		} else {
			// Successful HTTP response.
			int requestId = ParseRequestIdFromResponse(response);
			if (requestId == -1) {
				UE_LOG(HttpRpcRequestLog, Error, TEXT("HTTP response missing request id"));
				callState_.GetController()->SetFailed("Response missing request id");
				// TODO(san): Think about whether we should be strict about this given we have the request handy.
			} else if (requestId != FCString::Atoi(*request->GetHeader("X-Request-ID"))) {
				// If this happens legitimately then we are most likely inheriting a 'threading issue' from the
				// HTTP module - in which case we'll probably need to track outstanding requests ourselves.
				UE_LOG(HttpRpcRequestLog, Error, TEXT("Mismatched Request/Response!"));
				callState_.GetController()->SetFailed("Mismatched Request/Response ID");
			} else {
				// Request ID is valid. Extract the protobuf from the HTTP content buffer.
				// N.B: The returned protobuffer is allocated from the libproto.dll heap so it
				// must be freed via the same dll.
				Message* responseProto = ParseMessageFromResponse(response);
				if (responseProto != nullptr) {
					callState_.GetResponse()->MergeFrom(*responseProto);
					google::protobuf::util::windows::DeleteMessage(responseProto);
				} else {
					UE_LOG(HttpRpcRequestLog, Warning, TEXT("Failed to parse response protobuf"));
					callState_.GetController()->SetFailed("Failed to parse response protobuf");
				}
			}
		}
	}

	Closure* cachedClosure = callState_.GetDone();
	delete this;
	cachedClosure->Run();
}

int HttpRpcRequest::ParseRequestIdFromResponse(FHttpResponsePtr response) {
	FString requestIdString = response->GetHeader("X-Request-ID");
	if (requestIdString == "") {
		return -1;
	}
	return FCString::Atoi(*requestIdString);
}

Message* HttpRpcRequest::ParseMessageFromResponse(FHttpResponsePtr response) {
	const FString contentType = response->GetContentType();
	Message* responseProto = nullptr;

	if (contentType.StartsWith(kContentTypeJson)) {

	} else if (contentType.StartsWith(kContentTypeASCII)) {
		std::string textInput;
		if (!google::protobuf::util::windows::ParseFromTextString(
			callState_.GetResponse()->GetDescriptor(), TCHAR_TO_UTF8(*response->GetContentAsString()),
			&responseProto)) {
			UE_LOG(HttpRpcRequestLog, Error, TEXT("ASCII response parse failed"));
			return nullptr;
		}
	} else if (contentType.StartsWith(kContentTypeBinary)) {

	} else {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Invalid content type '%s'"), *contentType);
		return nullptr;
	}
	return responseProto;
}