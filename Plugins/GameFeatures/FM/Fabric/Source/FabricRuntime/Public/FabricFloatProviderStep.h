// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricFloatProvider.h"
#include "FabricFloatProviderStep.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFloatProviderStepInitialized);

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricStepGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepGenerator")
	TArray<float> Values;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricFloatProviderStep : public UFabricFloatProviderBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetStepLengthBeats() const;

protected:
	UPROPERTY(EditAnywhere, Category="FabricFloatProviderStep")
	FString StepRateParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderStep")
	FString ActiveStepsParam;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderStep")
	FString StepParamBase;

	UPROPERTY(EditAnywhere, Category="FabricFloatProviderStep")
	int32 MaxSteps;

	UPROPERTY(BlueprintReadOnly, Category="FabricFloatProviderStep")
	FFabricStepGenerator RuntimeGenerator;

	UPROPERTY(BlueprintAssignable)
	FOnFloatProviderStepInitialized OnFloatProviderStepInitialized;

};

