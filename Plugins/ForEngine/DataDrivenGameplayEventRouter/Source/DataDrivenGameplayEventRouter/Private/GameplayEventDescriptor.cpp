// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayEventDescriptor.h"

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

DEFINE_FUNCTION(UGameplayEventDescriptorLibrary::execBroadcastEvent)
{
	FortStub_SkipThunkParams(Stack, UGameplayEventDescriptorLibrary::StaticClass()->FindFunctionByName(TEXT("BroadcastEvent")));
}
bool UGameplayEventDescriptorLibrary::BroadcastEvent(const FGameplayEventDescriptor& EventDescriptor, UObject* EventContext, const int32& Event, UClass* EventRouterScope, AActor* RouterContextActor)
{
	return false;
}
