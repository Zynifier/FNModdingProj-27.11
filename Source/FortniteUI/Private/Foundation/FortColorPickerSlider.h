// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnalogSlider.h"
#include "FortColorPickerSlider.generated.h"

class UMaterialInstanceDynamic;

UCLASS()
class UFortColorPickerSlider : public UAnalogSlider
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DynamicSliderMaterialInstance;

};

