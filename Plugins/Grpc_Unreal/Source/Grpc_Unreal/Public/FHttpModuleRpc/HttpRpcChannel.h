// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Http.h"

#include "google/protobuf/service.h"

namespace google {
	namespace protobuf {
		namespace util {
			class TypeResolver;
		}  // namespace util.
	}  // namespace protobuf.
}  // namespace google.

class HttpRpcRequest;

class HttpRpcChannel : public google::protobuf::RpcChannel {
public:
	HttpRpcChannel(const FString& ServiceUri);
	virtual ~HttpRpcChannel();

	//
	// RpcChannel methods.
	//
	virtual void CallMethod(
		const google::protobuf::MethodDescriptor* method, google::protobuf::RpcController* controller, 
		const google::protobuf::Message* request, google::protobuf::Message* response, 
		google::protobuf::Closure* done) override;
private:
	// Service URI for this channel.
	FString serviceUri_;
	// Next available request ID.
	int64 nextRequestId_;
	TScopedPointer<google::protobuf::util::TypeResolver> typeResolver_;
};