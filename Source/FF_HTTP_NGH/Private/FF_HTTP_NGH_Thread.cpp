// Fill out your copyright notice in the Description page of Project Settings.

#include "FF_HTTP_NGH_Thread.h"
#include "FF_HTTP_NGH_Server.h"

// UE Includes.
#include "Async/Async.h"

FHTTP_Thread_Nghttp2::FHTTP_Thread_Nghttp2(AHTTP_Server_NGH* In_Parent_Actor)
{
	this->Parent_Actor = In_Parent_Actor;
	
	this->Port_HTTP = this->Parent_Actor->Port_HTTP;
	this->Port_HTTPS = this->Parent_Actor->Port_HTTPS;

	this->RunnableThread = FRunnableThread::Create(this, *this->Parent_Actor->Server_Name);
}

FHTTP_Thread_Nghttp2::~FHTTP_Thread_Nghttp2()
{
	if (this->RunnableThread)
	{
		this->RunnableThread->Kill(true);
		delete this->RunnableThread;
	}
}

bool FHTTP_Thread_Nghttp2::Init()
{	
	this->Callback_HTTP_Start();
	this->bStartThread = true;

	return true;
}

uint32 FHTTP_Thread_Nghttp2::Run()
{
	while (this->bStartThread)
	{
		
	}

	return 0;
}

void FHTTP_Thread_Nghttp2::Stop()
{
	this->Callback_HTTP_Stop();
	
	this->bStartThread = false;
}

bool FHTTP_Thread_Nghttp2::Toggle(bool bIsPause)
{
	if (!this->RunnableThread)
	{
		return false;
	}

	this->RunnableThread->Suspend(bIsPause);
	
	return true;
}

void FHTTP_Thread_Nghttp2::Callback_HTTP_Start()
{
	nghttp2_session_callbacks_new(&this->callbacks);
}

void FHTTP_Thread_Nghttp2::Callback_HTTP_Stop()
{

}