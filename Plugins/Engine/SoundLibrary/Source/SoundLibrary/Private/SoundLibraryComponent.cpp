// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundLibraryComponent.h"

void USoundLibraryComponent::AddLibraries(const TArray<USoundLibrary*>& InLibraries)
{
}

void USoundLibraryComponent::AddLibrary(USoundLibrary* InLibrary)
{
}

USoundLibraryContext* USoundLibraryComponent::GetContext() const
{
	return nullptr;
}

bool USoundLibraryComponent::IsEventActive(FGameplayTag InEventName)
{
	return false;
}

void USoundLibraryComponent::OnSoundPlayed_Implementation(FGameplayTag InEventName, UAudioComponent* InComponent)
{
}

void USoundLibraryComponent::OnSoundStopped_Implementation(FGameplayTag InEventName, UAudioComponent* InComponent, bool& bStopped)
{
}

FSoundLibraryPlayResult USoundLibraryComponent::PlayEvent(FGameplayTag InEventName)
{
	return FSoundLibraryPlayResult();
}

void USoundLibraryComponent::RemoveLibraries(const TArray<USoundLibrary*>& InLibraries)
{
}

void USoundLibraryComponent::RemoveLibrary(USoundLibrary* InLibrary)
{
}

bool USoundLibraryComponent::StopEvent(FGameplayTag InEventName)
{
	return false;
}
