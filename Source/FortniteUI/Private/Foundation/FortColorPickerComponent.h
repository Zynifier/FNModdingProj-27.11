// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortColorPickerComponent.generated.h"

class UCommonTextBlock;
class UFortColorPickerSlider;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortColorPickerComponent : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleOnValueChanged(float NormalizedNewValue);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ComponentName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CurrentValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPickerSlider> ColorSlider_Component;

};

