// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_Crafting.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_Crafting::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortGameStateComponent_Crafting::OnRep_CraftingResultsList()
{
}

void UFortGameStateComponent_Crafting::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_Crafting, CraftingResultsList);
}
