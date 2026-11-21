// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortItemQuantityPair.h"
#include "Items/FortItemEntry.h"
#include "STW/Items/FortOutpostItemDefinition.h"
#include "STW/Player/FortPlayerControllerPvE.h"
#include "FortPlayerControllerOutpost.generated.h"

class UFortOutpostItemDefinition;
enum class EOutpostBuildings : uint8;

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerOutpost : public AFortPlayerControllerPvE
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Outpost", meta=(HidePin="bLog"))
	bool CanUpgradeBuilding(EOutpostBuildings OutpostBuilding, bool bLog) const;

	UFUNCTION(BlueprintPure, Category="Outpost", meta=(HidePin="bLog"))
	bool CanUpgradeBuildingFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, bool bLog) const;

	UFUNCTION(Client, Reliable)
	void ClientOnOutpostRefundOccurred();

	UFUNCTION(Exec)
	void DumpInventory();

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetBuildingLevel(EOutpostBuildings OutpostBuilding) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetBuildingLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetBuildingMaxLevel(EOutpostBuildings OutpostBuilding) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetBuildingMaxLevelFromDefinition(UFortOutpostItemDefinition* OutpostBuilding) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	void GetBuildingUpgradeCost(EOutpostBuildings OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	void GetBuildingUpgradeCostFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, TArray<FFortItemQuantityPair>& OutWorldItems, TArray<FFortItemQuantityPair>& OutAccountItems) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	const int32 GetHighestEnduranceWaveReached() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetOutpostCoreLevel() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool IsOutpostOwner() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void LeaveOutpostAsParty();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Outpost")
	void OnCleanUpOnExit();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerCleanUpOnExit();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDepositPOSTResource(FGuid ItemGuid, int32 Count);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerLeaveOutpostAsParty();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveItemFromStorageVault(const FFortItemEntry& NewlyCollectedItem);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerMoveItemToStorageVault(const FFortItemEntry& NewlyStoredItem);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpgradePOST();

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void UpgradeBuilding(EOutpostBuildings OutpostBuilding);

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void UpgradeBuildingByDefinition(UFortOutpostItemDefinition* OutpostBuilding);

protected:
	UFUNCTION(Client, Reliable)
	void ClientOnBuildingLevelChanged(UFortOutpostItemDefinition* UpgradedBuilding, int32 InLevelBeforeUpgrade);

	UFUNCTION()
	void OnRep_PostDepositedResources();

	UPROPERTY()
	bool bOutpostRefundDialogPending;

	UPROPERTY(ReplicatedUsing=OnRep_PostDepositedResources)
	TArray<FFortDepositedResources> PostDepositedResources;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpgradeBuilding(UFortOutpostItemDefinition* BuildingToUpgrade);

	UFUNCTION(Exec)
	void ToggleOwnerInPIE();

	UPROPERTY(Transient)
	TObjectPtr<UFortOutpostItemDefinition> BuildingBeingUpgraded;

	UPROPERTY(Transient)
	int32 LevelBeforeUpgrade;

	UPROPERTY(Transient)
	bool bIsOutpostOwnerInPIE;

};

