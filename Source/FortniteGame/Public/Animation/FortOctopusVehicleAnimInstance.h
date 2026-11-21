// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortOctopusVehicleAnimInstance.generated.h"

class AFortOctopusVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortOctopusVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortOctopusVehicle> OctopusVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FRotator ShellRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FRotator SeatRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FVector SeatRotationVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FVector SeatRotationTorque;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	float SeatSteerYawDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	float SeatSteerPitchDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	float SeatSteerRollDelta;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	float FwdBwd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	float LeftRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FRotator TowhookRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FVector TargetHeading;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	FVector AimPoint;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	EFortCardinalDirection PivotDir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsTowhookExtending : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsTowhookAttached : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsTowhookContracting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsTowhookHolstered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsLowerVelocity : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bIsDriverFemale : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bShouldPlayPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortOctopusVehicleAnimInstance")
	uint8 bShouldPlayGrappleFire : 1;

};

