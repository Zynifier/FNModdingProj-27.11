// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayDataTracker/FortGameplayDataTrackerComponentManager.h"

UFortGameplayDataTrackerComponentManager::UFortGameplayDataTrackerComponentManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UFortGameplayDataTrackerComponentManager* UFortGameplayDataTrackerComponentManager::GetCurrent(UObject* WorldContextObject)
{
	return nullptr;
}

void UFortGameplayDataTrackerComponentManager::GetRegisteredDataTrackerComponents(TArray<UFortGameplayDataTrackerComponent*>& OutDataTrackerComponents)
{
}

void UFortGameplayDataTrackerComponentManager::OnTrackedActorDestroyed(AActor* DestroyedActor)
{
}

void UFortGameplayDataTrackerComponentManager::RegisterTrackedStateActor(AActor* Actor, const FGameplayTag& InitialState)
{
}

void UFortGameplayDataTrackerComponentManager::SetTrackedActorState(AActor* Actor, const FGameplayTag& CurrentState)
{
}

void UFortGameplayDataTrackerComponentManager::UnRegisterTrackedStateActor(AActor* Actor)
{
}
