// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimNotifyState_SpawnArrow.h"
#include "Animation/AnimationAsset.h"
#include "Engine/SkeletalMesh.h"
#include "Pawns/FortPlayerPawn.h"
#include "Weapons/FortWeaponRanged.h"

void UFortAnimNotifyState_SpawnArrow::GetSkeletalMeshPropOverride(AFortPawn* FortPawn, USkeletalMesh*& InOutSkeletalMeshProp, UAnimationAsset*& InOutSkeletalMeshPropAnimation)
{
	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);
	if (!FortPlayerPawn || !FortPlayerPawn->CurrentWeapon)
	{
		return;
	}

	AFortWeaponRanged* RangedWeapon = Cast<AFortWeaponRanged>(FortPlayerPawn->CurrentWeapon);
	if (!RangedWeapon)
	{
		return;
	}

	USkeletalMesh* SpawnPropOverride = RangedWeapon->FortSpawnPropOverride;
	UAnimationAsset* SpawnPropAnimOverride = RangedWeapon->FortSpawnPropAnimOverride;

	if (SpawnPropOverride)
	{
		InOutSkeletalMeshProp = SpawnPropOverride;
	}

	if (SpawnPropAnimOverride)
	{
		InOutSkeletalMeshPropAnimation = SpawnPropAnimOverride;
	}
}
