// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimationBlueprintLibrary.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CCP_AnimInstance_Body_Canary.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCCP_AnimInstance_Body_Canary : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="Canary|Player Movement Function")
	FVector GravityOverride;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Canary|Player Movement Function")
	float PlayerMovementFunction_X;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Canary|Player Movement Function")
	float PlayerMovementFunction_Y;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float ThighUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float ThighUpR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsCrouching;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsCrouchingNoMovingThighUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsCrouchingIsMovingThighUpL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float NotMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsNotCrouching;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsSprinting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsBackpedaling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float HeadRotBack;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsTargeting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsMoving2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsSkyDiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsNotSkydiving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsParachuteOpened;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	bool bIsWearingBackbling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsCrouchingMoving2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float LeftArmRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float CrouchingUpperArmRotZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float RightMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float LeftMovement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsNotBackpedaling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsNotSprinting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float LeftMovementClean;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsSprintingNoCrouch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsSprintingCrouch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float NotMovingHeadRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsInFrontEnd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float NotEmoting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsInFrontEndNotEmoting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsWearingBackBling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Canary")
	float IsInFrontEndNoBackbling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Player Movement Function|Settings")
	FMapRangeClamped_Ranges RightMovement_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Player Movement Function|Settings")
	FMapRangeClamped_Ranges LeftMovement_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Player Movement Function|Settings")
	FMapRangeClamped_Ranges Movement_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Player Movement Function|Settings")
	float PlayerMovement_YScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Settings")
	FMapRangeClamped_Ranges ThighUpL_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Settings")
	FMapRangeClamped_Ranges ThighUpR_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Settings")
	FMapRangeClamped_Ranges ThighSideL_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Settings")
	FMapRangeClamped_Ranges ThighSideR_Ranges;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Canary|Settings")
	float CheckForBackblingLongThreshold;

protected:
	UFUNCTION()
	void Handle_CharacterCustomizationFinished();

};

