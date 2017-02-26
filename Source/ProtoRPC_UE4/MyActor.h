// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SessionManager.h"

#include "MyActor.generated.h"

UCLASS()
class PROTORPC_UE4_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	void AuthenticationComplete();

	SessionManager sessionManager_;
	AuthCompletionDelegate authDelegate_;

};
