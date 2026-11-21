// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QualitativePerfMetrics.generated.h"

UENUM()
enum class EQualitativePerfMetric : int32
{
	/* The average MVP value for the match. Currently disabled on PC. */
	MVP = 0,
	/* The average Hitch Time Percent for the match. */
	HitchTimePercent = 1,
	/* The 1st percentile of the distances at which levels streamed in during the match. */
	LevelStreamingDistanceP01 = 2,
	/* Represented as the lerp values between the platform's min/max dynamic res (eg. 0.5 means halfway between min/max). */
	DynamicResolution = 3,
	/* The percent of frames during the match that were over the 'bad ping threshold'. */
	PercentFramesOverBadPingThreshold = 4,
	/* Not Implemented */
	FrameTime = 5,
	/* Not Implemented */
	MemoryRisk = 6,
	/* Not Implemented */
	MapLoadTime = 7,
	/* Not Implemented */
	BootTime = 8,
	Count = 9 UMETA(Hidden),
};

UENUM()
enum class EQualitativePerfMetricIndex : uint8
{
	Excellent = 0,
	Good = 1,
	Average = 2,
	Poor = 3,
	Terrible = 4,
	Count = 5 UMETA(Hidden),
};

USTRUCT()
struct FQualitativePerfMetricScale
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="QualitativePerfMetricScale")
	EQualitativePerfMetric Metric;

	UPROPERTY(EditDefaultsOnly, Config, Category="QualitativePerfMetricScale", meta=(ArraySizeEnum="/Script/FortniteGame.EQualitativePerfMetricIndex", EditFixedOrder))
	TArray<float> ScaleValues;

};

