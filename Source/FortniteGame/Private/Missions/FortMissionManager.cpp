// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionManager.h"
#include "Net/UnrealNetwork.h"

bool AFortMissionManager::GetSpawnLocationActorsMatchingEntryItemQuery(UObject* WorldContextObject, const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors)
{
	return false;
}

bool AFortMissionManager::GetSpawnLocationActorsThatHaveAddedTagsMatchingQuery(UObject* WorldContextObject, const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors)
{
	return false;
}

void AFortMissionManager::MissionsUpdated()
{
}

void AFortMissionManager::OnRep_AllMissionEnemyClasses()
{
}

void AFortMissionManager::OnRep_CurrentUIFocusedMission()
{
}

void AFortMissionManager::OnRep_EarnedBadgesArray()
{
}

void AFortMissionManager::OnRep_MissionUIActors()
{
}

bool AFortMissionManager::ShouldShowSecondaryMissionHeaders() const
{
	return false;
}

void AFortMissionManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMissionManager, BluGloManager);
	DOREPLIFETIME(AFortMissionManager, AllMissionEnemyClasses);
	DOREPLIFETIME(AFortMissionManager, MissionUIActors);
	DOREPLIFETIME(AFortMissionManager, CurrentUIFocusedMission);
	DOREPLIFETIME(AFortMissionManager, MissionClosestToPar);
	DOREPLIFETIME(AFortMissionManager, EarnedBadgesArray);
}
