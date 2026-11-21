// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/Components/FortVehicleFuelComponent.h"
#include "Net/UnrealNetwork.h"

float UFortVehicleFuelComponent::GetFuelCapacity() const
{
	return float();
}

const FRuntimeFuelUsageInfo& UFortVehicleFuelComponent::GetFuelUsageInfo()
{
	static FRuntimeFuelUsageInfo Dummy;
	return Dummy;
}

void UFortVehicleFuelComponent::OnRep_ServerFuel(float PreviousFuel)
{
}

void UFortVehicleFuelComponent::ReinitializeFuelUsageInfo()
{
}

void UFortVehicleFuelComponent::SetFuel(const float NewFuel)
{
}

void UFortVehicleFuelComponent::SetFuelUsageInfo(const FRuntimeFuelUsageInfo& NewFuelUsageInfo)
{
}

void UFortVehicleFuelComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleFuelComponent, ServerFuel);
}
