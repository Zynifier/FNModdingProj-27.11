// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Items/FortAccountItem.h"
#include "RealitySaplingAccountItem.generated.h"

USTRUCT(BlueprintType)
struct FCachedRealitySaplingData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CachedSapling")
	FVector location;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	FRotator rotation;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	int32 nurturing_level;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	int32 maturity_level;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	int64 planting_time;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	int64 last_weeding_time;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	TArray<int32> fruit_states;

};

USTRUCT(BlueprintType)
struct FRealitySaplingAccountData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	bool data_is_valid_for_mcp;

	UPROPERTY(EditAnywhere, Category="CachedSapling")
	TArray<FCachedRealitySaplingData> saplings;

};

UCLASS(MinimalAPI)
class URealitySaplingAccountItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RealitySaplingAccountItem")
	FRealitySaplingAccountData sapling_account_data;

};

