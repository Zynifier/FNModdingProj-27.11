// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMcpProfileCommonPublic.h"

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

DEFINE_FUNCTION(UFortMcpProfileCommonPublic::execSetHomebaseBanner)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonPublic::StaticClass()->FindFunctionByName(TEXT("SetHomebaseBanner")));
}

DEFINE_FUNCTION(UFortMcpProfileCommonPublic::execSetHomebaseName)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCommonPublic::StaticClass()->FindFunctionByName(TEXT("SetHomebaseName")));
}
