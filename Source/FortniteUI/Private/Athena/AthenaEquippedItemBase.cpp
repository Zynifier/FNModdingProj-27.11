// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaEquippedItemBase.h"

void UAthenaEquippedItemBase::BP_HandleWeaponEquipped_Implementation(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UAthenaEquippedItemBase::HandleBuildingMaterialChanged()
{
}

void UAthenaEquippedItemBase::HandleLocalAmmoChanged(int32 LocalCount, int32 LocalRemaining)
{
}

void UAthenaEquippedItemBase::HandleSecondaryFirePressed(AFortWeapon* Weapon)
{
}

void UAthenaEquippedItemBase::HandleSecondaryFireReleased(AFortWeapon* Weapon)
{
}

void UAthenaEquippedItemBase::HandleViewTargetChanged()
{
}

void UAthenaEquippedItemBase::HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UAthenaEquippedItemBase::HandleWeaponOverheatValueChanged(float CurrentValue, float MaxValue, EFortWeaponOverheatState State, bool bIsInCooldown)
{
}

void UAthenaEquippedItemBase::HandleWeaponReloadCancelled()
{
}

void UAthenaEquippedItemBase::HandleWeaponReloadStarted(float ReloadTime, EFortWeaponReloadType ReloadType)
{
}

void UAthenaEquippedItemBase::HandleWeaponTargetingChanged(bool bIsTargeting)
{
}

void UAthenaEquippedItemBase::HandleWorldItemsChanged()
{
}
