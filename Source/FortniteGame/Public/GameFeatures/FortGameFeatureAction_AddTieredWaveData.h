// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddTieredWaveData.generated.h"

class UCurveTable;
class UDataTable;

USTRUCT()
struct FFortTieredWaveData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UDataTable> WaveSetCollectionData;

	UPROPERTY(EditDefaultsOnly, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UDataTable> WaveSetData;

	UPROPERTY(EditDefaultsOnly, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UDataTable> ModifierSetData;

	UPROPERTY(EditDefaultsOnly, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UDataTable> WaveSetCollectionLootData;

	UPROPERTY(EditAnywhere, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UCurveTable> TieredWavesDefenseReqTable;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Save the World Tiered Wave Data"))
class UFortGameFeatureAction_AddTieredWaveData : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Tiered Wave Data")
	FFortTieredWaveData TieredWaveDataToAdd;

};

