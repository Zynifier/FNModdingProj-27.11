// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_AdjustedAim.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortGender.h"
#include "FortItemLayerAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	FFortAnimInput_AdjustedAim AdjustedAim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float Speed2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float FallPlayRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float DBNOTurnPlayRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float ADSToNonADSBlendTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float NonADSToADSBlendTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float SlopeSlidingPitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	float SlopeSlidingRoll;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsMoving2D : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsAboveMinimumLocomotionSpeed : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsTargeting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsRelaxedLevel1 : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsRelaxedLevel2 : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsCrouching : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsJumpBoosting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bSwimmingJumpInitiatedFromWater : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsRelaxedLevel1AndNotJumpingFromWater : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsInVehicle : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsDBNO : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance")
	uint8 bIsRiding : 1;

};

