// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "SeasonItem/AthenaSeasonItemTypes.h"
#include "AthenaSeasonItem.generated.h"

UCLASS(BlueprintType)
class UAthenaSeasonItem : public UFortAccountItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="AthenaSeasonItem")
	TArray<FAthenaSeasonItemMCPState> SeasonItemStateList;

};

