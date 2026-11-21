// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSquadManagement.generated.h"

UENUM(BlueprintType)
enum class ESquadSlotSortType : uint8
{
	ByRating = 0,
	ByLevel = 1,
	ByRarity = 2,
	ByBonus = 3,
	ByMatch = 4,
};

USTRUCT(BlueprintType)
struct FSquadSlotSortTypes
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SquadSlotSortTypes")
	TArray<ESquadSlotSortType> SortTypes;

};

