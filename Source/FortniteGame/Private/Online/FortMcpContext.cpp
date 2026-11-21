// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMcpContext.h"

UFortAsyncAction_CalendarEventWatcher* UFortAsyncAction_CalendarEventWatcher::WatchCalendarEvent(UObject* WorldContextObject, const FString& EventToWatch)
{
	return nullptr;
}

UFortAsyncAction_CalendarMultiEventWatcher* UFortAsyncAction_CalendarMultiEventWatcher::WatchCalendarEvents(UObject* WorldContextObject, TArray<FString> EventsToWatch)
{
	return nullptr;
}

void UFortAsyncAction_InitialCalendarSyncCompleted::HandleInitialCalendarSyncCompleted()
{
}

UFortAsyncAction_InitialCalendarSyncCompleted* UFortAsyncAction_InitialCalendarSyncCompleted::InitialCalendarSyncCompleted(UObject* WorldContextObject)
{
	return nullptr;
}

UFortAsyncAction_MCPContextConsumeItem* UFortAsyncAction_MCPContextConsumeItem::ConsumeItem(const UFortMcpContext* MCPContext, const UFortItem* ItemToConsume, const FUniqueNetIdRepl& TargetAccountId)
{
	return nullptr;
}

UFortAsyncAction_MCPContextUpgradeItem* UFortAsyncAction_MCPContextUpgradeItem::UpgradeItem(const UFortMcpContext* MCPContext, const UFortItem* ItemToUpgrade, int32 TargetLevel)
{
	return nullptr;
}

void UFortMcpContext::AbandonExpedition(const UFortExpeditionItem* Expedition)
{
}

void UFortMcpContext::ApplyAlteration(UFortAlterableItem* Item, UFortAlterationItem* AlterationToApply)
{
}

bool UFortMcpContext::AreMissionRewardsAvailable()
{
	return false;
}

void UFortMcpContext::CancelEpicPurchasingDisplay()
{
}

EOfferPurchaseError UFortMcpContext::CanGiftOffer(const FString& OfferId, const TArray<FString>& ReceiverAccountIds, const FString& GiftWrapTemplateId, const FString& UserMessageToRecipients, const int32 PriceIndex) const
{
	return EOfferPurchaseError();
}

EOfferPurchaseError UFortMcpContext::CanPurchaseOffer(const FString& OfferId, const int32 PriceIndex, int32 Quantity)
{
	return EOfferPurchaseError();
}

void UFortMcpContext::CheckAffiliateName(const FString& AffiliateName, FOnCheckAffiliateNameComplete OnCheckAffiliateNameComplete)
{
}

void UFortMcpContext::ClaimAllResourceCollectors()
{
}

void UFortMcpContext::ClaimItemCacheReward(UFortItem* ItemCache)
{
}

void UFortMcpContext::ClaimResourceCollectors(const TArray<UFortCollectedResourceItem*>& CollectorTypes)
{
}

void UFortMcpContext::CollectExpedition(const UFortExpeditionItem* Expedition)
{
}

void UFortMcpContext::ConvertItem(const UFortItem* ItemToConvert, int32 RecipeIndex)
{
}

void UFortMcpContext::DisplayEmptyStoreDialog() const
{
}

bool UFortMcpContext::DoesPlatformSupportFriendCodes()
{
	return false;
}

void UFortMcpContext::DownloadEULA(const FOnDownloadEULAComplete OnCompleteDelegate)
{
}

void UFortMcpContext::DownloadEULAWithKey(const FOnDownloadEULAComplete OnCompleteDelegate, const FString& Key)
{
}

UFortAccountItem* UFortMcpContext::GetAccountItemWithDefinition(const UFortAccountItemDefinition* AccountItemDefinition) const
{
	return nullptr;
}

const FString UFortMcpContext::GetAffiliateId() const
{
	return FString();
}

const FString UFortMcpContext::GetAffiliateName() const
{
	return FString();
}

void UFortMcpContext::GetAllAlterations(TArray<UFortAlterationItem*>& OutAlterations, EFortAlteration::Type InAlterationType) const
{
}

void UFortMcpContext::GetAllHeroes(TArray<UFortHero*>& Result) const
{
}

void UFortMcpContext::GetAllResourceCollectors(TArray<UFortCollectedResourceItem*>& ResourceCollectorsOwned)
{
}

UFortMcpProfileAthena* UFortMcpContext::GetAthenaProfile() const
{
	return nullptr;
}

FTimespan UFortMcpContext::GetBanDuration(const FMcpBanInfo& BanInfo) const
{
	return FTimespan();
}

const FMcpBanInfo& UFortMcpContext::GetBanInfo() const
{
	static FMcpBanInfo Dummy;
	return Dummy;
}

FFortCampaignLoadout UFortMcpContext::GetCampaignLoadoutForPlayer(FUniqueNetIdRepl MemberUniqueId) const
{
	return FFortCampaignLoadout();
}

UFortMcpProfileCommonCore* UFortMcpContext::GetCommonCoreMcpProfile() const
{
	return nullptr;
}

UFortMcpProfileCommonPublic* UFortMcpContext::GetCommonPublicMcpProfile() const
{
	return nullptr;
}

UFortMcpProfileCreative* UFortMcpContext::GetCreativeProfile() const
{
	return nullptr;
}

void UFortMcpContext::GetCurrentlyViewedAccountInfo(FFortPublicAccountInfo& Result) const
{
}

int32 UFortMcpContext::GetCurrentPhoenixLevel() const
{
	return int32();
}

int32 UFortMcpContext::GetCurrentPhoenixXp() const
{
	return int32();
}

UFortHero* UFortMcpContext::GetDefaultHero() const
{
	return nullptr;
}

FText UFortMcpContext::GetEULAText() const
{
	return FText();
}

FText UFortMcpContext::GetFriendCodeDescription(const FFriendCode& FriendCode)
{
	return FText();
}

FText UFortMcpContext::GetFriendCodeDisplayName(const FFriendCode& FriendCode)
{
	return FText();
}

int32 UFortMcpContext::GetGroupXpBonusPercent() const
{
	return int32();
}

int32 UFortMcpContext::GetHeroXpBalance() const
{
	return int32();
}

void UFortMcpContext::GetHomeBaseInfo(FFortHomeBaseInfo& Result) const
{
}

void UFortMcpContext::GetHomeBaseInfoForPlayer(FFortHomeBaseInfo& Result, FUniqueNetIdRepl MemberUniqueId) const
{
}

FFortAthenaLoadout UFortMcpContext::GetLoadoutForPlayer(FUniqueNetIdRepl MemberUniqueId) const
{
	return FFortAthenaLoadout();
}

UFortMcpProfileSubgame* UFortMcpContext::GetLoadoutProfile() const
{
	return nullptr;
}

void UFortMcpContext::GetLocalAccountInfo(FFortPrivateAccountInfo& Result) const
{
}

int32 UFortMcpContext::GetMaxAccountLevel() const
{
	return int32();
}

int32 UFortMcpContext::GetMaxPhoenixLevel() const
{
	return int32();
}

UFortMcpProfileCampaign* UFortMcpContext::GetMcpProfile() const
{
	return nullptr;
}

UFortGiftBoxItem* UFortMcpContext::GetNextGiftBox() const
{
	return nullptr;
}

UFortGiftBoxItem* UFortMcpContext::GetNextMessage() const
{
	return nullptr;
}

int32 UFortMcpContext::GetNumFriendCodesToIssue(const FString& CodeType) const
{
	return int32();
}

void UFortMcpContext::GetPendingItemCacheRewards(TArray<UFortItem*>& OutItemCacheRewards) const
{
}

int32 UFortMcpContext::GetPersonalXpBonusPercent() const
{
	return int32();
}

int32 UFortMcpContext::GetPersonnelXpBalance() const
{
	return int32();
}

float UFortMcpContext::GetPhoenixLevelProgressRatio() const
{
	return float();
}

int32 UFortMcpContext::GetPhoenixXpToNextLevel() const
{
	return int32();
}

int32 UFortMcpContext::GetPlayersXPPercentContributionToLocalPlayer(const FUniqueNetIdRepl& PlayerID) const
{
	return int32();
}

bool UFortMcpContext::GetReceivesMTXCurrency()
{
	return false;
}

int32 UFortMcpContext::GetRestXpBalance() const
{
	return int32();
}

int32 UFortMcpContext::GetRestXpBonusPercent() const
{
	return int32();
}

int32 UFortMcpContext::GetSchematicXpBalance() const
{
	return int32();
}

int32 UFortMcpContext::GetUpgradeXPBalance(const EFortItemType ItemTypeToBeUpgraded) const
{
	return int32();
}

int32 UFortMcpContext::GetXpBoostBalance() const
{
	return int32();
}

void UFortMcpContext::GrantPendingDifficultyIncreaseRewards()
{
}

void UFortMcpContext::GrantPendingMissionAlertRewards()
{
}

bool UFortMcpContext::HasEULADownloaded() const
{
	return false;
}

bool UFortMcpContext::HasEULAWithKeyDownloaded(const FString& EULAKey) const
{
	return false;
}

bool UFortMcpContext::HasMfaBeenEnabledAtSomePoint() const
{
	return false;
}

bool UFortMcpContext::HasPendingDifficultyIncreaseRewards() const
{
	return false;
}

bool UFortMcpContext::HasPendingMissionAlertRewards() const
{
	return false;
}

bool UFortMcpContext::IsAllowedConversionIndex(const UFortItem* ItemToConvert, int32 RecipeIndex)
{
	return false;
}

bool UFortMcpContext::IsDailyRewardAvailable(int32& OutMinutesUntilNextReward) const
{
	return false;
}

bool UFortMcpContext::IsLocalPlayersUniqueID(const FUniqueNetIdRepl& PlayerID) const
{
	return false;
}

bool UFortMcpContext::IsOfferCompletelyFree(const FString& OfferId, const int32 PriceIndex, int32 Quantity)
{
	return false;
}

bool UFortMcpContext::IsOwned(const FString& OfferId) const
{
	return false;
}

bool UFortMcpContext::IsPendingAccountTransfer(FDateTime& EstimatedCompletionMax) const
{
	return false;
}

bool UFortMcpContext::IsPublicFacing() const
{
	return false;
}

bool UFortMcpContext::IsQosProbeDone() const
{
	return false;
}

bool UFortMcpContext::IsRealMoneyPurchasePending() const
{
	return false;
}

void UFortMcpContext::IssueFriendCode(const FOnIssueFriendCodeComplete& OnCompleteDelegate)
{
}

bool UFortMcpContext::IsUserCurrentlyBanned(const FMcpBanInfo& BanInfo) const
{
	return false;
}

bool UFortMcpContext::IsUserOnlyCompetitiveBanned(const FMcpBanInfo& BanInfo) const
{
	return false;
}

bool UFortMcpContext::IsValid(const FString& OfferId) const
{
	return false;
}

void UFortMcpContext::MarkItemSeen(UFortAccountItem* ItemToMarkSeen)
{
}

void UFortMcpContext::OpenMissionRewards()
{
}

void UFortMcpContext::PromoteItem(const UFortItem* ItemToPromote)
{
}

void UFortMcpContext::PurchaseBattlePassOffer(const TArray<FString>& OfferIdList, const FOnPurchaseBattlePassOfferComplete& Callback)
{
}

EOfferPurchaseError UFortMcpContext::PurchaseMultipleOffers(const TMap<FString, int32>& OfferIdToQuantityMap, const FOnPurchaseMultipleOffersComplete& Callback, int32 IndexInSection, int32 ColumnIndexInSection, int32 InnerRowIndexInSection, int32 SectionIndex)
{
	return EOfferPurchaseError();
}

EOfferPurchaseError UFortMcpContext::PurchaseOffer(const FString& OfferId, const int32 PriceIndex, const FOnPurchaseOfferComplete& Callback, int32 Quantity, int32 IndexInSection, bool bIsIncarousel, int32 IndexIncarousel, int32 LengthOfCarousel, int32 ColumnIndexInSection, int32 InnerRowIndexInSection, int32 SectionIndex)
{
	return EOfferPurchaseError();
}

EOfferPurchaseError UFortMcpContext::PurchaseOfferAsGift(const FString& OfferId, int32 Quantity, int32 PriceIndex, const TArray<FString>& ReceiverAccountIds, const FString& GiftWrapTemplateId, const FString& UserMessageToRecipients, const FOnGiftOfferComplete& OnComplete, int32 ExpectedTotalPrice) const
{
	return EOfferPurchaseError();
}

void UFortMcpContext::PurchaseRealMoneyCatalogEntry(const FString& OfferId, const FOnRealMoneyPurchaseComplete& Callback, int32 PriceIndex, int32 Quantity)
{
}

void UFortMcpContext::QueryUnredeemedFriendCodes(const FOnQueryUnredeemedFriendCodesComplete& OnCompleteDelegate)
{
}

void UFortMcpContext::ReadPrivacySettings(const FOnReadPrivacySettingsComplete& OnComplete)
{
}

void UFortMcpContext::RecycleItem(const UFortItem* ItemToRecycle)
{
}

void UFortMcpContext::RecycleItemBatch(const TArray<UFortItem*>& ItemsToRecycle)
{
}

void UFortMcpContext::RefundItem(const UFortAccountItem* ItemToConvert)
{
}

void UFortMcpContext::RegisterForEpicPurchasingDisplay(const FOnEpicPurchasingWidgetDisplay& DisplayCallback, const FOnEpicPurchasingWidgetDismissed& DismissCallback)
{
}

void UFortMcpContext::RemoveGiftBox(const UFortGiftBoxItem* GiftBoxToRemove)
{
}

void UFortMcpContext::SendFriendCodePlatformMessage(const FFriendCode& FriendCode, const FOnSendFriendCodePlatformMessageComplete& OnCompleteDelegate)
{
}

void UFortMcpContext::SetAffiliateName(const AFortPlayerController* FortPC, const FString Name, const FString SourceName, FOnAffilateNameSetAcknowledged OnAffilateNameSetAcknowledged)
{
}

void UFortMcpContext::SetBansViewed(FOnBanAcknowledged OnBanAcknowledged)
{
}

void UFortMcpContext::SetItemFavoriteStatus(UFortAccountItem* Item, bool bFavorite, bool ShouldDeferMarking)
{
}

bool UFortMcpContext::ShouldApplyEUText()
{
	return false;
}

bool UFortMcpContext::StartExpedition(const UFortExpeditionItem* Expedition, const float SuccessChance, const FName& SquadId, const float SquadRating, const TArray<UFortItem*>& SlottedSquadItems, const TArray<int32>& SlotIndices, const TArray<float>& ItemRatingMods, float GlobalMod)
{
	return false;
}

void UFortMcpContext::TransmogItem(const UFortConversionControlItemDefinition* ControlKeyItem, const TArray<UFortItem*>& ItemsToSacrifice)
{
}

void UFortMcpContext::UpdatePrivacySettings(const FMcpPrivacySettings& NewSettings, const FOnUpdatePrivacySettingsComplete& OnComplete)
{
}

void UFortMcpContext::UpgradeItemRarity(const UFortItem* ItemToUpgrade)
{
}
