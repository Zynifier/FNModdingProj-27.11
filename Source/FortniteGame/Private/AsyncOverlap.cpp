// Copyright Epic Games, Inc. All Rights Reserved.

#include "AsyncOverlap.h"

void UAsyncOverlapQueue::AsyncSphereOverlapActors(AActor* ContextActor, const FVector& Location, const float Radius, const TArray<AActor*>& ActorsToIgnore, FShouldCancelOverlapProcess ShouldCancelProcess, FProcessHitActor ProcessHitActorFunction, FOnProcessComplete CompletionFunction, ECollisionChannel TraceChannel)
{
}

void UAsyncOverlapQueue::ThrottledAsyncSphereOverlapActors(AActor* ContextActor, const FVector& Location, const float Radius, const bool bCheckLineOfSight, const TArray<AActor*>& ActorsToIgnore, FShouldCancelOverlapProcess ShouldCancelProcess, FProcessHitActor ProcessHitActorFunction, FOnProcessComplete CompletionFunction, const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes, ECollisionChannel TraceChannel)
{
}
