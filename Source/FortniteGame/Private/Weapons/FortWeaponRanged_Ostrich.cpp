// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRanged_Ostrich.h"
#include "Net/UnrealNetwork.h"

float AFortWeaponRanged_Ostrich::GetAimPointCacheRange() const
{
	return float();
}

int32 AFortWeaponRanged_Ostrich::GetAmmoPerCharge() const
{
	return int32();
}

float AFortWeaponRanged_Ostrich::GetAutofireDelay() const
{
	return float();
}

float AFortWeaponRanged_Ostrich::GetFireRate() const
{
	return float();
}

int32 AFortWeaponRanged_Ostrich::GetMaxRockets() const
{
	return int32();
}

int32 AFortWeaponRanged_Ostrich::GetMinRocketsForFiring() const
{
	return int32();
}

float AFortWeaponRanged_Ostrich::GetRocketsCooldown() const
{
	return float();
}

float AFortWeaponRanged_Ostrich::GetTimeToLoadOneAmmoCharge() const
{
	return float();
}

void AFortWeaponRanged_Ostrich::LoadShotgunAmmo()
{
}

void AFortWeaponRanged_Ostrich::OnRep_RocketsCooldown()
{
}

void AFortWeaponRanged_Ostrich::OnServerActivateSecondaryFire(UFortGameplayAbility* SecondaryFire, const FVector& LaunchPosition)
{
}

void AFortWeaponRanged_Ostrich::OnServerLoadSingleRocket()
{
}

void AFortWeaponRanged_Ostrich::PlayReloadAnim()
{
}

void AFortWeaponRanged_Ostrich::ServerSetCharging_Implementation(bool bNewCharging)
{
}
bool AFortWeaponRanged_Ostrich::ServerSetCharging_Validate(bool bNewCharging)
{
	return true;
}

void AFortWeaponRanged_Ostrich::ServerSetFiringRockets_Implementation(bool bNewFiring, int32 NumToFire)
{
}
bool AFortWeaponRanged_Ostrich::ServerSetFiringRockets_Validate(bool bNewFiring, int32 NumToFire)
{
	return true;
}

void AFortWeaponRanged_Ostrich::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponRanged_Ostrich, bRocketsOnCooldown);
}
