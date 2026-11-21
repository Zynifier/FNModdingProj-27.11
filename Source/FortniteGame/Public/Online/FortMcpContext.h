// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "BlueprintContextBase.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "Online/AthenaLevelInfo.h"
#include "Online/FortMcpProfileCommonCore.h"
#include "Online/FortMcpTypes.h"
#include "Online/FortMcpUtils.h"
#include "STW/FortCampaignLoadout.h"
#include "STW/FortHomebase/FortHomeBaseInfo.h"
#include "FortMcpContext.generated.h"

class AFortPlayerController;
class UFortAccountItem;
class UFortAccountItemDefinition;
class UFortAlterableItem;
class UFortAlterationItem;
class UFortAsyncAction_CalendarEventWatcher;
class UFortAsyncAction_CalendarMultiEventWatcher;
class UFortAsyncAction_InitialCalendarSyncCompleted;
class UFortAsyncAction_MCPContextConsumeItem;
class UFortAsyncAction_MCPContextUpgradeItem;
class UFortCollectedResourceItem;
class UFortConversionControlItemDefinition;
class UFortExpeditionItem;
class UFortGameInstance;
class UFortGiftBoxItem;
class UFortHero;
class UFortItem;
class UFortMcpContext;
class UFortMcpProfileAthena;
class UFortMcpProfileCampaign;
class UFortMcpProfileCommonCore;
class UFortMcpProfileCommonPublic;
class UFortMcpProfileCreative;
class UFortMcpProfileSubgame;
class UObject;
class UWidget;
enum class EFortItemType : uint8;
enum class EOfferPurchaseError : uint8;

UENUM(BlueprintType)
enum class EOfferPurchaseError : uint8
{
	NoError = 0,
	// this is no error returned in cases where the purchase isn't being atempted.

	PendingServerConfirmation = 1,
	// this is "success" for all intents, wait for the callback to know for sure

	CannotAffordItem = 2,
	InvalidOfferID = 3,
	InvalidPriceIndex = 4,
	NoneLeft = 5,
	PurchaseAlreadyPending = 6,
	NoConnection = 7,
	AccountNotEligible = 8,
	CannotGiftItem = 9,
	MFANotEnabled = 10,
};

USTRUCT(BlueprintType)
struct FFortPublicAccountInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPublicAccountInfo")
	int32 Level;

	UPROPERTY(BlueprintReadOnly, Category="FortPublicAccountInfo")
	int32 MaxLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortPublicAccountInfo")
	int32 LevelXp;

	UPROPERTY(BlueprintReadOnly, Category="FortPublicAccountInfo")
	int32 LevelXpForLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortPublicAccountInfo")
	FAthenaLevelInfo BattleRoyaleLevel;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCurrentlyViewedAccountInfoChangedDelegate, FFortPublicAccountInfo, NewInfo);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDailyRewardScheduleTokenDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortConversionBeginDelegate, FString, ConvertedItemInstanceId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortConversionCompleteDelegate, const bool, bWasSuccessful, FString, ConvertedItemInstanceId, const TArray<FFortItemInstanceQuantityPair>&, ItemsQuantities);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortDifficultyIncreaseRewardsClaimFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortItemCacheRewardsClaimFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortItemCacheRewardsClaimed, const TArray<FFortItemInstanceQuantityPair>&, ClaimedRewards);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortMissionRewardsOpenFailed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMissionRewardsOpened, const TArray<FFortItemInstanceQuantityPair>&, MissionRewards);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortPromotionCompleteDelegate, const bool, bWasSuccessful);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortResourceCollectorClaimed, const TArray<FFortItemInstanceQuantityPair>&, CollectorRewards);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortTransmogCompleteDelegate, const TArray<FFortItemInstanceQuantityPair>&, TransmoggedItems, const TArray<FFortItemInstanceQuantityPair>&, RecycledItems);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortTransmogFailedDelegate, const FText&, ErrorMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortUpgradeRarityBeginDelegate, FString, UpgradedItemInstanceId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortUpgradeRarityCompleteDelegate, const bool, bWasSuccessful, FString, UpgradedItemInstanceId, const TArray<FFortItemInstanceQuantityPair>&, ItemsQuantities);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFounderChangeDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHeroesChangedDelegate);

USTRUCT(BlueprintType)
struct FFortPrivateAccountInfo : public FFortPublicAccountInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPrivateAccountInfo")
	int32 MtxBalance;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLocalAccountInfoChangedDelegate, FFortPrivateAccountInfo, NewInfo);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAffilateNameSetAcknowledged, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnBanAcknowledged, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnCheckAffiliateNameComplete, bool, bSuccess, bool, bWasValidAffiliateName, FString, AffilateNameChecked);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnDownloadEULAComplete, bool, bSuccessful, FText, EULAText, FString, Key);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnEpicPurchasingWidgetDismissed);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEpicPurchasingWidgetDisplay, UWidget*, WebWidget, FString, OfferId);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGiftBoxRemoved, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnGiftOfferComplete, bool, bSuccess, const TArray<FString>&, IneligableAccounts, const TArray<FString>&, ErrorCodes);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLiveStreamingQuestWindowEnds);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLiveStreamingQuestWindowSelectedViewers, const TArray<FText>&, Names);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLiveStreamingQuestWindowStarts, float, Seconds);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnLoginFlowWidgetDismissed);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnLoginFlowWidgetDisplay, UWidget*, WebWidget);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNativePurchaseBattlePassOfferComplete, const bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPhoenixXpChangeDelegate, int32, CurrentXp, int32, CurrentLevel);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPurchaseBattlePassOfferComplete, bool, bSuccess, const TArray<FString>&, OfferTemplateIdList);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPurchaseMultipleOffersComplete, bool, bSuccess, const TArray<FPurchasedItemInfo>&, PurchasedItems, const TArray<FString>&, OfferIdList);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPurchaseOfferCompleteMulti, bool, bSuccess, const TArray<FPurchasedItemInfo>&, PurchasedItems);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPurchaseOfferComplete, bool, bSuccess, const TArray<FPurchasedItemInfo>&, PurchasedItems, FString, OfferId);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnReadPrivacySettingsComplete, bool, bSuccess, const FMcpPrivacySettings&, Settings);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRealMoneyPurchaseCompleteMulti, bool, bSuccess, const TArray<FPurchasedItemInfo>&, PurchasedItems);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnRealMoneyPurchaseComplete, bool, bSuccess, const TArray<FPurchasedItemInfo>&, PurchasedItems);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnUpdatePrivacySettingsComplete, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FXpBoostChangeDelegate, int32, BoostAmount);

USTRUCT(BlueprintType)
struct FFriendCodeLocString
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FriendCodeLocString")
	FString Lang;

	UPROPERTY(EditDefaultsOnly, Category="FriendCodeLocString")
	FString Text;

};

USTRUCT(BlueprintType)
struct FMtxPackage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FString StorefrontName;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FString OfferId;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FText Title;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FText Description;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	int32 TotalAmount;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	int32 BonusAmount;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FText Price;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FText SaleBasePrice;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FString DisplayAssetPath;

	UPROPERTY(BlueprintReadOnly, Category="MtxPackage")
	FString BannerOverride;

};

UCLASS(Abstract)
class UFortAsyncAction_CalendarEventWatcherBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnClientEventFlagChanged, FString, EventName, FTimespan, TimeUntilEnd, FTimespan, TimeSinceBegin, float, TimeSpanRatio);

public:
	UPROPERTY(BlueprintAssignable)
	FOnClientEventFlagChanged OnEventActive;

	UPROPERTY(BlueprintAssignable)
	FOnClientEventFlagChanged OnEventUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnClientEventFlagChanged OnEventEnded;

protected:
	UPROPERTY()
	TObjectPtr<UFortGameInstance> MyGameInstance;

};

UCLASS()
class UFortAsyncAction_CalendarEventWatcher : public UFortAsyncAction_CalendarEventWatcherBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_CalendarEventWatcher* WatchCalendarEvent(UObject* WorldContextObject, const FString& EventToWatch);

};

UCLASS()
class UFortAsyncAction_CalendarMultiEventWatcher : public UFortAsyncAction_CalendarEventWatcherBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_CalendarMultiEventWatcher* WatchCalendarEvents(UObject* WorldContextObject, TArray<FString> EventsToWatch);

};

UCLASS()
class UFortAsyncAction_InitialCalendarSyncCompleted : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInitialCalendarSyncCompleted);

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_InitialCalendarSyncCompleted* InitialCalendarSyncCompleted(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FOnInitialCalendarSyncCompleted OnSyncComplete;

protected:
	UFUNCTION()
	void HandleInitialCalendarSyncCompleted();

	UPROPERTY()
	TObjectPtr<UFortGameInstance> MyGameInstance;

};

UCLASS()
class UFortAsyncAction_MCPContextConsumeItem : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMCPRequestComplete);

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_MCPContextConsumeItem* ConsumeItem(const UFortMcpContext* MCPContext, const UFortItem* ItemToConsume, const FUniqueNetIdRepl& TargetAccountId);

	UPROPERTY(BlueprintAssignable)
	FOnMCPRequestComplete OnMCPRequestComplete;

private:
	UPROPERTY()
	TWeakObjectPtr<UFortMcpContext> MCPContext;

	UPROPERTY()
	TWeakObjectPtr<UFortItem> ItemToConsume;

	UPROPERTY()
	FUniqueNetIdRepl TargetAccountId;

};

UCLASS()
class UFortAsyncAction_MCPContextUpgradeItem : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMCPRequestComplete);

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(BlueprintInternalUseOnly="true"))
	static UFortAsyncAction_MCPContextUpgradeItem* UpgradeItem(const UFortMcpContext* MCPContext, const UFortItem* ItemToUpgrade, int32 TargetLevel = -1);

	UPROPERTY(BlueprintAssignable)
	FOnMCPRequestComplete OnMCPRequestComplete;

private:
	UPROPERTY()
	TWeakObjectPtr<UFortMcpContext> MCPContext;

	UPROPERTY()
	TWeakObjectPtr<UFortItem> ItemToUpgrade;

};

UCLASS(Config=Game, MinimalAPI)
class UFortMcpContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnIssueFriendCodeComplete, bool, bSuccess, const FFriendCode&, FriendCode);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnQueryUnredeemedFriendCodesComplete, bool, bSuccess, const TArray<FFriendCode>&, FriendCodes);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSendFriendCodePlatformMessageComplete, bool, bMessageSent);

public:
	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void AbandonExpedition(const UFortExpeditionItem* Expedition);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void ApplyAlteration(UFortAlterableItem* Item, UFortAlterationItem* AlterationToApply);

	UFUNCTION(BlueprintCallable, Category="MCP Context|Mission")
	bool AreMissionRewardsAvailable();

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void CancelEpicPurchasingDisplay();

	UFUNCTION(BlueprintPure, Category="MCP Context")
	EOfferPurchaseError CanGiftOffer(const FString& OfferId, const TArray<FString>& ReceiverAccountIds, const FString& GiftWrapTemplateId, const FString& UserMessageToRecipients, const int32 PriceIndex) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	EOfferPurchaseError CanPurchaseOffer(const FString& OfferId, const int32 PriceIndex, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void CheckAffiliateName(const FString& AffiliateName, FOnCheckAffiliateNameComplete OnCheckAffiliateNameComplete);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void ClaimAllResourceCollectors();

	UFUNCTION(BlueprintCallable, Category="MCP Context|Item Cache Rewards")
	void ClaimItemCacheReward(UFortItem* ItemCache);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void ClaimResourceCollectors(const TArray<UFortCollectedResourceItem*>& CollectorTypes);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void CollectExpedition(const UFortExpeditionItem* Expedition);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void ConvertItem(const UFortItem* ItemToConvert, int32 RecipeIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="MCP Context")
	void DisplayEmptyStoreDialog() const;

	UFUNCTION(BlueprintCallable, Category="FriendCodes")
	bool DoesPlatformSupportFriendCodes();

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void DownloadEULA(const FOnDownloadEULAComplete OnCompleteDelegate);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void DownloadEULAWithKey(const FOnDownloadEULAComplete OnCompleteDelegate, const FString& Key);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortAccountItem* GetAccountItemWithDefinition(const UFortAccountItemDefinition* AccountItemDefinition) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	const FString GetAffiliateId() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	const FString GetAffiliateName() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetAllAlterations(TArray<UFortAlterationItem*>& OutAlterations, EFortAlteration::Type InAlterationType) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetAllHeroes(TArray<UFortHero*>& Result) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void GetAllResourceCollectors(TArray<UFortCollectedResourceItem*>& ResourceCollectorsOwned);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileAthena* GetAthenaProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	FTimespan GetBanDuration(const FMcpBanInfo& BanInfo) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	const FMcpBanInfo& GetBanInfo() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	FFortCampaignLoadout GetCampaignLoadoutForPlayer(FUniqueNetIdRepl MemberUniqueId) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileCommonCore* GetCommonCoreMcpProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileCommonPublic* GetCommonPublicMcpProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileCreative* GetCreativeProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetCurrentlyViewedAccountInfo(FFortPublicAccountInfo& Result) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetCurrentPhoenixLevel() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetCurrentPhoenixXp() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortHero* GetDefaultHero() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	FText GetEULAText() const;

	UFUNCTION(BlueprintPure, Category="FriendCodes")
	FText GetFriendCodeDescription(const FFriendCode& FriendCode);

	UFUNCTION(BlueprintPure, Category="FriendCodes")
	FText GetFriendCodeDisplayName(const FFriendCode& FriendCode);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetGroupXpBonusPercent() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetHeroXpBalance() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetHomeBaseInfo(FFortHomeBaseInfo& Result) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetHomeBaseInfoForPlayer(FFortHomeBaseInfo& Result, FUniqueNetIdRepl MemberUniqueId) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	FFortAthenaLoadout GetLoadoutForPlayer(FUniqueNetIdRepl MemberUniqueId) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileSubgame* GetLoadoutProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	void GetLocalAccountInfo(FFortPrivateAccountInfo& Result) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetMaxAccountLevel() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetMaxPhoenixLevel() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortMcpProfileCampaign* GetMcpProfile() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortGiftBoxItem* GetNextGiftBox() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	UFortGiftBoxItem* GetNextMessage() const;

	UFUNCTION(BlueprintPure, Category="FriendCodes")
	int32 GetNumFriendCodesToIssue(const FString& CodeType) const;

	UFUNCTION(BlueprintPure, Category="MCP Context|Item Cache Rewards")
	void GetPendingItemCacheRewards(TArray<UFortItem*>& OutItemCacheRewards) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetPersonalXpBonusPercent() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetPersonnelXpBalance() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	float GetPhoenixLevelProgressRatio() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetPhoenixXpToNextLevel() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetPlayersXPPercentContributionToLocalPlayer(const FUniqueNetIdRepl& PlayerID) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	bool GetReceivesMTXCurrency();

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetRestXpBalance() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetRestXpBonusPercent() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetSchematicXpBalance() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetUpgradeXPBalance(const EFortItemType ItemTypeToBeUpgraded) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	int32 GetXpBoostBalance() const;

	UFUNCTION(BlueprintCallable, Category="MCP Context|Mission Alert")
	void GrantPendingDifficultyIncreaseRewards();

	UFUNCTION(BlueprintCallable, Category="MCP Context|Mission Alert")
	void GrantPendingMissionAlertRewards();

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool HasEULADownloaded() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool HasEULAWithKeyDownloaded(const FString& EULAKey) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool HasMfaBeenEnabledAtSomePoint() const;

	UFUNCTION(BlueprintPure, Category="MCP Context|Mission Alert")
	bool HasPendingDifficultyIncreaseRewards() const;

	UFUNCTION(BlueprintPure, Category="MCP Context|Mission Alert")
	bool HasPendingMissionAlertRewards() const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	bool IsAllowedConversionIndex(const UFortItem* ItemToConvert, int32 RecipeIndex);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsDailyRewardAvailable(int32& OutMinutesUntilNextReward) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsLocalPlayersUniqueID(const FUniqueNetIdRepl& PlayerID) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	bool IsOfferCompletelyFree(const FString& OfferId, const int32 PriceIndex, int32 Quantity = 1);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsOwned(const FString& OfferId) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsPendingAccountTransfer(FDateTime& EstimatedCompletionMax) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsPublicFacing() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsQosProbeDone() const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsRealMoneyPurchasePending() const;

	UFUNCTION(BlueprintCallable, Category="FriendCodes")
	void IssueFriendCode(const FOnIssueFriendCodeComplete& OnCompleteDelegate);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsUserCurrentlyBanned(const FMcpBanInfo& BanInfo) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsUserOnlyCompetitiveBanned(const FMcpBanInfo& BanInfo) const;

	UFUNCTION(BlueprintPure, Category="MCP Context")
	bool IsValid(const FString& OfferId) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void MarkItemSeen(UFortAccountItem* ItemToMarkSeen);

	UFUNCTION(BlueprintCallable, Category="MCP Context|Mission")
	void OpenMissionRewards();

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void PromoteItem(const UFortItem* ItemToPromote);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void PurchaseBattlePassOffer(const TArray<FString>& OfferIdList, const FOnPurchaseBattlePassOfferComplete& Callback);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	EOfferPurchaseError PurchaseMultipleOffers(const TMap<FString, int32>& OfferIdToQuantityMap, const FOnPurchaseMultipleOffersComplete& Callback, int32 IndexInSection = -1, int32 ColumnIndexInSection = -1, int32 InnerRowIndexInSection = -1, int32 SectionIndex = -1);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	EOfferPurchaseError PurchaseOffer(const FString& OfferId, const int32 PriceIndex, const FOnPurchaseOfferComplete& Callback, int32 Quantity = 1, int32 IndexInSection = -1, bool bIsIncarousel = false, int32 IndexIncarousel = -1, int32 LengthOfCarousel = -1, int32 ColumnIndexInSection = -1, int32 InnerRowIndexInSection = -1, int32 SectionIndex = -1);

	UFUNCTION(BlueprintPure, Category="MCP Context")
	EOfferPurchaseError PurchaseOfferAsGift(const FString& OfferId, int32 Quantity, int32 PriceIndex, const TArray<FString>& ReceiverAccountIds, const FString& GiftWrapTemplateId, const FString& UserMessageToRecipients, const FOnGiftOfferComplete& OnComplete, int32 ExpectedTotalPrice = -1) const;

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void PurchaseRealMoneyCatalogEntry(const FString& OfferId, const FOnRealMoneyPurchaseComplete& Callback, int32 PriceIndex = 0, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category="FriendCodes")
	void QueryUnredeemedFriendCodes(const FOnQueryUnredeemedFriendCodesComplete& OnCompleteDelegate);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void ReadPrivacySettings(const FOnReadPrivacySettingsComplete& OnComplete);

	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(DisplayName="RecycleItem (LEGACY/DEPRECATED)"))
	void RecycleItem(const UFortItem* ItemToRecycle);

	UFUNCTION(BlueprintCallable, Category="MCP Context", meta=(DisplayName="RecycleItemBatch (LEGACY/DEPRECATED)"))
	void RecycleItemBatch(const TArray<UFortItem*>& ItemsToRecycle);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void RefundItem(const UFortAccountItem* ItemToConvert);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void RegisterForEpicPurchasingDisplay(const FOnEpicPurchasingWidgetDisplay& DisplayCallback, const FOnEpicPurchasingWidgetDismissed& DismissCallback);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void RemoveGiftBox(const UFortGiftBoxItem* GiftBoxToRemove);

	UFUNCTION(BlueprintCallable, Category="FriendCodes")
	void SendFriendCodePlatformMessage(const FFriendCode& FriendCode, const FOnSendFriendCodePlatformMessageComplete& OnCompleteDelegate);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void SetAffiliateName(const AFortPlayerController* FortPC, const FString Name, const FString SourceName, FOnAffilateNameSetAcknowledged OnAffilateNameSetAcknowledged);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void SetBansViewed(FOnBanAcknowledged OnBanAcknowledged);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void SetItemFavoriteStatus(UFortAccountItem* Item, bool bFavorite = true, bool ShouldDeferMarking = false);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	bool ShouldApplyEUText();

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	bool StartExpedition(const UFortExpeditionItem* Expedition, const float SuccessChance, const FName& SquadId, const float SquadRating, const TArray<UFortItem*>& SlottedSquadItems, const TArray<int32>& SlotIndices, const TArray<float>& ItemRatingMods, float GlobalMod);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void TransmogItem(const UFortConversionControlItemDefinition* ControlKeyItem, const TArray<UFortItem*>& ItemsToSacrifice);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void UpdatePrivacySettings(const FMcpPrivacySettings& NewSettings, const FOnUpdatePrivacySettingsComplete& OnComplete);

	UFUNCTION(BlueprintCallable, Category="MCP Context")
	void UpgradeItemRarity(const UFortItem* ItemToUpgrade);

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FHeroesChangedDelegate OnHeroesChanged;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FOnGiftBoxRemoved OnGiftBoxRemovedDelegate;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FXpBoostChangeDelegate OnXpBoostChanged;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FFounderChangeDelegate OnFounderGranted;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FDailyRewardScheduleTokenDelegate OnDailyRewardTokenGranted;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FOnPhoenixXpChangeDelegate OnPhoenixXpChanged;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FLocalAccountInfoChangedDelegate OnLocalAccountInfoChanged;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FCurrentlyViewedAccountInfoChangedDelegate OnCurrentlyViewedAccountInfoChanged;

	UPROPERTY(BlueprintReadOnly, Category="FortMcpContext")
	FMcpPrivacySettings PrivacySettings;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Mission")
	FFortMissionRewardsOpened OnMissionRewardsOpened;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Mission")
	FFortMissionRewardsOpenFailed OnMissionRewardsOpenFailed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Mission Alert")
	FFortMissionRewardsOpened OnMissionAlertRewardsOpened;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Difficulty Increase Rewards")
	FFortMissionRewardsOpened OnDifficultyIncreaseRewardsClaimed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Difficulty Increase Rewards")
	FFortDifficultyIncreaseRewardsClaimFailed OnDifficultyIncreaseRewardsClaimFailed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Item Cache Rewards")
	FFortItemCacheRewardsClaimed OnItemCacheRewardsClaimed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Item Cache Rewards")
	FFortItemCacheRewardsClaimFailed OnItemCacheRewardsClaimFailed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Mission")
	FFortResourceCollectorClaimed OnResourceCollectorClaimed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Conversion")
	FFortConversionBeginDelegate OnConversionBegin;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Conversion")
	FFortConversionCompleteDelegate OnConversionComplete;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Conversion")
	FFortUpgradeRarityBeginDelegate OnRarityUpgradeBegin;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Conversion")
	FFortUpgradeRarityCompleteDelegate OnRarityUpgradeComplete;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Conversion")
	FFortPromotionCompleteDelegate OnPromotionComplete;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Transmog")
	FFortTransmogCompleteDelegate OnTransmogComplete;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Transmog")
	FFortTransmogFailedDelegate OnTransmogFailed;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Refund")
	FFortConversionBeginDelegate OnRefundBegin;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|Refund")
	FFortConversionCompleteDelegate OnRefundComplete;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|LiveStreaming")
	FOnLiveStreamingQuestWindowStarts OnLiveStreamingQuestWindowStarts;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|LiveStreaming")
	FOnLiveStreamingQuestWindowEnds OnLiveStreamingQuestWindowEnds;

	UPROPERTY(BlueprintAssignable, Category="MCP Context|LiveStreaming")
	FOnLiveStreamingQuestWindowSelectedViewers OnLiveStreamingQuestWindowSelectedViewers;

	UPROPERTY(BlueprintAssignable, Category="MCP Context")
	FOnPurchaseOfferCompleteMulti OnOfferPurchaseComplete;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="MCP Context")
	FOnRealMoneyPurchaseCompleteMulti OnRealMoneyPurchaseComplete;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FriendCodes")
	TArray<FFriendCode> CachedFriendCodes;

	UPROPERTY(Transient)
	TArray<FOnQueryUnredeemedFriendCodesComplete> PendingFriendCodeOnCompleteDelegates;

	UPROPERTY(Config)
	double MinTimeBetweenFriendCodeRequestsSeconds;

	UPROPERTY(EditAnywhere, Config, Category="FriendCodes")
	FText FriendCodeMessageBody;

	UPROPERTY(Config)
	TArray<FString> EUCountryCodes;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGiftBoxItem>> RequestedGiftBoxesToDisplay;

	UPROPERTY()
	FOnEpicPurchasingWidgetDisplay DisplayPurchaseWidget;

	UPROPERTY()
	FOnEpicPurchasingWidgetDismissed DismissPurchaseWidget;

	UPROPERTY()
	FOnLoginFlowWidgetDisplay DisplayLoginWidget;

	UPROPERTY()
	FOnLoginFlowWidgetDismissed DismissLoginWidget;

	UPROPERTY()
	FOnLoginFlowWidgetDisplay DisplayAccountCreationWidget;

	UPROPERTY()
	FOnLoginFlowWidgetDismissed DismissAccountCreationWidget;

};

