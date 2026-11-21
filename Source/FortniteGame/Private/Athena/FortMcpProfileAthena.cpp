// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortMcpProfileAthena.h"

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

DEFINE_FUNCTION(UFortMcpProfileAthena::execApplyVote)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ApplyVote")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execAthenaPinQuest)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("AthenaPinQuest")));
}

bool UFortMcpProfileAthena::CanPurchaseSeasonBook() const
{
	return false;
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execChallengeBundleLevelUp)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ChallengeBundleLevelUp")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execDeleteModularCosmeticLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("DeleteModularCosmeticLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execEndBattleRoyaleGameV2)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("EndBattleRoyaleGameV2")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execEquipModularCosmeticLoadoutPreset)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("EquipModularCosmeticLoadoutPreset")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execExchangeGameCurrencyForBattlePassOffer)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ExchangeGameCurrencyForBattlePassOffer")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execExchangeGiftToken)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ExchangeGiftToken")));
}

UAthenaSeasonItemDefinition* UFortMcpProfileAthena::GetActiveSeasonDefinition() const
{
	return nullptr;
}

int32 UFortMcpProfileAthena::GetCurrencyTotal(const FString& CurrencyStatName) const
{
	return int32();
}

int32 UFortMcpProfileAthena::GetSeasonBookLevel() const
{
	return int32();
}

int32 UFortMcpProfileAthena::GetSeasonFriendMatchXpBoost() const
{
	return int32();
}

FAthenaSeasonRewardLevelInfo UFortMcpProfileAthena::GetSeasonLevelInfo(const int32 SeasonLevel) const
{
	return FAthenaSeasonRewardLevelInfo();
}

bool UFortMcpProfileAthena::GetSeasonLevelUpReward(int32 SeasonLevel, FFortItemInstanceQuantityPair& Reward, int32& RewardLevel)
{
	return false;
}

int32 UFortMcpProfileAthena::GetSeasonMatchXpBoost() const
{
	return int32();
}

int32 UFortMcpProfileAthena::GetSeasonRestedXp() const
{
	return int32();
}

int32 UFortMcpProfileAthena::GetSurvivorPrestige() const
{
	return int32();
}

int32 UFortMcpProfileAthena::GetSurvivorTier() const
{
	return int32();
}

void UFortMcpProfileAthena::HandleActiveEventFlagsChanged(const TArray<FString>& ActiveEventFlags)
{
}

bool UFortMcpProfileAthena::HasPurchasedSeasonBook() const
{
	return false;
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execPutModularCosmeticLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("PutModularCosmeticLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execRedeemSTWAccoladeTokens)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("RedeemSTWAccoladeTokens")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execReportConsumableUsed)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ReportConsumableUsed")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execRequestRestedStateIncrease)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("RequestRestedStateIncrease")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execSetHardcoreModifier)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("SetHardcoreModifier")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execSetRewardGraphConfig)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("SetRewardGraphConfig")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execToggleQuestActiveState)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("ToggleQuestActiveState")));
}

DEFINE_FUNCTION(UFortMcpProfileAthena::execUnlockRewardNode)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileAthena::StaticClass()->FindFunctionByName(TEXT("UnlockRewardNode")));
}
