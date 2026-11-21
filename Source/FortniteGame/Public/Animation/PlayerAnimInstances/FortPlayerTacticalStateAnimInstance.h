// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerTacticalStateAnimInstance.generated.h"

class AFortWeapon;

UCLASS(MinimalAPI, HideCategories=("AnimInstance"))
class UFortPlayerTacticalStateAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Landing")
	uint8 bIsHardLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Landing")
	uint8 bIsHurdleMantleLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Landing")
	uint8 bIsHurdleLanding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	uint8 bApplyWeaponBoneFix : 1;

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> CurrentWeapon;

	UPROPERTY(Transient)
	uint8 bTacticalStateActive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle50up_100fwd_Land : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle50up_250fwd_Land : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle100up_100fwd_Land : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle100up_100fwd_Land_Mirrored : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle100up_250fwd_Land : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle100up_250fwd_Land_Mirrored : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdle200up_100fwd_Land : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdleMantle50up : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdleMantle100up : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdleMantle100upMirrored : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Transitions")
	uint8 bTransitionHurdleMantle200up : 1;

};

