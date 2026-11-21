// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortMotorcycleVehicleAnimInstance.h"
#include "FortSportbikeAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortSportbikeAnimInstance : public UFortMotorcycleVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	FRotator LimitedWheelRotationFR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool HasPassenger;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool ShouldPlayGroundTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool IsWheelie;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool StateRuleFromWheelieToGroundTrickOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool SportBikeWheelieEarlyOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool ShouldExitFromLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Sportbike|Nativized")
	bool IsChangingGear;

};

