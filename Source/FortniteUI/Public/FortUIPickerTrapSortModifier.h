// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortUIPickerTrapSortModifier.generated.h"

USTRUCT(BlueprintType)
struct FFortUIPickerTrapSortModifier : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortModifier")
	FGameplayTagQuery ItemTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortModifier")
	float ScoreBonus;

};

USTRUCT(BlueprintType)
struct FFortUIPickerTrapSortScores
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortScores")
	float UniqueTrapBonus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortScores")
	float SlottedBonus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortScores")
	float FavoriteBonus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortScores")
	float MaxTrackedTrapBonusTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortUIPickerTrapSortScores")
	float TrackedTrapBonusMultiplier;

};

