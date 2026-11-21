// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMotorcycleVehicle.h"
#include "Net/UnrealNetwork.h"

void AFortMotorcycleVehicle::ChangeBoostAttackState(const bool bNewIsBoostAttacking)
{
}

FVector AFortMotorcycleVehicle::GetAverageSpringNormal() const
{
	return FVector();
}

float AFortMotorcycleVehicle::GetLeanAngleDegrees() const
{
	return float();
}

EPhysicalSurface AFortMotorcycleVehicle::GetSurfaceTypeVehicleOn() const
{
	return EPhysicalSurface();
}

bool AFortMotorcycleVehicle::IsInInventoryMode() const
{
	return false;
}

bool AFortMotorcycleVehicle::IsPowerSliding() const
{
	return false;
}

bool AFortMotorcycleVehicle::IsSuperSliding() const
{
	return false;
}

void AFortMotorcycleVehicle::OnPlayerWeaponChanged(AFortWeapon* InNewWeapon, AFortWeapon* InPrevWeapon)
{
}

void AFortMotorcycleVehicle::OnRep_IsBoostAttacking()
{
}

void AFortMotorcycleVehicle::ServerEjectAllPlayers_Implementation()
{
}

void AFortMotorcycleVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMotorcycleVehicle, BoostShapeIndices);
	DOREPLIFETIME(AFortMotorcycleVehicle, bIsBoostAttacking);
}
