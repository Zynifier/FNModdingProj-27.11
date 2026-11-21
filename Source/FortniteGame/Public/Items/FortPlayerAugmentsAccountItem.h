// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "Items/FortAccountItem.h"
#include "FortPlayerAugmentsAccountItem.generated.h"

USTRUCT()
struct FCarryOverPlayerAugmentPersistenceData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category="CarryOverPlayerAugmentPersistenceData")
	FPrimaryAssetId augment_asset_id;

	UPROPERTY(VisibleInstanceOnly, Category="CarryOverPlayerAugmentPersistenceData")
	FName source_playlist_name;

};

USTRUCT(BlueprintType)
struct FPlayerAugmentsPersistenceData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category="PlayerAugmentsPersistenceData")
	int32 roll_count_since_last_unlock;

	UPROPERTY(VisibleInstanceOnly, Category="PlayerAugmentsPersistenceData")
	TArray<FCarryOverPlayerAugmentPersistenceData> carry_over_player_augments;

};

UCLASS(MinimalAPI)
class UFortPlayerAugmentsAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Category="FortPlayerAugmentsAccountItem")
	FPlayerAugmentsPersistenceData data;

};

