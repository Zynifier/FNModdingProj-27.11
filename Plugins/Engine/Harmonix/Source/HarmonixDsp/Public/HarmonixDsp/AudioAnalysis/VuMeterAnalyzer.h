// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HarmonixDsp/AudioAnalysis/OutputSettings.h"
#include "VuMeterAnalyzer.generated.h"

USTRUCT(BlueprintType)
struct FHarmonixVuMeterAnalyzerChannelValues
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Results")
	float LevelMeanSquared;

	UPROPERTY(BlueprintReadOnly, Category="Results")
	float PeakSquared;

};

USTRUCT(BlueprintType)
struct FHarmonixVuMeterAnalyzerResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Results")
	float MonoPeakDecibels;

	UPROPERTY(BlueprintReadOnly, Category="Results")
	TArray<FHarmonixVuMeterAnalyzerChannelValues> ChannelValues;

	UPROPERTY(BlueprintReadOnly, Category="Results")
	FHarmonixVuMeterAnalyzerChannelValues MonoValues;

};

USTRUCT(BlueprintType)
struct FHarmonixVuMeterAnalyzerSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Settings")
	float AvgWindowMs;

	UPROPERTY(EditAnywhere, Category="Settings")
	float PeakHoldMs;

	UPROPERTY(EditAnywhere, Category="Settings")
	FHarmonixAudioAnalyzerOutputSettings OutputSettings;

};

