// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameStateComponent_HeistDisplayCaseItemManager.h"

UFortWorldItemDefinition* UFortGameStateComponent_HeistDisplayCaseItemManager::GetDisplayCaseItem(FGameplayTag DisplayCaseGroupTag)
{
	return nullptr;
}

void UFortGameStateComponent_HeistDisplayCaseItemManager::HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

bool UFortGameStateComponent_HeistDisplayCaseItemManager::IsDataReady() const
{
	return false;
}
