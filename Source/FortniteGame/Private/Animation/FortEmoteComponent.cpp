// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortEmoteComponent.h"

void UFortEmoteComponent::DespawnActivePersistentProp(bool bShouldInstantDestroy)
{
}

AFortPersistentProp* UFortEmoteComponent::GetActivePersistentProp() const
{
	return nullptr;
}

AFortPersistentProp* UFortEmoteComponent::SpawnPersistentProp(TSubclassOf<AFortPersistentProp> PropClass, FName AttachSocket)
{
	return nullptr;
}
