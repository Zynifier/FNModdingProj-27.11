// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantEditorWidgetBase.h"
#include "FortFloatSliderVariantPicker.generated.h"

class UAnalogSlider;
class UCommonTextBlock;
class UFortCosmeticFloatSliderVariant;

UCLASS()
class UFortFloatSliderVariantPicker : public UFortVariantEditorWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleSliderValueChanged(float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateValue(float NormalizedValue, bool bIsLocked);

	UPROPERTY(EditDefaultsOnly, Category="FortFloatSliderVariantPicker")
	float CommitDelay;

	UPROPERTY(Transient)
	TObjectPtr<UFortCosmeticFloatSliderVariant> FloatVariant;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VariantName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Value;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAnalogSlider> Slider_Value;

};

