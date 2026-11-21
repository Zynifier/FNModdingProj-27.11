// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMantisWeaponComponent.h"
#include "Net/UnrealNetwork.h"

const FFortMantisReplicatedAnimInstanceInfo& UFortMantisWeaponComponent::GetAnimInstanceInfo() const
{
	static FFortMantisReplicatedAnimInstanceInfo Dummy;
	return Dummy;
}

void UFortMantisWeaponComponent::OnEquip(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnPressSecondaryFire(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnPressTrigger(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnReleaseSecondaryFire(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnReleaseTrigger(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnRep_ReplayAnimInstanceInfo()
{
}

void UFortMantisWeaponComponent::OnUnEquip(AFortWeapon* Weapon)
{
}

void UFortMantisWeaponComponent::OnWeaponAbilitiesRemoved(AFortWeapon* Weapon, EFortWeaponAbilityRemovalReason RemovalReason)
{
}

void UFortMantisWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMantisWeaponComponent, AnimInstanceInfo);
	DOREPLIFETIME(UFortMantisWeaponComponent, ReplayAnimInstanceInfo);
}
