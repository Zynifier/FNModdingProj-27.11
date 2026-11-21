// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMissionGenerationData.generated.h"

class UFortMissionGenerator;

USTRUCT()
struct FFortDifficultyOptionBudget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionBudget")
	FGameplayTagContainer BudgetTypeTags;

	UPROPERTY(EditDefaultsOnly, Category="FortDifficultyOptionBudget")
	FCurveTableRowHandle DifficultyOptionPointsCurve;

};

UCLASS()
class UFortMissionGenerationData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PrimaryMissions")
	TArray<TObjectPtr<UFortMissionGenerator>> PrimaryMissionGenerators;

	UPROPERTY(EditDefaultsOnly, Category="PrimaryMissions", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float PrimaryMissionMinPowerPointsUsagePercentage;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle SecondaryMissionPowerPointsBudgetMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MinSecondaryMissionPowerPointsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MaxSecondaryMissionPowerPointsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MinSecondaryMissions;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MaxSecondaryMissions;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle TertiaryMissionPowerPointsBudgetMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MinTertiaryMissionPowerPointsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="SecondaryMissions")
	FCurveTableRowHandle MaxTertiaryMissionPowerPointsMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="PowerPoints")
	FCurveTableRowHandle PowerPointsCurve;

protected:
	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptionBudgets")
	TArray<FFortDifficultyOptionBudget> EncounterDifficultyOptionBudgets;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptionBudgets", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float EncounterMinDifficultyOptionPointsUsagePercentage;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptionBudgets")
	TArray<FFortDifficultyOptionBudget> MissionDifficultyOptionBudgets;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyOptionBudgets", meta=(ClampMax="1.0", ClampMin="0.0", UIMax="1.0", UIMin="0.0"))
	float MissionMinDifficultyOptionPointsUsagePercentage;

};

