// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "BallerRaceIntroWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBallerRaceIntroWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void StartCountdown();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Countdown Time")
	float LengthOfCountdown;

};

