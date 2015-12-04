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

// Strategy to be used to serialize the HTTP request.
enum class HttpRpcRequestStrategy {
	// Serialize using JSON.
	HRRS_JSON,
	// Serialize using Protobuf Text format.
	HRRS_PROTOASCII,
	// Serialize using Protobuf binary format.
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

	// Initializes the request.
	// Returns true on success; false otherwise.
	bool Init();

	// Executes the request asynchronously.
	// Returns false if the request couldn't be issued.
	bool Execute();

private:
	static const FString kContentTypeJson;
	static const FString kContentTypeBinary;
	static const FString kContentTypeASCII;

	int ParseRequestIdFromResponse(FHttpResponsePtr response);
	bool ParseMessageFromResponse(FHttpResponsePtr response);

	// Delegate called by UE4's HTTP module when a request completes.
	void onHttpRequestCompleted(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	PendingRpcCallState callState_;
	TSharedRef<IHttpRequest> httpRequest_;
	int64 requestId_;
	google::protobuf::util::TypeResolver* typeResolver_;
	HttpRpcRequestStrategy requestStrategy_;
};