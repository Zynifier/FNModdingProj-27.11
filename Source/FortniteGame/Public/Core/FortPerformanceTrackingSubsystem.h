// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortPerformanceTrackingSubsystem.generated.h"

class UFortPerfReport;

UCLASS(Abstract)
class UFortPerformanceTrackingSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortPerformanceChartSubsystem : public UFortPerformanceTrackingSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortPerfReport> PerfReportConfig;

};

