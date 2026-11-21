// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SpatialMetricsSubsystem.generated.h"

class USpatialMetric;
class USpatialMetricsSubsystemExtension;

UCLASS(Config=Engine, DefaultConfig, MinimalAPI)
class USpatialMetricsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	float UpdateRateInSeconds;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<USpatialMetric>> Metrics;

	UPROPERTY(Transient)
	TArray<TObjectPtr<USpatialMetricsSubsystemExtension>> Extensions;

};

