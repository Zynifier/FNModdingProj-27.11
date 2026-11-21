// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Outpost/FortOutpostContext.h"

bool UFortOutpostContext::CanUpgradeBuilding(EOutpostBuildings OutpostBuilding, bool bLog) const
{
	return false;
}

bool UFortOutpostContext::CanUpgradeBuildingFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, bool bLog) const
{
	return false;
}

bool UFortOutpostContext::CanUpgradePOST() const
{
	return false;
}

void UFortOutpostContext::CleanUpOnExit() const
{
}

void UFortOutpostContext::DepositPOSTResource(const UFortItemDefinition* ResourceItem, int32 Count)
{
}

int32 UFortOutpostContext::GetBuildingLevel(EOutpostBuildings OutpostBuilding) const
{
	return int32();
}

int32 UFortOutpostContext::GetBuildingLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const
{
	return int32();
}

int32 UFortOutpostContext::GetBuildingMaxLevel(EOutpostBuildings OutpostBuilding) const
{
	return int32();
}

int32 UFortOutpostContext::GetBuildingMaxLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const
{
	return int32();
}

void UFortOutpostContext::GetBuildingUpgradeCost(EOutpostBuildings OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const
{
}

void UFortOutpostContext::GetBuildingUpgradeCostFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const
{
}

UFortWorldItemDefinition* UFortOutpostContext::GetHarvestingToolForLevel(int32 InHarvestingOptimizerLevel) const
{
	return nullptr;
}

int32 UFortOutpostContext::GetHighestEnduranceWaveReached() const
{
	return int32();
}

TArray<UOutpostPOSTRequirementData*> UFortOutpostContext::GetNextPOSTLevelRequirements() const
{
	return TArray<UOutpostPOSTRequirementData*>();
}

int32 UFortOutpostContext::GetOutpostCoreLevel() const
{
	return int32();
}

float UFortOutpostContext::GetPOSTBuildingHealthMod(int32 POSTLevel) const
{
	return float();
}

void UFortOutpostContext::LeaveOutpostAsParty() const
{
}

void UFortOutpostContext::UpgradeBuilding(EOutpostBuildings OutpostBuilding)
{
}

void UFortOutpostContext::UpgradeBuildingByDefinition(UFortOutpostItemDefinition* BuildingToUpgrade)
{
}

void UFortOutpostContext::UpgradePOST()
{
}
