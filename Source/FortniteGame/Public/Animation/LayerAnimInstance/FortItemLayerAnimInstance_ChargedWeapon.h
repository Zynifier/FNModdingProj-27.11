// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortItemLayerAnimInstance_ChargedWeapon.generated.h"

class UAnimSequence;
class UCurveFloat;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_ChargedWeapon : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortItemLayerAnimInstance_ChargedWeapon")
	TObjectPtr<UCurveFloat> ChargeSpeedModifierCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_ChargedWeapon")
	TObjectPtr<UAnimSequence> WeaponChargeLoop;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_ChargedWeapon")
	float ChargeAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortItemLayerAnimInstance_ChargedWeapon")
	float ChargeBlendInTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_ChargedWeapon")
	bool bWeaponIsCharging;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_ChargedWeapon")
	bool bWeaponIsAtMaxCharge;

};

