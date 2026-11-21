// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCatalogEnums.h"
#include "McpEntitlementRefreshTimerInfo.h"
#include "McpInAppPurchases.generated.h"

USTRUCT()
struct GAMESUBCATALOG_API FMcpProcessedConsumables
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAppStore AppStore;

	UPROPERTY()
	TArray<FString> Ids;

};

USTRUCT()
struct GAMESUBCATALOG_API FMcpInAppPurchases
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Receipts;

	UPROPERTY()
	TArray<FString> IgnoredReceipts;

	UPROPERTY()
	TArray<FString> Fulfillments;

	UPROPERTY()
	TMap<FString, int32> FulfillmentCounts;

	UPROPERTY()
	TMap<EAppStore, FMcpEntitlementRefreshTimerInfo> RefreshTimers;

	UPROPERTY()
	TArray<FMcpProcessedConsumables> ProcessedConsumables;

};

