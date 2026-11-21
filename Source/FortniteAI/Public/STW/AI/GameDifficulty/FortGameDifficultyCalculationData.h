// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataTable.h"
#include "FortGameDifficultyCalculationData.generated.h"

UENUM()
enum class EClampType : uint8
{
	Minimum = 0,
	Maximum = 1,
};

UENUM(BlueprintType)
enum class ERatingsEnforcementType : uint8
{
	Default = 0,
	IgnoreMaximums = 1,
	IgnoreParty = 2,
	IgnorePartyMaximum = 3,
};

USTRUCT(BlueprintType)
struct FAttributeClamp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamping")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamping")
	EClampType ClampType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamping")
	float ClampValue;

};

USTRUCT(BlueprintType)
struct FGameDifficultyInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	bool bIsOnboarding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	float Difficulty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	float DifficultyMatchmakingMinOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	float DifficultyMatchmakingMaxOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	ERatingsEnforcementType RatingsEnforcement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 RequiredRating;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 MaximumRating;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	int32 PvPRating;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 RecommendedRating;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	float ScoreBonus;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString LootTierGroup;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString BonusLootTierGroup;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FString DifficultyIncreaseLootTierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 NumDifficultyIncreases;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	FText ThreatDisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	FName ColorParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	int32 DefaultPlayerLives;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameDifficulty")
	FName PlayerStatClampRowName;

};

USTRUCT(BlueprintType)
struct FPlayerClampInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Clamping")
	TArray<FAttributeClamp> AttributeClamps;

};

