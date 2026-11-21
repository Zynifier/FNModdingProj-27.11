// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/MinigameWidgetBase.h"

int32 UMinigameWidgetBase::GetStatValue(UFortMinigameStatFilter* InFilter, const bool bGameTotal) const
{
	return int32();
}

void UMinigameWidgetBase::HandleOwningPlayerChangedTeams()
{
}

void UMinigameWidgetBase::HandlePlayerStatChanged()
{
}

void UMinigameWidgetBase::HideAllMinigameWidgetUI()
{
}

FAthenaGameMessageData UMinigameWidgetBase::MakeMessageData(EAthenaGameMsgType MsgType, FText MsgText, USoundCue* MsgSound, float DisplayTime)
{
	return FAthenaGameMessageData();
}

void UMinigameWidgetBase::OnCurrentStateChangedDelegate(AFortMinigame* Minigame, EFortMinigameState MinigameState)
{
}

void UMinigameWidgetBase::OnDisplayMinigameInProgressUI_Implementation(bool bDisplay)
{
}

void UMinigameWidgetBase::OnVolumeMinigameChanged(AFortMinigame* Minigame)
{
}
