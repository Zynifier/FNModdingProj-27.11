// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetric.h"
#include "SpatialMetricsActorIndexerSubscriber.h"
#include "ActorPackageDependencyARDiskSizeMetric_Archive.generated.h"

UCLASS(meta=(DisplayName="ActorPackageDependencyARDiskSizeMetric (Archive References)"))
class UActorPackageDependencyARDiskSizeMetric_Archive : public USpatialMetric, public ISpatialMetricsActorIndexerSubscriber
{
	GENERATED_BODY()

};

