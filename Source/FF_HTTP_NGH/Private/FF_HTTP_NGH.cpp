// Copyright Epic Games, Inc. All Rights Reserved.

#include "FF_HTTP_NGH.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFF_HTTP_NGHModule"

void FFF_HTTP_NGHModule::StartupModule()
{
#if defined(_WIN64) && NGHTTP2_SHARED == 1

	const FString BasePluginDir = IPluginManager::Get().FindPlugin("FF_HTTP_NGH")->GetBaseDir();
	const FString Path_realsense2 = FPaths::Combine(*BasePluginDir, TEXT("Source/ff_nghttp2/Win64/lib/nghttp2.dll"));

	this->Handle_nghttp2 = FPlatformProcess::GetDllHandle(*Path_realsense2);

	if (this->Handle_nghttp2 != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("nghttp2.dll loaded successfully!"));
	}

	else
	{
		UE_LOG(LogTemp, Fatal, TEXT("nghttp2.dll failed to load!"));
	}

#endif
}

void FFF_HTTP_NGHModule::ShutdownModule()
{
#if defined(_WIN64) && NGHTTP2_SHARED == 1

	FPlatformProcess::FreeDllHandle(this->Handle_nghttp2);
	this->Handle_nghttp2 = nullptr;

#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFF_HTTP_NGHModule, FF_HTTP_NGH)