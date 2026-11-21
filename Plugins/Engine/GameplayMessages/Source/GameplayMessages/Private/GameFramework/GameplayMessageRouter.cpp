// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameFramework/GameplayMessageRouter.h"

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

void UGameplayMessageRouter::ClearSavedMessage(FEventMessageTag Channel)
{
}

bool UGameplayMessageRouter::HasValidSavedMessage(FEventMessageTag Channel) const
{
	return false;
}

DEFINE_FUNCTION(UGameplayMessageRouter::execK2_BroadcastMessage)
{
	FortStub_SkipThunkParams(Stack, UGameplayMessageRouter::StaticClass()->FindFunctionByName(TEXT("K2_BroadcastMessage")));
}
void UGameplayMessageRouter::K2_BroadcastMessage(FEventMessageTag Channel, const int32& Message, bool bSaveToChannel, AActor* ActorContext)
{
}
