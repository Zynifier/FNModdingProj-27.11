// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortWeaponPickupSpawnModData.generated.h"

class UDataTable;
class UFortWeaponModItemDefinition;
class UFortWeaponModSetData;

USTRUCT()
struct FWeaponModItemDefinitionWeightData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeaponModItemDefinitionWeightData")
	TSoftObjectPtr<UFortWeaponModItemDefinition> WeaponMod;

	UPROPERTY(EditAnywhere, Category="WeaponModItemDefinitionWeightData")
	FScalableFloat Weight;

};

USTRUCT()
struct FWeightedWeaponModList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WeightedWeaponModList")
	TArray<FWeaponModItemDefinitionWeightData> WeightedWeaponMods;

};

USTRUCT()
struct FAutoApplyWeaponModData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AutoApplyWeaponModData")
	TArray<FGameplayTag> ApplicableWeaponTags;

	UPROPERTY(EditAnywhere, Category="AutoApplyWeaponModData")
	TArray<FScalableFloat> WeightedNumModsToRoll;

	UPROPERTY(EditAnywhere, Category="AutoApplyWeaponModData")
	TMap<FGameplayTag, FScalableFloat> WeightedSlotsToRoll;

	UPROPERTY(EditAnywhere, Category="AutoApplyWeaponModData")
	TMap<FGameplayTag, FWeightedWeaponModList> ModSlotsToWeightedMods;

};

USTRUCT()
struct FFortWeaponModBucketEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponModSetData> ModSet;

	UPROPERTY(Transient)
	float EntryWeight;

};

USTRUCT()
struct FFortWeaponModBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortWeaponModBucketEntry> BucketEntries;

};

UCLASS()
class UFortWeaponPickupSpawnModData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortWeaponPickupSpawnModData")
	TArray<FAutoApplyWeaponModData> ApplyWeaponModData;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponPickupSpawnModData")
	TObjectPtr<UDataTable> ModSetDataTable;

	UPROPERTY(Transient)
	TMap<FGameplayTag, FFortWeaponModBucket> TagToBucketDataCache;

};

