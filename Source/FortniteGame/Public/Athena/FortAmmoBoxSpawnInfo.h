// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "FortAmmoBoxSpawnInfo.generated.h"

class ABuildingContainer;

USTRUCT(BlueprintType)
struct FFortAmmoBoxSpawnInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAmmoBoxSpawnInfo")
	TSubclassOf<ABuildingContainer> AmmoBoxClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAmmoBoxSpawnInfo")
	FScalableFloat AmmoBoxMinSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAmmoBoxSpawnInfo")
	FScalableFloat AmmoBoxMaxSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAmmoBoxSpawnInfo")
	FScalableFloat GoldenPoiAmmoBoxMinSpawnPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAmmoBoxSpawnInfo")
	FScalableFloat GoldenPoiAmmoBoxMaxSpawnPercent;

};

