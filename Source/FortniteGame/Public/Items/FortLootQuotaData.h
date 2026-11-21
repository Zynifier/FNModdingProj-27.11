// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortLootQuotaData.generated.h"

UENUM(BlueprintType)
namespace ELootQuotaLevel
{
	enum Type
	{
		Unlimited = 0,
		Level1 = 1,
		Level2 = 2,
		Level3 = 3,
		Level4 = 4,
		Level5 = 5,
		Level6 = 6,
		Level7 = 7,
		Level8 = 8,
		Level9 = 9,
		Level10 = 10,
		Level11 = 11,
		Level12 = 12,
		Level13 = 13,
		Level14 = 14,
		Level15 = 15,
		Level16 = 16,
		Level17 = 17,
		NumLevels = 18,
	};
}

USTRUCT()
struct FFortLootQuotaData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	FName QuotaCategory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	TEnumAsByte<ELootQuotaLevel::Type> QuotaLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	int32 Min;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	int32 Max;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	float Quota;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	int32 MinWorldLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	int32 MaxWorldLevel;

};

