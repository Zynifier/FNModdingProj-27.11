// Copyright Epic Games, Inc. All Rights Reserved.

#include "Expeditions/FortExpeditionUtilities.h"

bool UFortExpeditionUtilities::AreAnyExpeditionsComplete(const UWidget* Widget)
{
	return false;
}

bool UFortExpeditionUtilities::AreExpeditionsUnlocked(UObject* WorldContextObject, const FUniqueNetIdRepl& UniqueId)
{
	return false;
}

float UFortExpeditionUtilities::CalculateExpeditionPercentageChanceForSuccess(const UFortExpeditionItem* Expedition, const float TotalPower)
{
	return float();
}

void UFortExpeditionUtilities::CalculateGlobalAndItemRatingModValuesBP(const UFortExpeditionItem* Expedition, const TArray<UFortItem*>& SlottedItems, float& GlobalPowerMod, TArray<float>& SlottedItemMods)
{
}

float UFortExpeditionUtilities::CalculateTotalPower(AFortPlayerController* FortPC, const UFortExpeditionItem* Expedition, const FName& SquadId, const TArray<UFortItem*>& SlottedItems)
{
	return float();
}

void UFortExpeditionUtilities::GetAllExpeditionSquadIds(TArray<FName>& OutExpeditionSquadIds)
{
}

float UFortExpeditionUtilities::GetExpeditionSquadPower(AFortPlayerController* FortPC, const FName& SquadId)
{
	return float();
}

bool UFortExpeditionUtilities::GetExpeditionSquadsThatMatchRequirements(const FGameplayTagContainer& RequirementTags, AFortPlayerController* FortPC, TArray<FName>& OutExpeditionSquadIds)
{
	return false;
}

void UFortExpeditionUtilities::GetMatchedCriteriaTags(UFortExpeditionItem* Expedition, const TArray<UFortItem*>& SlottedItems, TArray<FGameplayTag>& OutMatchedCriteria)
{
}

void UFortExpeditionUtilities::GetTotalExpeditionVehiclesAvailable(const UWidget* Widget, AFortPlayerController* FortPC, int32& OutLandVehicles, int32& OutLandVehiclesAvailable, int32& OutSeaVehicles, int32& OutSeaVehiclesAvailable, int32& OutAirVehicles, int32& OutAirVehiclesAvailable)
{
}

bool UFortExpeditionUtilities::GetVehicleTagFromSquadId(const FName& SquadId, FGameplayTag& OutFoundVehicleTag)
{
	return false;
}

FGameplayTag UFortExpeditionUtilities::GetVehicleTagRequiredForExpedition(const UFortExpeditionItem* Expedition)
{
	return FGameplayTag();
}

bool UFortExpeditionUtilities::IsSquadOnExpedition(const UWidget* Widget, const FName& SquadId)
{
	return false;
}

int32 UFortExpeditionUtilities::TotalUnseenExpeditionsForTab(const UWidget* Widget, const FName& TabNameId)
{
	return int32();
}
