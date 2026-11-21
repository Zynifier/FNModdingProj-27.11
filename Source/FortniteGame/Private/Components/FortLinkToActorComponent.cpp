// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortLinkToActorComponent.h"

void UFortLinkToActorComponent::GetActorsLinkedTo(TArray<AActor*>& OutArray)
{
}

ELinkToDirection UFortLinkToActorComponent::GetDirectionForLink() const
{
	return ELinkToDirection();
}

void UFortLinkToActorComponent::HandleBuildingActorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortLinkToActorComponent::HandleLinkedActorDestroyed(AActor* DestroyedActor)
{
}

void UFortLinkToActorComponent::HandleLinkedActorEndedPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void UFortLinkToActorComponent::HandleLinkedPhysicsObjectAwakeChanged(UPrimitiveComponent* SimulatingComponent, bool bIsAwake)
{
}

void UFortLinkToActorComponent::HandleMovementStopped(const FHitResult& Hit)
{
}

void UFortLinkToActorComponent::HandleSimulatedObjectAwake(UPrimitiveComponent* SimulatingComponent, FName Bone)
{
}

void UFortLinkToActorComponent::OnGeometryCollectionBreak(const FChaosBreakEvent& BreakEvent)
{
}

void UFortLinkToActorComponent::OnGeometryCollectionCrumbling(const FChaosCrumblingEvent& Event)
{
}

void UFortLinkToActorComponent::OnMonitorLinkedActors()
{
}

bool UFortLinkToActorComponent::PerformLinkingCheck(const ELinkToDirection InDirection, AActor*& OutActorLinkedTo)
{
	return false;
}

void UFortLinkToActorComponent::RegisterWithOwnersProjectileMovementComponent()
{
}

void UFortLinkToActorComponent::SetPerformLinkingCheckOnBeginPlay(const bool bCheckOnBeginPlay)
{
}

void UFortLinkToActorComponent::SetRegisterWithOwnerMovementComponent(const bool bRegisterWithMovementComp)
{
}

void UFortLinkToActorComponent::SetUseActorRotationForDirectionVectors(const bool InbUseActorRotationForDirectionVectors)
{
}
