// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortVehicleModSubsystem.generated.h"

class AActor;
class UFortVehicleModConfig;

USTRUCT(BlueprintType)
struct FFortGameFeatureActionParameters_AddVehicleModData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureActionParameters_AddVehicleModData", meta=(AssetBundles="Client, Server"))
	TSoftClassPtr<UFortVehicleModConfig> VehicleMod;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureActionParameters_AddVehicleModData")
	FGameplayTagContainer TargetVehicleTags;

};

USTRUCT(BlueprintType)
struct FFortVehicleModConfigEntries
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TSubclassOf<UFortVehicleModConfig>> VehicleTagToModConfig;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Vehicle Mod Data"))
class UFortGameFeatureAction_AddVehicleModData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Category="FortGameFeatureAction_AddVehicleModData", meta=(TitleProperty="VehicleMod"))
	TArray<FFortGameFeatureActionParameters_AddVehicleModData> VehicleMods;

};

UCLASS(MinimalAPI)
class UFortVehicleModSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, FFortVehicleModConfigEntries> ModTagToData;

	UPROPERTY(Transient)
	TSet<TWeakObjectPtr<AActor>> VehiclesPendingModCollection;

};

