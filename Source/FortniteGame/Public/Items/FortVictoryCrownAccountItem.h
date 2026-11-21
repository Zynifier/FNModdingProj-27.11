// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortVictoryCrownAccountItem.generated.h"

USTRUCT(BlueprintType)
struct FVictoryCrownAccountData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool has_victory_crown;

	UPROPERTY()
	int32 total_victory_crowns_bestowed_count;

	UPROPERTY()
	int32 total_royal_royales_achieved_count;

	UPROPERTY()
	bool data_is_valid_for_mcp;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortVictoryCrownAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortVictoryCrownAccountItem")
	FVictoryCrownAccountData victory_crown_account_data;

};

