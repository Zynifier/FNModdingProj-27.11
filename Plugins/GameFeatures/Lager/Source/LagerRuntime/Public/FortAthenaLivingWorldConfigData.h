// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldConfigData.generated.h"

class AFortAthenaLivingWorldEQSHelper;
class UDataTable;

USTRUCT()
struct FFortAthenaLivingWorldCategoryTableData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	FName Name;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> CategoryTable;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	FScalableFloat IsEnabled;

};

USTRUCT()
struct FFortAthenaLivingWorldTagDensityGridData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(Categories="Athena.AI.Lager.TagDensity"))
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat GridCellSize;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaLivingWorldConfigData : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="LivingWorld", meta=(AssetBundles="Server"))
	TArray<FFortAthenaLivingWorldCategoryTableData> CategoryTableDatas;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxActorCount;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxEventSpawnPerTick;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxActorDespawnPerTick;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MinimumEventGenerationInterval;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxActorDensity;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MaxActorUpdatesPerTick;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat ActorDensityGridCellSize;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat PointClusterSize;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat MinNumberOfPlayerForAggressiveSpawning;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	TArray<FFortAthenaLivingWorldTagDensityGridData> TagDensityGridData;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FGameplayTagQuery SingleUseSpawnerDataQuery;

	UPROPERTY(EditDefaultsOnly, Category="EQS Actor Helper")
	TSubclassOf<AFortAthenaLivingWorldEQSHelper> EQSActorHelperClass;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat DelayEventGeneration;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat RestrictDensityReservationForReservoirs;

};

