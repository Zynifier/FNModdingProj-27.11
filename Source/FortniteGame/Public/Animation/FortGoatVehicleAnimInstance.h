// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortGoatVehicleAnimInstance.generated.h"

class AFortAthenaGoatVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortGoatVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaGoatVehicle> GolfCart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	float GolfCartSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bForwardSpeedIsNearlyZero;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bForwardSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bReverseSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bSpeedIsGreaterThanFiveAndPlayerHitSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bIsEBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bIsPowerSliding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGoatVehicleAnimInstance")
	bool bPlayerHitSpaceBar;

};

