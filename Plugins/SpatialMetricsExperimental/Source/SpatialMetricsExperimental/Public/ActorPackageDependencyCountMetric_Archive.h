// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SpatialMetric.h"
#include "SpatialMetricsActorIndexerSubscriber.h"
#include "ActorPackageDependencyCountMetric_Archive.generated.h"

UCLASS(meta=(DisplayName="ActorPackageDependencyCountMetric (Archive References)"))
class UActorPackageDependencyCountMetric_Archive : public USpatialMetric, public ISpatialMetricsActorIndexerSubscriber
{
	GENERATED_BODY()

};

