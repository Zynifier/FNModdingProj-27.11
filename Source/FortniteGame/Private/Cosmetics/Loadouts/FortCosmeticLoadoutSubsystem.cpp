// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Loadouts/FortCosmeticLoadoutSubsystem.h"

void UFortCosmeticLoadoutSubsystem::BP_EquipCosmeticLoadoutPreset(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId)
{
}

bool UFortCosmeticLoadoutSubsystem::BP_GetCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId, FCosmeticBackendLoadout& OutLoadout) const
{
	return false;
}

bool UFortCosmeticLoadoutSubsystem::BP_GetEquippedCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, FCosmeticBackendLoadout& OutLoadout) const
{
	return false;
}

void UFortCosmeticLoadoutSubsystem::BP_PutCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId, const FCosmeticBackendLoadout& Loadout)
{
}

void UFortCosmeticLoadoutSubsystem::BP_RemoveCosmeticLoadout(const AFortPlayerController* PlayerController, const FString& LoadoutType, const FString& PresetId)
{
}

void UFortCosmeticLoadoutSubsystem::HandlePlayerDestroyed(AActor* DestroyedActor)
{
}
