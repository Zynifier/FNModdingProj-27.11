// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortGoopAnimInstance.generated.h"

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortGoopAnimInstance : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	FVector LocalVelocity;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	bool bIsInGoop;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="FortGoopAnimInstance")
	uint8 bIsRelaxedLevel2 : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AnimSets")
	FFortAnimInput_PlayerAnimAsset CurrentAnimSet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Aiming")
	float ADSToNonADSBlendTime;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Transient, Category="Default")
	bool bGoopJumpExecuted;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Transient, Category="Default")
	uint8 bIsTargeting : 1;

};

