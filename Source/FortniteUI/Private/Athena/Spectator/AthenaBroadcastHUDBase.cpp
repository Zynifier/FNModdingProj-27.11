// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Spectator/AthenaBroadcastHUDBase.h"

void UAthenaBroadcastHUDBase::HandleHudVisibilityChanged(EHudVisibilityState NewVisibility)
{
}

void UAthenaBroadcastHUDBase::HandleNameplatesEnabledChanged(bool bInNameplatesEnabled)
{
}

void UAthenaBroadcastHUDBase::HandleSpectatorViewTargetChanged()
{
}

void UAthenaBroadcastHUDBase::HandleToggleActionFeedScreen()
{
}

void UAthenaBroadcastHUDBase::HandleToggleGoToTime()
{
}

void UAthenaBroadcastHUDBase::HandleToggleHighlightsList()
{
}

void UAthenaBroadcastHUDBase::HandleToggleReplayViewSettings()
{
}

void UAthenaBroadcastHUDBase::OnCurrentPlaylistChanged()
{
}

void UAthenaBroadcastHUDBase::OnCursorModeChanging(bool bCursorModeEnabled, FName ActionName)
{
}

void UAthenaBroadcastHUDBase::OnGameStateSet(AFortGameState* NewGameState)
{
}

void UAthenaBroadcastHUDBase::OnToggleActiveGridScreenActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnToggleEliminatedGridScreenActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnToggleKillFeedActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnToggleMatchStatusScreenActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnTogglePipModeActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnToggleScoreboardScreenActionExecuted(bool& bPassthrough)
{
}

void UAthenaBroadcastHUDBase::OnVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UAthenaBroadcastHUDBase::OnVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UAthenaBroadcastHUDBase::OnVolumeMinigameChanged(AFortMinigame* Minigame)
{
}

void UAthenaBroadcastHUDBase::TryHandleIfPlayerStateAlreadyInVolume()
{
}
