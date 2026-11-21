// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Athena/Faction/FortFactionMapping.h"
#include "FortAffiliationBlueprintLibrary.generated.h"

class AActor;
class UObject;

UCLASS()
class UFortAffiliationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation")
	static void AddToFaction(const AActor* Actor, const FGameplayTag FactionTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation")
	static void AddToFactions(const AActor* Actor, const FGameplayTagContainer& FactionsTagContainer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation", meta=(WorldContext="WorldContextObject"))
	static void ChangeAttitudeBetweenActors(UObject* WorldContextObject, const AActor* FactionOwner, const AActor* TowardsActor, const EFortFactionAttitude::Type Attitude);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation", meta=(WorldContext="WorldContextObject"))
	static void ChangeFactionAttitudeTowardsActor(UObject* WorldContextObject, const FGameplayTagContainer& FactionTags, const AActor* TowardsActor, const EFortFactionAttitude::Type Attitude);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation")
	static FGameplayTagContainer GetCurrentFactions(const AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation")
	static void RemoveFromAllFactions(const AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation")
	static void RemoveFromFaction(const AActor* Actor, const FGameplayTag FactionTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Affiliation", meta=(WorldContext="WorldContextObject"))
	static void SetAffiliationGameplayOwnership(UObject* WorldContextObject, const AActor* OwnerActor, const AActor* OwnedActor);

};

