// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/SpatialGameplayActorTrackerComponent.h"

void USpatialGameplayActorTrackerComponent::ActorEnteredVolume(AActor* OverlapingVolume, AActor* EnteringActor)
{
}

void USpatialGameplayActorTrackerComponent::ActorExitVolume(AActor* OverlapingVolume, AActor* LeavingActor)
{
}

const int32 USpatialGameplayActorTrackerComponent::GetNumTrackedActors() const
{
	return int32();
}

void USpatialGameplayActorTrackerComponent::HandleTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}
