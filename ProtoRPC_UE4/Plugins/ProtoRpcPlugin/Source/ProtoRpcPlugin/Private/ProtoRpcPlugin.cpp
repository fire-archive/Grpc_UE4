// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#include "ProtoRpcPluginPrivatePCH.h"
#include "ProtoRpcPlugin.h"


DEFINE_LOG_CATEGORY_STATIC(ProtoRpcPluginLog, Log, All);
#define LOCTEXT_NAMESPACE "ProtoRpcPlugin"

void FProtoRpcPlugin::StartupModule() {
	UE_LOG(ProtoRpcPluginLog, Display, TEXT("Module startup"));
}

void FProtoRpcPlugin::ShutdownModule() {
	UE_LOG(ProtoRpcPluginLog, Display, TEXT("Module shutdown."));
}

IMPLEMENT_GAME_MODULE(FProtoRpcPlugin, ProtoRpcPlugin);
