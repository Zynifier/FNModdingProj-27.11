// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayEventRouterComponent.h"

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

void UGameplayEventRouterComponent::ClearEventState(const UObject* EventType)
{
}

void UGameplayEventRouterComponent::ClearEventStateByContext(const UObject* EventType, const UObject* Context)
{
}

bool UGameplayEventRouterComponent::HasValidEventState(const UObject* EventType, const UObject* Context) const
{
	return false;
}

DEFINE_FUNCTION(UGameplayEventRouterComponent::execK2_BroadcastEvent)
{
	FortStub_SkipThunkParams(Stack, UGameplayEventRouterComponent::StaticClass()->FindFunctionByName(TEXT("K2_BroadcastEvent")));
}
bool UGameplayEventRouterComponent::K2_BroadcastEvent(const int32& EventData, UObject* EventContext)
{
	return false;
}

DEFINE_FUNCTION(UGameplayEventRouterComponent::execK2_BroadcastStatefulEvent)
{
	FortStub_SkipThunkParams(Stack, UGameplayEventRouterComponent::StaticClass()->FindFunctionByName(TEXT("K2_BroadcastStatefulEvent")));
}
bool UGameplayEventRouterComponent::K2_BroadcastStatefulEvent(const int32& EventData, UObject* EventContext)
{
	return false;
}

void UGameplayEventRouterComponent::StopListeningToEvent(FGameplayEventListenerHandle& HandleToRemove)
{
}
