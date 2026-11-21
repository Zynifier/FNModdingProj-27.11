// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayEffectCalculations/ModifierCalculations/FortGameplayModMagnitudeCalculation.h"
#include "PlayerTrapBonusModMagnitudeCalculation.generated.h"

UCLASS(HideCategories=("Attributes", "ExternalDependencies"))
class UPlayerTrapBonusModMagnitudeCalculation : public UFortGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly, Category="Attribute")
	float AttributeDefaultValue;

};

