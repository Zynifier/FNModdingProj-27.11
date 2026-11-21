// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_ColumbusBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_ColumbusBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	FVector2D SpinePositivePitchInputRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ThighRotationRightDynamicsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ThighRotationLeftDynamicsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ThighRotationRightAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ThighRotationLeftAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ClavicleRotationRightAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ClavicleRotationLeftAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float PickaxeSwingPositionLeftPositiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float PickaxeSwingPositionLeftNegativeAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float PickaxeSwingPositionRightPositiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float PickaxeSwingPositionRightNegativeAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ChestArmorDynamicsAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ChestArmorDynamicsInvAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ChestArmorDynamicsClavicleLeftInvAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float ChestArmorDynamicsClavicleRightInvAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float CrouchMoveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float UpperArmLeftSwingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float SkyDivingAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	float SpinePositivePitchAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	bool bChestDynamicsDisableRB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	bool bIsCrouchMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	bool bIsAboveLODThreshold;

	UPROPERTY(EditDefaultsOnly, Category="CustomCharacterPartAnimInstance_ColumbusBody")
	bool bShouldResetDynamics;

};

