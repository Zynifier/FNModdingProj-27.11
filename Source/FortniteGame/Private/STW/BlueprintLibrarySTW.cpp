// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/BlueprintLibrarySTW.h"

FFortEncounterSettings UBlueprintLibrarySTW::ApplyEncounterOptionOverridesFromWaveDataToEncounterSettings(const FTieredWaveSetData& WaveData, FFortEncounterSettings& EncounterSettings)
{
	return FFortEncounterSettings();
}

float UBlueprintLibrarySTW::GetCalculatedGameDifficulty(UObject* WorldContextObject)
{
	return float();
}

float UBlueprintLibrarySTW::GetGameDifficulty()
{
	return float();
}

UFortAbilityKit* UBlueprintLibrarySTW::GetGrantedAbilityKit(const FFortSpecializationSlot& Slot)
{
	return nullptr;
}

bool UBlueprintLibrarySTW::GetLocalPlayerHasHeroBackpack(UObject* WorldContextObject)
{
	return false;
}

bool UBlueprintLibrarySTW::GetLocalPlayerHasHeroHeadAccessories(UObject* WorldContextObject)
{
	return false;
}

bool UBlueprintLibrarySTW::GetPurchaseCostsRow(FDataTableRowHandle DataTableRowHandle, FFortCollectionBookDirectPurchaseData& OutRow)
{
	return false;
}

UFortAbilityKit* UBlueprintLibrarySTW::GetRemovedAbilityKit(const FFortSpecializationSlot& Slot)
{
	return nullptr;
}

bool UBlueprintLibrarySTW::GetShowHeroBackpackForLocalPlayer(UObject* WorldContextObject)
{
	return false;
}

bool UBlueprintLibrarySTW::GetShowHeroHeadAccessoriesForLocalPlayer(UObject* WorldContextObject)
{
	return false;
}

void UBlueprintLibrarySTW::SetCriticalMissionJoinability(UObject* WorldContextObject, bool bJoinable)
{
}

void UBlueprintLibrarySTW::SetIdleKickEnabled(UObject* WorldContextObject, bool bEnabled)
{
}

bool UBlueprintLibrarySTW::SwitchHeroType(AFortPlayerController* FortPC, const FString& NewHeroName)
{
	return false;
}
