// Copyright Epic Games, Inc. All Rights Reserved.

#include "Sound/FortSoundLibraryContexts.h"

void UFortPlayerFoleyContext::ConfigureContext(AActor* OwningActor, const FFortPlayerFoleyContextSettings& InSettings)
{
}

bool UFortSoundLibraryContext::PlaySoundAttached(AActor* InActor, USoundBase* InSound, TArray<UAudioComponent*>& OutComponents) const
{
	return false;
}

bool UFortSoundLibraryContext::PlaySoundSimple(AActor* InActor, USoundBase* InSound, TArray<UAudioComponent*>& OutComponents) const
{
	return false;
}
