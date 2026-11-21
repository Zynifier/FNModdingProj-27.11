// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineAccountCommon.h"
#include "FortOnlineAccount.generated.h"

USTRUCT()
struct FGeneralChatRoom
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString RoomName;

	UPROPERTY()
	int32 CurrentMembersCount;

	UPROPERTY()
	int32 MaxMembersCount;

	UPROPERTY()
	FString PublicFacingShardName;

};

USTRUCT()
struct FGeneralChatReturn
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGeneralChatRoom> GlobalChatRooms;

	UPROPERTY()
	TArray<FGeneralChatRoom> FounderChatRooms;

	UPROPERTY()
	bool bNeedsPaidAccessForGlobalChat;

	UPROPERTY()
	bool bNeedsPaidAccessForFounderChat;

	UPROPERTY()
	bool bIsGlobalChatDisabled;

	UPROPERTY()
	bool bIsFounderChatDisabled;

	UPROPERTY()
	bool bIsSubGameGlobalChatDisabled;

};

USTRUCT()
struct FRestrictedCountry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bHealthWarningShown;

	UPROPERTY()
	bool bAntiAddictionMessageShown;

	UPROPERTY()
	bool bRealMoneyStoreRestriction;

	UPROPERTY()
	bool bGameplayRestrictions;

};

USTRUCT()
struct FVerifyProfileTokenPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FString> ProfileTokens;

};

UCLASS(MinimalAPI)
class UFortOnlineAccount : public UOnlineAccountCommon
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	bool bDisablePurchasingOnRedemptionFailure;

	UPROPERTY(Config)
	double MinimumSecondsBetweenPurchaseRedemptionAttempts;

	UPROPERTY(Config)
	bool bPromptUserAndReverifyAuthToken;

	UPROPERTY(Config)
	float RefreshConnectionTimerDuration;

	UPROPERTY(Config)
	float RefreshChatPrivilegeOnReactivateTimerDuration;

	UPROPERTY(Config)
	TArray<FString> RealMoneyPurchaseBlockedCountryCodes;

private:
	UPROPERTY(Config)
	bool bEnableEulaCheck;

	UPROPERTY(Config)
	bool bShouldAthenaQueryRecentPlayers;

	UPROPERTY(Config)
	bool bRestorePartiesAnalyticsEnabled;

	UPROPERTY(Config)
	bool bRestorePartiesEnabled;

	UPROPERTY()
	bool bHadLoginPurchaseCheckFailure;

	UPROPERTY(Config)
	TArray<FString> IgnoreProducts;

	UPROPERTY(Config)
	TArray<FString> IgnoreReceiptSuffixes;

	UPROPERTY(Config)
	TArray<FString> IncludeReceiptSuffixes;

	UPROPERTY(Config)
	TArray<FString> ResubmitProducts;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortOnlineAccount")
	TMap<FString, FRestrictedCountry> RestrictedCountries;

	UPROPERTY(Config)
	bool bShouldRefreshOnReactivate;

	UPROPERTY(Config)
	bool bShouldCallPurchaseRedemptionOnApplicationReactivate;

	UPROPERTY(Config)
	bool bMergePerPlayerEncryptionKeysOnLogin;

};

