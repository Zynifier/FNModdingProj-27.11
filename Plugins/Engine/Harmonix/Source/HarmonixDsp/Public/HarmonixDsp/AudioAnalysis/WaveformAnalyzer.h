// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WaveformAnalyzer.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixWaveformAnalyzerResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Results")
	TArray<float> WaveformRaw;

	UPROPERTY(BlueprintReadOnly, Category="Results")
	TArray<float> WaveformSmoothed;

};

USTRUCT(BlueprintType)
struct FHarmonixWaveformAnalyzerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	int32 NumBinsHeld;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 NumBinsPerSecond;

	UPROPERTY(EditAnywhere, Category="Settings")
	int32 SmoothingDistance;

	UPROPERTY(EditAnywhere, Category="Settings")
	float SmoothingFactor;

};

