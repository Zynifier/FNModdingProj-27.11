// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Faction/FortGameStateComponent_AffiliationManager.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_AffiliationManager::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortGameStateComponent_AffiliationManager::OnRep_FactionInfos()
{
}

void UFortGameStateComponent_AffiliationManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_AffiliationManager, FactionInfos);
}
