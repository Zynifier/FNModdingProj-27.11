// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundLibraryContext.h"

bool USoundLibraryContext::CreateEventName_Implementation(FGameplayTag& OutEventName) const
{
	return false;
}

bool USoundLibraryContext::GatherActorTargets_Implementation(TArray<AActor*>& OutActors) const
{
	return false;
}

void USoundLibraryContext::OnAddedToActor_Implementation(const AActor* InActor)
{
}

void USoundLibraryContext::OnRemovedFromActor_Implementation(const AActor* InActor)
{
}

bool USoundLibraryContext::Play_Implementation(const FSoundLibraryContextEventInput& InEventData, TArray<UAudioComponent*>& OutComponents)
{
	return false;
}
