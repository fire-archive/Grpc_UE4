// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.

#pragma once
#include "Engine.h"
#include <grpc++/channel.h>
#include "GeneratedProtoStubs/ExampleService.grpc.pb.h"

enum class SessionState {
	SS_NotAuthenticated,
	SS_Authenticating,
	SS_Authenticated,
	SS_AuthenticationFailed
};

// Delegate called when a session login operation completes.
DECLARE_DELEGATE(AuthCompletionDelegate);

// Example of a simple class which manages user authentication / session management.

class SessionManager {
public:
	SessionManager();
	virtual ~SessionManager();

	// Issues an authentication request.
	// Username is the username to authenticate.
	// HashedPassword is the password to authenticate with.
	// Completion the delegate to call when authentication has completed. Ownership of pointer not taken.
	void StartAuthentication(const FString& Username, const FString& HashedPassword, AuthCompletionDelegate* Completion);

	// Gets the current session state.
	SessionState GetSessionState() { return sessionState_; }
	// Gets the current session error message. Only valid when SessionState is SS_AuthenticationFailed.
	const FString& GetSessionErrorMsg() { return sessionErrorMsg_; }
	// Gets the current session authentication cookie. Only valid when SessionState is SS_Authenticated.
	const FString& GetSessionAuthCookie() { return sessionCookie_; }

private:
	// Callback called when an underlying auth RPC completes.
	// Completion is the UE4 delegate to call to notify users of completion. Ownership not taken.
	void AuthenticationRpcCompleted(AuthCompletionDelegate* Completion);

	// Current state of the session.
	SessionState sessionState_;
	// Authentication reply message.
	TSharedPtr<com::paddlecreekgames::AuthResponse> authResponse_;
	// Session error message. Only valid when sessionState_ == SS_AuthenticationFailed.
	FString sessionErrorMsg_;
	// Session authentication cookie. Only valid when sessionState_ == SS_Authenticated.
	FString sessionCookie_;
	// Underlying RPC channel to use. Pointer owned.
	std::shared_ptr<grpc::Channel> channel_;
	// Underlying grpc context to use. Pointer owned.
	TSharedPtr<grpc::ClientContext> context_;
	// The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    TSharedPtr<grpc::CompletionQueue> cq_;
	// The status response
	TSharedPtr<grpc::Status> status_;
	// Underlying RPC service stub. Pointer owned.
	TSharedPtr<com::paddlecreekgames::AuthService::Stub> authService_;
};