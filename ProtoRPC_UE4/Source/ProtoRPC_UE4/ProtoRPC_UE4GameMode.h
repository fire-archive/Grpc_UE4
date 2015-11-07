// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "ProtoRPC_UE4GameMode.generated.h"

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
/**
 * 
 */
UCLASS()
class PROTORPC_UE4_API AProtoRPC_UE4GameMode : public AGameMode
{
	GENERATED_BODY()

	bool InitializeRpcChannel();
	void InitiateAuthentication(const FString& username, const FString& hashedPassword);
private:
	void AuthDone();

	virtual void HandleMatchHasStarted() override;

	google::protobuf::RpcChannel* channel_;
	google::protobuf::RpcController* controller_;
	example_proto::AuthService* authService_;
	example_proto::AuthRequest* authRequest_;
	example_proto::AuthResponse* authResponse_;
};
