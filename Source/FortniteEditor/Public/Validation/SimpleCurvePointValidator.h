// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseValidationDataRepository.h"
#include "SimpleCurvePointValidator.generated.h"

USTRUCT()
struct FCurvePoint
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CurvePoint")
	float Time;

	UPROPERTY(EditDefaultsOnly, Category="CurvePoint")
	float Value;

};

USTRUCT()
struct FCurvePoints
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CurvePoints")
	TArray<FCurvePoint> CurvePoints;

};

UCLASS()
class UFortSimpleCurvePointValidator : public UFortBaseValidator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortSimpleCurvePointValidator")
	TMap<FName, FCurvePoints> CurveValidationData;

};

