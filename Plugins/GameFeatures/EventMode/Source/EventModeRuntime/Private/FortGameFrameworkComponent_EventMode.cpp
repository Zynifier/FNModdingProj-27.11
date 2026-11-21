// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameFrameworkComponent_EventMode.h"

UFortGameFrameworkComponent_EventMode::UFortGameFrameworkComponent_EventMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortGameFrameworkComponent_EventMode::GetIsEventModeActive() const
{
	return false;
}

bool UFortGameFrameworkComponent_EventMode::GetIsFocusAvailable() const
{
	return false;
}

bool UFortGameFrameworkComponent_EventMode::GetIsFocusing() const
{
	return false;
}

void UFortGameFrameworkComponent_EventMode::OnEnterVehicle()
{
}

void UFortGameFrameworkComponent_EventMode::OnExitVehicle()
{
}

void UFortGameFrameworkComponent_EventMode::OnPlayerPawnPossessed(APawn* PossessedPawn)
{
}
