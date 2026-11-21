// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Player/FortPlayerControllerOutpost.h"
#include "Net/UnrealNetwork.h"

bool AFortPlayerControllerOutpost::CanUpgradeBuilding(EOutpostBuildings OutpostBuilding, bool bLog) const
{
	return false;
}

bool AFortPlayerControllerOutpost::CanUpgradeBuildingFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, bool bLog) const
{
	return false;
}

void AFortPlayerControllerOutpost::ClientOnBuildingLevelChanged_Implementation(UFortOutpostItemDefinition* UpgradedBuilding, int32 InLevelBeforeUpgrade)
{
}

void AFortPlayerControllerOutpost::ClientOnOutpostRefundOccurred_Implementation()
{
}

void AFortPlayerControllerOutpost::DumpInventory()
{
}

int32 AFortPlayerControllerOutpost::GetBuildingLevel(EOutpostBuildings OutpostBuilding) const
{
	return int32();
}

int32 AFortPlayerControllerOutpost::GetBuildingLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const
{
	return int32();
}

int32 AFortPlayerControllerOutpost::GetBuildingMaxLevel(EOutpostBuildings OutpostBuilding) const
{
	return int32();
}

int32 AFortPlayerControllerOutpost::GetBuildingMaxLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const
{
	return int32();
}

void AFortPlayerControllerOutpost::GetBuildingUpgradeCost(EOutpostBuildings OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const
{
}

void AFortPlayerControllerOutpost::GetBuildingUpgradeCostFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const
{
}

const int32 AFortPlayerControllerOutpost::GetHighestEnduranceWaveReached() const
{
	return int32();
}

int32 AFortPlayerControllerOutpost::GetOutpostCoreLevel() const
{
	return int32();
}

bool AFortPlayerControllerOutpost::IsOutpostOwner() const
{
	return false;
}

void AFortPlayerControllerOutpost::LeaveOutpostAsParty()
{
}

void AFortPlayerControllerOutpost::OnRep_PostDepositedResources()
{
}

void AFortPlayerControllerOutpost::ServerCleanUpOnExit_Implementation()
{
}
bool AFortPlayerControllerOutpost::ServerCleanUpOnExit_Validate()
{
	return true;
}

void AFortPlayerControllerOutpost::ServerDepositPOSTResource_Implementation(FGuid ItemGuid, int32 Count)
{
}
bool AFortPlayerControllerOutpost::ServerDepositPOSTResource_Validate(FGuid ItemGuid, int32 Count)
{
	return true;
}

void AFortPlayerControllerOutpost::ServerLeaveOutpostAsParty_Implementation()
{
}
bool AFortPlayerControllerOutpost::ServerLeaveOutpostAsParty_Validate()
{
	return true;
}

void AFortPlayerControllerOutpost::ServerMoveItemFromStorageVault_Implementation(const FFortItemEntry& NewlyCollectedItem)
{
}
bool AFortPlayerControllerOutpost::ServerMoveItemFromStorageVault_Validate(const FFortItemEntry& NewlyCollectedItem)
{
	return true;
}

void AFortPlayerControllerOutpost::ServerMoveItemToStorageVault_Implementation(const FFortItemEntry& NewlyStoredItem)
{
}
bool AFortPlayerControllerOutpost::ServerMoveItemToStorageVault_Validate(const FFortItemEntry& NewlyStoredItem)
{
	return true;
}

void AFortPlayerControllerOutpost::ServerUpgradeBuilding_Implementation(UFortOutpostItemDefinition* BuildingToUpgrade)
{
}
bool AFortPlayerControllerOutpost::ServerUpgradeBuilding_Validate(UFortOutpostItemDefinition* BuildingToUpgrade)
{
	return true;
}

void AFortPlayerControllerOutpost::ServerUpgradePOST_Implementation()
{
}
bool AFortPlayerControllerOutpost::ServerUpgradePOST_Validate()
{
	return true;
}

void AFortPlayerControllerOutpost::ToggleOwnerInPIE()
{
}

void AFortPlayerControllerOutpost::UpgradeBuilding(EOutpostBuildings OutpostBuilding)
{
}

void AFortPlayerControllerOutpost::UpgradeBuildingByDefinition(UFortOutpostItemDefinition* OutpostBuilding)
{
}

void AFortPlayerControllerOutpost::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerControllerOutpost, PostDepositedResources);
}
