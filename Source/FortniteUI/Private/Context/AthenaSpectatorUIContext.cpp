// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/AthenaSpectatorUIContext.h"

UAthenaRemotePlayerViewData* UAthenaSpectatorUIContext::GetFollowedPlayerData() const
{
	return nullptr;
}

bool UAthenaSpectatorUIContext::GetPipMode() const
{
	return false;
}

UAthenaRemotePlayerViewData* UAthenaSpectatorUIContext::GetPlayerData(const FUniqueNetIdRepl PlayerUID) const
{
	return nullptr;
}

void UAthenaSpectatorUIContext::OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer)
{
}

void UAthenaSpectatorUIContext::OnGameStateSet(AFortGameState* InGameState)
{
}

void UAthenaSpectatorUIContext::OnPawnForReplayRelevancyChanged(AFortPawn* InPawnForReplayRelevancy)
{
}

void UAthenaSpectatorUIContext::OnPlayerBecameIrrelevant(AFortPlayerState* FPS)
{
}

void UAthenaSpectatorUIContext::OnPlayerBecameRelevant(AFortPlayerState* FPS)
{
}

void UAthenaSpectatorUIContext::OnPlayerControllerSet()
{
}

void UAthenaSpectatorUIContext::OnPlayerStateAdded(AFortPlayerStateAthena* FPSA)
{
}
