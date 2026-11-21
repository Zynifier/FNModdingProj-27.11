// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaTimeWidgetBase.h"

void UAthenaTimeWidgetBase::ClientEnteredVolume(APlayerState* PlayerState, AFortVolume* FortVolume)
{
}

bool UAthenaTimeWidgetBase::IsTextStyleValid_Implementation(const FName& DisplayTextStyle)
{
	return false;
}

void UAthenaTimeWidgetBase::OnMinigameEnded_Implementation()
{
}

void UAthenaTimeWidgetBase::OnMinigameStarted_Implementation()
{
}

void UAthenaTimeWidgetBase::OnTimerWidgetActorUpdated(const AActor* TimerWidgetActor)
{
}

void UAthenaTimeWidgetBase::UpdateTimeText()
{
}
