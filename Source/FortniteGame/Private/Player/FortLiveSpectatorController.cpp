// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortLiveSpectatorController.h"

void AFortLiveSpectatorController::HandlePlayerAdded(APlayerController* AddedPlayer)
{
}

void AFortLiveSpectatorController::ServerSetFollowedPlayer_Implementation(AFortPlayerState* NewPlayerToFollow, const FVector& SpectatorLocation, bool bValidPos)
{
}
bool AFortLiveSpectatorController::ServerSetFollowedPlayer_Validate(AFortPlayerState* NewPlayerToFollow, const FVector& SpectatorLocation, bool bValidPos)
{
	return true;
}
