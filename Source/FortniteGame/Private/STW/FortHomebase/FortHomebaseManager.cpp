// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortHomebase/FortHomebaseManager.h"

bool UFortHomebaseManager::AreNodeCostsMet(const UFortHomebaseNodeItemDefinition* NodeItemDef, UFortMcpProfileCampaign* McpProfile, int32 Level)
{
	return false;
}

FString UFortHomebaseManager::GetNodeInstanceIdByNodeId(const FString& NodeTemplateId, const UFortMcpProfileCampaign* McpProfile) const
{
	return FString();
}

int32 UFortHomebaseManager::GetNumAccountInventoryBonusTokens(UFortMcpProfileCampaign* McpProfile)
{
	return int32();
}

int32 UFortHomebaseManager::GetNumAccountLimitedItems(UFortMcpProfileCampaign* McpProfile)
{
	return int32();
}

int32 UFortHomebaseManager::GetNumWorldInventoryBonusTokens(UFortMcpProfileCampaign* McpProfile)
{
	return int32();
}

bool UFortHomebaseManager::GetSquadCopyById(FName SquadId, FHomebaseSquad& OutSquad)
{
	return false;
}

void UFortHomebaseManager::GetSquadPopulation(FName SquadId, const UFortMcpProfileCampaign* McpProfile, TArray<UFortWorker*>& OutSquadMembers) const
{
}

UFortWorker* UFortHomebaseManager::GetWorkerInSquadSlot(FName SquadId, int32 SlotIdx, const UFortMcpProfileCampaign* McpProfile) const
{
	return nullptr;
}

bool UFortHomebaseManager::IsSquadSlotUnlocked(FName SquadId, int32 SlotIdx, const UFortMcpProfileCampaign* McpProfile) const
{
	return false;
}
