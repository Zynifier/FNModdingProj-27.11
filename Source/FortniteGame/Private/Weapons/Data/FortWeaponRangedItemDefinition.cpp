// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Data/FortWeaponRangedItemDefinition.h"

bool UFortWeaponRangedItemDefinition::DoNotAllowDoublePump() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ForceProjectileTooltip() const
{
	return false;
}

UParticleSystem* UFortWeaponRangedItemDefinition::GetBulletShellFXTemplate() const
{
	return nullptr;
}

TSubclassOf<AFortProjectileBase> UFortWeaponRangedItemDefinition::GetProjectileTemplate() const
{
	return TSubclassOf<AFortProjectileBase>();
}

bool UFortWeaponRangedItemDefinition::HasLightweightProjectile() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::HasPhysicsObjectProjectile() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::IsProjectileWeapon() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldShowReticleHitNotifyAtImpactLocation() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldSpawnBulletShellFX() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldTraceThroughPawns() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldTraceThroughWorld() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldUseNativeWeaponTrace() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::ShouldUsePerfectAimWhenTargetingMinSpread() const
{
	return false;
}

bool UFortWeaponRangedItemDefinition::UseOnTouch() const
{
	return false;
}
