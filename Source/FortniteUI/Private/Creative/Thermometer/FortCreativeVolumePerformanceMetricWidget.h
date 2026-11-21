// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Thermometer/FortCreativeVolumeWidget.h"
#include "ObjectTracking/FortBudgetCategory.h"
#include "ObjectTracking/ObjectTracking.h"
#include "FortCreativeVolumePerformanceMetricWidget.generated.h"

class AFortVolume;
enum class ESpatialLoadingState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeVolumePerformanceMetricWidget : public UFortCreativeVolumeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Cost Preview Of Selected Actor Updated"))
	void BP_OnCostPreviewOfSelectedActorUpdated(const int32 CostPreviewOfSelectedActor, const int32 HighestCellCostPreviewOfSelectedActor);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Volume Performance Metrics Updated"))
	void BP_OnVolumePerformanceMetricsUpdated(const FVolumePerformanceMetrics& VolumePerformanceMetrics);

	UFUNCTION()
	void OnVolumeManagerVolumeStateChanged(ESpatialLoadingState VolumeState, AFortVolume* Volume);

	UFUNCTION()
	void OnVolumePerformanceMetricsUpdated(const FVolumePerformanceMetrics& VolumePerformanceMetrics);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCreativeVolumePerformanceMetricWidget")
	FVolumePerformanceMetrics LastVolumePerformanceMetrics;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeVolumePerformanceMetricWidget")
	EFortBudgetCategory VolumePerformanceMetricCategory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCreativeVolumePerformanceMetricWidget")
	int32 LastCostPreviewOfSelectedActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="FortCreativeVolumePerformanceMetricWidget")
	int32 HighestCellLastCostPreviewOfSelectedActor;

};

