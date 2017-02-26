// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "Grpc_UnrealPrivatePCH.h"

#include "HttpRpcRequest.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/util/type_resolver_util.h>

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

HttpRpcRequest::~HttpRpcRequest() {}

bool HttpRpcRequest::Init() {
	if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_JSON) {
		std::string jsonString;
		JsonOptions jsonOptions;
		jsonOptions.always_print_primitive_fields = true;
		jsonOptions.add_whitespace = true;
		Status status = google::protobuf::util::BinaryToJsonString(
			typeResolver_, GetTypeUrl(callState_.GetRequest()->GetDescriptor()), callState_.GetRequest()->SerializeAsString(),
			&jsonString, jsonOptions);
		if (!status.ok()) {
			UE_LOG(HttpRpcRequestLog,
				Error,
				TEXT("Failed to serialize to json (%s)"),
				*FString(status.error_message().ToString().c_str()));
			callState_.GetController()->SetFailed("JSON serialization failed");
			return false;
		}
		httpRequest_->SetHeader("Content-Type", kContentTypeJson);
		httpRequest_->SetContentAsString(FString(jsonString.c_str()));
	} else if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_PROTOASCII) {
		std::string textString;
		if (!google::protobuf::TextFormat::PrintToString(*callState_.GetRequest(), &textString)) {
			UE_LOG(HttpRpcRequestLog, Error, TEXT("Failed to serialize to text"));
			callState_.GetController()->SetFailed("Text serialization failed");
			return false;
		}
		httpRequest_->SetHeader("Content-Type", kContentTypeASCII);
		httpRequest_->SetContentAsString(FString(textString.c_str()));
	} else if (requestStrategy_ == HttpRpcRequestStrategy::HRRS_PROTOBINARY) {
		std::string binaryString = callState_.GetRequest()->SerializeAsString();
		httpRequest_->SetHeader("Content-Type", kContentTypeBinary);
		httpRequest_->SetContentAsString(FString(binaryString.c_str()));
	} else {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Invalid HTTP request strategy"));
		callState_.GetController()->SetFailed("Invalid HTTP request strategy");
		return false;
	}

	httpRequest_->OnProcessRequestComplete().BindRaw(this, &HttpRpcRequest::onHttpRequestCompleted);
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
				if (!ParseMessageFromResponse(response)) {
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

bool HttpRpcRequest::ParseMessageFromResponse(FHttpResponsePtr response) {
	const FString contentType = response->GetContentType();

	if (contentType.StartsWith(kContentTypeJson)) {

	} else if (contentType.StartsWith(kContentTypeASCII)) {
		if (!google::protobuf::TextFormat::ParseFromString(TCHAR_TO_UTF8(*response->GetContentAsString()), callState_.GetResponse())) {
			UE_LOG(HttpRpcRequestLog, Error, TEXT("ASCII response parse failed"));
			return false;
		}
		return true;
	} else if (contentType.StartsWith(kContentTypeBinary)) {

	} else {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Invalid content type '%s'"), *contentType);
	}
	return false;
}