// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaStormSurgeWidgetBase.generated.h"

enum class EStormSurgeThresholdType : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EStormSurgeThresholdType : uint8
{
	None = 0,
	Above = 1,
	Below = 2,
	Equal = 3,
};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaStormSurgeWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStartDisplaying(const FText& TitleText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopDisplaying();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateThresholdDisplay(const FText& ThresholdText, EStormSurgeThresholdType ThresholdType);

	UFUNCTION(BlueprintCallable)
	void UpdateUI();

};

