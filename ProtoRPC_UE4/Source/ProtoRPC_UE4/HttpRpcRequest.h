// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Http.h"
#include "PendingRpcCallState.h"

namespace google {
	namespace protobuf {
		class Closure;
		class MethodDescriptor;
		class Message;
		class RpcController;
		namespace util {
			class TypeResolver;
		}  // namespace util.
	}  // namespace protobuf.
}  // namespace google.

enum class HttpRpcRequestStrategy {
	HRRS_JSON,
	HRRS_PROTOASCII,
	HRRS_PROTOBINARY,
};

class HttpRpcRequest {
public:
	HttpRpcRequest(
		HttpRpcRequestStrategy RequestStrategy,
		google::protobuf::util::TypeResolver* ProtoTypeResolver,
		int64 RequestId, const FString& ServiceUri, const google::protobuf::MethodDescriptor* method,
		google::protobuf::RpcController* Controller, const google::protobuf::Message* Request,
		google::protobuf::Message* Response, google::protobuf::Closure* Done);
	virtual ~HttpRpcRequest();
	  
	bool Init();

	bool Execute();

private:
	bool SerializeAsJSON();
	bool SerializeAsProtoASCII();
	bool SerializeAsProtoBinary();

	// Delegate called by UE4's HTTP module when a request completes.
	void onHttpRequestCompleted(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	PendingRpcCallState callState_;
	TSharedRef<IHttpRequest> httpRequest_;
	int64 requestId_;
	google::protobuf::util::TypeResolver* typeResolver_;
	HttpRpcRequestStrategy requestStrategy_;
};