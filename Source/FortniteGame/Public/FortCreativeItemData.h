// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/PrimaryAssetId.h"
#include "FortCreativeItemData.generated.h"

UENUM()
enum class ECreativeItemCategory : uint8
{
	Prefabs = 0,
	Devices = 1,
	Weapons = 2,
	Consumables = 3,
	Gallery = 4,
	Hidden = 5,
	None = 6,
};

UENUM(BlueprintType)
enum class ECreativeOptionDestructiveActionOperator : uint8
{
	Invalid = 0,
	LessThan = 1,
	NotEqual = 2,
	GreaterThan = 3,
};

USTRUCT()
struct FCreativeItemMetaData
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortCreativeItemListData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListData")
	ECreativeItemCategory Category;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListData")
	FPrimaryAssetId ItemPrimaryAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListData")
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListData")
	float SortPriority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCreativeItemListData")
	bool bIncluded;

};

