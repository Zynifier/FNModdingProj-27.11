// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortWeaponPickaxeAthena.h"
#include "Net/UnrealNetwork.h"

bool AFortWeaponPickaxeAthena::AttachesAnimTrailsToWeapon() const
{
	return false;
}

FFortAthenaLoadout AFortWeaponPickaxeAthena::BP_GetCosmeticData() const
{
	return FFortAthenaLoadout();
}

UFXSystemComponent* AFortWeaponPickaxeAthena::CreateAnimTrailFX()
{
	return nullptr;
}

FName AFortWeaponPickaxeAthena::GetAnimTrailsFirstSocketName() const
{
	return FName();
}

UNiagaraSystem* AFortWeaponPickaxeAthena::GetAnimTrailsNiagaraAsset() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeAthena::GetAnimTrailsPSC() const
{
	return nullptr;
}

UParticleSystem* AFortWeaponPickaxeAthena::GetAnimTrailsPSCTemplate() const
{
	return nullptr;
}

FName AFortWeaponPickaxeAthena::GetAnimTrailsSecondSocketName() const
{
	return FName();
}

float AFortWeaponPickaxeAthena::GetAnimTrailsWidth() const
{
	return float();
}

UFXSystemComponent* AFortWeaponPickaxeAthena::GetAnimTrailVFXComponent() const
{
	return nullptr;
}

FName AFortWeaponPickaxeAthena::GetIdleFXSocketName() const
{
	return FName();
}

UParticleSystemComponent* AFortWeaponPickaxeAthena::GetIdlePSC() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeAthena::GetIdleVFXComponent() const
{
	return nullptr;
}

FName AFortWeaponPickaxeAthena::GetSwingFXSocketName() const
{
	return FName();
}

UParticleSystemComponent* AFortWeaponPickaxeAthena::GetSwingPSC() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeAthena::GetSwingVFXComponent() const
{
	return nullptr;
}

bool AFortWeaponPickaxeAthena::GetUseAnimTrailsPSC() const
{
	return false;
}

void AFortWeaponPickaxeAthena::OnRep_CosmeticData()
{
}

void AFortWeaponPickaxeAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponPickaxeAthena, CosmeticData);
}
