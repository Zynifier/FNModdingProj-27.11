// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortHudContextTutorialIndicatorBall.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortHudContextTutorialIndicatorBall : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayIntroAnimation();

	UFUNCTION(BlueprintImplementableEvent)
	void SetArrowOrientation(float Angle);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortHudContextTutorialIndicatorBall")
	bool bCanArrowAnimationPlay;

};

