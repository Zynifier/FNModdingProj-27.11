// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItem.h"
#include "AthenaRewardEventGraphItem.generated.h"

USTRUCT()
struct FRewardKeyState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString static_key_template_id;

	UPROPERTY()
	int32 unlock_keys_used;

};

UCLASS(MinimalAPI, BlueprintType)
class UAthenaRewardEventGraphItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 player_random_seed;

	UPROPERTY()
	int64 reward_graph_purchased_timestamp;

	UPROPERTY()
	FDateTime unlock_epoch;

	UPROPERTY()
	int32 unlock_keys_used;

	UPROPERTY()
	bool reward_graph_purchased;

	UPROPERTY()
	TArray<FGameplayTag> reward_nodes_claimed;

	UPROPERTY()
	TArray<FString> player_state;

	UPROPERTY()
	TArray<FRewardKeyState> reward_keys;

};

