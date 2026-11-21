// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameFramework/AsyncAction_RegisterGameplayMessageReceiver.h"

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

DEFINE_FUNCTION(UAsyncAction_RegisterGameplayMessageReceiver::execGetPayload)
{
	FortStub_SkipThunkParams(Stack, UAsyncAction_RegisterGameplayMessageReceiver::StaticClass()->FindFunctionByName(TEXT("GetPayload")));
}
bool UAsyncAction_RegisterGameplayMessageReceiver::GetPayload(int32& OutPayload)
{
	return false;
}

UAsyncAction_RegisterGameplayMessageReceiver* UAsyncAction_RegisterGameplayMessageReceiver::RegisterGameplayMessageReceiver(UObject* WorldContextObject, FEventMessageTag Channel, UObject* PayloadType, EGameplayMessageMatchType MatchType, AActor* ActorContext)
{
	return nullptr;
}

void UAsyncAction_RegisterGameplayMessageReceiver::Unregister()
{
}
