// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorResourceSizeMetric.h"
#include "SpatialMetric.h"
#include "SpatialMetricsActorIndexerSubscriber.h"
#include "ActorPackageDependencyResourceSizeMetric_Archive.generated.h"

UCLASS(meta=(DisplayName="ActorPackageDependencyResourceSizeMetric (Archive References)"))
class UActorPackageDependencyResourceSizeMetric_Archive : public USpatialMetric, public ISpatialMetricsActorIndexerSubscriber
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EResourceSizeMemoryCategory MemoryCategoryFlags;

};

