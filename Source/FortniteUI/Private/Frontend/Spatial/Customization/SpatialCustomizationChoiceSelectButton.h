// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "CommonButtonLegacy.h"
#include "SpatialCustomizationChoiceSelectButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationChoiceSelectButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetupChoiceSelectButton(const FLinearColor& CategoryStateColor);

};

