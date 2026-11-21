// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetricsActorTrackerSubscriber.h"
#include "SpatialMetricsSubsystemExtension.h"
#include "SpatialMetricsActorIndexer.generated.h"

UCLASS(Config=Engine, DefaultConfig, MinimalAPI)
class USpatialMetricsActorIndexer : public USpatialMetricsSubsystemExtension, public ISpatialMetricsActorTrackerSubscriber
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 IndexCacheSize;

};

