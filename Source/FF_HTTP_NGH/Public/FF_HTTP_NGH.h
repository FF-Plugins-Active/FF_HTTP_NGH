// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#define NGHTTP2_SHARED 1

class FFF_HTTP_NGHModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if defined(_WIN64) && NGHTTP2_SHARED == 1

	void* Handle_nghttp2 = nullptr;

#endif

};
