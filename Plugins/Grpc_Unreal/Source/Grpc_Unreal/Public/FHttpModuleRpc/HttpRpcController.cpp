// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "Grpc_UnrealPrivatePCH.h"
#include "HttpRpcController.h"

DEFINE_LOG_CATEGORY_STATIC(HttpRpcControllerLog, Log, All);
#define LOCTEXT_NAMESPACE "HttpRpcController"

HttpRpcController::HttpRpcController()
    : failed_(false),
	  error_reason_("") {
	if (!FHttpModule::Get().IsHttpEnabled()) {
		UE_LOG(HttpRpcControllerLog, Error, TEXT("Http module is not enabled"));
		failed_ = true;
		error_reason_ = "HTTP module not enabled";
		return;
	}
}

HttpRpcController::~HttpRpcController() {}

void HttpRpcController::Reset(){
	failed_ = false;
	error_reason_ = "";
	if (!FHttpModule::Get().IsHttpEnabled()) {
		UE_LOG(HttpRpcControllerLog, Error, TEXT("Http module is not enabled"));
		failed_ = true;
		error_reason_ = "HTTP module not enabled";
		return;
	}
}

bool HttpRpcController::Failed() const {
	return failed_;
}

std::string HttpRpcController::ErrorText() const {
	return error_reason_;
}

void HttpRpcController::StartCancel() {}

void HttpRpcController::SetFailed(const std::string& reason) {
	failed_ = true;
	error_reason_ = reason;
}

bool HttpRpcController::IsCanceled() const {
	return true; 
}

void HttpRpcController::NotifyOnCancel(google::protobuf::Closure* callback) {
}

