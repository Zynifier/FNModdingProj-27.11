// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/Components/FortBuildingEnergyComponent.h"
#include "Net/UnrealNetwork.h"

void UFortBuildingEnergyComponent::OnRep_EnergyAttrSet()
{
}

void UFortBuildingEnergyComponent::UpdateCurrentEnergyLevelAttr(float NewEnergyLevel)
{
}

void UFortBuildingEnergyComponent::UpdateEnergyCapacityAttr(float NewEnergyCapacity)
{
}

void UFortBuildingEnergyComponent::UpdateEnergyCostAttr(float NewEnergyCost)
{
}

void UFortBuildingEnergyComponent::UpdateEnergyRechargeDelayAttr(float NewEnergyRechargeDelay)
{
}

void UFortBuildingEnergyComponent::UpdateRegenRateAttr(float NewRegenRate)
{
}

void UFortBuildingEnergyComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingEnergyComponent, EnergyComponentAttrSet);
}

void UFortBuildingEnergyComponentAttrSet::OnRep_CurrentEnergyLevel(const FFortGameplayAttributeData& OldValue)
{
}

void UFortBuildingEnergyComponentAttrSet::OnRep_EnergyCapacity(const FFortGameplayAttributeData& OldValue)
{
}

void UFortBuildingEnergyComponentAttrSet::OnRep_EnergyCost(const FFortGameplayAttributeData& OldValue)
{
}

void UFortBuildingEnergyComponentAttrSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingEnergyComponentAttrSet, CurrentEnergyLevel);
	DOREPLIFETIME(UFortBuildingEnergyComponentAttrSet, EnergyCost);
	DOREPLIFETIME(UFortBuildingEnergyComponentAttrSet, EnergyCapacity);
}
