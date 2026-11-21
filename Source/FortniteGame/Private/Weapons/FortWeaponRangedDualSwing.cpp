// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRangedDualSwing.h"
#include "Net/UnrealNetwork.h"

void AFortWeaponRangedDualSwing::AttachRope(AActor* AttachPointActor)
{
}

void AFortWeaponRangedDualSwing::DetachRope()
{
}

FVector AFortWeaponRangedDualSwing::GetRopeAttachSocketLocation() const
{
	return FVector();
}

void AFortWeaponRangedDualSwing::OnPlayerHit(AActor* HitPlayer, AActor* HitActor, FVector NormalImpulse, const FHitResult& Hit)
{
}

void AFortWeaponRangedDualSwing::OnRep_RopeAttachPointActor()
{
}

bool AFortWeaponRangedDualSwing::SetActiveOverrideSwingingControlParams(const FGameplayTag ControlParamsTag)
{
	return false;
}

void AFortWeaponRangedDualSwing::UpdateRope()
{
}

void AFortWeaponRangedDualSwing::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponRangedDualSwing, RopeAttachPointActor);
}
