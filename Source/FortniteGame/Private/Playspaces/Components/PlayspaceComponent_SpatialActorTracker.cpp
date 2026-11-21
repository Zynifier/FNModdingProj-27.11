// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_SpatialActorTracker.h"

void UPlayspaceComponent_SpatialActorTracker::ActorEnteredVolume(AActor* OverlapingVolume, AActor* EnteringActor)
{
}

void UPlayspaceComponent_SpatialActorTracker::ActorExitVolume(AActor* OverlapingVolume, AActor* LeavingActor)
{
}

const int32 UPlayspaceComponent_SpatialActorTracker::GetNumTrackedActors() const
{
	return int32();
}

const TSet<AActor*>& UPlayspaceComponent_SpatialActorTracker::GetTrackedActors() const
{
	static TSet<AActor*> Dummy;
	return Dummy;
}

void UPlayspaceComponent_SpatialActorTracker::HandleTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}
