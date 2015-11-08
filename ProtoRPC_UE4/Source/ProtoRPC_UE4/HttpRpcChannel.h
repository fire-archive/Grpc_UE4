// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once

#include "Engine.h"

#include "google/protobuf/service.h"

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
	FString serviceUri_;
};