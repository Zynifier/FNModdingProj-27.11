// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsOverlapComponent.h"

void UFortPhysicsOverlapComponent::OnPhysicsObjectBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void UFortPhysicsOverlapComponent::OnPhysicsObjectEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void UFortPhysicsOverlapComponent::SetNeverSleepWhenOverlapping(const bool bShouldSleep)
{
}
