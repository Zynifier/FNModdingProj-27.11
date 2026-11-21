// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortGameplayAbility_ReloadTracker.h"
#include "Net/UnrealNetwork.h"

int32 UFortGameplayAbility_ReloadTracker::GetScourceWeaponTimesReloaded() const
{
	return int32();
}

void UFortGameplayAbility_ReloadTracker::OnRep_TimesReloaded()
{
}

void UFortGameplayAbility_ReloadTracker::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameplayAbility_ReloadTracker, TimesReloaded);
}
