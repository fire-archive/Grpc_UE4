// Copyright 2015 Paddle Creek Games Inc. All Rights Reserved.
#pragma once

#include "IProtoRpcPlugin.h"

class PROTORPCPLUGIN_API FProtoRpcPlugin : public IProtoRpcPlugin {
public:
	//
	// IModuleInterface methods.
	//
	void StartupModule() override;
	void ShutdownModule() override;
	bool SupportsDynamicReloading() override { return true; }
	bool IsGameModule() const override { return false; }

	//
	// Public API methods.
	//

	//
	// Other  methods.
	//
private:
};
