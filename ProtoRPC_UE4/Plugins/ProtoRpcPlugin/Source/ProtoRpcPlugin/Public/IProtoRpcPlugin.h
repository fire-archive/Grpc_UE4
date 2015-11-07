// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#pragma once

#include "ModuleManager.h"

class PROTORPCPLUGIN_API IProtoRpcPlugin : public IModuleInterface
{
public:
	// Static method which returns true if the module is available for use.
	// Should be called upon server startup.
	static bool IsModuleAvailable() {
		return FModuleManager::Get().IsModuleLoaded("ProtoRpcPlugin");
	}

	// Returns the singleton instance of the ProtoRpcPlugin.
	// Should not be called during shutdown phase.
	// Ownership of the returned pointer is not transferred.
	static IProtoRpcPlugin* Get() {
		return FModuleManager::LoadModulePtr<IProtoRpcPlugin>("ProtoRpcPlugin");
	}

	//
	// Public API methods.
	//

	
};
