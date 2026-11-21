// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaCharmItemDefinition.h"

TSubclassOf<AFortPlayerCharm> UAthenaCharmItemDefinition::GetCharmPrefabClass() const
{
	return TSubclassOf<AFortPlayerCharm>();
}

TSoftClassPtr<UAnimInstance> UAthenaCharmItemDefinition::GetOverrideAnimSetPtr() const
{
	return TSoftClassPtr<UAnimInstance>();
}

TSoftClassPtr<UAnimInstance> UAthenaCharmItemDefinition::GetOverrideAnimSetPtrForCharmSlot(const int32 CharmSlotIn) const
{
	return TSoftClassPtr<UAnimInstance>();
}

TSoftObjectPtr<USkeletalMesh> UAthenaCharmItemDefinition::GetOverrideSkelMeshPtr() const
{
	return TSoftObjectPtr<USkeletalMesh>();
}

TSoftClassPtr<UAnimInstance> UAthenaCharmItemDefinition::GetOverrideWeaponAnimSetPtr() const
{
	return TSoftClassPtr<UAnimInstance>();
}
