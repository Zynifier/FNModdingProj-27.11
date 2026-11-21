// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "FortPerformanceTrackingSettings.generated.h"

class UQualitativePerfMetricSettings;

UCLASS(Config=Game, DefaultConfig)
class UFortPerformanceTrackingSettings : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, NoClear, Instanced, Category="Qualitative Perf Metrics")
	TObjectPtr<UQualitativePerfMetricSettings> QualitativePerfMetricSettings;

};

