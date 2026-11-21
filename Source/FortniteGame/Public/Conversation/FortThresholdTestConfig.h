// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScalableFloat.h"
#include "FortThresholdTestConfig.generated.h"

UENUM()
enum class EThresholdRequirement : uint8
{
	LessThan = 0,
	LessThanOrEqual = 1,
	Equal = 2,
	GreaterThan = 3,
	GreaterThanOrEqual = 4,
};

USTRUCT(BlueprintType)
struct FThresholdTestConfig
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ThresholdTestConfig")
	EThresholdRequirement Requirement;

	UPROPERTY(EditAnywhere, Category="ThresholdTestConfig")
	FScalableFloat Quantity;

};

UCLASS(meta=(ScriptName="ThresholdTestLibrary"))
class UThresholdTestConfigLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool DoesQueryValuePass(const FThresholdTestConfig& ThresholdTestConfig, const float QueryValue) const;

};

