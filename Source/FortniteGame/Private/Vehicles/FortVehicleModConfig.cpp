// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/FortVehicleModConfig.h"
#include "Net/UnrealNetwork.h"

void UFortVehicleModInstanceDataComponent::OnRep_ModConfig()
{
}

void UFortVehicleModInstanceDataComponent::OnRep_ModEnabled()
{
}

void UFortVehicleModInstanceDataComponent::OnRep_PhysicsShapeModifiers()
{
}

void UFortVehicleModInstanceDataComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleModInstanceDataComponent, ModConfig);
	DOREPLIFETIME(UFortVehicleModInstanceDataComponent, SpawnedBGAs);
	DOREPLIFETIME(UFortVehicleModInstanceDataComponent, PhysicsShapeModifiers);
	DOREPLIFETIME(UFortVehicleModInstanceDataComponent, bModEnabled);
}
