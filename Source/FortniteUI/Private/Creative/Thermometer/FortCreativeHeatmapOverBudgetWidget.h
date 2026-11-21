// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Thermometer/FortCreativeVolumeWidget.h"
#include "FortCreativeHeatmapOverBudgetWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeHeatmapOverBudgetWidget : public UFortCreativeVolumeWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Heatmap Over Budget Changed"))
	void BP_OnHeatmapOverBudgetChanged(const bool bHeatmapOverBudget);

};

