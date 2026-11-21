// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortGender.h"
#include "FortVehicleLayerAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	FFortAnimInput_CommonVehicle CommonVehicleInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	FFortAnimInput_TurnInPlace TurnInPlaceInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	float LocalVelocityYawAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	float SlopePitchDegreeAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	float SlopeRollDegreeAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bHasBalloons : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bIsDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bIsBackLeftPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bIsBackRightPassenger : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bTransitionLocomotionAdditiveCrouchTurning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bRecentlyFired : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	float Speed2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance")
	uint8 bIsTargeting : 1;

};

