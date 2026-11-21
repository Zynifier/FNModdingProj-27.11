// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetric.h"
#include "SpatialMetricsActorIndexerSubscriber.h"
#include "ActorResourceSizeMetric.generated.h"

UENUM()
enum class EResourceSizeMemoryCategory : uint8
{
	None = 0,
	System = 1,
	Video = 2,
	Other = 4,
	All = 7,
};

UCLASS()
class UActorResourceSizeMetric : public USpatialMetric, public ISpatialMetricsActorIndexerSubscriber
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float UpdateTimeThresholdInMs;

	UPROPERTY()
	EResourceSizeMemoryCategory MemoryCategoryFlags;

};

