// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Projectiles/FortAttachableProjectileComponent.h"
#include "Net/UnrealNetwork.h"

void UFortAttachableProjectileComponent::AuthorityAttachToActor(const FHitResult& Hit, const AActor* AttachToActor, const float StickyOffsetFromPhysicsMesh, const float StickyOffsetFromBoneCenter, const float NarrowPlacementAgainstVelocityThreshold)
{
}

void UFortAttachableProjectileComponent::EjectFromAttachedToActor()
{
}

AActor* UFortAttachableProjectileComponent::GetAttachedToActor() const
{
	return nullptr;
}

void UFortAttachableProjectileComponent::HandleAttachedToDied(const AActor* DamagedActor, const float Damage, const AController* InstigatedBy, const AActor* DamageCauser, const FVector HitLocation, const UPrimitiveComponent* HitComponent, const FName BoneName, const FVector Momentum)
{
}

void UFortAttachableProjectileComponent::HandleAttachedToEndedPlay(const AActor* DamagedActor, const EEndPlayReason::Type EndPlayReason)
{
}

void UFortAttachableProjectileComponent::OnRep_AttachParams()
{
}

void UFortAttachableProjectileComponent::OverrideFinalizedAttachmentParams(const FVector& WorldLocation, const FRotator& WorldRotation, const FName& SocketName)
{
}

void UFortAttachableProjectileComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAttachableProjectileComponent, AttachParams);
}
