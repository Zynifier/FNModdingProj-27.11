// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortOutpostData.generated.h"

class UDataTable;
class UFortItemDefinition;
class UFortOutpostItemDefinition;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EOutpostBuildings : uint8
{
	StormShield = 0,
	HarvestingOptimizer = 1,
	StorageVault = 2,
	POST = 3,
};

USTRUCT(BlueprintType)
struct FOutpostBuildingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OutpostData")
	TSoftObjectPtr<UFortOutpostItemDefinition> ItemDefinition;

};

USTRUCT()
struct FHarvestingOptimizerBuildingData : public FOutpostBuildingData
{
	GENERATED_BODY()

};

USTRUCT()
struct FOutpostItemUpgradeData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	TSoftObjectPtr<UFortOutpostItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 ItemLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	FString RequiredItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	FString RequiredAccountItems;

};

USTRUCT(BlueprintType)
struct FOutpostPOSTBoost
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="POST")
	FCurveTableRowHandle PlayerStructureHealthModPerPOSTLevel;

};

USTRUCT(BlueprintType)
struct FOutpostPOSTPerTheaterData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="POST")
	int32 TheaterSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="POST")
	FOutpostPOSTBoost POSTData;

};

USTRUCT(BlueprintType)
struct FOutpostPrestigeEffects
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="OutpostData")
	TArray<TSubclassOf<UGameplayEffect>> EnemyPrestigeEffect;

};

USTRUCT(BlueprintType)
struct FOutpostPrestigeEffectsPerTheater
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OutpostData")
	int32 TheaterSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OutpostData")
	FOutpostPrestigeEffects PrestigeEffects;

};

USTRUCT(BlueprintType)
struct FOutpostUpgradesPerTheaterData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 TheaterSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	TObjectPtr<UDataTable> OutpostUpgradesData;

};

USTRUCT(BlueprintType)
struct FOutpostUpgradeAndPrestigeBuildingData : public FOutpostBuildingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OutpostData")
	int32 MaxPrestigeLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Upgrade")
	TObjectPtr<UDataTable> DefaultOutpostBuildingUpgradeData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Upgrade")
	TArray<FOutpostUpgradesPerTheaterData> PerTheaterOutpostBuildingUpgradeData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Prestige")
	FOutpostPrestigeEffects DefaultPrestigeData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Prestige")
	TArray<FOutpostPrestigeEffectsPerTheater> PrestigePerTheaterData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="POST")
	FOutpostPOSTBoost DefaultPOSTData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="POST")
	TArray<FOutpostPOSTPerTheaterData> POSTPerTheaterData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="POST")
	TSubclassOf<UGameplayEffect> POSTBuildingGameplayEffectClass;

};

USTRUCT(BlueprintType)
struct FStorageVaultBuildingData : public FOutpostBuildingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="OutpostData")
	TArray<int32> ItemCapacityPerLevel;

};

UCLASS(MinimalAPI)
class UFortOutpostData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NewOutpost")
	int32 StructureLimitNotificationThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NewOutpost")
	FOutpostBuildingData StormShieldData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NewOutpost")
	FHarvestingOptimizerBuildingData HarvestingOptimizerData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NewOutpost")
	FStorageVaultBuildingData StorageVaultData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NewOutpost")
	FOutpostUpgradeAndPrestigeBuildingData OutpostUpgradeAndPrestigeData;

};

UCLASS(BlueprintType)
class UOutpostPOSTRequirementData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="POST")
	TObjectPtr<UFortItemDefinition> RequirementItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="POST")
	int32 TotalRequired;

	UPROPERTY(BlueprintReadOnly, Category="POST")
	int32 AlreadyDeposited;

	UPROPERTY(BlueprintReadOnly, Category="POST")
	int32 AmountOwned;

	UPROPERTY(BlueprintReadOnly, Category="POST")
	bool bHasEnough;

	UPROPERTY(BlueprintReadOnly, Category="POST")
	int32 AmountToDeposit;

};

