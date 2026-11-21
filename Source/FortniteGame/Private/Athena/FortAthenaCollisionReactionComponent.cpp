// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaCollisionReactionComponent.h"

void UFortAthenaCollisionReactionComponent::HandleImpactForCollisionReaction(const UPrimitiveComponent* HitComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const FVector NormalImpulse, const FHitResult& Hit)
{
}

void UFortAthenaCollisionReactionComponent::HandleOverlapForCollisionReaction(const UPrimitiveComponent* OverlappedComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const int32 OtherBodyIndex, const bool bFromSweep, const FHitResult& SweepResult)
{
}

bool UFortAthenaCollisionReactionComponent::K2_IsBuildingActorValidForReaction(const ABuildingActor* BuildingActor) const
{
	return false;
}

void UFortAthenaCollisionReactionComponent::RegisterPrimitiveForCollisionsReaction(const UPrimitiveComponent* PrimitiveComponentToRegister)
{
}

void UFortAthenaCollisionReactionComponent::RegisterPrimitiveForOverlapReaction(const UPrimitiveComponent* PrimitiveComponentToRegister)
{
}

bool UFortAthenaCollisionReactionComponent::Run()
{
	return false;
}

void UFortAthenaCollisionReactionComponent::Stop()
{
}
