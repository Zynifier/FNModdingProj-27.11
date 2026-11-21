// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMcpProfileCreative.h"

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

DEFINE_FUNCTION(UFortMcpProfileCreative::execCreateNewBattleLabFile)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("CreateNewBattleLabFile")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execCreateNewIsland)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("CreateNewIsland")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execCreateNewIslandFromLinkCode)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("CreateNewIslandFromLinkCode")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execDeleteIsland)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("DeleteIsland")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execDuplicateIsland)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("DuplicateIsland")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execModifyCreativePlotPermissions)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("ModifyCreativePlotPermissions")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execRestoreDeletedIsland)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("RestoreDeletedIsland")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execSetCreativePlotMetadata)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("SetCreativePlotMetadata")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execSetLastUsedCreativePlot)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("SetLastUsedCreativePlot")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execUpdatePlotBuildCode)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("UpdatePlotBuildCode")));
}

DEFINE_FUNCTION(UFortMcpProfileCreative::execUpdatePlotPublishInfo)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCreative::StaticClass()->FindFunctionByName(TEXT("UpdatePlotPublishInfo")));
}
