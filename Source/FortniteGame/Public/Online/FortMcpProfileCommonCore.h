// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "CatalogTypes.h"
#include "McpCatalogEnums.h"
#include "McpCommandContexts.h"
#include "McpSharedTypes.h"
#include "Online/FortMcpProfile.h"
#include "FortMcpProfileCommonCore.generated.h"

enum class EAppStore : uint8;
enum class ESocialImportPanelPlatform : uint8;

UENUM(BlueprintType)
enum class EMcpSubscriptionState : uint8
{
	/** Subscription disabled */
	Inactive = 0,
	/** Subscription active and current month payment completed */
	Active = 1,
	/** Subscription active but no recurring payment instrument was set */
	NotAutoRenewable = 2,
	/** Subscription disabled but current month not expired */
	Canceled = 3,
	/** Subscription active but current month payment failed */
	PaymentProcessError = 4,
	/** Subscription active but needs player to login on subscription platform to give benefits */
	PlatformAuthError = 5,
	/** Subscription active but MCP fails to claim the rewards on time for reasons other than payment or auth */
	RewardsDelayed = 6,
	/** Invalid State, should never be returned from MCP profile */
	Unknown = 7,
};

UENUM(BlueprintType)
enum class EPlayerBanReasons : uint8
{
	Teaming = 0,
	Afk_Leeching = 1,
	Harassment = 2,
	TradeScamming = 3,
	Exploiting = 4,
	Competitive = 5,
	Creative = 6,
	TeamingWithCheater = 7,
	StreamSniping = 8,
	ModifiedCosmetics = 9,
};

UENUM(BlueprintType)
enum class EPlayerCompetitiveBanReasons : uint8
{
	None = 0,
	Cheating = 1,
	Collusion = 2,
	Toxicity = 3,
	Harassment = 4,
	Ringing = 5,
	Gambling = 6,
	Exploiting = 7,
	IntentionalDisconnect = 8,
	IllegalRestart = 9,
	Other = 10,
	AccountSharing = 11,
	CircumventingRegionLock = 12,
	CircumventingBan = 13,
	Smurfing = 14,
	CircumventingTeamLock = 15,
	RuleViolation = 16,
};

UENUM(BlueprintType)
enum class ESocialImportPanelPlatform : uint8
{
	Facebook = 0,
	VK = 1,
	Steam = 2,
	Xbox = 3,
	Playstation = 4,
	Switch = 5,
	None = 6,
};

USTRUCT()
struct FGiftHistory
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FMcpBanInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="McpBanInfo")
	TArray<EPlayerBanReasons> BanReasons;

	UPROPERTY(BlueprintReadOnly, Category="McpBanInfo")
	FString ExploitProgramName;

	UPROPERTY(BlueprintReadOnly, Category="McpBanInfo")
	FString AdditionalInfo;

	UPROPERTY()
	FDateTime BanStartTimeUtc;

	UPROPERTY()
	float BanDurationDays;

	UPROPERTY(BlueprintReadOnly, Category="McpBanInfo")
	EPlayerCompetitiveBanReasons CompetitiveBanReason;

	UPROPERTY(BlueprintReadOnly, Category="McpBanInfo")
	bool bRequiresUserAck;

	UPROPERTY()
	bool bBanHasStarted;

};

USTRUCT(BlueprintType)
struct FMtxPurchaseHistoryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FString PurchaseId;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FString OfferId;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FDateTime PurchaseDate;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FDateTime OriginalPurchaseDate;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FDateTime RefundDate;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FDateTime UndoTimeout;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	bool FreeRefundEligible;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	bool bHasBeenRefunded;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	TArray<FMcpLootEntry> LootResult;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	int32 TotalMtxPaid;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FString DynamicBundleLinkId;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	FString RefundPrerequisite;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	int32 IndexInBundle;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistoryEntry")
	int32 NumPurchasesInBundle;

};

USTRUCT(BlueprintType)
struct FMtxPurchaseHistory
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistory")
	TArray<FMtxPurchaseHistoryEntry> Purchases;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistory")
	int32 RefundCredits;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistory")
	int32 RefundsUsed;

	UPROPERTY(BlueprintReadOnly, Category="MtxPurchaseHistory")
	FDateTime TokenRefreshReferenceTime;

};

USTRUCT(BlueprintType)
struct FRmtPurchaseHistoryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RmtPurchaseHistoryEntry")
	FString FulfillmentId;

	UPROPERTY(BlueprintReadOnly, Category="RmtPurchaseHistoryEntry")
	FDateTime PurchaseDate;

	UPROPERTY(BlueprintReadOnly, Category="RmtPurchaseHistoryEntry")
	TArray<FMcpLootEntry> LootResult;

};

USTRUCT(BlueprintType)
struct FRmtPurchaseHistory
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RmtPurchaseHistory")
	TArray<FRmtPurchaseHistoryEntry> Purchases;

};

UCLASS(MinimalAPI)
class UFortMcpProfileCommonCore : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void CancelOrResumeSubscription(EAppStore AppStore, const FString& UniqueSubscriptionId, bool WillAutoRenew, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCancelOrResumeSubscription);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimImportFriendsReward(ESocialImportPanelPlatform Network, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimImportFriendsReward);

	UFUNCTION(ServiceRequest(MCP))
	void ClaimMfaEnabled(bool bClaimForStw, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execClaimMfaEnabled);

	UFUNCTION(ServiceRequest(MCP))
	void CompletePlayerSurvey(const FString& SurveyId, bool bUpdateAllSurveysMetadata, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execCompletePlayerSurvey);

	UFUNCTION(ServiceRequest(MCP))
	void IssueFriendCode(const FString& CodeTokenType, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execIssueFriendCode);

	UFUNCTION(ServiceRequest(MCP))
	void PurchaseCatalogEntry(const FString& OfferId, EStoreCurrencyType::Type Currency, const FString& CurrencySubType, const int32 ExpectedTotalPrice, const int32 PurchaseQuantity, const FString& GameContext, const FString& client_request_id, const FCatalogPurchaseAdditionalData& AdditionalData, const FBaseUrlContext& Context);
	DECLARE_FUNCTION(execPurchaseCatalogEntry);

	UFUNCTION(ServiceRequest(MCP))
	void PurchaseMultipleCatalogEntries(const TArray<FCatalogPurchaseInfo>& PurchaseInfoList, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execPurchaseMultipleCatalogEntries);

	UFUNCTION(ServiceRequest(MCP))
	void RefundMtxPurchase(const FString& PurchaseId, bool QuickReturn, const FString& GameContext, const FCatalogPurchaseAdditionalData& AdditionalData, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRefundMtxPurchase);

	UFUNCTION(ServiceRequest(MCP))
	void SetAffiliateName(const FString& AffiliateName, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetAffiliateName);

	UFUNCTION(ServiceRequest(MCP))
	void SetForcedIntroPlayed(const FString& ForcedIntroName, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetForcedIntroPlayed);

	UFUNCTION(ServiceRequest(MCP))
	void SetMatchmakingBansViewed(const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetMatchmakingBansViewed);

	UFUNCTION(ServiceRequest(MCP))
	void SetMtxPlatform(const FString& NewPlatform, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetMtxPlatform);

	UFUNCTION(ServiceRequest(MCP))
	void SetReceiveGiftsEnabled(bool bReceiveGifts, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetReceiveGiftsEnabled);

private:
	UFUNCTION(ServiceRequest(MCP))
	void ClearUndoTimeoutForPurchase(const TArray<FString>& PurchaseIds, const FDedicatedServerUrlContext& Context);
	DECLARE_FUNCTION(execClearUndoTimeoutForPurchase);

	UPROPERTY(Config)
	FString ListCatalogEntriesUrl;

	UPROPERTY(Config)
	int32 AffiliateExpirationSeconds;

	UPROPERTY(Config)
	bool bMergePerPlayerEncryptionKeys;

};

