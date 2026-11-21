// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "FortAIPerkBase.generated.h"

USTRUCT()
struct FFortAIRuntimePerkInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFortAIPerkBase : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat CooldownDuration;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat CooldownDurationRandomDeviation;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat ActivationCountBeforeCooldown;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat ActivationDuration;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat ActivationDurationRandomDeviation;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat OddsToActivate;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat FailedActivationCooldownDuration;

	UPROPERTY(EditAnywhere, Category="FortAIPerkBase")
	FScalableFloat FailedActivationCooldownDurationRandomDeviation;

};

