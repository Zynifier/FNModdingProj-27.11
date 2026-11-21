// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaAvailableSquadSlotsListBase.h"

void UAthenaAvailableSquadSlotsListBase::HandleGameMemberChanged(uint8 InSquadId, uint8 InTeamIndex, AFortPlayerStateAthena* ChangedPS)
{
}

void UAthenaAvailableSquadSlotsListBase::HandlePlayerEnterVolume(APlayerState* ClientPlayerState, AFortVolume* Volume)
{
}

void UAthenaAvailableSquadSlotsListBase::HandlePlayerExitVolume(APlayerState* ClientPlayerState, AFortVolume* Volume)
{
}

void UAthenaAvailableSquadSlotsListBase::HandlePlayerUniqueIdReplicated(const FUniqueNetIdRepl& UniqueId)
{
}

void UAthenaAvailableSquadSlotsListBase::UpdateIsTeamMiniGameOnGameStateChanged(AFortMinigame* Minigame, EFortMinigameState MiniGameState)
{
}

void UAthenaAvailableSquadSlotsListBase::UpdateIsTeamMiniGameOnMinigameVolumeChanged(AFortVolume* Volume)
{
}

void UAthenaAvailableSquadSlotsListBase::UpdateSquadFromMinigameOptionChange()
{
}
