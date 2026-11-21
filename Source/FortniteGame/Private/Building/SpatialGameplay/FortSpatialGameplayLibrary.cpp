// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/SpatialGameplay/FortSpatialGameplayLibrary.h"

bool UFortSpatialGameplayLibrary::GetComponentsFromSpatialGameplayInterfaceByClass(const TScriptInterface<IFortSpatialGameplayInterface>& SpatialGameplayInterface, const TSubclassOf<UActorComponent> ComponentType, TArray<UActorComponent*>& OutComponents)
{
	return false;
}

FName UFortSpatialGameplayLibrary::GetSpatialGameplayInterfaceFNameForActor(const AActor* Actor)
{
	return FName();
}
