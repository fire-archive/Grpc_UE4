// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "ProtoRPC_UE4PrivatePCH.h"

#include "AllowWindowsPlatformTypes.h"
#include "HttpRpcRequest.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf//message.h>
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
using google::protobuf::util::BinaryToJsonString;
using google::protobuf::util::JsonOptions;
using google::protobuf::util::JsonToBinaryString;
using google::protobuf::util::NewTypeResolverForDescriptorPool;
using google::protobuf::util::Status;
using google::protobuf::util::TypeResolver;

static const char kTypeUrlPrefix[] = "type.googleapis.com";

static std::string GetTypeUrl(const Descriptor* message) {
	return std::string(kTypeUrlPrefix) + "/" + message->full_name();
}

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
	httpRequest_->SetHeader("Content-Type", "application/json");
	httpRequest_->SetHeader("X-Request-ID", FString::Printf(TEXT("%u"), RequestId));
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
	callState_.GetController()->SetFailed("Not implemented");
	return false;
}

bool HttpRpcRequest::SerializeAsProtoBinary() {
	callState_.GetController()->SetFailed("Not implemented");
	return false;
}

bool HttpRpcRequest::SerializeAsJSON() {
	FString stringBuffer;
	{
		std::string jsonString;
		// TODO(san): FIX THIS UGLY UGLY HACK.
		// So.... the proto library interface for JSON serialization takes a mutable string pointer
		// which it extends. This is bad since the proto library is hosted in a .dll which has its
		// own heap. As a work-around, we pre-allocate space in the string on OUR heap before passing
		// it in to the proto library.
		jsonString.reserve(1024 * 64);
		{
			JsonOptions jsonOptions;
			jsonOptions.always_print_primitive_fields = true;
			jsonOptions.add_whitespace = true;
			Status status = BinaryToJsonString(typeResolver_,
				GetTypeUrl(callState_.GetRequest()->GetDescriptor()),
				callState_.GetRequest()->SerializeAsString(),
				&jsonString,
				jsonOptions);
			if (!status.ok()) {
				UE_LOG(HttpRpcRequestLog,
					Error,
					TEXT("Failed to serialize to json (%s)"),
					*FString(status.error_message().ToString().c_str()));
				callState_.GetController()->SetFailed("JSON serialization failed");
				return false;
			}
		}
		stringBuffer = FString(jsonString.c_str());
	}
	httpRequest_->SetContentAsString(stringBuffer);
	return true;
}

bool HttpRpcRequest::Execute() {
	if (!httpRequest_->ProcessRequest()) {
		UE_LOG(HttpRpcRequestLog, Error, TEXT("Login HTTP request failed"));
		callState_.GetController()->SetFailed("ProcessRequest failed");
		return false;
	}
	return true;
}

void HttpRpcRequest::onHttpRequestCompleted(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
	int64 requestId = -1;
	if (!bWasSuccessful) {

	}
	else {
		switch (response->GetResponseCode()) {
		case 200:
			break;
		default:
			UE_LOG(HttpRpcRequestLog, Error, TEXT("HTTP response code %d"), response->GetResponseCode());
			break;
		}
	}

	// TODO(san): Notify our channel.
}