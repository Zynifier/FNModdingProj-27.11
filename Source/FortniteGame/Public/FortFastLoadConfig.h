// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortFastLoadConfig.generated.h"

UCLASS(Config=Game)
class UFortFastLoadConfig : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	uint8 bDisableStreamInBuildings : 1;

	UPROPERTY(Config)
	uint8 bDisableStartupAIDirector : 1;

	UPROPERTY(Config)
	uint8 bDisableUpgradePlayerBuildingClasses : 1;

	UPROPERTY(Config)
	uint8 bUseMinimalPlayerBuildingClasses : 1;

	UPROPERTY(Config)
	uint8 bDisableStartingMissions : 1;

	UPROPERTY(Config)
	uint8 bUseFastLoadDefaultInventory : 1;

	UPROPERTY(Config)
	uint8 bDisableThreatVisualsManager : 1;

	UPROPERTY(Config)
	uint8 bDisablePreLoadAssets : 1;

	UPROPERTY(Config)
	uint8 bDisablePreLoadLootAssets : 1;

	UPROPERTY(Config)
	uint8 bDisableLoadStateClientAthena : 1;

	UPROPERTY(Config)
	uint8 bDisableGameFeaturePlugins : 1;

};

