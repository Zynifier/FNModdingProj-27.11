// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortSpawnActorComponent.h"

UFortSpawnActorComponent::UFortSpawnActorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortSpawnActorComponent::OnPlaylistDataLoaded(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}
