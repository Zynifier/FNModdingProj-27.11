// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortSpecialActorStatType.h"
#include "FortSpecialActorStatData.generated.h"

USTRUCT(BlueprintType)
struct FSpecialActorSingleStatData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActorSingleStatData")
	ESpecialActorStatType StatType;

	UPROPERTY()
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActorSingleStatData")
	float StatLogicValue;

};

USTRUCT()
struct FSpecialActorStatData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag CategoryTag;

	UPROPERTY()
	TArray<FSpecialActorSingleStatData> Stats;

};

