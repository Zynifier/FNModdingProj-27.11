// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortAttachableProjectileDeprecated.h"
#include "Net/UnrealNetwork.h"

AActor* AFortAttachableProjectileDeprecated::GetAttachedToActor()
{
	return nullptr;
}

void AFortAttachableProjectileDeprecated::OnRep_ReplicatedAttachedInfo()
{
}

void AFortAttachableProjectileDeprecated::ServerAttachToActor(const FHitResult& Hit, AActor* AttachToActor, float StickyOffsetFromPhysicsMesh, float StickyOffsetFromBoneCenter, float NarrowPlacementAgainstVelocityThreshold)
{
}

void AFortAttachableProjectileDeprecated::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAttachableProjectileDeprecated, AttachedInfo);
}
