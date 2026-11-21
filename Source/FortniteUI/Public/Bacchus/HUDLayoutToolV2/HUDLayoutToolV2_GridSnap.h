// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_GridSnap.generated.h"

class UAnalogSlider;
class UCommonTextBlock;
class UFortSimpleMaterialProgressBar;
class UHUDLayoutToolV2_Button;
class UPaperSprite;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_GridSnap : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleSliderValueChanged(float InValue);

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_GridSnap")
	bool bGridSnapEnabled;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_GridSnap")
	TObjectPtr<UPaperSprite> CheckMarkSprite;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SettingValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAnalogSlider> Slider_SettingValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleEnabled;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSimpleMaterialProgressBar> ProgressBar_ColoredBackground;

};

