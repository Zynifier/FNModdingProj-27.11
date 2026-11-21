// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "McpSharedTypes.generated.h"

USTRUCT(BlueprintType)
struct MCPPROFILESYS_API FMcpLootEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items")
	FString ItemType;

	UPROPERTY(BlueprintReadOnly, Category="Items")
	FString ItemGuid;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items")
	int32 Quantity;

	UPROPERTY(EditAnywhere, Category="Items")
	FJsonObjectWrapper Attributes;

	UPROPERTY(BlueprintReadOnly, Category="Items")
	FString ItemProfile;

};

USTRUCT(BlueprintType)
struct MCPPROFILESYS_API FGiftBoxInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="GiftBoxInfo")
	FDateTime GiftedOn;

	UPROPERTY(BlueprintReadOnly, Category="GiftBoxInfo")
	FString FromAccountId;

	UPROPERTY(BlueprintReadOnly, Category="GiftBoxInfo")
	TArray<FMcpLootEntry> LootList;

	UPROPERTY()
	FJsonObjectWrapper Params;

};

USTRUCT(BlueprintType)
struct MCPPROFILESYS_API FMcpItemIdAndQuantity : public FMcpLootEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct MCPPROFILESYS_API FMcpLootResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Items")
	FString TierGroupName;

	UPROPERTY(EditAnywhere, Category="Items")
	TArray<FMcpLootEntry> Items;

};

