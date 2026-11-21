// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortChargingSet_ScoutDroneEnergy.h"
#include "Net/UnrealNetwork.h"

void UFortChargingSet_ScoutDroneEnergy::OnRep_Energy(const FFortGameplayAttributeData& OldValue)
{
}

void UFortChargingSet_ScoutDroneEnergy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortChargingSet_ScoutDroneEnergy, Energy);
	DOREPLIFETIME(UFortChargingSet_ScoutDroneEnergy, MaxEnergy);
	DOREPLIFETIME(UFortChargingSet_ScoutDroneEnergy, EnergyChargeRate);
	DOREPLIFETIME(UFortChargingSet_ScoutDroneEnergy, ServerTimeEnergyIncrements);
}
