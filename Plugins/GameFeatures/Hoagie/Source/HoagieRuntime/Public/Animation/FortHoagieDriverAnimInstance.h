// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortVehicleOccupantAnimInstance.h"
#include "FortHoagieDriverAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortHoagieDriverAnimInstance : public UFortVehicleOccupantAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieDriverAnimInstance")
	FVector LeftHandIKPositionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieDriverAnimInstance")
	FVector RightHandIKPositionOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieDriverAnimInstance")
	FRotator LeftHandIKRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieDriverAnimInstance")
	FRotator RightHandIKRotationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	EFortCardinalDirection BoostCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	float NormalizedAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	float VehicleRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	float VehicleYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	float ForwardSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bIsMovingAnyDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bIsMovingFastAnyDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bShouldReverse;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bShouldGoBackToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bTransition_Default_ReverseStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieDriverAnimInstance")
	bool bTransition_BoostLoop_Reverse;

};

