// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortWeaponPickupSpawnAmmoData.generated.h"

USTRUCT()
struct FHelperGameplayTagToAmmoCountMultiplier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Ammo Multiplier")
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category="Ammo Multiplier")
	FScalableFloat CountMultiplier;

};

USTRUCT()
struct FSourceToAmmoMultiplierOverrideData : public FHelperGameplayTagToAmmoCountMultiplier
{
	GENERATED_BODY()

};

USTRUCT()
struct FWeaponPickupAmmoCountData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Ammo Count", meta=(Categories="supplies.ammo"))
	FGameplayTag AmmoItemDefinitionTag;

	UPROPERTY(EditAnywhere, Category="Ammo Count")
	FScalableFloat SpawnCount;

};

USTRUCT()
struct FWeaponPickupAmmoMultiplierOverrideData : public FHelperGameplayTagToAmmoCountMultiplier
{
	GENERATED_BODY()

};

UCLASS()
class UFortWeaponPickupSpawnAmmoData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Ammo Counts", meta=(TitleProperty="AmmoItemDefinitionTag"))
	TArray<FWeaponPickupAmmoCountData> WeaponPickupAmmoCountArray;

	UPROPERTY(EditAnywhere, Category="Ammo Multiplier | Default", meta=(DisplayAfter="Ammo Counts"))
	FScalableFloat DefaultWeaponAmmoMultiplier;

	UPROPERTY(EditAnywhere, Category="Ammo Multiplier | Weapon Overrides", meta=(DisplayAfter="Ammo Multiplier | Default", TitleProperty="Tag"))
	TArray<FWeaponPickupAmmoMultiplierOverrideData> WeaponPickupAmmoMultiplierOverrideArray;

	UPROPERTY(EditAnywhere, Category="Ammo Multiplier | Source Object Overrides", meta=(DisplayAfter="Ammo Multiplier | Weapon Overrides", TitleProperty="Tag"))
	TArray<FSourceToAmmoMultiplierOverrideData> SourceToAmmoMultiplierOverrideArray;

};

