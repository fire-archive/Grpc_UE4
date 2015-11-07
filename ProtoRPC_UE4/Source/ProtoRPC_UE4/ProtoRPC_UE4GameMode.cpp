// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtoRPC_UE4.h"
#include "ProtoRPC_UE4GameMode.h"

#include "AllowWindowsPlatformTypes.h"
#include "GeneratedProtoStubs/ExampleService.pb.h"

bool AProtoRPC_UE4GameMode::InitializeRpcChannel()
{
	channel_ = nullptr;
	controller_ = nullptr;
	//channel_ = new HTTPRpcChannel("bleh.com:1234");
	//controller_ = new HTTPRpcController();
	authService_ = new example_proto::AuthService::Stub(channel_);
	authRequest_ = new example_proto::AuthRequest();
	authResponse_ = new example_proto::AuthResponse();

	return true;
}

// TODO(san): Move this somewhere else.
void AProtoRPC_UE4GameMode::InitiateAuthentication(const FString& username, const FString& hashedPassword) {
	authRequest_->set_username(TCHAR_TO_UTF8(*username));
	authRequest_->set_hash(TCHAR_TO_UTF8(*hashedPassword));
	authService_->Authenticate(controller_, authRequest_, authResponse_, google::protobuf::NewCallback(this, &AProtoRPC_UE4GameMode::AuthDone));
}

void AProtoRPC_UE4GameMode::AuthDone() {
	if (authResponse_->has_failedauthdata()) {

	}
	else if (authResponse_->has_successfullauthdata()) {

	}
	else {
		// Error. Server sent an empty msg... :(
	}

}

void AProtoRPC_UE4GameMode::HandleMatchHasStarted()
{
	InitializeRpcChannel();
	InitiateAuthentication("the_username", "the_hashed_password");
}
