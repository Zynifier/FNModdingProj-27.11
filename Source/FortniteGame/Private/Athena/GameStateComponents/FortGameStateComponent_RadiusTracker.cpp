// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/GameStateComponents/FortGameStateComponent_RadiusTracker.h"

UFortGameStateComponent_RadiusTracker::UFortGameStateComponent_RadiusTracker(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FRadiusTrackingGroupKey UFortGameStateComponent_RadiusTracker::AddActorTrackingInfo(const FRadiusTrackingInitializer& RadiusTrackingInitializer)
{
	return FRadiusTrackingGroupKey();
}

void UFortGameStateComponent_RadiusTracker::AddOwnerSquadMemberIndexFromTracking(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor)
{
}

void UFortGameStateComponent_RadiusTracker::AddToInitializerOwnerSquadMemberIndex(FRadiusTrackingInitializer& RadiusTrackerInitializer, AFortPlayerStateAthena* PlayerToAdd)
{
}

void UFortGameStateComponent_RadiusTracker::BreakRadiusTrackingInitializer(const FRadiusTrackingInitializer& RadiusTrackingInitializer, float& MaxCenterOffset, float& MinimumRadius, float& MaximumRadius, float& TimeBetweenUpdatesInSeconds, float& RadiusAmountToShrinkEachUpdate, FLinearColor& CircleColor, UMaterialInterface*& CircleDrawingMaterial, AActor*& ActorTarget, TArray<AFortPlayerController*>& TargetTrackers, ERadiusTrackingGroupingType& GroupingType)
{
}

UFortGameStateComponent_RadiusTracker* UFortGameStateComponent_RadiusTracker::GetGameStateRadiusTrackerComponent(UObject* WorldContextObject)
{
	return nullptr;
}

FRadiusTrackingInitializer UFortGameStateComponent_RadiusTracker::MakeRadiusTrackingInitializer(float MaxCenterOffset, float MinimumRadius, float MaximumRadius, float TimeBetweenUpdatesInSeconds, float RadiusAmountToShrinkEachUpdate, FLinearColor CircleColor, UMaterialInterface* CircleDrawingMaterial, AActor* ActorTarget, TArray<AFortPlayerController*> TargetTrackers, ERadiusTrackingGroupingType GroupingType, float MaximumDistance)
{
	return FRadiusTrackingInitializer();
}

void UFortGameStateComponent_RadiusTracker::OnTrackedActorDestroyed(AActor* DestroyedActor)
{
}

void UFortGameStateComponent_RadiusTracker::OnTrackedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortGameStateComponent_RadiusTracker::OnTrackedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

bool UFortGameStateComponent_RadiusTracker::RemoveFromInitializerOwnerSquadMemberIndex(FRadiusTrackingInitializer& RadiusTrackerInitializer, AFortPlayerStateAthena* PlayerToRemove)
{
	return false;
}

bool UFortGameStateComponent_RadiusTracker::RemoveOwnerSquadMemberIndexFromTracking(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor)
{
	return false;
}

void UFortGameStateComponent_RadiusTracker::RemoveTrackingForActor(AActor* TrackedActor)
{
}

void UFortGameStateComponent_RadiusTracker::RemoveTrackingForActorAndTrackingKey(AActor* TrackedActor, FRadiusTrackingGroupKey TrackingKey)
{
}

void UFortGameStateComponent_RadiusTracker::RemoveTrackingForActorFromPlayer(AActor* TrackedActor, AFortPlayerController* PlayerTrackingActor, ERadiusTrackingGroupingType GroupingType)
{
}

void UFortGameStateComponent_RadiusTracker::RemoveTrackingForActorFromTrackingGroup(AActor* TrackedActor, const AFortPlayerController* PlayerTrackingActor, ERadiusTrackingGroupingType GroupingType)
{
}

void UFortGameStateComponent_RadiusTracker::SetRadiusTrackingViewersFromPlayerPawns(FRadiusTrackingInitializer& RadiusTrackingInitializer, const FRadiusTrackingInitializer& RadiusTrackingInitializerInput, const TArray<AFortPlayerPawn*>& ViewerPawns)
{
}

bool UFortGameStateComponent_RadiusTracker::UpdateRadiusTrackingSizes(AActor* ActorTarget, float MaxCenterOffset, float MinimumRadius, float MaximumRadius, float MaximumDistance)
{
	return false;
}
