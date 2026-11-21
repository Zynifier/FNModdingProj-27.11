// Copyright Epic Games, Inc. All Rights Reserved.

#include "CosmeticDataComponent.h"

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

DEFINE_FUNCTION(UCosmeticDataComponent::execBP_AddOrOverrideProperty)
{
	FortStub_SkipThunkParams(Stack, UCosmeticDataComponent::StaticClass()->FindFunctionByName(TEXT("BP_AddOrOverrideProperty")));
}
bool UCosmeticDataComponent::BP_AddOrOverrideProperty(FGameplayTag SlotTag, const FCosmeticPropertyBase& Property)
{
	return false;
}

DEFINE_FUNCTION(UCosmeticDataComponent::execBP_FindProperty)
{
	FortStub_SkipThunkParams(Stack, UCosmeticDataComponent::StaticClass()->FindFunctionByName(TEXT("BP_FindProperty")));
}
bool UCosmeticDataComponent::BP_FindProperty(FGameplayTag SlotTag, FGameplayTag PropertyTag, FCosmeticPropertyBase& OutProperty)
{
	return false;
}

void UCosmeticDataComponent::ResetProperties()
{
}
