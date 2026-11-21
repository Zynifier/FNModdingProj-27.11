// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItem.h"
#include "McpSharedTypes.h"
#include "FortPrerollDataItem.generated.h"

UCLASS(MinimalAPI)
class UFortPrerollDataItem : public UFortAccountItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	FDateTime Expiration;

	UPROPERTY()
	TArray<FMcpLootEntry> Items;

	UPROPERTY()
	int32 Highest_Rarity;

};

