// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "SimpleNumericValidator.generated.h"

UENUM()
enum class EFortNumericRule : uint8
{
	// Checks if the Number > 0

	CheckIfPositive = 0,
	// Checks if the Number < 0

	CheckIfNegative = 1,
	// Checks if the Number == 0

	CheckIfZero = 2,
	// Checks if the Number != 0

	CheckIfNonZero = 3,
	// Checks if the Number <= 0

	CheckIfNonPositive = 4,
	// Checks if the Number >= 0

	CheckIfNonNegative = 5,
};

UCLASS()
class UFortSimpleNumericValdiator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortSimpleNumericValdiator")
	FName PropertyName;

	UPROPERTY(EditDefaultsOnly, Category="FortSimpleNumericValdiator")
	EFortNumericRule NumericRule;

};

