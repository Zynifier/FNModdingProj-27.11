// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "MultiPropertyNumericComparisonValidator.generated.h"

UENUM()
enum class EFortNumericComparisonRule : uint8
{
	// Checks if the each number is greater than the next

	CheckIfGreater = 0,
	// Checks if the each number is greater or equal to the next

	CheckIfGreaterOrEqual = 1,
	// Checks if the each number is lesser than the next

	CheckIfLesser = 2,
	// Checks if the each number is lesser or equal to the next

	CheckIfLesserOrEqual = 3,
	// Checks if the each number is equal to the next

	CheckIfEqual = 4,
	// Checks if the each number is not equal to the next

	CheckIfNotEqual = 5,
};

UCLASS()
class UFortMultiPropertyNumericComparisonValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortMultiPropertyNumericComparisonValidator")
	TArray<FName> PropertyNames;

	UPROPERTY(EditDefaultsOnly, Category="FortMultiPropertyNumericComparisonValidator")
	EFortNumericComparisonRule NumericComparisonRule;

};

