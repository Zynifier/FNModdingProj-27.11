// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortLiveBroadcastController.h"

bool AFortLiveBroadcastController::CanStartBattleBus()
{
	return false;
}

void AFortLiveBroadcastController::ClientHideBusButton_Implementation()
{
}

void AFortLiveBroadcastController::ServerBeginBusPhase_Implementation()
{
}
bool AFortLiveBroadcastController::ServerBeginBusPhase_Validate()
{
	return true;
}

void AFortLiveBroadcastController::ServerOnSpectatorCameraTypeChanged_Implementation(ESpectatorCameraType NewCameraMode, const FVector& SpectatorLocation, bool bValidPos)
{
}
bool AFortLiveBroadcastController::ServerOnSpectatorCameraTypeChanged_Validate(ESpectatorCameraType NewCameraMode, const FVector& SpectatorLocation, bool bValidPos)
{
	return true;
}

void AFortLiveBroadcastController::TryBeginBusPhase()
{
}
