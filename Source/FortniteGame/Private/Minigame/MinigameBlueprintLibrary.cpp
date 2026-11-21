// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/MinigameBlueprintLibrary.h"

bool UMinigameBlueprintLibrary::CanOperateOnMinigame(const AFortPlayerController* PlayerController)
{
	return false;
}

UActorComponent* UMinigameBlueprintLibrary::GetComponentFromCurrentMinigameExperience(const AActor* ContextActor, TSubclassOf<UActorComponent> ComponentClass)
{
	return nullptr;
}

AFortMinigame* UMinigameBlueprintLibrary::GetMinigame(const AActor* ContextActor)
{
	return nullptr;
}

AFortMinigame* UMinigameBlueprintLibrary::GetMinigameForActor(const AActor* Actor)
{
	return nullptr;
}

AFortMinigameSettingsBuilding* UMinigameBlueprintLibrary::GetMinigameSettingsMachine(const AActor* ContextActor)
{
	return nullptr;
}

AFortMinigameSettingsBuilding* UMinigameBlueprintLibrary::GetMinigameSettingsMachine_NotPure(const AActor* ContextActor)
{
	return nullptr;
}

UFortMinigameStatsComponent* UMinigameBlueprintLibrary::GetMinigameStatsComponent(const AActor* ContextActor)
{
	return nullptr;
}

UFortMinigameVolumeComponent* UMinigameBlueprintLibrary::GetMinigameVolumeComponent(const AActor* ContextActor)
{
	return nullptr;
}

bool UMinigameBlueprintLibrary::IsInPlayMode(const AActor* ContextActor)
{
	return false;
}

bool UMinigameBlueprintLibrary::IsMingameExperienceReady(const AActor* ContextActor)
{
	return false;
}
