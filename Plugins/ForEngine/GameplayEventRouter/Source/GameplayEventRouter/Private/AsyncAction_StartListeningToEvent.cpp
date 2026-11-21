// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncAction_StartListeningToEvent.h"

#ifndef FORTSTUB_SKIP_THUNK_PARAMS
#define FORTSTUB_SKIP_THUNK_PARAMS
static void FortStub_SkipThunkParams(FFrame& Stack, UFunction* Function)
{
	if (Function)
	{
		for (TFieldIterator<FProperty> It(Function); It && It->HasAnyPropertyFlags(CPF_Parm); ++It)
		{
			if (It->HasAnyPropertyFlags(CPF_ReturnParm))
			{
				continue;
			}
			void* Temp = FMemory::Malloc(It->GetSize(), It->GetMinAlignment());
			It->InitializeValue(Temp);
			Stack.StepCompiledIn(Temp, It->GetClass());
			It->DestroyValue(Temp);
			FMemory::Free(Temp);
		}
	}
	P_FINISH;
}
#endif

DEFINE_FUNCTION(UAsyncAction_StartListeningToEvent::execGetPayload)
{
	FortStub_SkipThunkParams(Stack, UAsyncAction_StartListeningToEvent::StaticClass()->FindFunctionByName(TEXT("GetPayload")));
}
bool UAsyncAction_StartListeningToEvent::GetPayload(int32& OutPayload)
{
	return false;
}

UAsyncAction_StartListeningToEvent* UAsyncAction_StartListeningToEvent::StartListeningToEvent(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context, EEventBubblingRule EventBubblingRule)
{
	return nullptr;
}

UAsyncAction_StartListeningToEvent* UAsyncAction_StartListeningToEvent::StartListeningToEventBackwardCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context, EEventBubblingRule EventBubblingRule)
{
	return nullptr;
}

void UAsyncAction_StartListeningToEvent::StopListeningToEvent()
{
}
