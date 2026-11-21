// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_Aircraft.h"

void UFortControllerComponent_Aircraft::ClientEnterAircraft_Implementation(AFortAircraft* InAircraft)
{
}

void UFortControllerComponent_Aircraft::ClientExitAircraft_Implementation()
{
}

bool UFortControllerComponent_Aircraft::IsInAircraft() const
{
	return false;
}

void UFortControllerComponent_Aircraft::KickFromAircraft()
{
}

void UFortControllerComponent_Aircraft::OnCurrentAircraftEnterDropZone(AFortAthenaAircraft* InAircraft)
{
}

void UFortControllerComponent_Aircraft::PlacePlayerInAircraft(AFortAircraft* AircraftToEnter, const bool bKeepInventory)
{
}

void UFortControllerComponent_Aircraft::ServerAttemptAircraftJump_Implementation(FRotator ClientRotation)
{
}
