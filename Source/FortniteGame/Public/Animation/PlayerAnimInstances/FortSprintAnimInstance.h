// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_WeaponAdditiveAnimAsset.h"
#include "Animation/PlayerAnimInstances/FortLocomotionAnimInstance.h"
#include "FortSprintAnimInstance.generated.h"

class UAnimSequence;
class UFortWeaponAdditiveAnimSet;

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortSprintAnimInstance : public UFortLocomotionAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	FFortAnimInput_WeaponAdditiveAnimAsset CurrentWeaponAdditiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TObjectPtr<UFortWeaponAdditiveAnimSet> WeaponAdditiveAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Consumable")
	TObjectPtr<UAnimSequence> ConsumableOffsetPose;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float SprintYawAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float LeanAngle;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float LeftArmMaskWeight;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	float LeanAdditiveAlpha;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Tactical Sprint")
	uint8 bIsDoorBashExit : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bPlayUpperBodyTargeting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsSurfaceSwimming : 1;

};

