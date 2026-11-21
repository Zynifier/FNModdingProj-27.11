// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaWinConditionMsgBase.h"

void UAthenaWinConditionMsgBase::BindVolumeManagerEvents()
{
}

FSlateColor UAthenaWinConditionMsgBase::GetTextFillColor(const FRichTextStyleRow& Row) const
{
	return FSlateColor();
}

void UAthenaWinConditionMsgBase::HandleEnteredVolume(APlayerState* ClientState, AFortVolume* Volume)
{
}

void UAthenaWinConditionMsgBase::HandleExitVolume(APlayerState* ClientState, AFortVolume* Volume)
{
}

void UAthenaWinConditionMsgBase::HandleGameStateInitialized(AFortGameState* GameState)
{
}

void UAthenaWinConditionMsgBase::HandleMinigameEnded()
{
}

void UAthenaWinConditionMsgBase::HandlePlaylistInitialized()
{
}

void UAthenaWinConditionMsgBase::HandleSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume)
{
}

void UAthenaWinConditionMsgBase::OnShowHUDMessage(FHUDMessageData MessageData)
{
}
