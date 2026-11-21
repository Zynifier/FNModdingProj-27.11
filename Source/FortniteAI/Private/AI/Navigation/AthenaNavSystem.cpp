// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Navigation/AthenaNavSystem.h"

bool UAthenaNavSystem::IsInitialNavigationLockActive(UObject* WorldContextObject)
{
	return false;
}

void UAthenaNavSystem::RegisterNavGenerationObserver(USceneComponent* Component, FOnNavGenerationFinished Event)
{
}

void UAthenaNavSystem::UnregisterNavGenerationObserver(USceneComponent* Component)
{
}
