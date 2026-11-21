// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortItemTier.h"
#include "FortRarityEnum.h"
#include "Items/FortProfileItemDefinition.h"
#include "FortTeamPerkItemDefinition.generated.h"

class UFortAbilityKit;

USTRUCT()
struct FFortTeamPerkLoadoutCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SquadCondition")
	int32 NumTimesSatisfiable;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition")
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMinimumTier : 1;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMaximumTier : 1;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMinimumLevel : 1;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMaximumLevel : 1;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMinimumRarity : 1;

	UPROPERTY(EditAnywhere, Category="SquadCondition", meta=(InlineEditConditionToggle, PinHiddenByDefault))
	uint8 bConsiderMaximumRarity : 1;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMinimumTier"))
	EFortItemTier MinimumHeroTier;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMaximumTier"))
	EFortItemTier MaximumHeroTier;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMinimumLevel"))
	int32 MinimumHeroLevel;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMaximumLevel"))
	int32 MaximumHeroLevel;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMinimumRarity"))
	EFortRarity MinimumHeroRarity;

	UPROPERTY(EditDefaultsOnly, Category="SquadCondition", meta=(EditCondition="bConsiderMaximumRarity"))
	EFortRarity MaximumHeroRarity;

};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortTeamPerkItemDefinition : public UFortProfileItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Abilities", meta=(DisplayName="Get Ability Kit"))
	UFortAbilityKit* GetAbilityKitBP() const;

	UFUNCTION(BlueprintPure, Category="Abilities")
	bool HasProgressiveBonus() const;

protected:
	UPROPERTY(EditDefaultsOnly, Category="TeamPerkRules")
	bool bProgressiveBonus;

	UPROPERTY(EditDefaultsOnly, Category="TeamPerkRules")
	FGameplayTagQuery RequiredCommanderTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="TeamPerkRules")
	FText CommanderRequirementsText;

	UPROPERTY(EditDefaultsOnly, Category="TeamPerkRules")
	TArray<FFortTeamPerkLoadoutCondition> TeamPerkLoadoutConditions;

private:
	UPROPERTY(EditDefaultsOnly, Category="Abilities", meta=(AssetBundles="ItemDetails"))
	TSoftObjectPtr<UFortAbilityKit> GrantedAbilityKit;

};

