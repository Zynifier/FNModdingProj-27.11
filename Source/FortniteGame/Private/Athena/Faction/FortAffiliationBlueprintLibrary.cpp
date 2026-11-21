// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Faction/FortAffiliationBlueprintLibrary.h"

void UFortAffiliationFunctionLibrary::AddToFaction(const AActor* Actor, const FGameplayTag FactionTag)
{
}

void UFortAffiliationFunctionLibrary::AddToFactions(const AActor* Actor, const FGameplayTagContainer& FactionsTagContainer)
{
}

void UFortAffiliationFunctionLibrary::ChangeAttitudeBetweenActors(UObject* WorldContextObject, const AActor* FactionOwner, const AActor* TowardsActor, const EFortFactionAttitude::Type Attitude)
{
}

void UFortAffiliationFunctionLibrary::ChangeFactionAttitudeTowardsActor(UObject* WorldContextObject, const FGameplayTagContainer& FactionTags, const AActor* TowardsActor, const EFortFactionAttitude::Type Attitude)
{
}

FGameplayTagContainer UFortAffiliationFunctionLibrary::GetCurrentFactions(const AActor* Actor)
{
	return FGameplayTagContainer();
}

void UFortAffiliationFunctionLibrary::RemoveFromAllFactions(const AActor* Actor)
{
}

void UFortAffiliationFunctionLibrary::RemoveFromFaction(const AActor* Actor, const FGameplayTag FactionTag)
{
}

void UFortAffiliationFunctionLibrary::SetAffiliationGameplayOwnership(UObject* WorldContextObject, const AActor* OwnerActor, const AActor* OwnedActor)
{
}
