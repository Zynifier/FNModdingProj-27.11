// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortWeaponAttrSet.generated.h"

UCLASS(BlueprintType)
class UFortWeaponAttrSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_AccumulatedWeaponChanceToNotConsumeAmmo(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CharacterItemDurabilityDecayModifier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ConsumeConsumableSpeedMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponADSTransitionInTime(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponADSTransitionOutTime(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponAmmoClipSize(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponChanceToNotConsumeAmmo(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponChargeRate(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponCriticalHitChance(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponCriticalHitDamageMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponCrouchingSpreadMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponHeadshotMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponHorizontalRecoil(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponOverheatCooldownMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponOverheatCoolingMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponOverheatMaxMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponOverheatMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponPerBulletRecoil(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponRangeLong(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponRangeMid(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponRangePointBlank(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponRateOfFire(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponRecoilDownsightsMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponReloadSpeed(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponSlidingSpreadMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponSpreadDownsightsMultiplier(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponSpreadReduction(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_WeaponVerticalRecoil(const FFortGameplayAttributeData& OldValue);

private:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponChanceToNotConsumeAmmo, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponChanceToNotConsumeAmmo;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_AccumulatedWeaponChanceToNotConsumeAmmo, Category="Weapon", meta=(AllowPrivateAccess="true", HideFromModifiers))
	FFortGameplayAttributeData AccumulatedWeaponChanceToNotConsumeAmmo;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponRateOfFire, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponRateOfFire;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponHorizontalRecoil, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponHorizontalRecoil;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponVerticalRecoil, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponVerticalRecoil;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponSpreadReduction, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponSpreadReduction;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponReloadSpeed, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponReloadSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponAmmoClipSize, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponAmmoClipSize;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponChargeRate, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponChargeRate;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponPerBulletRecoil, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponPerBulletRecoil;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponRangePointBlank, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponRangePointBlank;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponRangeMid, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponRangeMid;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponRangeLong, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponRangeLong;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponSpreadDownsightsMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponSpreadDownsightsMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponRecoilDownsightsMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponRecoilDownsightsMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponADSTransitionInTime, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponADSTransitionInTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponADSTransitionOutTime, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponADSTransitionOutTime;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponCrouchingSpreadMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponCrouchingSpreadMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponSlidingSpreadMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponSlidingSpreadMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponHeadshotMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponHeadshotMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponCriticalHitChance, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponCriticalHitChance;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponCriticalHitDamageMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponCriticalHitDamageMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponOverheatMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponOverheatMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponOverheatMaxMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponOverheatMaxMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponOverheatCoolingMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponOverheatCoolingMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponOverheatCooldownMultiplier, Category="Weapon", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData WeaponOverheatCooldownMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CharacterItemDurabilityDecayModifier, Category="Item", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData CharacterItemDurabilityDecayModifier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ConsumeConsumableSpeedMultiplier, Category="Item", meta=(AllowPrivateAccess="true"))
	FFortGameplayAttributeData ConsumeConsumableSpeedMultiplier;

};

