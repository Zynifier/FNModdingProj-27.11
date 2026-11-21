// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortDeterminismConfig.generated.h"

UCLASS(Config=Game)
class UFortDeterminismConfig : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static int32 GetSkyPoiDeterministicSpawnIndex();

	UFUNCTION(BlueprintPure)
	static bool IsUsingBaseDefenseDeterminism();

	UFUNCTION(BlueprintPure)
	static bool IsUsingNoMilkshake();

	UFUNCTION(BlueprintPure)
	static bool IsUsingRadioTowerDeterminism();

private:
	UPROPERTY(Config)
	uint8 bStormDeterminism : 1;

	UPROPERTY(Config)
	uint8 bAIDeterminism : 1;

	UPROPERTY(Config)
	uint8 bNoAI : 1;

	UPROPERTY(Config)
	uint8 bNoLager : 1;

	UPROPERTY(Config)
	uint8 bWorldDeterminism : 1;

	UPROPERTY(Config)
	uint8 bWeatherDeterminism : 1;

	UPROPERTY(Config)
	uint8 bNoValet : 1;

	UPROPERTY(Config)
	uint8 bSkyPoiDeterminism : 1;

	UPROPERTY(Config)
	int8 SkyPoiDeterministicSpawnIndex;

	UPROPERTY(Config)
	uint8 bNoMilkshake : 1;

	UPROPERTY(Config)
	uint8 bRadioTowerDeterminism : 1;

	UPROPERTY(Config)
	uint8 bBaseDefenseDeterminism : 1;

};

