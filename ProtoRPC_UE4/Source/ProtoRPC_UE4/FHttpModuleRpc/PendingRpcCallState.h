// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Http.h"

#include "google/protobuf/service.h"

// Encapsulates state for an outstanding request to the channel.
class PendingRpcCallState {
public:
	PendingRpcCallState(const google::protobuf::MethodDescriptor* Method,
		google::protobuf::RpcController* Controller,
		const google::protobuf::Message* Request,
		google::protobuf::Message* Response,
		google::protobuf::Closure* Done)
		: method_(Method),
		controller_(Controller),
		request_(Request),
		response_(Response),
		done_(Done) {}
	virtual ~PendingRpcCallState() {}

	const google::protobuf::MethodDescriptor* GetMethod() const { return method_; }
	google::protobuf::RpcController* GetController() const { return controller_; }
	const google::protobuf::Message* GetRequest() const { return request_; }
	google::protobuf::Message* GetResponse() const { return response_; }
	google::protobuf::Closure* GetDone() const { return done_; }
private:
	const google::protobuf::MethodDescriptor* method_;
	google::protobuf::RpcController* controller_;
	const google::protobuf::Message* request_;
	google::protobuf::Message* response_;
	google::protobuf::Closure* done_;
};