// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortWeaponPickaxeDualWieldAthena.h"
#include "Net/UnrealNetwork.h"

UFXSystemComponent* AFortWeaponPickaxeDualWieldAthena::CreateAnimTrailOffhandFX()
{
	return nullptr;
}

FName AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandFirstSocketName() const
{
	return FName();
}

UNiagaraSystem* AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandNiagaraAsset() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandPSC() const
{
	return nullptr;
}

UParticleSystem* AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandPSCTemplate() const
{
	return nullptr;
}

FName AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandSecondSocketName() const
{
	return FName();
}

float AFortWeaponPickaxeDualWieldAthena::GetAnimTrailsOffhandWidth() const
{
	return float();
}

EFortDualWieldSwingState AFortWeaponPickaxeDualWieldAthena::GetCurrentSwingState() const
{
	return EFortDualWieldSwingState();
}

FName AFortWeaponPickaxeDualWieldAthena::GetIdleFXOffhandSocketName() const
{
	return FName();
}

UParticleSystemComponent* AFortWeaponPickaxeDualWieldAthena::GetIdleOffhandPSC() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeDualWieldAthena::GetIdleOffhandVFXComponent() const
{
	return nullptr;
}

FName AFortWeaponPickaxeDualWieldAthena::GetSwingFXOffhandSocketName() const
{
	return FName();
}

UParticleSystemComponent* AFortWeaponPickaxeDualWieldAthena::GetSwingOffhandPSC() const
{
	return nullptr;
}

UFXSystemComponent* AFortWeaponPickaxeDualWieldAthena::GetSwingOffhandVFXComponent() const
{
	return nullptr;
}

bool AFortWeaponPickaxeDualWieldAthena::GetUseAnimTrailsOffhandPSC() const
{
	return false;
}

USkeletalMeshComponentBudgeted* AFortWeaponPickaxeDualWieldAthena::GetWeaponMeshOffhand() const
{
	return nullptr;
}

EFortDualWieldDataSource AFortWeaponPickaxeDualWieldAthena::GetWieldStance() const
{
	return EFortDualWieldDataSource();
}

bool AFortWeaponPickaxeDualWieldAthena::IsDualWielding() const
{
	return false;
}

bool AFortWeaponPickaxeDualWieldAthena::IsSingleWielding() const
{
	return false;
}

void AFortWeaponPickaxeDualWieldAthena::OnRep_WieldStance()
{
}

void AFortWeaponPickaxeDualWieldAthena::SetCurrentSwingState(EFortDualWieldSwingState NewState)
{
}

void AFortWeaponPickaxeDualWieldAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponPickaxeDualWieldAthena, CurrentWieldStance);
}
