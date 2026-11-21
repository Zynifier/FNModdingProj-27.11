// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortWeaponModDataRow.generated.h"

USTRUCT()
struct FFortWeaponModDataRow : public FTableRowBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponChanceToNotConsumeAmmo;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float AccumulatedWeaponChanceToNotConsumeAmmo;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponRateOfFire;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponHorizontalRecoil;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponVerticalRecoil;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponSpreadReduction;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponReloadSpeed;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponAmmoClipSize;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponChargeRate;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponPerBulletRecoil;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponRangePointBlank;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponRangeMid;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponRangeLong;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponSpreadDownsightsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponRecoilDownsightsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponADSTransitionInTime;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponADSTransitionOutTime;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponCrouchingSpreadMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponSlidingSpreadMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponHeadshotMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponCriticalHitChance;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponModDataRow")
	float WeaponCriticalHitDamageMultiplier;

};

