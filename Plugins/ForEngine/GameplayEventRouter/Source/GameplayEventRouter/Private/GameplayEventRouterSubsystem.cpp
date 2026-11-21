// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayEventRouterSubsystem.h"

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

void UGameplayEventRouterSubsystem::ClearEventStateBackwardCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, const UObject* EventType)
{
}

void UGameplayEventRouterSubsystem::ClearEventStateByContextBackwardCompatible(UObject* WorldContextObject, FEventMessageTag Channel, UGameplayEventRouterComponent* Target, const UObject* EventType, const UObject* Context)
{
}

UGameplayEventRouterComponent* UGameplayEventRouterSubsystem::GetEventRouter(UClass* Scope, AActor* ContextActor)
{
	return nullptr;
}

UGameplayEventRouterComponent* UGameplayEventRouterSubsystem::GetGlobalEventRouter(const UObject* WorldContextObject)
{
	return nullptr;
}

DEFINE_FUNCTION(UGameplayEventRouterSubsystem::execK2_BroadcastEventBackwardCompatible)
{
	FortStub_SkipThunkParams(Stack, UGameplayEventRouterSubsystem::StaticClass()->FindFunctionByName(TEXT("K2_BroadcastEventBackwardCompatible")));
}
bool UGameplayEventRouterSubsystem::K2_BroadcastEventBackwardCompatible(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, FEventMessageTag Channel, const int32& EventData, UObject* EventContext)
{
	return false;
}

DEFINE_FUNCTION(UGameplayEventRouterSubsystem::execK2_BroadcastStatefulEventBackwardCompatible)
{
	FortStub_SkipThunkParams(Stack, UGameplayEventRouterSubsystem::StaticClass()->FindFunctionByName(TEXT("K2_BroadcastStatefulEventBackwardCompatible")));
}
bool UGameplayEventRouterSubsystem::K2_BroadcastStatefulEventBackwardCompatible(UObject* WorldContextObject, UGameplayEventRouterComponent* Target, FEventMessageTag Channel, const int32& EventData, UObject* EventContext)
{
	return false;
}
