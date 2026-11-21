// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_DrawTaggedPlayerIndicators.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_DrawTaggedPlayerIndicators::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void AFortAthenaMutator_DrawTaggedPlayerIndicators::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_DrawTaggedPlayerIndicators, DrawingDataArray);
}
