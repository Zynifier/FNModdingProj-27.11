// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoundLibrary.h"

void USoundLibrary::AddSound(FGameplayTag InTag, USoundBase* InSound)
{
}

USoundBase* USoundLibrary::FindSound(FGameplayTag InTag) const
{
	return nullptr;
}

void USoundLibrary::SetChannel(FGameplayTag InTag)
{
}

void USoundLibrary::SetPriority(int32 InPriority)
{
}

#if WITH_EDITOR
void USoundLibrary::Sort()
{
}
#endif
