// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortItemTier.h"
#include "FortRarityEnum.h"
#include "FortHeroGameplayDefinition.generated.h"

class UFortAbilityKit;
class UFortCampaignHeroLoadoutItem;
class UFortHero;
class UFortHeroClassGameplayDefinition;
class UFortHeroType;
class UFortTeamPerkItem;
class UFortTeamPerkItemDefinition;
enum class EFortItemTier : uint8;

UENUM(BlueprintType)
enum class EFortHeroLoadoutPerkType : uint8
{
	Commander = 0,
	Standard = 1,
};

USTRUCT()
struct FFortHeroGameplayPiece
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(AssetBundles="ItemDetails"))
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	FGameplayTagQuery RequiredCommanderTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	FText CommanderRequirementsText;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	bool bUseGlobalDefaultMinima;

	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(EditCondition="!bUseGlobalDefaultMinima"))
	EFortItemTier MinimumHeroTier;

	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(EditCondition="!bUseGlobalDefaultMinima"))
	int32 MinimumHeroLevel;

	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(EditCondition="!bUseGlobalDefaultMinima"))
	EFortRarity MinimumHeroRarity;

};

USTRUCT()
struct FFortHeroTierAbilityKit
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(AssetBundles="ItemDetails"))
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	EFortRarity MinimumHeroRarity;

};

USTRUCT()
struct FFortTeamPerkSlotFilteringData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortHeroGameplayDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool DoesHeroPerkApplyToCommander(UFortHero* FortHero, UFortHero* CommanderHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool DoesHeroSatisfyTeamPerkCondition(const UFortTeamPerkItemDefinition* TeamPerk, UFortHero* SupportHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool DoesTeamPerkApplyToCommander(const UFortTeamPerkItem* TeamPerk, const UFortHero* CommanderHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static UFortAbilityKit* GetAbilityKitForCommanderPerk(const UFortHeroType* HeroDefinition);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static UFortAbilityKit* GetAbilityKitForHeroPerk(const UFortHeroType* HeroDefinition);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static TArray<UFortAbilityKit*> GetAbilityKitsForActiveAbilityPerks(const UFortHeroType* HeroDefinition);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static EFortItemTier GetAbilityKitUnlockTierForHero(const UFortHero* FortHero, UFortAbilityKit* AbilityKit);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static EFortItemTier GetCommanderTierRequiredForHeroPerkToApplyToCommander(UFortHero* FortHero, UFortHero* CommanderHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static EFortItemTier GetCommanderTierRequiredForTeamPerkToApplyToCommander(const UFortTeamPerkItem* TeamPerk, const UFortHero* CommanderHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static TArray<FText> GetKeywordDisplayNames(UFortHeroType* HeroType);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsAbilityKitUnlockedForHero(const UFortHero* FortHero, UFortAbilityKit* AbilityKit);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsCommanderPerkUnlockedForHero(UFortHero* FortHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsHeroPerkUnlockedForHero(UFortHero* FortHero);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsHeroPerkValidForCommander(const UFortHero* SlottedHero, const UFortCampaignHeroLoadoutItem* HeroLoadout, const FName& SupportHeroSlotName, bool bIsSlotting, FText& OutReason);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsSlottedHeroAbilityDuplicated(const UFortHero* PotentiallySlottedHero, const UFortCampaignHeroLoadoutItem* HeroLoadout, const FName& SupportHeroSlotName, bool bIsSlotting);

	UFUNCTION(BlueprintPure, Category="Abilities")
	static bool IsTeamPerkValidForCommander(const UFortTeamPerkItem* TeamPerk, const UFortCampaignHeroLoadoutItem* HeroLoadout, FText& OutReason);

private:
	UPROPERTY(EditDefaultsOnly, Category="ClassData", meta=(IncludeAssetBundles))
	TObjectPtr<UFortHeroClassGameplayDefinition> HeroClassGameplayDefinition;

	UPROPERTY(EditDefaultsOnly, Category="ClassData")
	FGameplayTagContainer HeroBaseStatlineTags;

	UPROPERTY(EditDefaultsOnly, Category="ClassData")
	FGameplayTagContainer HeroTags;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	TArray<FFortHeroTierAbilityKit> TierAbilityKits;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	FFortHeroGameplayPiece HeroPerk;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	FFortHeroGameplayPiece CommanderPerk;

};

