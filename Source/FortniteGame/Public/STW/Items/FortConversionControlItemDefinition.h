// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortConversionControlItemDefinition.generated.h"

class UFortAccountItemDefinition;
class UFortItemDefinition;
enum class EFortRarity : uint8;

USTRUCT(BlueprintType)
struct FFortConversionTierData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	int32 TierCost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	int32 RequiredItemQuantity;

};

USTRUCT(BlueprintType)
struct FFortConversionControlKeyCosts : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftObjectPtr<UFortItemDefinition> RequiredItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Common;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Uncommon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Rare;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Epic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Legendary;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Mythic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Transcendent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FFortConversionTierData Unattainable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConversionControl")
	FGameplayTagContainer RequiredCatalysts;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("QuickbarDisplay", "Stats", "PickupVisuals", "OwnedTags", "Sounds", "Attributes", "LootLevel"))
class UFortConversionControlItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Converion Cost")
	EFortRarity GetFirstConversionTier() const;

	UFUNCTION(BlueprintPure, Category="Converion Cost")
	EFortRarity GetMaxConversionTier() const;

	UFUNCTION(BlueprintPure, Category="Converion Cost")
	int32 GetPointsForTier(EFortRarity InTier) const;

	UFUNCTION(BlueprintPure, Category="Converion Cost")
	FGameplayTagContainer GetRequiredCatalysts() const;

	UFUNCTION(BlueprintPure, Category="Converion Cost")
	UFortAccountItemDefinition* GetRequiredItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Converion Cost")
	int32 GetRequiredItemQuantity(int32 SacrificePoints) const;

	UFUNCTION(BlueprintPure, Category="ConversionControlItem")
	virtual FText GetRewardName() const;

	UFUNCTION(BlueprintPure, Category="Conversion Cost")
	bool GetTierFromSacrificePoints(int32 SacrificePoints, EFortRarity& CalculatedTier) const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversionControlItemDefinition")
	FString LootTierGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversionControlItemDefinition")
	FDataTableRowHandle ConversionPointsToTierCosts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortConversionControlItemDefinition")
	bool bConsumedOnConversion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FText RewardName;

};

