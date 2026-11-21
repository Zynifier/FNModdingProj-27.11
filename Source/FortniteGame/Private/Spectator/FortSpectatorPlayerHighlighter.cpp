// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spectator/FortSpectatorPlayerHighlighter.h"

ESpectatorCameraType AFortSpectatorPlayerHighlighter::GetCurrentSpectatorCameraType() const
{
	return ESpectatorCameraType();
}

void AFortSpectatorPlayerHighlighter::HandleFirstPlaceHighlightEnabledChanged(bool bFirstPlaceHighlightEnabled)
{
}

void AFortSpectatorPlayerHighlighter::HandleFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer)
{
}

void AFortSpectatorPlayerHighlighter::HandleHighlightedPlayerDeadStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDead)
{
}

void AFortSpectatorPlayerHighlighter::HandleHighlightedPlayerDisconnectedChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDisconnected)
{
}

void AFortSpectatorPlayerHighlighter::HandleHighlightedPlayerPawnChanged()
{
}

void AFortSpectatorPlayerHighlighter::HandlePlayerOutlinesEnabledChanged(bool bOutlinesEnabled)
{
}

void AFortSpectatorPlayerHighlighter::HandleSpectatorCameraTypeChanged(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType)
{
}

bool AFortSpectatorPlayerHighlighter::ShouldBeVisible() const
{
	return false;
}
