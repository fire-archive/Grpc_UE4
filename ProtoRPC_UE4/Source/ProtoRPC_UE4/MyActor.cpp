// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "SessionManager.h"

AMyActor::AMyActor() {
	PrimaryActorTick.bCanEverTick = true;
	authDelegate_.BindUObject(this, &AMyActor::AuthenticationComplete);
}

void AMyActor::BeginPlay() {
	Super::BeginPlay();
	sessionManager_.StartAuthentication("san", "some_secure_hash", &authDelegate_);
}

// Called every frame
void AMyActor::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}

void AMyActor::AuthenticationComplete() {
	if (sessionManager_.GetSessionState() == SessionState::SS_Authenticated) {

	}
	else {

	}

}

