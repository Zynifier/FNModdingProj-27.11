// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Outpost/FortOutpostFunctionLibrary.h"

bool UFortOutpostFunctionLibrary::BuildingActorRecordUpdatesEnabled(UObject* WorldContextObject)
{
	return false;
}

void UFortOutpostFunctionLibrary::CacheIronCityDifficultyInfo(UObject* WorldContextObject, int32 AccountLevel)
{
}

bool UFortOutpostFunctionLibrary::DeployOutpostBuildingTagOnPlacementTag(UObject* WorldContextObject, const FGameplayTag& BuildingTag, const FGameplayTag& PlacementTag)
{
	return false;
}

void UFortOutpostFunctionLibrary::FlushTransferRequests(AFortPlayerController* Player)
{
}

FIronCityDifficultyInfo UFortOutpostFunctionLibrary::GetCachedIronCityDifficultyInfo(UObject* WorldContextObject)
{
	return FIronCityDifficultyInfo();
}

int32 UFortOutpostFunctionLibrary::GetIronCityAveragePlayerAccountLevel(UObject* WorldContextObject)
{
	return int32();
}

UFortOutpostItemDefinition* UFortOutpostFunctionLibrary::GetOutpostBuildingItemDefinition(UObject* WorldContextObject, EOutpostBuildings Building)
{
	return nullptr;
}

FGameplayTag UFortOutpostFunctionLibrary::GetOutpostBuildingTagFromPlacementTag(UObject* WorldContextObject, const FGameplayTag& PlacementTag)
{
	return FGameplayTag();
}

AFortPlayerControllerOutpost* UFortOutpostFunctionLibrary::GetOutpostOwner(UObject* WorldContextObject)
{
	return nullptr;
}

UFortMissionConfigData* UFortOutpostFunctionLibrary::GetOutpostQuestMissionConfigData(UObject* WorldContextObject, FGameplayTagContainer ConfigTagContainer)
{
	return nullptr;
}

UFortMissionConfigData* UFortOutpostFunctionLibrary::GetOutpostQuestMissionConfigDataFrontEnd(AFortPlayerControllerFrontEnd* FortPC, FGameplayTagContainer ConfigTagContainer)
{
	return nullptr;
}

FGameplayTag UFortOutpostFunctionLibrary::GetPlacementTagFromOutpostBuildingTag(UObject* WorldContextObject, const FGameplayTag& BuildingTag)
{
	return FGameplayTag();
}

void UFortOutpostFunctionLibrary::SaveIronCityEarlyPlayerInfos(UObject* WorldContextObject)
{
}

void UFortOutpostFunctionLibrary::SaveIronCityLowestPlayerAccountLevel(UObject* WorldContextObject, int32 AccountLevel)
{
}

void UFortOutpostFunctionLibrary::SetEnduranceWaveCompleted(UObject* WorldContextObject, const int32 WaveNumber, bool& bNewHighest)
{
}

void UFortOutpostFunctionLibrary::SetIronCityMinMaxPowerLevels(UObject* WorldContextObject, float MinPowerLevel, float MaxPowerLevel)
{
}

void UFortOutpostFunctionLibrary::SetOutpostDefenseActive(UObject* WorldContextObject, bool bActive)
{
}

void UFortOutpostFunctionLibrary::SetOutpostGameDifficultyRow(UObject* WorldContextObject, const FDataTableRowHandle& GameDifficultyInfo)
{
}

void UFortOutpostFunctionLibrary::SetStormShieldDefenseType(UObject* WorldContextObject, EStormShieldDefense Type)
{
}

void UFortOutpostFunctionLibrary::SetWargameActive(UObject* WorldContextObject, bool bActive)
{
}

void UFortOutpostFunctionLibrary::TransferItemFromStorage(AFortPlayerController* Player, UFortWorldItem* Item, int32 Count)
{
}

void UFortOutpostFunctionLibrary::TransferItemToStorage(AFortPlayerController* Player, UFortWorldItem* Item, int32 Count)
{
}
