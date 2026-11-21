// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortRuntimeOptions.h"

bool UFortRuntimeOptions::AllowInGameMatchmaking(const UObject* WorldContextObject) const
{
	return false;
}

bool UFortRuntimeOptions::AllowInGameMatchmakingOnPlaylist(const UFortPlaylistAthena* PlaylistAthena) const
{
	return false;
}

float UFortRuntimeOptions::GetDelayGiftButtonWhenMFANotEnabledSeconds() const
{
	return float();
}

const TArray<FRuntimeOptionTabStateInfo>& UFortRuntimeOptions::GetDisabledFrontendNavigationTabs() const
{
	static TArray<FRuntimeOptionTabStateInfo> Dummy;
	return Dummy;
}

bool UFortRuntimeOptions::GetDisablePurchaseHistoryScreen() const
{
	return false;
}

float UFortRuntimeOptions::GetEliminationMarkerTTL()
{
	return float();
}

bool UFortRuntimeOptions::GetEnableLFG() const
{
	return false;
}

bool UFortRuntimeOptions::GetEnableLobbyGenericLinkButton()
{
	return false;
}

bool UFortRuntimeOptions::GetEnableMainMenuSocialButton() const
{
	return false;
}

const bool UFortRuntimeOptions::GetEnableSplitWalletTextNotice() const
{
	return bool();
}

void UFortRuntimeOptions::GetExternalNewsURL(ESubGame CurrentMode, bool& bHasValidExternalURL, FString& ExternalURL, ENewsExternalURLMode& ButtonMode) const
{
}

FString UFortRuntimeOptions::GetGameVersion() const
{
	return FString();
}

float UFortRuntimeOptions::GetHPMicrophoneToastDisplaySeconds()
{
	return float();
}

FGameplayTagContainer UFortRuntimeOptions::GetInvalidCreativeItemTags(const FGameplayTagContainer& AdditionalInvalidCreativeItemTags) const
{
	return FGameplayTagContainer();
}

bool UFortRuntimeOptions::GetIsBacchusTabNavOnTop() const
{
	return false;
}

bool UFortRuntimeOptions::GetIsDiscoverInLobbyEnabled(const UWidget* ContextWidget) const
{
	return false;
}

bool UFortRuntimeOptions::GetIsDiscoverTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const
{
	return false;
}

bool UFortRuntimeOptions::GetIsDonutIdleGameEnabled()
{
	return false;
}

const bool UFortRuntimeOptions::GetIsFriendLinkEnabled() const
{
	return bool();
}

bool UFortRuntimeOptions::GetIsLibraryTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const
{
	return false;
}

bool UFortRuntimeOptions::GetIsNewSearchEnabled(const UWidget* ContextWidget) const
{
	return false;
}

bool UFortRuntimeOptions::GetIsSearchTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const
{
	return false;
}

FText UFortRuntimeOptions::GetLobbyGenericLinkButtonOverrideText()
{
	return FText();
}

FString UFortRuntimeOptions::GetLobbyGenericLinkButtonURL()
{
	return FString();
}

const int32 UFortRuntimeOptions::GetNumGameplayMessageChannels() const
{
	return int32();
}

FText UFortRuntimeOptions::GetOverrideBonusEventXpTitleText() const
{
	return FText();
}

float UFortRuntimeOptions::GetRebootChipExpirationTime() const
{
	return float();
}

float UFortRuntimeOptions::GetRebootDirectiveDisplayTime() const
{
	return float();
}

bool UFortRuntimeOptions::GetRebootShowInInventory() const
{
	return false;
}

UFortRuntimeOptions* UFortRuntimeOptions::GetRuntimeOptions()
{
	return nullptr;
}

int32 UFortRuntimeOptions::GetSearchForLinkCodesDigitThreshold(const UWidget* ContextWidget) const
{
	return int32();
}

const bool UFortRuntimeOptions::GetShowReplayTrailerButton_Athena() const
{
	return bool();
}

const TArray<FString>& UFortRuntimeOptions::GetValidAffiliateNames() const
{
	static TArray<FString> Dummy;
	return Dummy;
}

bool UFortRuntimeOptions::IsForcedIntroEnabled() const
{
	return false;
}

const bool UFortRuntimeOptions::IsGameplayMessageEnabled(const FName& MessageOwnerClassName, const FName& MessageName) const
{
	return bool();
}

bool UFortRuntimeOptions::IsGiftingDisabled() const
{
	return false;
}

bool UFortRuntimeOptions::IsHabaneroEnabled() const
{
	return false;
}

const bool UFortRuntimeOptions::IsMatchmakingKnobEnabled(const FString& KnobName) const
{
	return bool();
}

const bool UFortRuntimeOptions::IsMatchmakingKnobVisible(const FString& KnobName) const
{
	return bool();
}

bool UFortRuntimeOptions::IsPartyInProgressEnabled()
{
	return false;
}

bool UFortRuntimeOptions::IsShippingBuild() const
{
	return false;
}

bool UFortRuntimeOptions::IsShowCurrentRegionInLobbyEnabled() const
{
	return false;
}

bool UFortRuntimeOptions::IsSidebarEnabled(const UWidget* ContextWidget) const
{
	return false;
}

bool UFortRuntimeOptions::IsSitoutOptionEnabled()
{
	return false;
}

void UFortRuntimeOptions::SetEnableMainMenuSocialButton(bool NewValue)
{
}

bool UFortRuntimeOptions::ShouldShowLeaderboardPrivacySettings() const
{
	return false;
}

bool UFortRuntimeOptions::ShouldShowMultiProductItemShop(const UFortExperimentContext* ExperimentContext) const
{
	return false;
}

bool UFortRuntimeOptions::ShouldShowMultiProductLocker(const UFortExperimentContext* ExperimentContext) const
{
	return false;
}
