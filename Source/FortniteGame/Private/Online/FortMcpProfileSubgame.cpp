// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMcpProfileSubgame.h"

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

DEFINE_FUNCTION(UFortMcpProfileSubgame::execClaimQuestReward)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("ClaimQuestReward")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execClientQuestLogin)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("ClientQuestLogin")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execCopyCosmeticLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("CopyCosmeticLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execDeleteCosmeticLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("DeleteCosmeticLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execFortRerollDailyQuest)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("FortRerollDailyQuest")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execMarkNewQuestNotificationSent)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("MarkNewQuestNotificationSent")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execServerQuestLogin)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("ServerQuestLogin")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetCosmeticLockerBanner)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetCosmeticLockerBanner")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetCosmeticLockerName)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetCosmeticLockerName")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetCosmeticLockerSlot)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetCosmeticLockerSlot")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetCosmeticLockerSlots)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetCosmeticLockerSlots")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetItemArchivedStatusBatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetItemArchivedStatusBatch")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetItemFavoriteStatus)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetItemFavoriteStatus")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetItemFavoriteStatusBatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetItemFavoriteStatusBatch")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetPinnedQuests)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetPinnedQuests")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execSetRandomCosmeticLoadoutFlag)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("SetRandomCosmeticLoadoutFlag")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execUpdateQuestClientObjectives)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("UpdateQuestClientObjectives")));
}

DEFINE_FUNCTION(UFortMcpProfileSubgame::execUpdateQuests)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileSubgame::StaticClass()->FindFunctionByName(TEXT("UpdateQuests")));
}
