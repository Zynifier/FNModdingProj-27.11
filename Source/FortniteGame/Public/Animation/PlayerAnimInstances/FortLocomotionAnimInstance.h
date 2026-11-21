// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortGender.h"
#include "FortLocomotionAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortLocomotionAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLocomotionAnimInstance")
	FCachedAnimStateArray IdleStatesData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Locomotion")
	float SpeedAdjustedPlayrate;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsCrouching : 1;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsFemale : 1;

};

