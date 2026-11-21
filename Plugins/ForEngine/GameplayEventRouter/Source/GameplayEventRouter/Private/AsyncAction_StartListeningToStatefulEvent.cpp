// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncAction_StartListeningToStatefulEvent.h"

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

DEFINE_FUNCTION(UAsyncAction_StartListeningToStatefulEvent::execGetPayload)
{
	FortStub_SkipThunkParams(Stack, UAsyncAction_StartListeningToStatefulEvent::StaticClass()->FindFunctionByName(TEXT("GetPayload")));
}
bool UAsyncAction_StartListeningToStatefulEvent::GetPayload(int32& OutPayload)
{
	return false;
}

UAsyncAction_StartListeningToStatefulEvent* UAsyncAction_StartListeningToStatefulEvent::StartListeningToStatefulEvent(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context, EEventBubblingRule EventBubblingRule)
{
	return nullptr;
}

UAsyncAction_StartListeningToStatefulEvent* UAsyncAction_StartListeningToStatefulEvent::StartListeningToStatefulEventBackwardsCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, UObject* EventType, UObject* Context, EEventBubblingRule EventBubblingRule)
{
	return nullptr;
}

void UAsyncAction_StartListeningToStatefulEvent::StopListeningToStatefulEvent()
{
}
