// Fill out your copyright notice in the Description page of Project Settings.
#include "ProtoRPC_UE4PrivatePCH.h"

#include "SessionManager.h"


#include "AllowWindowsPlatformTypes.h"
#include "GeneratedProtoStubs/ExampleService.pb.h"
#include "HttpRpcChannel.h"
#include "HttpRpcController.h"

SessionManager::SessionManager()
    : sessionState_(SessionState::SS_NotAuthenticated),
	  channel_(new HttpRpcChannel("http://bleh.com:1234")),
      controller_(new HttpRpcController()),
      authService_(new example_proto::AuthService::Stub(channel_)),
      authRequest_(new example_proto::AuthRequest()),
      authResponse_(new example_proto::AuthResponse())  {
}

SessionManager::~SessionManager() {}
  
void SessionManager::StartAuthentication(const FString& Username, const FString& HashedPassword, AuthCompletionDelegate* Completion) {
	authRequest_->set_username(TCHAR_TO_UTF8(*Username));
	authRequest_->set_hash(TCHAR_TO_UTF8(*HashedPassword));
	authService_->Authenticate(controller_, authRequest_, authResponse_, google::protobuf::NewCallback(this, &SessionManager::AuthenticationRpcCompleted, Completion));
	sessionState_ = SessionState::SS_Authenticating;
}

void SessionManager::AuthenticationRpcCompleted(AuthCompletionDelegate* Completion) {
	if (authResponse_->has_failedauthdata()) {
		sessionState_ = SessionState::SS_AuthenticationFailed;
		sessionErrorMsg_ = FString(authResponse_->failedauthdata().errormessage().c_str());
	}
	else if (authResponse_->has_successfullauthdata()) {
		sessionState_ = SessionState::SS_Authenticated;
		sessionCookie_ = FString(authResponse_->successfullauthdata().authtoken().c_str());
	}
	else {
		// Error. Server sent an empty msg... :(
		sessionState_ = SessionState::SS_AuthenticationFailed;
		sessionErrorMsg_ = "Empty message from server";
	}
	Completion->ExecuteIfBound();
}