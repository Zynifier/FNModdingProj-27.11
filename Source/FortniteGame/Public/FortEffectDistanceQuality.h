// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEffectDistanceQuality.generated.h"

USTRUCT()
struct FFortEffectDistanceQuality
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Quality", meta=(EditCondition="bAllowCinematic"))
	float MinDistanceCinematic;

	UPROPERTY(EditAnywhere, Category="Quality", meta=(EditCondition="bAllowEpic"))
	float MinDistanceEpic;

	UPROPERTY(EditAnywhere, Category="Quality", meta=(EditCondition="bAllowHigh"))
	float MinDistanceHigh;

	UPROPERTY(EditAnywhere, Category="Quality", meta=(EditCondition="bAllowMedium"))
	float MinDistanceMedium;

	UPROPERTY(EditAnywhere, Category="Quality", meta=(EditCondition="bAllowLow"))
	float MinDistanceLow;

	UPROPERTY()
	uint8 bAllowCinematic : 1;

	UPROPERTY()
	uint8 bAllowEpic : 1;

	UPROPERTY()
	uint8 bAllowHigh : 1;

	UPROPERTY()
	uint8 bAllowMedium : 1;

	UPROPERTY()
	uint8 bAllowLow : 1;

};

