// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUIFeature.generated.h"

UENUM(BlueprintType)
enum class EFortUIFeature : uint8
{
	// Main Tabs

	ShowHome = 0,
	ShowPlay = 1,
	ShowCommand = 2,
	ShowHeros = 3,
	ShowSquads = 4,
	ShowArmory = 5,
	ShowLocker = 6,
	ShowMultiProductLocker = 7,
	ShowSkillTree = 8,
	ShowStore = 9,
	ShowQuests = 10,
	ShowMainStore = 11,
	ShowContextHelpMenu = 12,
	// Other UI Features

	ShowCampaign = 13,
	ShowActiveBoost = 14,
	ShowJournal = 15,
	/** If the player should see the party bar  */
	ShowPartyBar = 16,
	/** If the player sees the chat window */
	ShowChatWindow = 17,
	/** If the player should have access to the friends menu and social tools */
	ShowFriendsMenu = 18,
	/**
	* If the player should be able to select the Objectives tab.
	* NOTE not supported by NavigateToFeature
	*/
	ShowObjectives = 19,
	ShowRatingIconsInTopbar = 20,
	ShowAntiAddictionMessage = 21,
	ShowMinorShutdownMessage = 22,
	ShowHealthWarningScreen = 23,
	/** Show a stripped down simplified hud for perf */
	ShowSimplifiedHUD = 24,
	/** If the player is able to access the top bar */
	LargeHeaderFooterButtons = 25,
	// Athena features

	ShowAthenaFavoriting = 26,
	ShowAthenaItemRandomization = 27,
	ShowAthenaQuests = 28,
	ShowBattlePass = 29,
	ShowNewBattlePass = 30,
	ShowDynamicBattlePass = 31,
	ShowBattlePassFAQ = 32,
	ShowReplays = 33,
	ShowProfileStatsUI = 34,
	//This widget has been deleted - TODO: Remove?

	ShowAthenaItemShop = 35,
	ShowMultiProductItemShop = 36,
	ShowShowdown = 37,
	SpecialEventsStart = 38 UMETA(Hidden),
	ShowSpecialEvent = 39,
	// Generic, avoid using this for two events simultaneously

	ShowWinterfest = 40,
	SpecialEventsEnd = 41 UMETA(Hidden),
	ShowSpatialUI = 42,
	ShowSocial = 43,
	// Additional features

	ShowAccountBoosts = 44,
	ShowCustomerSupport = 45,
	ShowGlobalChat = 46,
	ShowEULA = 47,
	ShowEndOfZoneCinematic = 48,
	ShowOnboardingCinematics = 49,
	ShowFounderBannerIcons = 50,
	ShowCurrentRegionInLobby = 51,
	ShowPrerollLlamas = 52,
	EnableFoundersDailyRewards = 53,
	EnableMatchmakingRegionSetting = 54,
	EnableLanguageSetting = 55,
	EnableFriendCodeSetting = 56,
	EnableEarlyAccessLoadingScreenBanner = 57,
	EnableAlterationModifications = 58,
	EnableSchematicRarityUpgrade = 59,
	EnableMissionActivationVote = 60,
	EnableLtmRetrieveTheData = 61,
	EnableUpgradesVideos = 62,
	ShowPreviewTestTab = 63,
	ShowDMCustomization = 64,
	ShowDMModes = 65,
	EnableSearchTabInTopNavigationBar = 66,
	EnableDiscoverTabInTopNavigationBar = 67,
	EnableLibraryTabInTopNavigationBar = 68,
	// Start Temp UI Feature States to unblock development while finding better generic solutions for ui feature states.

	PlaceholderUIFeature1 = 69,
	PlaceholderUIFeature2 = 70,
	PlaceholderUIFeature3 = 71,
	PlaceholderUIFeature4 = 72,
	PlaceholderUIFeature5 = 73,
	// End Temp UI Feature States to unblock development while finding better generic solutions for ui feature states.

	Max_None = 74,
};

UENUM(BlueprintType)
enum class EFortUIFeatureState : uint8
{
	/** Feature is fully enabled */
	Enabled = 0,
	/** Feature is disabled but visible to the user */
	Disabled = 1,
	/** Feature is disabled and hidden from the user */
	Hidden = 2,
	/** Completely invalid state, player may still be logging in */
	Invalid = 3,
};

UENUM(BlueprintType)
enum class EFortUIFeatureStateReason : uint8
{
	/** No specific reason provided.  Generally for Enabled states.*/
	Default = 0,
	/** Disabled and Hidden reasons */
	Tutorial = 1,
	ContentInstall = 2,
	AccountRestrictions = 3,
	Platform = 4,
	SeasonOrEventNotActive = 5,
	/** Invalid reasons */
	NoPlayerController = 6,
	UnexpectedFeature = 7,
	Invalid = 8,
};

