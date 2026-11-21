// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInstance.h"
#include "FortGender.h"
#include "FortBowWeaponAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortBowWeaponAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	float ChargeBlendSpaceCrouchSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	float ChargePlayRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	float OutOfAmmoAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	float BowAimYaw;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	float BowAimPitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	TEnumAsByte<EFortCustomGender::Type> OwnerGender;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsBowCharging : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bEnterChargingNormalTransition : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bEnterChargingFastTransition : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bShouldPlayDefaultPose : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsBowAtMaxCharge : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsCrouchMoving : 1;

};

