// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortMcpProfileMetadata.h"

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

DEFINE_FUNCTION(UFortMcpProfileMetadata::execCreateDeployableBaseItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileMetadata::StaticClass()->FindFunctionByName(TEXT("CreateDeployableBaseItem")));
}

DEFINE_FUNCTION(UFortMcpProfileMetadata::execCreateOrUpgradeOutpostItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileMetadata::StaticClass()->FindFunctionByName(TEXT("CreateOrUpgradeOutpostItem")));
}

DEFINE_FUNCTION(UFortMcpProfileMetadata::execUpdateDeployableBaseTierProgression)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileMetadata::StaticClass()->FindFunctionByName(TEXT("UpdateDeployableBaseTierProgression")));
}

DEFINE_FUNCTION(UFortMcpProfileMetadata::execUpdateOutpostCore)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileMetadata::StaticClass()->FindFunctionByName(TEXT("UpdateOutpostCore")));
}
