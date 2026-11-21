// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Online/FortMcpProfileCampaign.h"

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

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAbandonExpedition)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AbandonExpedition")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execActivateConsumable)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ActivateConsumable")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execApplyAlteration)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ApplyAlteration")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAssignGadgetToLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AssignGadgetToLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAssignHeroToLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AssignHeroToLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAssignTeamPerkToLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AssignTeamPerkToLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAssignWorkerToSquad)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AssignWorkerToSquad")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execAssignWorkerToSquadBatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("AssignWorkerToSquadBatch")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClaimCollectedResources)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClaimCollectedResources")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClaimCollectionBookRewards)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClaimCollectionBookRewards")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClaimDifficultyIncreaseRewards)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClaimDifficultyIncreaseRewards")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClaimLoginReward)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClaimLoginReward")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClaimMissionAlertRewards)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClaimMissionAlertRewards")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execClearHeroLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ClearHeroLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execCollectExpedition)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("CollectExpedition")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execConsumeItems)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ConsumeItems")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execConvertItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ConvertItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execConvertLegacyAlterations)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ConvertLegacyAlterations")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execEarnScore)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("EarnScore")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execEndMatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("EndMatch")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execEndPrimaryMission)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("EndPrimaryMission")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execEquipCampaignCustomization)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("EquipCampaignCustomization")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execFailsafeSaveMissionResults)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("FailsafeSaveMissionResults")));
}

void UFortMcpProfileCampaign::GetCurrentHeroLoadoutItem(UFortCampaignHeroLoadoutItem*& OutCampaignHeroLoadoutItem) const
{
}

TArray<UFortCampaignHeroLoadoutItem*> UFortMcpProfileCampaign::GetOrderedHeroLoadoutItems()
{
	return TArray<UFortCampaignHeroLoadoutItem*>();
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execModifyMission)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ModifyMission")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execOpenCardPack)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("OpenCardPack")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execOpenCardPackBatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("OpenCardPackBatch")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execOverrideMissionRewardLootLevel)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("OverrideMissionRewardLootLevel")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execOverrideMissionRewardLootTierGroup)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("OverrideMissionRewardLootTierGroup")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execPopulatePrerolledOffers)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("PopulatePrerolledOffers")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execPromoteItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("PromoteItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execPurchaseOrUpgradeHomebaseNode)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("PurchaseOrUpgradeHomebaseNode")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execPurchaseResearchStatUpgrade)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("PurchaseResearchStatUpgrade")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRecycleItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RecycleItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRecycleItemBatch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RecycleItemBatch")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRefreshExpeditions)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RefreshExpeditions")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRefundItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RefundItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execResearchItemFromCollectionBook)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("ResearchItemFromCollectionBook")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRespecAlteration)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RespecAlteration")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRespecResearch)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RespecResearch")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execRespecUpgrades)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("RespecUpgrades")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSetActiveHeroLoadout)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SetActiveHeroLoadout")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSetGameplayStats)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SetGameplayStats")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSetHeroCosmeticVariants)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SetHeroCosmeticVariants")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSetLoadoutName)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SetLoadoutName")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSkipTutorial)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SkipTutorial")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execSlotItemInCollectionBook)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("SlotItemInCollectionBook")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execStartExpedition)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("StartExpedition")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execStartPrimaryMission)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("StartPrimaryMission")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execTransmogItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("TransmogItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUnassignAllSquads)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UnassignAllSquads")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUnloadWarehouse)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UnloadWarehouse")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUnslotAllWorkers)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UnslotAllWorkers")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUnslotItemFromCollectionBook)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UnslotItemFromCollectionBook")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUpdateBuildingLevelAndRating)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UpdateBuildingLevelAndRating")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUpgradeAlteration)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UpgradeAlteration")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUpgradeItem)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UpgradeItem")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUpgradeItemBulk)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UpgradeItemBulk")));
}

DEFINE_FUNCTION(UFortMcpProfileCampaign::execUpgradeItemRarity)
{
	FortStub_SkipThunkParams(Stack, UFortMcpProfileCampaign::StaticClass()->FindFunctionByName(TEXT("UpgradeItemRarity")));
}
