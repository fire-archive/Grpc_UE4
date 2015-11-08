// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once

#include "Engine.h"

#include "google/protobuf/service.h"

class HttpRpcController : public google::protobuf::RpcController {
public:
	HttpRpcController();
	virtual ~HttpRpcController();

	// RpcController methods.
	virtual void Reset() override;
	virtual bool Failed() const override;
	virtual std::string ErrorText() const override;
	virtual void StartCancel() override;
	virtual void SetFailed(const std::string& reason) override;
	virtual bool IsCanceled() const override;
	virtual void NotifyOnCancel(google::protobuf::Closure* callback) override;
private:
};