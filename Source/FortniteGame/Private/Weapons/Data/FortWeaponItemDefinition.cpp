// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Data/FortWeaponItemDefinition.h"

bool UFortWeaponItemDefinition::AllowSecondaryFireToInterruptPrimary() const
{
	return false;
}

bool UFortWeaponItemDefinition::AlwaysChargeUpToMin() const
{
	return false;
}

const TArray<FName>& UFortWeaponItemDefinition::GetAnalyticTags() const
{
	static TArray<FName> Dummy;
	return Dummy;
}

UFortAlterationItemDefinition* UFortWeaponItemDefinition::GetBaseAlteration() const
{
	return nullptr;
}

UFortAlterationItemDefinition* UFortWeaponItemDefinition::GetBaseCosmeticAlteration() const
{
	return nullptr;
}

float UFortWeaponItemDefinition::GetDegradedPercentage() const
{
	return float();
}

EFortDisplayTier UFortWeaponItemDefinition::GetDisplayTier() const
{
	return EFortDisplayTier();
}

FText UFortWeaponItemDefinition::GetDisplayTierAsText(const EFortDisplayTier DisplayTier)
{
	return FText();
}

TArray<TSubclassOf<UFortGameplayAbility>> UFortWeaponItemDefinition::GetEquippedAbilities() const
{
	return TArray<TSubclassOf<UFortGameplayAbility>>();
}

float UFortWeaponItemDefinition::GetHitNotifyDuration() const
{
	return float();
}

float UFortWeaponItemDefinition::GetLowAmmoPercentage() const
{
	return float();
}

TSubclassOf<UFortGameplayAbility> UFortWeaponItemDefinition::GetOnHitAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

TSubclassOf<UFortGameplayAbility> UFortWeaponItemDefinition::GetPrimaryFireAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

TSubclassOf<UFortGameplayAbility> UFortWeaponItemDefinition::GetReloadAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

FVector2D UFortWeaponItemDefinition::GetReticleCenterImageOffset() const
{
	return FVector2D();
}

const TArray<float>& UFortWeaponItemDefinition::GetReticleCornerAngles() const
{
	static TArray<float> Dummy;
	return Dummy;
}

TSubclassOf<UFortGameplayAbility> UFortWeaponItemDefinition::GetSecondaryFireAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

EFortWeaponTriggerType::Type UFortWeaponItemDefinition::GetSecondaryTriggerType() const
{
	return EFortWeaponTriggerType::Type();
}

FText UFortWeaponItemDefinition::GetShortDisplayName() const
{
	return FText();
}

EFortWeaponTriggerType::Type UFortWeaponItemDefinition::GetTriggerType() const
{
	return EFortWeaponTriggerType::Type();
}

bool UFortWeaponItemDefinition::GetUsesCustomAmmoType() const
{
	return false;
}

TSubclassOf<AFortWeapon> UFortWeaponItemDefinition::GetWeaponActorClass() const
{
	return TSubclassOf<AFortWeapon>();
}

TArray<TSoftObjectPtr<UMaterialInterface>> UFortWeaponItemDefinition::GetWeaponMaterialOverrides() const
{
	return TArray<TSoftObjectPtr<UMaterialInterface>>();
}

USkeletalMesh* UFortWeaponItemDefinition::GetWeaponMeshOverride() const
{
	return nullptr;
}

float UFortWeaponItemDefinition::GetWeaponRechargeAmmoQuantity(const int32 InLevel) const
{
	return float();
}

float UFortWeaponItemDefinition::GetWeaponRechargeAmmoRate(const int32 InLevel) const
{
	return float();
}

FDataTableRowHandle UFortWeaponItemDefinition::GetWeaponStatHandle() const
{
	return FDataTableRowHandle();
}

const bool UFortWeaponItemDefinition::HasAmmo() const
{
	return bool();
}

const bool UFortWeaponItemDefinition::HasUniqueAmmo() const
{
	return bool();
}

void UFortWeaponItemDefinition::InitializeAlterationsBasedOnLootLevel(FFortItemEntry& ItemEntry)
{
}

bool UFortWeaponItemDefinition::NoFireOnReleaseBeforeMinChargeTime() const
{
	return false;
}

bool UFortWeaponItemDefinition::ShouldAllowTargetingDuringReload() const
{
	return false;
}

bool UFortWeaponItemDefinition::ShouldEndAbilityOnChargeEnd() const
{
	return false;
}

bool UFortWeaponItemDefinition::ShouldShowAmmoAsPercent() const
{
	return false;
}

bool UFortWeaponItemDefinition::ShouldUpdateLastFireTimeOnDischarge() const
{
	return false;
}

bool UFortWeaponItemDefinition::TargetingPreventsReload() const
{
	return false;
}

bool UFortWeaponItemDefinition::TryGetBaseClipSizeWithMods(UFortWorldItem* WeaponWorldItem, int32& OutClipSize)
{
	return false;
}

bool UFortWeaponItemDefinition::UsesPhantomReserveAmmo() const
{
	return false;
}
