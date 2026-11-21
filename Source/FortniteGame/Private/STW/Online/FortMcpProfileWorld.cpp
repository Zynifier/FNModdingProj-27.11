// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortMcpProfileWorld.h"

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

DEFINE_FUNCTION(UFortMcpProfileWorld::execBatchUpdatePlayers)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("BatchUpdatePlayers")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execBatchUpdatePlayers_DeployableBase)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("BatchUpdatePlayers_DeployableBase")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execBatchUpdatePlayers_Outpost)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("BatchUpdatePlayers_Outpost")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execCraftWorldItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("CraftWorldItem")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execDepositPostResources)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("DepositPostResources")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execDestroyWorldItems)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("DestroyWorldItems")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execDisassembleWorldItems)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("DisassembleWorldItems")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execInitializeTheater)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("InitializeTheater")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execLockProfiles)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("LockProfiles")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execModifyQuickbar)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("ModifyQuickbar")));
}

void UFortMcpProfileWorld::OnHotbarUpdated()
{
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execStorageTransfer)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("StorageTransfer")));
}

DEFINE_FUNCTION(UFortMcpProfileWorld::execUnlockProfiles)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileWorld::StaticClass()->FindFunctionByName(TEXT("UnlockProfiles")));
}
