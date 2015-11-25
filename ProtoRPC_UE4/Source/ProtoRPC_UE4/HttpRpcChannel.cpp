// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "ProtoRPC_UE4PrivatePCH.h"

#include "AllowWindowsPlatformTypes.h"
#include "HttpRpcChannel.h"
#include "HttpRpcRequest.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/util/type_resolver_util.h>

DEFINE_LOG_CATEGORY_STATIC(HttpRpcChannelLog, Log, All);
#define LOCTEXT_NAMESPACE "HttpRpcChannel"

using google::protobuf::Closure;
using google::protobuf::Descriptor;
using google::protobuf::DescriptorPool;
using google::protobuf::Message;
using google::protobuf::MethodDescriptor;
using google::protobuf::RpcController;
using google::protobuf::Message;
using google::protobuf::MethodDescriptor;
using google::protobuf::util::NewTypeResolverForDescriptorPool;
using google::protobuf::util::TypeResolver;

static const char kTypeUrlPrefix[] = "type.googleapis.com";

static std::string GetTypeUrl(const Descriptor* message) {
	return std::string(kTypeUrlPrefix) + "/" + message->full_name();
}


HttpRpcChannel::HttpRpcChannel(const FString& ServiceUri)
    : serviceUri_(ServiceUri),
	  nextRequestId_(0),
	  typeResolver_(NewTypeResolverForDescriptorPool(kTypeUrlPrefix, DescriptorPool::generated_pool())) {
}

HttpRpcChannel::~HttpRpcChannel() {}

void HttpRpcChannel::CallMethod(const MethodDescriptor* method, RpcController* controller, const Message* request, Message* response, Closure* done) {
	int64 requestId = FPlatformAtomics::InterlockedIncrement(&nextRequestId_);
	HttpRpcRequest* newRequest = new HttpRpcRequest(
		HttpRpcRequestStrategy::HRRS_PROTOASCII, typeResolver_, requestId, serviceUri_, method, controller, request, response, done);
	{
		FScopeLock mutexLock(&outstandingRequestsLock_);
		outstandingRequests_.Add(requestId, newRequest);
	}
	if (!newRequest->Init() || !newRequest->Execute()) {
		UE_LOG(HttpRpcChannelLog, Error, TEXT("Failed to init/execute the request on the client side"));
		delete newRequest;
		done->Run();
		return;
	}
}

