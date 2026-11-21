// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/FortPlacementActorTagTest.h"

bool UFortPlacementActorTagTest::LineTraceByChannel(AFortPlacementActor* PlacementActor, const FVector Start, const FVector End, ETraceTypeQuery TraceChannel, bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore, FHitResult& OutHit, bool bIgnoreSelf) const
{
	return false;
}

bool UFortPlacementActorTagTest::ShouldApplyTagsToPlacementActor_Implementation(AFortPlacementActor* FocusPlacementActor, const FVector& AveragePlacementActorLocation) const
{
	return false;
}
