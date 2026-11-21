// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAISpawnGroupUpgradeUIData.h"
#include "FortAISpawnGroupUpgrade.generated.h"

class UFortGameplayModifierItemDefinition;

USTRUCT()
struct FFortAIPawnUpgradeData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeData")
	FCurveTableRowHandle SpawnPointsMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeData")
	FCurveTableRowHandle LifespanMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeData")
	FCurveTableRowHandle ScoreMultiplierCurve;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeData")
	TObjectPtr<UFortGameplayModifierItemDefinition> ModifierDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgradeData")
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> AdditionalModifiers;

};

USTRUCT()
struct FFortAIPawnUpgrade
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgrade")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnUpgrade")
	TArray<FFortAIPawnUpgradeData> PawnUpgradeDataPerPlayerCount;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAISpawnGroupUpgrade : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	FGameplayTagContainer UpgradeTags;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	FGameplayTagQuery GroupRequiredTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	TArray<FFortAIPawnUpgrade> BasePawnUpgrades;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	FName AdditionalModifiersLootTierGroup;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	bool bInvalidForEnemySpawners;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float SpawnGroupDiscountPercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortAISpawnGroupUpgrade")
	FFortAISpawnGroupUpgradeUIData UIData;

};

