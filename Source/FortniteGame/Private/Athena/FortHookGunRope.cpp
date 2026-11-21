// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortHookGunRope.h"
#include "Net/UnrealNetwork.h"

void AFortHookGunRope::OnRep_HookGunRopeRepData()
{
}

void AFortHookGunRope::SetOwningProjectileMesh(UStaticMeshComponent* NewValue)
{
}

void AFortHookGunRope::SetStartPointOfRope()
{
}

void AFortHookGunRope::SetWeaponAndProjectile(AFortWeapon* InWeapon, AFortProjectileBase* InProjectile)
{
}

void AFortHookGunRope::SetWeaponMesh(USkeletalMeshComponentBudgeted* NewValue)
{
}

void AFortHookGunRope::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortHookGunRope, HookGunRopeRepData);
}
