// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/Components/FortVehicleSeatWeaponComponent.h"
#include "Net/UnrealNetwork.h"

void UFortVehicleSeatWeaponComponent::EquipVehicleWeapon(AFortPawn* FortPawn, FWeaponSeatDefinition& WeaponSeatDefinition, int32 ItemLevel)
{
}

float UFortVehicleSeatWeaponComponent::GetCurrentOverheatValue() const
{
	return float();
}

const FVector UFortVehicleSeatWeaponComponent::GetDynamicReticleLocation() const
{
	return FVector();
}

float UFortVehicleSeatWeaponComponent::GetOverheatingMaxValue() const
{
	return float();
}

float UFortVehicleSeatWeaponComponent::GetOverheatScaler() const
{
	return float();
}

float UFortVehicleSeatWeaponComponent::GetOverheatTime() const
{
	return float();
}

AActor* UFortVehicleSeatWeaponComponent::GetVehicle() const
{
	return nullptr;
}

void UFortVehicleSeatWeaponComponent::OnRep_OverheatValueRepped()
{
}

void UFortVehicleSeatWeaponComponent::OnRep_ShotsFired()
{
}

void UFortVehicleSeatWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, OverheatValueRepped);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, bWeaponEquipped);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, ActorBase);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, ShotsFired);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, bWeaponOverheatDataHasBeenCached);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, CachedWeaponOverheatData);
	DOREPLIFETIME(UFortVehicleSeatWeaponComponent, CachedWeaponState);
}
