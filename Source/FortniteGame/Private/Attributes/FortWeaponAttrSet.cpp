// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortWeaponAttrSet.h"
#include "Net/UnrealNetwork.h"

void UFortWeaponAttrSet::OnRep_AccumulatedWeaponChanceToNotConsumeAmmo(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_CharacterItemDurabilityDecayModifier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_ConsumeConsumableSpeedMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponADSTransitionInTime(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponADSTransitionOutTime(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponAmmoClipSize(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponChanceToNotConsumeAmmo(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponChargeRate(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponCriticalHitChance(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponCriticalHitDamageMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponCrouchingSpreadMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponHeadshotMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponHorizontalRecoil(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponOverheatCooldownMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponOverheatCoolingMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponOverheatMaxMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponOverheatMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponPerBulletRecoil(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponRangeLong(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponRangeMid(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponRangePointBlank(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponRateOfFire(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponRecoilDownsightsMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponReloadSpeed(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponSlidingSpreadMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponSpreadDownsightsMultiplier(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponSpreadReduction(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::OnRep_WeaponVerticalRecoil(const FFortGameplayAttributeData& OldValue)
{
}

void UFortWeaponAttrSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponChanceToNotConsumeAmmo);
	DOREPLIFETIME(UFortWeaponAttrSet, AccumulatedWeaponChanceToNotConsumeAmmo);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponRateOfFire);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponHorizontalRecoil);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponVerticalRecoil);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponSpreadReduction);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponReloadSpeed);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponAmmoClipSize);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponChargeRate);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponPerBulletRecoil);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponRangePointBlank);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponRangeMid);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponRangeLong);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponSpreadDownsightsMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponRecoilDownsightsMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponADSTransitionInTime);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponADSTransitionOutTime);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponCrouchingSpreadMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponSlidingSpreadMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponHeadshotMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponCriticalHitChance);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponCriticalHitDamageMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponOverheatMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponOverheatMaxMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponOverheatCoolingMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, WeaponOverheatCooldownMultiplier);
	DOREPLIFETIME(UFortWeaponAttrSet, CharacterItemDurabilityDecayModifier);
	DOREPLIFETIME(UFortWeaponAttrSet, ConsumeConsumableSpeedMultiplier);
}
