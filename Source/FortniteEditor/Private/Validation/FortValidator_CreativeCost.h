// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_CreativeCost.generated.h"

class AActor;

USTRUCT()
struct FFortCostValidatorOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TSoftClassPtr<AActor> Class;

	UPROPERTY(Config)
	int32 PercentIncreased;

};

UCLASS(Config=Engine)
class UFortValidator_CreativeCost : public UFortEditorValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	int32 WarningIncreasePercent;

	UPROPERTY(Config)
	int32 WarningIncreaseAmount;

	UPROPERTY(Config)
	int32 ErrorIncreasePercent;

	UPROPERTY(Config)
	TArray<FFortCostValidatorOverride> ClassesToSkipValidator;

	UPROPERTY(Config)
	bool bOnlyLogAsWarning;

};

