// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MusterCoreWeaponsAnimInstance.generated.h"

class AFortWeapon;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UMusterCoreWeaponsAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	TObjectPtr<AFortWeapon> OwningWeapon;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bIsShotFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	int32 LocalAmmoCount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	float CylinderMaskAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bIsAmmoCountTwo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bIsAmmoCountOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bStateRuleFromFullToTwoAmmo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bStateRuleFromTwoToOneAmmo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Muster Core Weapon")
	bool bStateRuleFromOneToZero;

};

