// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaRiftPortal.h"

void AFortAthenaRiftPortal::AddIgnoredActor(const AActor* Actor)
{
}

bool AFortAthenaRiftPortal::IsIgnoredActor(const AActor* QueryActor) const
{
	return false;
}

void AFortAthenaRiftPortal::NotifyTeleportedVehicle_Implementation(AActor* VehicleActor)
{
}

void AFortAthenaRiftPortal::TeleportVehicle(AActor* Vehicle, const FVector& TeleportLocation)
{
}

void AFortAthenaRiftPortal::TeleportVehicleFacing(AActor* Vehicle, const FVector& TeleportLocation, const FRotator& Rot)
{
}
