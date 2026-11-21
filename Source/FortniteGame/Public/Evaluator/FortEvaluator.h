// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEvaluator.generated.h"

USTRUCT(BlueprintType)
struct FEvaluationResult
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="EvaluationResult")
	bool bSucceeded;

	UPROPERTY(BlueprintReadOnly, Category="EvaluationResult")
	FString ErrorCode;

	UPROPERTY(BlueprintReadOnly, Category="EvaluationResult")
	FText ErrorMessage;

};

