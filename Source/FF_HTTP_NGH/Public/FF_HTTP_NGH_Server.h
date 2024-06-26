// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Threads.
#include "FF_HTTP_NGH_Thread.h"

#include "FF_HTTP_NGH_Server.generated.h"


UCLASS()
class FF_HTTP_NGH_API UHttpConnectionNghttp2 : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual bool ParseRequest()
	{
		return true;
	}

	UFUNCTION(BlueprintCallable, Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual bool SendResponse(const FString In_Response, TMap<FString, FString> In_Header, const bool bAddAllowOrigin = true, int32 Status_Code = 200)
	{
		return true;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateNghttp2, UHttpConnectionNghttp2*, Connection);

UCLASS()
class FF_HTTP_NGH_API AHTTP_Server_NGH : public AActor
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the game end or when destroyed.
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	

	// Sets default values for this actor's properties.
	AHTTP_Server_NGH();

	// Called every frame.
	virtual void Tick(float DeltaTime) override;

#ifdef _WIN64
	class FHTTP_Thread_Nghttp2* Thread_Nghttp2 = nullptr;
#endif

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttpAdvStart();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttpAdvStop();

	UFUNCTION(BlueprintImplementableEvent, meta = (Description = ""), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	void OnHttpAdvMessage(UHttpConnectionNghttp2* Connection);

	UPROPERTY(BlueprintAssignable, Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FDelegateNghttp2 DelegateHttpMessageAdv;

public:

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FString Server_Path_Root = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FString Server_Path_404 = "";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	int32 Port_HTTP = 8081;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	int32 Port_HTTPS = 8453;

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "If you want to change API parameter, just put /* to the end. If you don't do that, server won't detect dynamic API requests.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FString API_URI = "api/*";

	UPROPERTY(BlueprintReadOnly, meta = (ToolTip = "It shouldn't bigger than 15 chars and it has to be unique.", ExposeOnSpawn = "true"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	FString Server_Name = "";

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server NGHTTP2 - Start"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual bool HTTP_Server_Start();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server NGHTTP2 - Stop"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual void HTTP_Server_Stop();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HTTP Server NGHTTP2 - Toggle"), Category = "Frozen Forest|HTTP|Server|NGHTTP2")
	virtual bool HTTP_Server_Toggle(bool bIsPause);

};