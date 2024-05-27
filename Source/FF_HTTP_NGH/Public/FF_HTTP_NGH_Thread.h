// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#include "nghttp2/nghttp2.h"
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AHTTP_Server_NGH;

class FHTTP_Thread_Nghttp2 : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_Nghttp2(AHTTP_Server_NGH* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_Nghttp2() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual bool Toggle(bool bIsPause);

	AHTTP_Server_NGH* Parent_Actor = nullptr;

private:

	virtual void Callback_HTTP_Start();
	virtual void Callback_HTTP_Stop();

	int32 Port_HTTP = 8081;
	int32 Port_HTTPS = 8443;

	FString Server_Address_HTTPS = "";
	FString Server_Address_HTTP = "";
	FString Server_Path_Root = "";
	FString API_URI = "";

private:

	FRunnableThread* RunnableThread = nullptr;
	bool bStartThread = false;

	nghttp2_session_callbacks* NGH_Callbacks = nullptr;
	nghttp2_session* NGH_Session = nullptr;
};