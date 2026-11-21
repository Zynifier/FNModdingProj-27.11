// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "FortTreasureChestSpawnInfo.generated.h"

class ABuildingContainer;

USTRUCT(BlueprintType)
struct FFortTreasureChestSpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTreasureChestSpawnInfo")
	TSubclassOf<ABuildingContainer> TreasureChestClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTreasureChestSpawnInfo")
	FScalableFloat TreasureChestMinSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTreasureChestSpawnInfo")
	FScalableFloat TreasureChestMaxSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTreasureChestSpawnInfo")
	FScalableFloat GoldenPoiTreasureChestMinSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTreasureChestSpawnInfo")
	FScalableFloat GoldenPoiTreasureChestMaxSpawnPercent;

};

