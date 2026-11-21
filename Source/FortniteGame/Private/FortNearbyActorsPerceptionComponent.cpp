// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortNearbyActorsPerceptionComponent.h"

FFortNearbyActorsHandle UFortNearbyActorsPerceptionComponent::BP_RegisterListener(const FFortNearbyActorsPerceptionConfiguration& Configuration, FBPOnNearbyActorsPerceptionChangedNearbyActors HandleDeltaDelegate)
{
	return FFortNearbyActorsHandle();
}

bool UFortNearbyActorsPerceptionComponent::BP_UnregisterListener(FFortNearbyActorsHandle& Handle)
{
	return false;
}

UFortNearbyActorsPerceptionComponent* UFortNearbyActorsPerceptionComponent::FindOrCreateNearbyActorsPerceptionComponentOnActor(const AActor* Owner, const TSubclassOf<UFortNearbyActorsPerceptionComponent> ActorComponentClass)
{
	return nullptr;
}
