// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AthenaXPTableRowTypes.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FAthenaDynamicRestedXpGoldenPath : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 Day;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 GoldenPathXP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 GoldenPathXPAvailable;

};

USTRUCT(BlueprintType)
struct FAthenaDynamicRestedXpProgression : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 Accumulated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	float DynamicRestMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	float NonBRDynamicRestMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	float StWDynamicRestMult;

};

USTRUCT(BlueprintType)
struct FAthenaExtendedXPCurveEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XpPerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 UntilLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	TSoftObjectPtr<UFortItemDefinition> RewardItemAssetPerLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 RewardItemCountPerLevel;

};

USTRUCT(BlueprintType)
struct FAthenaReengagementRestedXp : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 Interval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 TimeSinceLastSession;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RestXP")
	int32 RestXPGained;

};

USTRUCT(BlueprintType)
struct FAthenaSeasonalXPCurveEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XpToNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XpTotal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	TSoftObjectPtr<UFortItemDefinition> RewardItemAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 RewardItemCount;

};

