// Copyright Epic Games, Inc. All Rights Reserved.

#include "McpProfile.h"

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

DEFINE_FUNCTION(UMcpProfile::execDeleteAllProfiles)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("DeleteAllProfiles")));
}

DEFINE_FUNCTION(UMcpProfile::execDeleteProfile)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("DeleteProfile")));
}

DEFINE_FUNCTION(UMcpProfile::execLockProfileForWrite)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("LockProfileForWrite")));
}

DEFINE_FUNCTION(UMcpProfile::execQueryProfile)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("QueryProfile")));
}

DEFINE_FUNCTION(UMcpProfile::execQueryPublicProfile)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("QueryPublicProfile")));
}

DEFINE_FUNCTION(UMcpProfile::execUnlockProfileForWrite)
{
	FortStub_SkipThunkParams(Stack, UMcpProfile::StaticClass()->FindFunctionByName(TEXT("UnlockProfileForWrite")));
}
