// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortItemQuantityPair.h"
#include "FortOutpostContext.generated.h"

class UFortItemDefinition;
class UFortOutpostItemDefinition;
class UFortWorldItemDefinition;
class UOutpostPOSTRequirementData;
enum class EOutpostBuildings : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBuildingLevelChanged, UFortOutpostItemDefinition*, OutpostBuilding);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGooContentNeedRefresh);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemsNeedRefresh);

UCLASS()
class UFortOutpostContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Outpost", meta=(HidePin="bLog"))
	bool CanUpgradeBuilding(EOutpostBuildings OutpostBuilding, bool bLog) const;

	UFUNCTION(BlueprintPure, Category="Outpost", meta=(HidePin="bLog"))
	bool CanUpgradeBuildingFromDefinition(UFortOutpostItemDefinition* OutpostBuilding, bool bLog) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	bool CanUpgradePOST() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Outpost")
	void CleanUpOnExit() const;

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void DepositPOSTResource(const UFortItemDefinition* ResourceItem, int32 Count);

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

	UFUNCTION(BlueprintPure, Category="HarvestingOptimizer")
	UFortWorldItemDefinition* GetHarvestingToolForLevel(int32 InHarvestingOptimizerLevel) const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetHighestEnduranceWaveReached() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	TArray<UOutpostPOSTRequirementData*> GetNextPOSTLevelRequirements() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	int32 GetOutpostCoreLevel() const;

	UFUNCTION(BlueprintPure, Category="Outpost")
	float GetPOSTBuildingHealthMod(int32 POSTLevel) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Outpost")
	void LeaveOutpostAsParty() const;

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void UpgradeBuilding(EOutpostBuildings OutpostBuilding);

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void UpgradeBuildingByDefinition(UFortOutpostItemDefinition* BuildingToUpgrade);

	UFUNCTION(BlueprintCallable, Category="Outpost")
	void UpgradePOST();

	UPROPERTY(BlueprintAssignable, Category="Outpost")
	FOnBuildingLevelChanged OnBuildingLevelChanged;

	UPROPERTY(BlueprintAssignable, Category="Outpost")
	FOnItemsNeedRefresh OnItemsNeedRefresh;

	UPROPERTY(BlueprintAssignable, Category="Outpost")
	FOnGooContentNeedRefresh OnGooContentNeedRefresh;

};

