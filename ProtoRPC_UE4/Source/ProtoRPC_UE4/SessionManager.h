// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"

// Forward declarations.
namespace google {
	namespace protobuf {
		class RpcChannel;
		class RpcController;
	}
}
namespace example_proto {
	class AuthService;
	class AuthRequest;
	class AuthResponse;
}

enum class SessionState {
	SS_NotAuthenticated,
	SS_Authenticating,
	SS_Authenticated,
	SS_AuthenticationFailed
};

// Delegate called when a session login operation completes.
DECLARE_DELEGATE(AuthCompletionDelegate);

// A little class to encapsulate an example session manager.
class SessionManager {
public:
	SessionManager();
	virtual ~SessionManager();


	void StartAuthentication(const FString& Username, const FString& HashedPassword, AuthCompletionDelegate* Completion);

	SessionState GetSessionState() { return sessionState_; }
	const FString& GetSessionErrorMsg() { return sessionErrorMsg_; }
	const FString& GetSessionAuthCookie() { return sessionCookie_; }

private:
	void AuthenticationRpcCompleted(AuthCompletionDelegate* Completion);

	SessionState sessionState_;
	FString sessionErrorMsg_;
	FString sessionCookie_;
	TScopedPointer<google::protobuf::RpcChannel> channel_;
	TScopedPointer<google::protobuf::RpcController> controller_;
	TScopedPointer<example_proto::AuthService> authService_;
	TScopedPointer<example_proto::AuthRequest> authRequest_;
	TScopedPointer<example_proto::AuthResponse> authResponse_;
};