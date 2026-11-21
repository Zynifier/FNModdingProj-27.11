// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "RangeValidator.generated.h"

UENUM()
enum class EFortRangeRule : int32
{
	// The value should be between Min and Max

	Bounded = 0,
	// The value should be less than Max

	MinUnbounded = 1,
	// The value should be greater than Min

	MaxUnbounded = 2,
};

UCLASS()
class UFortRangeValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	FName PropertyName;

	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	float Min;

	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	float Max;

	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	bool bMinInclusive;

	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	bool bMaxInclusive;

	UPROPERTY(EditDefaultsOnly, Category="FortRangeValidator")
	EFortRangeRule RangeRule;

};

