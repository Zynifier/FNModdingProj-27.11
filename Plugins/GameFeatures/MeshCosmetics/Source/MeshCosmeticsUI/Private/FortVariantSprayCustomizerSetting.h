// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortVariantSprayCustomizerSetting.generated.h"

class UAnalogSlider;

UCLASS(Abstract, meta=(Category="MeshCosmetics UI", DisableNativeTick))
class UFortVariantSprayCustomizerSetting : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortVariantSprayCustomizerSetting(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Change Value"))
	void BP_OnChangeValue(const float Value, const float NormalizedValue);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Set Constraints"))
	void BP_OnSetConstraints(const FFloatRange& Constraints);

private:
	UFUNCTION()
	void HandleSliderValueChanged(float NormalizedValue);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVariantSprayCustomizerSetting", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAnalogSlider> Slider_Value;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantSprayCustomizerSetting")
	float CommitDelay;

};

