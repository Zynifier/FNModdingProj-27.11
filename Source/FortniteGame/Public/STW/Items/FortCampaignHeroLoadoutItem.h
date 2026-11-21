// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/FortProfileItem.h"
#include "FortCampaignHeroLoadoutItem.generated.h"

class UFortGadgetItemDefinition;
class UFortHero;
class UFortTeamPerkItem;
class UFortTeamPerkItemDefinition;

USTRUCT(BlueprintType)
struct FFilledGadgetSlot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString gadget;

	UPROPERTY()
	int32 slot_index;

};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortCampaignHeroLoadoutItem : public UFortProfileItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortHero* GetCommanderHero() const;

	UFUNCTION(BlueprintPure)
	UFortGadgetItemDefinition* GetGadgetDefinitionBySlotIndex(const int32 SlotIndex) const;

	UFUNCTION(BlueprintPure)
	UFortHero* GetHeroBySlotName(const FName& SlotName) const;

	UFUNCTION(BlueprintPure)
	void GetHeroes(TArray<UFortHero*>& OutHeroes) const;

	UFUNCTION(BlueprintPure)
	void GetHeroesBySlotTag(const FGameplayTagQuery& TagQuery, TArray<UFortHero*>& OutHeroes) const;

	UFUNCTION(BlueprintPure)
	int32 GetLoadoutOrdinal() const;

	UFUNCTION(BlueprintPure)
	FName GetSlotNameByHero(const UFortHero* Hero) const;

	UFUNCTION(BlueprintPure)
	void GetSupportHeroes(TArray<UFortHero*>& OutHeroes) const;

	UFUNCTION(BlueprintPure)
	void GetSupportHeroesAndSupportSlotIndices(TArray<UFortHero*>& OutHeroes, TArray<int32>& OutSupportSlotIndices) const;

	UFUNCTION(BlueprintPure)
	UFortTeamPerkItem* GetTeamPerk() const;

	UFUNCTION(BlueprintPure)
	int32 GetTeamPerkActivationLevel() const;

	UFUNCTION(BlueprintPure)
	int32 GetTeamPerkActivationLevelAndSatisfyingSlotIndices(TArray<int32>& OutSatisfyingSlotIndices) const;

	UFUNCTION(BlueprintPure)
	UFortTeamPerkItemDefinition* GetTeamPerkItemDefinition() const;

	UFUNCTION(BlueprintPure)
	int32 GetTeamPerkMaxActivationLevel() const;

	UFUNCTION(BlueprintPure)
	bool IsTeamPerkActive() const;

	UFUNCTION(BlueprintPure)
	bool IsTeamPerkProgressive() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortCampaignHeroLoadoutItem", meta=(DisplayName="LoadoutName"))
	FString loadout_name;

	UPROPERTY()
	int32 loadout_index;

	UPROPERTY()
	TMap<FString, FString> crew_members;

	UPROPERTY()
	TArray<FFilledGadgetSlot> gadgets;

	UPROPERTY()
	FString team_perk;

private:
	UPROPERTY()
	TMap<FName, FString> CrewMembers;

};

