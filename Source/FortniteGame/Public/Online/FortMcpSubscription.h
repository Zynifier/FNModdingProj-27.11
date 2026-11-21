// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "CatalogTypes.h"
#include "McpCatalogEnums.h"
#include "FortMcpSubscription.generated.h"

class UFortSubscriptionConfig;

USTRUCT()
struct FFortActiveSubscription
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime NextRewardDate;

	UPROPERTY()
	FDateTime NextRenewalRewardDate;

	UPROPERTY()
	FDateTime LastRenewalRewardDate;

	UPROPERTY()
	bool RenewedAsOverlapped;

	UPROPERTY()
	FDateTime LastStatusRefresh;

	UPROPERTY()
	FDateTime MustRefreshAuthBy;

	UPROPERTY()
	FDateTime LastAuthRefresh;

	UPROPERTY()
	FDateTime SubscriptionEndDate;

	UPROPERTY()
	bool IsRetryingRenewal;

	UPROPERTY()
	EAppStore AppStore;

	UPROPERTY()
	bool WillAutoRenew;

	UPROPERTY()
	EAutoRenewState AutoRenewState;

	UPROPERTY()
	FString UniqueSubscriptionId;

	UPROPERTY()
	TMap<FString, FString> Metadata;

};

USTRUCT()
struct FFortSubscriptionProgressiveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime AcquiredDate;

	UPROPERTY()
	int32 Stage;

	UPROPERTY()
	FDateTime NextStageRewardDate;

};

USTRUCT()
struct FFortSubscriptionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FFortSubscriptionProgressiveInfo> Progressables;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortSubscriptionConfig> Config;

};

USTRUCT()
struct FFortSubscriptionProgressiveFulfillmentConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FulfillmentId;

	UPROPERTY()
	int32 GrantOnDayOfMonth;

	UPROPERTY()
	bool ExpirationEnabled;

	UPROPERTY()
	FString AcquisitionCutoffDate;

	UPROPERTY()
	FString AcquireStartDate;

};

UCLASS(Config=Game)
class UFortSubscriptionConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 RefreshAuthMinutes;

	UPROPERTY(Config)
	TArray<FFortSubscriptionProgressiveFulfillmentConfig> Progressives;

};

