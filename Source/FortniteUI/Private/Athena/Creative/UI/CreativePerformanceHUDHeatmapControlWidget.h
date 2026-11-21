// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortHUDElementWidget.h"
#include "CreativePerformanceHUDHeatmapControlWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCreativePerformanceHUDHeatmapControlWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Heatmap")
	FBox GetCurrentVolumeBox() const;

	UFUNCTION(BlueprintPure, Category="Heatmap")
	FVector GetCurrentVolumeSize() const;

	UFUNCTION()
	void OnPlayerMovementUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void RefreshHeatmap(const FVector& PlayerPosition);

	UFUNCTION(BlueprintCallable, Category="Heatmap")
	void StartTimer();

	UFUNCTION(BlueprintCallable, Category="Heatmap")
	void StopTimer();

};

