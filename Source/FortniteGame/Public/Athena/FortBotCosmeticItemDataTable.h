// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "FortBotCosmeticItemDataTable.generated.h"

USTRUCT()
struct FFortBotCosmeticItemDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId PrimaryAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	float Weight;

};

USTRUCT()
struct FFortBotCosmeticItemSetDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId CharacterAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId GliderAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId SkyDiveContrailAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId BackpackAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FPrimaryAssetId PickaxeAssetId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Info")
	FGameplayTag SetTag;

};

USTRUCT()
struct FFortBotCosmeticLibraryWeightRegionOverrideDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortBotCosmeticLibraryWeightRegionOverrideDataTableRow")
	FString RegionId;

	UPROPERTY(EditDefaultsOnly, Category="FortBotCosmeticLibraryWeightRegionOverrideDataTableRow")
	FScalableFloat RegionWeights;

};

USTRUCT()
struct FFortLimitedAvailabilityBotCosmeticItemDataTableRow : public FFortBotCosmeticItemDataTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
	FDateTime StartDate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
	FDateTime EndDate;

};

USTRUCT()
struct FFortLimitedAvailabilityBotCosmeticItemSetDataTableRow : public FFortBotCosmeticItemSetDataTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
	FDateTime StartDate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Availability")
	FDateTime EndDate;

};

