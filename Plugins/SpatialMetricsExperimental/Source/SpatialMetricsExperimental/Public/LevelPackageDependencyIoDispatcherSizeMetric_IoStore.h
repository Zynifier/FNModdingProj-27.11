// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActorPackageDependencyIoDispatcherSizeMetric_Archive.h"
#include "SpatialMetric.h"
#include "LevelPackageDependencyIoDispatcherSizeMetric_IoStore.generated.h"

UCLASS(meta=(DisplayName="LevelPackageDependencyIoDispatcherSizeMetric (IoStore References)"))
class ULevelPackageDependencyIoDispatcherSizeMetric_IoStore : public USpatialMetric
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EIoDispatcherChunkTypeFlags ChunkTypeFlags;

};

