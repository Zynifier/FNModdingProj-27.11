// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Items/FortAccountItem.h"
#include "FortCampsiteAccountItem.generated.h"

USTRUCT(BlueprintType)
struct FCachedCampSpawnLocation
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FVector3d world_spawn_location;

};

USTRUCT(BlueprintType)
struct FCachedItemData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="StashedItem")
	FString item_definition_persistent_name;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	int32 item_count;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	int32 item_level;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	int32 item_loaded_ammo;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	int32 item_phantom_ammo;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	TArray<float> item_attributes;

};

USTRUCT(BlueprintType)
struct FCampsiteAccountData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="StashedItem")
	bool data_is_valid_for_mcp;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	TArray<FCachedItemData> stashed_items;

	UPROPERTY(EditAnywhere, Category="StashedItem")
	TArray<FCachedCampSpawnLocation> camp_spawn_locations;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortCampsiteAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCampsiteAccountItem")
	FCampsiteAccountData campsite_account_data;

};

