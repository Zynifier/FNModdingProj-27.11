// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRangedDual.h"

EDualWeaponHand AFortWeaponRangedDual::GetLastFireHand() const
{
	return EDualWeaponHand();
}

USkeletalMeshComponentBudgeted* AFortWeaponRangedDual::GetLeftHandWeaponMesh() const
{
	return nullptr;
}

EDualWeaponHand AFortWeaponRangedDual::GetNextFireHand() const
{
	return EDualWeaponHand();
}
