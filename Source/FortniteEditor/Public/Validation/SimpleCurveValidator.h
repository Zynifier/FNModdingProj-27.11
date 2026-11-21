// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "SimpleCurveValidator.generated.h"

UENUM()
enum class EFortCurveRule : uint8
{
	// Checks if each value on the curve is >= the previous value

	CheckIfMonotonicallyIncreasing = 0,
	// Checks if each value on the curve is <= the previous value

	CheckIfMonotonicallyDecreasing = 1,
};

UCLASS()
class UFortSimpleCurveValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortSimpleCurveValidator")
	EFortCurveRule CurveRule;

};

