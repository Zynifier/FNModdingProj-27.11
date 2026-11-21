// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundLibrarySubsystem.h"

USoundLibraryContext* USoundLibrarySubsystem::AddContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass)
{
	return nullptr;
}

void USoundLibrarySubsystem::AddLibraries(AActor* Actor, TArray<USoundLibrary*> Libraries)
{
}

void USoundLibrarySubsystem::AddLibrariesFromCollections(AActor* Actor, const FGameplayTagContainer& CollectionTags)
{
}

void USoundLibrarySubsystem::AddLibrary(AActor* Actor, USoundLibrary* Library)
{
}

void USoundLibrarySubsystem::DisableEventsForActor(const AActor* Actor)
{
}

void USoundLibrarySubsystem::EnableEventsForActor(const AActor* Actor)
{
}

USoundLibraryContext* USoundLibrarySubsystem::GetContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass)
{
	return nullptr;
}

void USoundLibrarySubsystem::PlaySound(USoundLibraryContext* Context, FSoundLibraryPlayResult& OutResults)
{
}

FSoundLibraryPlayResult USoundLibrarySubsystem::PlaySoundSimple(AActor* OwningActor, const FSoundLibrarySimpleContextSettings& InSettings)
{
	return FSoundLibraryPlayResult();
}

bool USoundLibrarySubsystem::RemoveContext(const AActor* Actor, TSubclassOf<USoundLibraryContext> ContextClass)
{
	return false;
}

void USoundLibrarySubsystem::RemoveLibraries(const AActor* Actor, TArray<USoundLibrary*> Libraries)
{
}

void USoundLibrarySubsystem::RemoveLibrariesFromCollections(const AActor* Actor, const FGameplayTagContainer& CollectionTags)
{
}

void USoundLibrarySubsystem::RemoveLibrary(const AActor* Actor, USoundLibrary* Library)
{
}
