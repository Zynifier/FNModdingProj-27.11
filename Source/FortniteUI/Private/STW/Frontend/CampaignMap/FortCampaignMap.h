// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Input/FortSwipeDetector.h"
#include "FortCampaignMap.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCampaignMap : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Campaign Map")
	void OnShowNextPage();

	UFUNCTION(BlueprintImplementableEvent, Category="Campaign Map")
	void OnShowPreviousPage();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SwipeDetection")
	FFortSwipeDetector SwipeDetector;

private:
	UFUNCTION()
	void OnSwipeLeft();

	UFUNCTION()
	void OnSwipeRight();

};

