// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHUDQualityLevelSelectTimer.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(meta=(DisableNativeTick))
class UFortHUDQualityLevelSelectTimer : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnProgressStarted(const float Duration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTimeRemainingChanged(const float TimeRemaining);

private:
	UFUNCTION()
	void UpdateTimeRemainingText(const float TimeRemaining);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDQualityLevelSelectTimer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ProgressBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHUDQualityLevelSelectTimer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

	UPROPERTY(EditAnywhere, Category="FortHUDQualityLevelSelectTimer")
	float TimerDuration;

	UPROPERTY(EditAnywhere, Category="FortHUDQualityLevelSelectTimer")
	FName ProgressBarMaterialParamName;

};

