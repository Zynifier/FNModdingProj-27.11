// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlayerStartupController.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerStartupController::DropContainmentTimeToAllInCountdownTime()
{
}

float AFortPlayerStartupController::GetContainmentTimeRemaining()
{
	return float();
}

int32 AFortPlayerStartupController::GetNumPlayersCurrentlyReady()
{
	return int32();
}

int32 AFortPlayerStartupController::GetNumPlayersExpected()
{
	return int32();
}

int32 AFortPlayerStartupController::GetNumPlayersStillWaitingFor()
{
	return int32();
}

void AFortPlayerStartupController::HandleAllInCountdownInitiated_Implementation()
{
}

void AFortPlayerStartupController::HandlePlayerStartupControllerCreated_Implementation()
{
}

void AFortPlayerStartupController::HandlePlayerStartupControllerDestroyed_Implementation()
{
}

void AFortPlayerStartupController::HandlePlayerStartupControllerRegistered_Implementation()
{
}

void AFortPlayerStartupController::HandlePlayerStartupControllerReset_Implementation()
{
}

void AFortPlayerStartupController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerStartupController, ContainmentTimer);
}
