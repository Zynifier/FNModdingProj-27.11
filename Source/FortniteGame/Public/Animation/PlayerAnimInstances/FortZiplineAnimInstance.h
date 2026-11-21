// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortZiplineAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortZiplineAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Locomotion")
	float LocalVelocityYawAngle;

	UPROPERTY(BlueprintReadOnly, Category="Zipline")
	FFortAnimInput_Zipline ZiplineInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ADSToNonADSBlendTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsTargeting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Relaxed")
	uint8 bIsRelaxedLevel2 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Relaxed")
	uint8 bIsWeaponEquipped : 1;

};

