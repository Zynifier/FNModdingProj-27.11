// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortItemTier.h"
#include "FortRarityEnum.h"
#include "FortHeroData.generated.h"

class UFortHeroType;

USTRUCT()
struct FHeroKeywordDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="HeroKeywordDisplayData")
	FGameplayTag KeyWordGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="HeroKeywordDisplayData")
	FText KeywordDisplayName;

};

USTRUCT()
struct FHeroPerkDefaultRequirements
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Default Perk Requirements")
	EFortItemTier MinimumHeroTier;

	UPROPERTY(EditDefaultsOnly, Category="Default Perk Requirements")
	int32 MinimumHeroLevel;

	UPROPERTY(EditDefaultsOnly, Category="Default Perk Requirements")
	EFortRarity MinimumHeroRarity;

};

USTRUCT()
struct FHeroSubclassRarityAttributeData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	TArray<FFortAttributeInitializationKey> AttributeInitKeysPerTier;

};

USTRUCT()
struct FHeroSubclassAttributeData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FGameplayTagContainer HeroClassAndSubclassTags;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	TArray<FHeroSubclassRarityAttributeData> AttributeInitKeysPerRarity;

};

UCLASS(BlueprintType)
class UFortHeroData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Defaults")
	FText DefaultHeroName;

	UPROPERTY(EditAnywhere, Category="Defaults", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortHeroType> DefaultHero;

	UPROPERTY(EditAnywhere, Category="Defaults")
	FHeroPerkDefaultRequirements CommanderPerkDefaultRequirements;

	UPROPERTY(EditAnywhere, Category="Defaults")
	bool bTeamPerkDependsOnSupportTierUnlocks;

	UPROPERTY(EditDefaultsOnly, Category="CombinedStats", meta=(AssetBundles="ItemDetails"))
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;

	UPROPERTY(EditDefaultsOnly, Category="HeroData", meta=(AssetBundles="ItemDetails"))
	TArray<FHeroSubclassAttributeData> HeroAttributeDataForSubclasses;

	UPROPERTY(EditDefaultsOnly, Category="HeroDisplayData", meta=(AssetBundles="ItemDetails"))
	TArray<FHeroKeywordDisplayData> HeroKeywordDisplayData;

	UPROPERTY(EditDefaultsOnly, Category="HeroDisplayData", meta=(AssetBundles="ItemDetails"))
	FText HeroPerkDuplicatedText;

	UPROPERTY(EditDefaultsOnly, Category="HeroDisplayData", meta=(AssetBundles="ItemDetails"))
	FText HeroTierTooLowForPerkText;

};

