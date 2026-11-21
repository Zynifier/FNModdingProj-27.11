// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance.h"
#include "FortItemLayerAnimInstance_FullLocomotion.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_FullLocomotion : public UFortItemLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	FFortAnimInput_SpeedWarping SpeedWarping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	FFortAnimInput_SpeedWarping JogStartSpeedWarping;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	FVector ActorSpaceVelocityDirPreTurn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float LocalVelocityYawAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float LocalVelocityYawAngleMinusMeleeTwist;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float LocalVelocityYawAngleMinusJogBlendSpaceRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float StartAnimDeltaAngleNorth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float StartAnimDeltaAngleEast;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float StartAnimDeltaAngleSouth;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float StartAnimDeltaAngleWest;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	float SpeedAdjustedPlayrate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	EFortCardinalDirection StopCardinalDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	EFortCardinalDirection PrePivotCardinalDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	EFortCardinalDirection PostPivotCardinalDirection;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_FullLocomotion")
	bool bIsSprinting;

};

