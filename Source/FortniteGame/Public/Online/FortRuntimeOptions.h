// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/RuntimeOptionsBase.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"
#include "CommonInputTypes.h"
#include "Creative/FortCreativeTypes.h"
#include "Online/FortPlaylistCuratedContent.h"
#include "FortRuntimeOptions.generated.h"

class UFortExperimentContext;
class UFortMissionGenerator;
class UFortPlaylistAthena;
class UFortRuntimeOptions;
class UObject;
class UWidget;
enum class ENewsExternalURLMode : uint8;
enum class ESubGame : uint8;

UENUM()
enum class ECrucibleWhitelistOverride : uint8
{
	DoNothing = 0,
	// Don't override.

	ForceOn = 1,
	// Force crucible on for everyone.

	ForceOff = 2,
};

UENUM()
enum class EFortItemShopSection : uint8
{
	// IMPORTANT:  Do not change the order of elements in this enum. It is used as a uint8 key in UserSettings

	RMTItemOffer = 0,
	Featured = 1,
	Daily = 2,
	SpecialFeatured = 3,
	SpecialDaily = 4,
	Standalone = 5,
	CommunityChoice = 6,
	MegaBundle = 7,
	BattlePass = 8,
	MAX_None = 9 UMETA(Hidden),
};

UENUM()
enum class EFortRuntimeOptionTabState : uint8
{
	Default = 0,
	Disabled = 1,
	Hidden = 2,
};

UENUM()
enum class EFortRuntimeOptionTabStateTarget : uint8
{
	All = 0,
	Primary = 1,
	Secondary = 2,
};

UENUM(BlueprintType)
enum class ENewsExternalURLMode : uint8
{
	PatchNotes = 0,
	UpdateNotes = 1,
	MoreInformation = 2,
};

USTRUCT()
struct FAthenaItemShopSectionOverrideDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortItemShopSection Section;

	UPROPERTY()
	bool bHideTitle;

	UPROPERTY()
	bool bNoSectionTab;

};

USTRUCT()
struct FAthenaItemShopSectionPriority
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortItemShopSection Section;

	UPROPERTY()
	int32 Priority;

};

USTRUCT(BlueprintType)
struct FCreativeBetaPermissionCustomPrimaryAssetId
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionCustomPrimaryAssetId")
	FName Type;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionCustomPrimaryAssetId")
	FName Name;

};

USTRUCT(BlueprintType)
struct FCreativeBetaPermissionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	bool bUseCustomPrimaryAssetId;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig", meta=(EditCondition="!bUseCustomPrimaryAssetId"))
	FPrimaryAssetId PrimaryAssetId;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	TArray<FString> PermissionTagContainer;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	TArray<FString> EntitlementTagContainer;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig", meta=(EditCondition="bUseCustomPrimaryAssetId"))
	FCreativeBetaPermissionCustomPrimaryAssetId CustomPrimaryAssetId;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	bool bDisabledInVKPlaylists;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	bool bDisabledInCreativePlaylists;

	UPROPERTY(EditAnywhere, Config, Category="CreativeBetaPermissionConfig")
	bool bEnabled;

};

USTRUCT()
struct FCreativeIslandResource
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	float WorldRadius;

	UPROPERTY(Config)
	FName Tag;

	UPROPERTY(Config)
	int32 MaxCount;

};

USTRUCT()
struct FExperimentalBucketPercentList
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 ExperimentNum;

	UPROPERTY(Config)
	FString Name;

	UPROPERTY(Config)
	TArray<int32> BucketPercents;

	UPROPERTY(Config)
	int32 WinningBucketIndex;

};

USTRUCT()
struct FExperimentalCohortPercent
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	int32 ExperimentNum;

	UPROPERTY(Config)
	int32 CohortPercent;

	UPROPERTY(Config)
	FString Name;

};

USTRUCT()
struct FPictureInPictureInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	bool bDisableLoadingScreenPerf;

};

USTRUCT()
struct FPlayerMarkerConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool EnableHoldClickAction;

	UPROPERTY()
	float HoldTime;

	UPROPERTY()
	float DoubleClickTime;

	UPROPERTY()
	bool bShowMarkerDetailsWidget;

	UPROPERTY()
	bool bCreateMarkerActors;

	UPROPERTY()
	bool bCreateMarkerWidgets;

	UPROPERTY()
	bool bClampEnemyMarkers;

	UPROPERTY()
	bool bClampItemMarkers;

	UPROPERTY()
	bool bShowLocationMarkersOnCompass;

	UPROPERTY()
	int32 LocalPlaceableMarkersPerRate;

	UPROPERTY()
	float LocalPlaceableMarkersRechargeRate;

	UPROPERTY()
	int32 RemotePlayableMarkerSoundsPerRate;

	UPROPERTY()
	int32 RemotePlayableMarkerSoundsRechargeRate;

	UPROPERTY()
	int32 RemotePlayableMarkerSoundsByPlayerIDPerRate;

	UPROPERTY()
	int32 RemotePlayableMarkerSoundsByPlayerIDRechargeRate;

	UPROPERTY()
	int32 RemotePlayableMarkerSoundsByPlayerIDRechargeRateCap;

	UPROPERTY()
	bool EnableDoubleClickAction;

	UPROPERTY()
	bool EnableItemMarking;

	UPROPERTY()
	bool EnableInteractionMarking;

	UPROPERTY()
	float ScreenPercentageDistanceToShowMarkerInfo;

	UPROPERTY()
	float MarkerTickOptimizationCullThresholdCosTheta;

	UPROPERTY()
	float EnemyMarkerTLL;

	UPROPERTY()
	float ItemMarkerTTL;

	UPROPERTY()
	float SpecialServerMarkerTTL;

	UPROPERTY()
	float EliminationMarkerTTL;

	UPROPERTY()
	float SelfEliminationMarkerTTL;

	UPROPERTY()
	float TeammateMarkerTTL;

	UPROPERTY()
	int32 MaxItemMarkers;

	UPROPERTY()
	int32 MaxEnemyMarkers;

	UPROPERTY()
	int32 MaxEliminationMarkers;

	UPROPERTY()
	int32 MaxSpecialLocalMarkers;

	UPROPERTY()
	int32 MaxSpecialServerMarkers;

	UPROPERTY()
	int32 MaxTeammateMarkers;

};

USTRUCT()
struct FRuntimeOptionDisabledGameplayMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName MessageOwnerClassName;

	UPROPERTY(Config)
	FName MessageName;

};

USTRUCT()
struct FRuntimeOptionLocalizableStringEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Culture;

	UPROPERTY()
	FString Text;

};

USTRUCT()
struct FRuntimeOptionLocalizableString
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FRuntimeOptionLocalizableStringEntry> Entries;

};

USTRUCT(BlueprintType)
struct FRuntimeOptionPlaygroundKnobOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RuntimeOptionPlaygroundKnobOverride")
	FString KnobID;

	UPROPERTY(BlueprintReadOnly, Category="RuntimeOptionPlaygroundKnobOverride")
	bool bEnabled;

	UPROPERTY(BlueprintReadOnly, Category="RuntimeOptionPlaygroundKnobOverride")
	FString OverrideDefault;

};

USTRUCT()
struct FRuntimeOptionPlaysetPropActorPath
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FName ActorPath;

	UPROPERTY(Config)
	bool bEnabled;

};

USTRUCT()
struct FRuntimeOptionReviewPromptCriteria
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MinutesPlayed;

	UPROPERTY()
	int32 GamesPlayed;

	UPROPERTY()
	int32 BestResult;

	UPROPERTY()
	int32 KillCount;

	UPROPERTY()
	bool RequireAll;

};

USTRUCT()
struct FRuntimeOptionScheduledNotification
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FDateTime FireDateTime;

	UPROPERTY(Config)
	bool LocalTime;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString Title;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString Body;

};

USTRUCT()
struct FRuntimeOptionSpectateAPartyMemberOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PropertyName;

	UPROPERTY()
	bool bEnabled;

};

USTRUCT(BlueprintType)
struct FRuntimeOptionTabStateInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RuntimeOptionTabStateInfo")
	FName TabName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RuntimeOptionTabStateInfo")
	EFortRuntimeOptionTabState TabState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RuntimeOptionTabStateInfo")
	EFortRuntimeOptionTabStateTarget TargetPlayer;

};

USTRUCT()
struct FRuntimeOptionTournamentScoreThreshold
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 StartingPlacement;

	UPROPERTY()
	int32 PointsIncrement;

};

USTRUCT(BlueprintType)
struct FSeasonVideoIDs
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Config, Category="SeasonVideoIDs")
	FString SeasonTrailer;

	UPROPERTY(BlueprintReadOnly, Config, Category="SeasonVideoIDs")
	FString BattlePassTrailer;

	UPROPERTY(BlueprintReadOnly, Config, Category="SeasonVideoIDs")
	FString Combo;

	UPROPERTY(BlueprintReadOnly, Config, Category="SeasonVideoIDs")
	FString BattlePassHowto;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortRuntimeOptions : public URuntimeOptionsBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(DefaultToSelf="WorldContextObject", WorldContext="WorldContextObject"))
	bool AllowInGameMatchmaking(const UObject* WorldContextObject) const;

	UFUNCTION(BlueprintPure)
	bool AllowInGameMatchmakingOnPlaylist(const UFortPlaylistAthena* PlaylistAthena) const;

	UFUNCTION(BlueprintPure)
	float GetDelayGiftButtonWhenMFANotEnabledSeconds() const;

	UFUNCTION(BlueprintPure, Category="Options")
	const TArray<FRuntimeOptionTabStateInfo>& GetDisabledFrontendNavigationTabs() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetDisablePurchaseHistoryScreen() const;

	UFUNCTION(BlueprintCallable)
	float GetEliminationMarkerTTL();

	UFUNCTION(BlueprintPure)
	bool GetEnableLFG() const;

	UFUNCTION(BlueprintCallable)
	bool GetEnableLobbyGenericLinkButton();

	UFUNCTION(BlueprintPure)
	bool GetEnableMainMenuSocialButton() const;

	UFUNCTION(BlueprintPure)
	const bool GetEnableSplitWalletTextNotice() const;

	UFUNCTION(BlueprintPure, Category="Options")
	void GetExternalNewsURL(ESubGame CurrentMode, bool& bHasValidExternalURL, FString& ExternalURL, ENewsExternalURLMode& ButtonMode) const;

	UFUNCTION(BlueprintPure, Category="Options")
	FString GetGameVersion() const;

	UFUNCTION(BlueprintCallable)
	float GetHPMicrophoneToastDisplaySeconds();

	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetInvalidCreativeItemTags(const FGameplayTagContainer& AdditionalInvalidCreativeItemTags) const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsBacchusTabNavOnTop() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsDiscoverInLobbyEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsDiscoverTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintCallable)
	bool GetIsDonutIdleGameEnabled();

	UFUNCTION(BlueprintPure)
	const bool GetIsFriendLinkEnabled() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsLibraryTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsNewSearchEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool GetIsSearchTabInTopNavigationBarEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintCallable)
	FText GetLobbyGenericLinkButtonOverrideText();

	UFUNCTION(BlueprintCallable)
	FString GetLobbyGenericLinkButtonURL();

	UFUNCTION(BlueprintPure, Category="Options")
	const int32 GetNumGameplayMessageChannels() const;

	UFUNCTION(BlueprintPure, Category="Events")
	FText GetOverrideBonusEventXpTitleText() const;

	UFUNCTION(BlueprintPure)
	float GetRebootChipExpirationTime() const;

	UFUNCTION(BlueprintPure)
	float GetRebootDirectiveDisplayTime() const;

	UFUNCTION(BlueprintPure)
	bool GetRebootShowInInventory() const;

	UFUNCTION(BlueprintPure, Category="Options")
	static UFortRuntimeOptions* GetRuntimeOptions();

	UFUNCTION(BlueprintPure, Category="Options")
	int32 GetSearchForLinkCodesDigitThreshold(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintPure, Category="Options")
	const bool GetShowReplayTrailerButton_Athena() const;

	UFUNCTION(BlueprintPure)
	const TArray<FString>& GetValidAffiliateNames() const;

	UFUNCTION(BlueprintPure)
	bool IsForcedIntroEnabled() const;

	UFUNCTION(BlueprintPure, Category="Options")
	const bool IsGameplayMessageEnabled(const FName& MessageOwnerClassName, const FName& MessageName) const;

	UFUNCTION(BlueprintPure)
	bool IsGiftingDisabled() const;

	UFUNCTION(BlueprintPure)
	bool IsHabaneroEnabled() const;

	UFUNCTION(BlueprintPure, Category="Options")
	const bool IsMatchmakingKnobEnabled(const FString& KnobName) const;

	UFUNCTION(BlueprintPure, Category="Options")
	const bool IsMatchmakingKnobVisible(const FString& KnobName) const;

	UFUNCTION(BlueprintCallable, Category="Options")
	static bool IsPartyInProgressEnabled();

	UFUNCTION(BlueprintPure, Category="Options")
	bool IsShippingBuild() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool IsShowCurrentRegionInLobbyEnabled() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool IsSidebarEnabled(const UWidget* ContextWidget) const;

	UFUNCTION(BlueprintCallable, Category="Options")
	static bool IsSitoutOptionEnabled();

	UFUNCTION(BlueprintCallable)
	void SetEnableMainMenuSocialButton(bool NewValue);

	UFUNCTION(BlueprintPure)
	bool ShouldShowLeaderboardPrivacySettings() const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool ShouldShowMultiProductItemShop(const UFortExperimentContext* ExperimentContext) const;

	UFUNCTION(BlueprintPure, Category="Options")
	bool ShouldShowMultiProductLocker(const UFortExperimentContext* ExperimentContext) const;

	UPROPERTY(Config)
	TArray<FRuntimeOptionPlaysetPropActorPath> CreativePlaysetPropActorPaths;

	UPROPERTY(Config)
	bool bCanAccoladesDeviceGrantAccolades;

	UPROPERTY(Config)
	TArray<FCreativeBetaPermissionConfig> CreativeBetaPermissions;

	UPROPERTY(Config)
	bool bEnableItemDefinitionWhiteListing;

	UPROPERTY(Config)
	bool bEnableItemDefinitionWhiteListingForTransientPickups;

	UPROPERTY(Config)
	bool bEnableItemDefinitionBlockListForTransientPickups;

	UPROPERTY(Config)
	bool bAlwaysReadyUpAllLocalPlayersForMatchmaking;

	UPROPERTY(Config)
	TArray<FCreativeIslandResource> IslandResources;

	UPROPERTY(Config)
	TArray<TSoftClassPtr<UObject>> VolumeManagerBannedClasses;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 CreativeIslandDescriptionTagsMaxQty;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	TArray<FCreativeIslandDescriptionTag> CreativeIslandDescriptionTagsWhitelist;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	TArray<FString> CreativeIslandTypeBlocklist;

	UPROPERTY(Config)
	TArray<FExperimentalCohortPercent> ExperimentalCohortPercent;

	UPROPERTY(Config)
	TArray<FExperimentalBucketPercentList> ExperimentalBucketPercentList;

	UPROPERTY(Config)
	bool bEnableSpectatorUpdates;

	UPROPERTY(Config)
	bool bEnableNPCInteractionsForSpectators;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bIsTournamentMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bIsOutOfSeasonMode;

	UPROPERTY(Config)
	bool bForceBRMode;

	UPROPERTY(Config)
	bool bLoadDirectlyIntoLobby;

	UPROPERTY(Config)
	bool bAllowBPTokenRefund;

	UPROPERTY(Config)
	bool bEnableSpeculativeCreativeMMTeamSizeFix;

	UPROPERTY(Config)
	bool bUseTournamentAnonymousOverrideEnabled;

	UPROPERTY(Config)
	bool bForceDisallowAnonymousMode;

	UPROPERTY(Config)
	bool bEnableGeneratedScreenshotForPortalPreview;

	UPROPERTY(Config)
	bool bAllowLoadoutSwitchingInLobby;

	UPROPERTY(Config)
	int32 IngameMatchmakingDelaySeconds;

	UPROPERTY(Config)
	int32 NumSavedLoadouts;

	UPROPERTY(Config)
	FName TournamentPlaylistName;

	UPROPERTY(Config)
	int32 TournamentPlaylistPriorityBase;

	UPROPERTY(Config)
	float TournamentModeQueueInterval;

	UPROPERTY(Config)
	int32 MinimumAccountLevelForTournamentPlay;

	UPROPERTY(Config)
	bool bEnableManualBroadcasterStart;

	UPROPERTY(Config)
	bool bCreativeManualBroadcasterStart;

	UPROPERTY(Config)
	bool bCreativeEnableTimerForPhoneToolEnforcement;

	UPROPERTY(Config)
	bool bAutoloadRestrictedPlots;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableMyIslandDescriptionPanel;

	UPROPERTY(Config)
	bool bEnableAllRemoteClientInfos;

	UPROPERTY(Config)
	bool bEnableBuildPreviewForBroadcast;

	UPROPERTY(Config)
	bool bEnableRemoteAimSnapshotManagerForBroadcast;

	UPROPERTY(Config)
	float EsportsAnalyticsHeartbeatRate;

	UPROPERTY(Config)
	bool bUseBroadcastPostProcessing;

	UPROPERTY(Config)
	bool bUseBroadcastKillFeed;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bUseServerReplayActionFeed;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bReplayGoToTimeEnabled;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bBroadcastPipModeToggle;

	UPROPERTY(Config)
	bool bShowBroadcastPlayerEventScoreWidget;

	UPROPERTY(Config)
	bool bUseOutsideTopThreeSpectatorLeaderboard;

	UPROPERTY(Config)
	bool bReplayPauseZeroDeltas;

	UPROPERTY(Config)
	int32 CurrentSocialImportVersion;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float PawnDeathScreenDelay;

	UPROPERTY(Config)
	int32 CurrentVKImportVersion;

	UPROPERTY(Config)
	bool bEnableMassFriendImport;

	UPROPERTY(Config)
	bool bEnableSocialTab;

	UPROPERTY(Config)
	bool bEnableAthenaQuestsTab;

	UPROPERTY(Config)
	bool bAllowSocialPresenceUpdates;

	UPROPERTY(Config)
	bool bEnableToastSocialWidget;

	UPROPERTY(Config)
	bool bEnableToastSocialWidgetInStW;

	UPROPERTY(Config)
	bool bEnableINICachedSocialStatus;

	UPROPERTY(Config)
	int32 MaxINICachedSocialStatuses;

	UPROPERTY(Config)
	double MinSecondsBetweenINICachedSocialStatuses;

	UPROPERTY(Config)
	int32 NumDaysBeforeFailedImportReattempt;

	UPROPERTY(Config)
	bool bEnableSocialBanModal;

	UPROPERTY(Config)
	bool bEnableDedicatedServerSocialBanVoiceQuery;

	UPROPERTY(Config)
	bool bEnableDedicatedServerSocialBanVoiceEnforcement;

	UPROPERTY(Config)
	bool bDisplayLastOnlineTime;

	UPROPERTY(Config)
	bool bDisplayLastInteraction;

	UPROPERTY(Config)
	bool bEnableStartupSocialImport;

	UPROPERTY(Config)
	bool bEnableBladeRAF;

	UPROPERTY(Config)
	int32 MinNumberOfInvitesToShowMultFriendAcctionAccept;

	UPROPERTY(Config)
	bool bEnableStartupErebusFriendImport;

	UPROPERTY(Config)
	bool bEnableVKImport;

	UPROPERTY(Config)
	bool bEnableSteamImport;

	UPROPERTY(Config)
	FString SocialImportURI;

	UPROPERTY(Config)
	int32 DaysBetweenSocialImportPrompts;

	UPROPERTY(Config)
	int32 DaysBetweenVKImportPrompt;

	UPROPERTY(Config)
	int32 FriendImportCaptionSelection;

	UPROPERTY(Config)
	bool bEnableSplitWalletTextNotice;

	UPROPERTY(Config)
	bool bShowAthenaStoreToast;

	UPROPERTY(Config)
	bool bShowAthenaStoreToastForRolloverAlone;

	UPROPERTY(Config)
	bool bAllow3DInspectOfRMTItems;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAltUpdateFlow;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowRMTDescriptionPopup;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowJuniorEndingMovie;

	UPROPERTY(Config)
	TArray<FName> AthenaStarterGameMode;

	UPROPERTY(Config)
	bool AthenaStarterFill;

	UPROPERTY(Config)
	float PartyRichPresenceUpdateTime;

	UPROPERTY(Config)
	float PartySuggestionUpdateTimer;

	UPROPERTY(Config)
	int32 MaxPartySuggestionsToConsider;

	UPROPERTY(Config)
	bool bAllowLFG;

	UPROPERTY(Config)
	bool bAllowPartyPresenceUpdates;

	UPROPERTY(Config)
	bool bAllowJoinabilityPresenceUpdates;

	UPROPERTY(Config)
	bool bAllowGameplayPresenceUpdates;

	UPROPERTY(Config)
	bool bEnablePlaylistNameInRichPresence;

	UPROPERTY(Config)
	bool bAllowDiscordFrictionlessJoin;

	UPROPERTY(Config)
	bool bEnableInteractiveConsumables;

	UPROPERTY(Config)
	bool bEnableContextHelpMenu;

	UPROPERTY(Config)
	bool bShowAthenaItemShop;

	UPROPERTY(Config)
	bool bEnableMPItemShopTopLevelItemPreview;

	UPROPERTY(Config)
	bool bEnableMPItemShopItemPreviewOnTouch;

	UPROPERTY(Config)
	bool bEnableRufusOnePageShop;

	UPROPERTY(Config)
	bool bEnableShowdown;

	UPROPERTY(Config)
	bool bEnableTournamentMatchCaps;

	UPROPERTY(Config)
	bool bUsePlayingEventIds;

	UPROPERTY(Config)
	bool bRetryCMSLoads;

	UPROPERTY(Config)
	float RefreshScoreDelay;

	UPROPERTY(Config)
	bool bAlwaysForceTournamentLobbyPanelRefresh;

	UPROPERTY(Config)
	bool bEnableEventLeaderboards;

	UPROPERTY(Config)
	int32 NumCachedLeaderboardPages;

	UPROPERTY(Config)
	int32 MaxPagesPerLeaderboard;

	UPROPERTY(Config)
	int32 EventLeaderboardLiveRefreshTimeSeconds;

	UPROPERTY(Config)
	int32 EventLeaderboardLivePostEventRefreshWindowMinutes;

	UPROPERTY(Config)
	bool bGetLiveSessionsFromLeaderboards;

	UPROPERTY(Config)
	bool bUseServerTournamentPlacementNotifications;

	UPROPERTY(Config)
	bool bEnableCreativeTournamentStatTrackersNotifications;

	UPROPERTY(Config)
	int32 MaximumEventLengthHoursForCallout;

	UPROPERTY(Config)
	bool bEnableHypeLeaderboards;

	UPROPERTY(Config)
	bool bEnableSwapRegionsButton;

	UPROPERTY(Config)
	bool bFillCompetitivePanelFromDiscovery;

	UPROPERTY(Config)
	FString HypeLeaderboardEventId;

	UPROPERTY(Config)
	int32 HypeLeaderboardRefreshTimeSeconds;

	UPROPERTY(Config)
	bool bHypeLeaderboardIncludeFriendsTab;

	UPROPERTY(Config)
	FName CreativePlaylistName;

	UPROPERTY(Config)
	FName BattleLabPlaylistName;

	UPROPERTY(Config)
	FName CampaignPlaylistName;

	UPROPERTY(Config)
	FString EpicAccountId;

	UPROPERTY(Config)
	FString EpicCreatorName;

	UPROPERTY(Config)
	FString EpicCreatorIdAlternate;

	UPROPERTY(Config)
	TArray<FString> CreatorIdsToUseAccountNameAsDisplayName;

	UPROPERTY(Config)
	TMap<FString, FString> CreatorCodeToDisplayName;

	UPROPERTY(Config)
	bool bEnableEventScoreClamping;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowIslandExporting;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowCreativeModeratorMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bIslandExportingEnabledMCPOverride;

	UPROPERTY(Config)
	bool bEnableCreativeServerImportFriendsOption;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 MaxPlayersInCreativeServer;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 MaxPlayersInCreativeWhitelist;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowSupportACreatorOnIslandLinkScreen;

	UPROPERTY(Config)
	bool bHideServersWithZeroPlayers;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableIslandCodeEntryOnPlayerPortal;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableIslandCodeEntryOnCuratedPortal;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableIslandCodeEntryInFrontend;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float RefreshFavoriteIslandsWaitTime;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 IslandCodeLength;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bApplyCodeFormatting;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCreativePortalContentStatusUpdateMessages;

	UPROPERTY(Config)
	bool bAdvertiseBattleLabOwnerInSession;

	UPROPERTY(Config)
	bool bEnableHeatmapUIDisplayForCreative;

	UPROPERTY(Config)
	bool bEnableHeatmapUIDisplayForBattleLab;

	UPROPERTY(Config)
	bool bUseHeatmapHighPrecison;

	UPROPERTY(Config)
	bool bEnableBudgetTrackerSpatialTest;

	UPROPERTY(Config)
	bool bEnableSpatialThermometerForCreative;

	UPROPERTY(Config)
	bool bEnableSpatialSettingsForCreative;

	UPROPERTY(Config)
	bool bIsMatchmakingEnabledForPlayers;

	UPROPERTY(Config)
	float CreativeHeatmapThermometerCellSize;

	UPROPERTY(Config)
	bool bEnableThermomterCostPreviwer;

	UPROPERTY(Config)
	bool bEnableSlateVersionOfThermometer;

	UPROPERTY(Config)
	bool bEnableJoinInProgress;

	UPROPERTY(Config)
	bool bEnableSpectateAPartyMember;

	UPROPERTY(Config)
	bool bEnableJoinAndSpectate;

	UPROPERTY(Config)
	bool bEnableRequestToJoin;

	UPROPERTY(Config)
	int32 MaxNumAlivePlayersForSpectateAPartyMember;

	UPROPERTY(Config)
	int32 MaxNumPartyMemberSpectatorsPerMatch;

	UPROPERTY(Config)
	TArray<FRuntimeOptionSpectateAPartyMemberOverride> SpectateAPartyMemberPlaylistOverrides;

	UPROPERTY(Config)
	bool bEnableJoinInProgressInMatchmakingWidget;

	UPROPERTY(Config)
	bool bAnyPartyMemberAllowedToCancelMatchmakingV2;

	UPROPERTY(Config)
	bool bEnableBattlePass;

	UPROPERTY(Config)
	bool bEnableBattlePassFAQ;

	UPROPERTY(Config)
	bool bShowBattlePassBangAfterPurchase;

	UPROPERTY(Config)
	bool bShowBattlePassBangEveryLevel;

	UPROPERTY(Config)
	bool bShowBattlePassBangs;

	UPROPERTY(Config)
	bool bShowBattlePassLandingPageBangs;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bBattlePassVideoDelay;

	UPROPERTY(Config)
	bool bShowBattlePassLandingPageInGame;

	UPROPERTY(Config)
	bool bEnableAthenaFavoriting;

	UPROPERTY(Config)
	bool bShowAthenaDailyQuests;

	UPROPERTY(Config)
	bool bEnableAthenaCustomPreviewActionForCosmetics;

	UPROPERTY(Config)
	bool bEnableAthenaItemRandomization;

	UPROPERTY(Config)
	bool bEnableProfileStatTracking;

	UPROPERTY(Config)
	bool bEnableProfileStatUI;

	UPROPERTY(Config)
	bool bEnableTrickUI;

	UPROPERTY(Config)
	bool bEnableMultiplayerTricks;

	UPROPERTY(Config)
	bool bCreateEpicAccountPinGrantDisabled;

	UPROPERTY(Config)
	bool bLoginEpicWeb;

	UPROPERTY(Config)
	bool bEnableClientSettingsSaveToCloud;

	UPROPERTY(Config)
	bool bEnableClientSettingsSaveToDisk;

	UPROPERTY(Config)
	bool bEnableClientSettingsRestoreInputPresets;

	UPROPERTY(Config)
	int32 bDedServerEventServiceDownloadTryCount;

	UPROPERTY(Config)
	int32 TournamentRefreshPayoutMaxRateSeconds;

	UPROPERTY(Config)
	int32 TournamentRefreshEventsMaxRateSeconds;

	UPROPERTY(Config)
	int32 TournamentRefreshPlayerMaxRateSeconds;

	UPROPERTY(Config)
	float TournamentHUDPointCounterDelay;

	UPROPERTY(Config)
	int32 MaxNumDisplayNamesOnLiveGameList;

	UPROPERTY(Config)
	int32 LiveGameListInitialLimit;

	UPROPERTY(Config)
	int32 LiveGameListQueryIncreaseAmount;

	UPROPERTY(Config)
	bool bEnableLiveGamesScreen;

	UPROPERTY(Config)
	bool bLiveGameTimeDurationVisible;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableFlagSelection;

	UPROPERTY(Config)
	FString DefaultFlagRegionId;

	UPROPERTY(Config)
	FString MixedNationTeamFlagRegionId;

	UPROPERTY(Config)
	TArray<FString> DisabledFlagSelections;

	UPROPERTY(Config)
	int32 FlagChangeCooldownDays;

	UPROPERTY(Config)
	bool bEnableEventServicePayouts;

	UPROPERTY(Config)
	bool bLiveGamesClientAnalyticsEnabled;

	UPROPERTY(Config)
	float MinimumWaitTimeToRequestNewShowdownScoreForWindow;

	UPROPERTY(Config)
	int32 EventServicePayoutRefreshRateSeconds;

	UPROPERTY(Config)
	int32 EventServicePayoutRefreshSpreadSeconds;

	UPROPERTY(Config)
	float BundleLoaderWidgetTimerInterval;

	UPROPERTY(Config)
	TArray<FString> CancelledEvents;

	UPROPERTY(Config)
	int32 SecondsShowStartingMatchMessageForScheduledMMEvents;

	UPROPERTY(Config)
	bool bEnableMatchAbandonProcess;

	UPROPERTY(Config)
	float MatchAbandonTimeout;

	UPROPERTY(Config)
	bool bEnableMultidivisionTournamentEventIdQuorum;

	UPROPERTY(Config)
	double CloudSaveIntervalConfig;

	UPROPERTY(Config)
	bool bSaveToCloudOnMapLoad;

	UPROPERTY(Config)
	bool bSaveToCloudOnSuspend;

	UPROPERTY(Config)
	bool bSaveToCloudOnDeactivate;

	UPROPERTY(Config)
	bool bSaveToCloudOnTerminate;

	UPROPERTY(Config)
	bool bSaveToCloudOnExit;

	UPROPERTY(Config)
	bool bSaveToCloudOnLogout;

	UPROPERTY(Config)
	double GiftNotificationRefreshTimer;

	UPROPERTY(Config)
	bool bEnableUndoPurchase;

	UPROPERTY(Config)
	bool bMoveUndoToBottomBar;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowStoreBanner;

	UPROPERTY(Config)
	float InGameStoreUpdateChance;

	UPROPERTY(Config)
	bool bEnableReplayBrowser;

	UPROPERTY(Config)
	TArray<uint32> ReplayCompatAllowList;

	UPROPERTY(Config)
	bool bAllowAllReplays;

	UPROPERTY(Config)
	bool bEnableReplayRecording;

	UPROPERTY(Config)
	bool bEnableLargeTeamReplayRecording;

	UPROPERTY(Config)
	bool bEnableCreativeModeReplayRecording;

	UPROPERTY(Config)
	bool bEnablePlaygroundModeReplayRecording;

	UPROPERTY(Config)
	bool bEnableSplitscreenReplayRecording;

	UPROPERTY(Config)
	bool bEnableReplayDemoSplitting;

	UPROPERTY(Config)
	bool bStableReplayPlayback;

	UPROPERTY(Config)
	bool bEnableHearingAccessibility;

	UPROPERTY(Config)
	bool bDisableSpatializationInsteadOfMutingWhenHearingAccessibilityEnabled;

	UPROPERTY(Config)
	bool bAllowVisualizingSoundsWithStereoAudio;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableWeaponAMetaSoundTest;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableNPCMusicMetaSoundTest;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableBlockPartyMetaSoundTest;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableValetAudioUpgrade;

	UPROPERTY(Config)
	bool bDisableGifting;

	UPROPERTY(Config)
	bool bImmediateClaimOfEmote;

	UPROPERTY(Config)
	bool bForceRestrictChat;

	UPROPERTY(Config)
	int32 GiftLimitAmount;

	UPROPERTY(Config)
	bool bBattlePassGiftingEmergencyDisable;

	UPROPERTY(Config)
	bool bEnableBattlePassGiftingButton;

	UPROPERTY(Config)
	bool bEnableBattlePassGiftingButtonTokenOnly;

	UPROPERTY(Config)
	bool bShowBPGiftBoxPopup;

	UPROPERTY(Config)
	float EndBattleRoyalUpdateDelay;

	UPROPERTY(Config)
	float LightswitchDownLoginDelay;

	UPROPERTY(Config)
	bool bShowStatusButtonOnWaitingRoomScreen;

	UPROPERTY(Config)
	bool bInvertMotionOnUnattachedSwitchControllers;

	UPROPERTY(Config)
	bool bDisableTouchLookVelocityScaling;

	UPROPERTY(Config)
	bool bDisablePurchaseHistoryScreen;

	UPROPERTY(Config)
	bool bEnableRedeemOfflinePurchasesToasts;

	UPROPERTY(Config)
	bool bAllowProcessedPayoutsToRefreshProfile;

	UPROPERTY(Config)
	float TouchAimAssistStrengthScalar;

	UPROPERTY(Config)
	bool bDisableTouchAimAssistAutoTracking;

	UPROPERTY(Config)
	bool bProcessGamepadInputOnMobile;

	UPROPERTY(Config)
	bool bMobileForceGamepadHUDWhenAttached;

	UPROPERTY(Config)
	bool bDisableLegacyControls;

	UPROPERTY(Config)
	bool bFixAimAssistDeadzoneExploit;

	UPROPERTY(Config)
	ECrucibleWhitelistOverride CrucibleWhitelistOverride;

	UPROPERTY(Config)
	bool bDisableCrucibleStatUpload;

	UPROPERTY(Config)
	bool bDisableCrucibleStatDownload;

	UPROPERTY(Config)
	bool bDisableCrucibleGlobalLeaderboards;

	UPROPERTY(Config)
	bool bDisableCrucibleFriendLeaderboards;

	UPROPERTY(Config)
	bool bDisableCrucibleAnalyticsEvents;

	UPROPERTY(Config)
	bool bDisableCrucibleDestroyDeadBots;

	UPROPERTY(Config)
	bool bDisableCrucibleForcedGC;

	UPROPERTY(Config)
	bool bDisableCrucibleLeaderboardFilterText;

	UPROPERTY(Config)
	bool bDisableCrucibleLeaderboardSwitching;

	UPROPERTY(Config)
	bool bCrucibleLockToPlatform;

	UPROPERTY(Config)
	bool bCrucibleSendStatsEndOfSession;

	UPROPERTY(Config)
	bool bCrucibleSendStatsEndOfSessionOnShutdownEvent;

	UPROPERTY(Config)
	int32 CrucibleMinValidStatScoreMilliseconds;

	UPROPERTY(Config)
	int32 CrucibleLeaderboardFriendQueryMaxSize;

	UPROPERTY(Config)
	bool bCrucibleLeaderboardEnableDisplayNameIcons;

	UPROPERTY(Config)
	bool bEnableFortLeaderboardHelperDisplayNonPlatformNames;

	UPROPERTY(Config)
	bool bEnableFortLeaderboardHelperConsolePlatformNameSearch;

	UPROPERTY(Config)
	bool bEnableFortLeaderboardHelperConsoleDisplayNameFallback;

	UPROPERTY(Config)
	bool bDisableCollectionStatsUpload;

	UPROPERTY(Config)
	bool bDisableCollectionStatsDownload;

	UPROPERTY(Config)
	TArray<FString> DisableCollectionStatsDownloadForCategories;

	UPROPERTY(Config)
	int32 CollectionStatsFriendQueryMaxSize;

	UPROPERTY(Config)
	bool bSoundIndicatorsAlwaysEnabled;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bSoundIndicatorsEnabledForTeammates;

	UPROPERTY(Config)
	bool bSoundIndicatorsPooled;

	UPROPERTY(Config)
	int32 SoundIndicatorMaxNum;

	UPROPERTY(Config)
	int32 TencentDefaultBookStatSeason;

	UPROPERTY(Config)
	bool bEquipFirstWeaponOnMobile;

	UPROPERTY(Config)
	bool bClearLastFireOnAbilityFailed;

	UPROPERTY(Config)
	bool bUsePrototypeSubGameLoadingScreen;

	UPROPERTY(Config)
	bool bForcePrototypeLoadingScreenScaling;

	UPROPERTY(Config)
	float ShowEliminationDistanceOver;

	UPROPERTY(Config)
	float FadeOutTeamIndicatorsAfter;

	UPROPERTY(Config)
	float FadeOutNPCEnemyIndicatorsAfter;

	UPROPERTY(Config)
	float FadeOutEnemyIndicatorsAfter;

	UPROPERTY(Config)
	float FadeOutWorldItemIndicatorsAfter;

	UPROPERTY(Config)
	float FadeOutHardCoreBeaconIndicatorsAfter;

	UPROPERTY(Config)
	float MapIndicatorTouchClearDistance;

	UPROPERTY(Config)
	FVector2D MapIndicatorOffset;

	UPROPERTY(Config)
	float AthenaMapZoomMax;

	UPROPERTY(Config)
	float BacchusMapIndicatorSizeMultiplier;

	UPROPERTY(Config)
	float AthenaMapZoomSpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAthenaMapMapIconsFlowEnabled;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float WaitTimeBeforeShowingNewModeViolator;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString FriendCodeShareWarningMessage;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString PlatformPlayAllowedErrorMessage;

	UPROPERTY(Config)
	bool bOnlyShareURLWithNoMessage;

	UPROPERTY(Config)
	bool bExcludeURLInShareMessage;

	UPROPERTY(Config)
	bool bEnableContextTutorial;

	UPROPERTY(Config)
	bool bDebugForcePlayerSurveys;

	UPROPERTY(Config)
	bool bFeedbackTextShown;

	UPROPERTY(Config)
	bool bEnableBadMatchPopup;

	UPROPERTY(Config)
	int32 BadMatchIncidentThreshold;

	UPROPERTY(Config)
	float BadConnectionUpdateTime;

	UPROPERTY(Config)
	int32 BadMatchPopupRecallInterval;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString AthenaCodeOfConductURL;

	UPROPERTY(Config)
	FString KairosCommunityRulesURL;

	UPROPERTY(Config)
	FString BacchusFriendCodeShareURL;

	UPROPERTY(Config)
	FString CreateAccountURL;

	UPROPERTY(Config)
	FString GooglePlayRatingURL;

	UPROPERTY(Config)
	FString LinkAccountURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString AccountMergeMoreInfoURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableFactionTechScreen;

	UPROPERTY(Config)
	bool bRequireFactionChoiceOnInfiltrationPlay;

	UPROPERTY(Config)
	int32 TotalPlayerTechLevelsToShow;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString SupportURL;

	UPROPERTY(Config)
	FString CheckStatusURL;

	UPROPERTY(Config)
	FString iOSAppStoreURL;

	UPROPERTY(Config)
	FString TurnOnMfaURL;

	UPROPERTY(Config)
	FString ArenaResetTime;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString ListOfCreatorsURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowCodeRedemptionInSubgameSelect;

	UPROPERTY(Config)
	bool bEnableAutomaticMOTD;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowMOTDInLobby;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bMOTDSameNewsForCreative;

	UPROPERTY(Config)
	bool bSkipSubgameSelect;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	ENewsExternalURLMode BRUpdatesURLMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString BRUpdatesURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	ENewsExternalURLMode STWUpdatesURLMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString STWUpdatesURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString GiftingInfoURL;

	UPROPERTY(Config)
	FString PrivacyPolicyURL;

	UPROPERTY(Config)
	FString FanContentPolicyURL;

	UPROPERTY(Config)
	FString TermsOfServiceURL;

	UPROPERTY(Config)
	int32 GuardianChallengeLengthDays;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableContentControls;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString ContentControlsMoreInfoURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString ContentControlsForgotPinURL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString ContentControlsVerifyEmailURL;

	UPROPERTY(Config)
	bool bEnableContentControlsPlaytimeReporting;

	UPROPERTY(Config)
	bool bEnableContentControlsPurchaseReporting;

	UPROPERTY(Config)
	bool bContentControlsViewUGCEnabled;

	UPROPERTY(Config)
	int32 ParentalControlsPinLength;

	UPROPERTY(Config)
	int32 InitializeKWSWithCCSSettingsCount;

	UPROPERTY(Config)
	int32 TargetDeltaUpdateKWSWithCCSSettings;

	UPROPERTY(Config)
	int32 ShowSettingReviewModal;

	UPROPERTY(Config)
	TArray<FString> SettingsToAddToReviewModal;

	UPROPERTY(Config)
	TArray<FString> SettingsToAddToVoiceReportIntroModal;

	UPROPERTY(Config)
	int32 ShowParentalControlsUpdatedModal;

	UPROPERTY(Config)
	int32 ShowEnterCabinModeModal;

	UPROPERTY(Config)
	bool bEnableSqueegee;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 MaxNumItemsInCreativeChests;

	UPROPERTY(Config)
	int32 MaxStackSizeForCreativeResources;

	UPROPERTY(Config)
	int32 MaxStreamerMatchmakingDelay;

	UPROPERTY(Config)
	bool bEnableHiddenMatchmakingDelay;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString TencentStoreDetailsURL;

	UPROPERTY(Config)
	int32 PSALoadingScreenPercentChance;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString StwDownloadLauncherOption;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString OverrideDefaultBonusXpEventTitleString;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString XBLDisableText;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString PSNDisableText;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString SwitchDisableText;

	UPROPERTY(Config)
	FRuntimeOptionReviewPromptCriteria ReviewPromptCriteria;

	UPROPERTY(Config)
	bool bDisableAllKnobs;

	UPROPERTY(Config)
	bool bDisableAllGameplayMessages;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableMatchmakingKnobs;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableMinigameKnobs;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableGameOptionKnobs;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableCreativeSACFeature;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableAffiliateFeature;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bUseHotfixedAffiliateNamesArray;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnablePrerollLlamas;

	UPROPERTY(Config)
	bool bEnableSubregionNetworkAccelerators;

	UPROPERTY(Config)
	TArray<FString> DisabledNetworkAcceleratedSubregions;

	UPROPERTY(Config)
	TArray<FString> AdvertisedNetworkAcceleratedSubregions;

	UPROPERTY(Config)
	bool bShowAccountItemWarningForVaultThreshold;

	UPROPERTY(Config)
	int32 DaysBetweenAccountItemWarnings;

	UPROPERTY(Config)
	float VaultLimitThresholdForAccountItemWarning;

	UPROPERTY(Config)
	bool bShowAccountItemWarningForItemCount;

	UPROPERTY(Config)
	int32 AlwaysWarnAccountItemCount;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 DurianMinPlayerCountToTriggerBackfillOn;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 DurianMaxPlayerCountToTriggerBackfillOff;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool DurianEnableBackfillControl;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool DurianDoDebugOutput;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float DurianTimeRemainingToStopBackfill;

	UPROPERTY(Config)
	FDateTime DPlusVBuckPromoStart;

	UPROPERTY(Config)
	FDateTime DPlusVBuckPromoEnd;

	UPROPERTY(Config)
	TArray<FString> CountryCodesForDPlusVBuckOverride;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FDateTime RockyRidgeStart;

	UPROPERTY(Config)
	TArray<FRuntimeOptionTournamentScoreThreshold> SoloTournamentScoreThresholds;

	UPROPERTY(Config)
	TArray<FRuntimeOptionTournamentScoreThreshold> DuoTournamentScoreThresholds;

	UPROPERTY(Config)
	TArray<FRuntimeOptionTournamentScoreThreshold> SquadsTournamentScoreThresholds;

	UPROPERTY(Config)
	float PickingInteractDistance;

	UPROPERTY(Config)
	float PickingHighlightMovementUpdateDist;

	UPROPERTY(Config)
	float PickingHighlightUpdateTime;

	UPROPERTY(Config)
	float PickingTime;

	UPROPERTY(Config)
	float AutoPickingInteractDistanceFactor;

	UPROPERTY(Config)
	float AutoOpenDoorInputMagnitude;

	UPROPERTY(Config)
	float AutoOpenDoorTraceDistance;

	UPROPERTY(Config)
	bool bAutofireEnabled;

	UPROPERTY(Config)
	bool bShowXPWidgets;

	UPROPERTY(Config)
	bool bShowAccoladesListWidget;

	UPROPERTY(Config)
	bool bEnableInGameMatchmaking;

	UPROPERTY(Config)
	bool bUseNewFlowIngameMatchmaking;

	UPROPERTY(Config)
	bool bToggleIGMAnalytics;

	UPROPERTY(Config)
	TArray<FString> WhitelistedInGameMatchmakingRegions;

	UPROPERTY(Config)
	TArray<FString> WhitelistedInGameMatchmakingSubRegions;

	UPROPERTY(Config)
	TArray<FString> BlacklistedInGameMatchmakingSubRegions;

	UPROPERTY(Config)
	TArray<FName> BlacklistedInGameMatchmakingPlaylists;

	UPROPERTY(Config)
	TArray<FName> SubRegionWhitelistedInGameMatchmakingPlaylists;

	UPROPERTY(Config)
	bool bAllowPreserveSquad;

	UPROPERTY(Config)
	bool bAllowPreserveSquadMemberVoting;

	UPROPERTY(Config)
	bool bKeepPlayingTogether;

	UPROPERTY(Config)
	bool bPartyRift;

	UPROPERTY(Config)
	bool bAutofireUsesComponent;

	UPROPERTY(Config)
	bool bAutofireUsesAutoaimTarget;

	UPROPERTY(Config)
	bool bHoldToFireOnAutofireTarget;

	UPROPERTY(Config)
	float DefaultAutofireRange;

	UPROPERTY(Config)
	float AutofireExtraTrackingRange;

	UPROPERTY(Config)
	bool bServerNetDriverAnalytics;

	UPROPERTY(Config)
	bool bClientNetDriverAnalytics;

	UPROPERTY(Config)
	bool bDisableReplicationGraph;

	UPROPERTY(Config)
	float BRServerMaxTickRate;

	UPROPERTY(Config)
	float DoubleTapOnEndTouchTime;

	UPROPERTY(Config)
	float DoubleTapOnStartTouchTime;

	UPROPERTY(Config)
	float DoubleTapDistance;

	UPROPERTY(Config)
	float SingleTapDistance;

	UPROPERTY(Config)
	float TouchMoveStickRadius;

	UPROPERTY(Config)
	float TouchMoveStickRadiusTargeting;

	UPROPERTY(Config)
	float TouchMoveStickRadiusScoped;

	UPROPERTY(Config)
	float TouchMoveStickRadiusDriving;

	UPROPERTY(Config)
	float AutorunLockZoneOffset;

	UPROPERTY(Config)
	float AutorunLockZoneDelay;

	UPROPERTY(Config)
	float MoveOriginResetTime;

	UPROPERTY(Config)
	float MoveOriginResetDistance;

	UPROPERTY(Config)
	float MoveOriginFollowDistance;

	UPROPERTY(Config)
	bool bDisableTouchLookInertia;

	UPROPERTY(Config)
	float RotateInertiaMultiplier;

	UPROPERTY(Config)
	float RotateInertiaMinTime;

	UPROPERTY(Config)
	float RotateInertiaMinLength;

	UPROPERTY(Config)
	float RotateInertiaMinMagnitude;

	UPROPERTY(Config)
	int32 RotateInertiaNumAveragedTouches;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bTouchQuickbarTapToLockEnabled;

	UPROPERTY(Config)
	bool bTouchInteractInUIAvailable;

	UPROPERTY(Config)
	bool bTouchInteractInUIForced;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDLayoutTool;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDLayoutCloudSave;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDLayoutToolPanZoom;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableMobileHUDV2;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDLayoutToolV2;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDLayoutToolV2_GridSnap;

	UPROPERTY(Config)
	int32 HUDLayoutTool_DefaultGridSnapSliderValue;

	UPROPERTY(Config)
	bool bHUDLayoutTool_GridSnapEnabledByDefault;

	UPROPERTY(Config)
	bool bEnableGFNSettingEditCondition;

	UPROPERTY(Config)
	float AthenaExternalRichPresenceDelayTimeSeconds;

	UPROPERTY(Config)
	bool bEnableExternalPresenceAthenaPlayersRemain;

	UPROPERTY(Config)
	float MinimumTimeBetweenConsolePresenceUpdates;

	UPROPERTY(Config)
	float MinimumTimeBetweenMCPPresenceUpdates;

	UPROPERTY(Config)
	int32 PreloadMapUIDestructionVersion;

	UPROPERTY(Config)
	int32 TimeBetweenStorePatchCheckRequestsSeconds;

	UPROPERTY(Config)
	bool bInviteUIDisabled;

	UPROPERTY(Config)
	bool bEnableInGameMipsAnalyticsReporting;

	UPROPERTY(Config)
	float SecondsBetweenTextureStatsGathering;

	UPROPERTY(Config)
	int32 CurrentMipsCapExperimentVersion;

	UPROPERTY(Config)
	bool bEnableQualitySelectionScreen;

	UPROPERTY(Config)
	bool bEnableQualityLevelSelectScreenTimer;

	UPROPERTY(Config)
	bool bEnableDownloadAnalyticsReporting;

	UPROPERTY(Config)
	bool bEnableDownloadHeartbeat;

	UPROPERTY(Config)
	float DownloadHeartbeatIntervalInSeconds;

	UPROPERTY(Config)
	bool bEnableShowSettingsChangeAcknowledgementScreen;

	UPROPERTY(Config)
	bool bEnableFriendsListButton;

	UPROPERTY(Config)
	bool bForceDisableCrossplatformSquadFill;

	UPROPERTY(Config)
	bool bRequireCrossplayOptIn;

	UPROPERTY(Config)
	bool bUseAccountCrossplayPermissions;

	UPROPERTY(Config)
	bool bSingleCrossplayOptInPrompt;

	UPROPERTY(Config)
	bool bImmediatelyDisplayCrossplayOptIn_STW;

	UPROPERTY(Config)
	bool bImmediatelyDisplayCrossplayOptIn_BR;

	UPROPERTY(Config)
	bool bCrossplayOptInByDefault;

	UPROPERTY(Config)
	bool bShowIconForSamePlatformPlayers;

	UPROPERTY(Config)
	bool bObscuredPlatformIcons;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableChatWidget;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowVoiceChatSettings;

	UPROPERTY(Config)
	bool bUseClientSettingsForControllerImage;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableMobileControlHelp;

	UPROPERTY(Config)
	bool bPartyInProgress;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHiddenPlayersList;

	UPROPERTY(Config)
	bool bEnableSocialProfile;

	UPROPERTY(Config)
	bool bEnableLFG;

	UPROPERTY(Config)
	int32 HotTamaleWithVeggiesEditorTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 HotTamaleWithVeggiesTabTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 RebootRallyTooltipDurationSeconds;

	UPROPERTY(Config)
	bool HotTamaleWithVeggiesHidesLastInteraction;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName HotTamaleWithVeggiesStringTable;

	UPROPERTY(Config)
	bool bEnableViewModelDrivenUserListEntry;

	UPROPERTY(Config)
	int32 SidebarSupervisedSettingsTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 SidebarVoiceChatPanelSupervisedSettingsTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 ContentRatingTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 UnlockedContentTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 CreativeUnlockTooltipDurationSeconds;

	UPROPERTY(Config)
	int32 SidebarVoiceRepTooltipDuration;

	UPROPERTY(Config)
	bool bEnableSocialNotificationSetting;

	UPROPERTY(Config)
	bool bShowPartyJoinabilityInSettingsAcount;

	UPROPERTY(Config)
	bool bSkipCCSDownloadUser;

	UPROPERTY(Config)
	bool bShowHideSocialNamesSetting;

	UPROPERTY(Config)
	bool bShowSquadMembersNamesVisibilityInParentalControls;

	UPROPERTY(Config)
	bool bShouldAthenaQueryRecentPlayers;

	UPROPERTY(Config)
	bool bEnableAwayFriendsList;

	UPROPERTY(Config)
	bool bEnableRecentPlayerList;

	UPROPERTY(Config)
	bool bEnableSuggestedFriendList;

	UPROPERTY(Config)
	bool bEnableBlockedList;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableFriendListInGame;

	UPROPERTY(Config)
	bool bPushJIPInfoToPlatformPresence;

	UPROPERTY(Config)
	bool bEnableStWInZonePrivacyChange;

	UPROPERTY(Config)
	bool bEnableSitoutOption;

	UPROPERTY(Config)
	bool bEnableSitoutOption_STW;

	UPROPERTY(Config)
	bool bEnableSocialPanelLeaveParty;

	UPROPERTY(Config)
	bool bEnableMainMenuLeaveParty;

	UPROPERTY(Config)
	int32 MinUSSNameLength;

	UPROPERTY(Config)
	bool bEnableNewSocialPlayerAvatars;

	UPROPERTY(Config)
	bool bEnablePreferredVoiceChannel;

	UPROPERTY(Config)
	bool bEnablePastelDeNata;

	UPROPERTY(Config)
	FName PastelDeNataModuleName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString VRRFaq;

	UPROPERTY(Config)
	float AudioKSTimeoutValue;

	UPROPERTY(Config)
	float AudioUploadTimeoutValue;

	UPROPERTY(Config)
	bool bEnableNickname;

	UPROPERTY(Config)
	bool bAllowNicknameEmoji;

	UPROPERTY(Config)
	TArray<FString> NicknameEmojiBlacklist;

	UPROPERTY(Config)
	bool bNicknameInFront;

	UPROPERTY(Config)
	bool bShowAccountBoosts;

	UPROPERTY(Config)
	bool bShowCustomerSupport;

	UPROPERTY(Config)
	bool bEnableChannelChangePopup;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableVoiceSpeakerWidget;

	UPROPERTY(Config)
	bool bEnableSpeakerWidgetZonePerfMode;

	UPROPERTY(Config)
	bool bShowVoiceIndicatorsWhileLoading;

	UPROPERTY(Config)
	bool bEnableVoiceChannelSelectionUI;

	UPROPERTY(Config)
	bool bEnableGlobalChat;

	UPROPERTY(Config)
	bool bEnableAllTabInChat;

	UPROPERTY(Config)
	bool bEnableEULA;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableEndOfZoneCinematic;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableOnboardingCinematics;

	UPROPERTY(Config)
	TArray<FName> VideoDisplayDataBlacklist;

	UPROPERTY(Config)
	bool bShowFounderBannerIcons;

	UPROPERTY(Config)
	bool bShowCurrentRegionInLobby;

	UPROPERTY(Config)
	bool bEnableFoundersDailyRewards;

	UPROPERTY(Config)
	bool bEnableMatchmakingRegionSetting;

	UPROPERTY(Config)
	bool bEnableReadyupButtonWhileSittingout;

	UPROPERTY(Config)
	bool bEnableEulaRequiredTournaments;

	UPROPERTY(Config)
	bool bEnableMFARequiredTournaments;

	UPROPERTY(Config)
	bool bAllTournamentsRequireMFA;

	UPROPERTY(Config)
	bool bSpectatorBroadcasterSkipMfaEulaCheck;

	UPROPERTY(Config)
	bool bEnableLiveSpectatorEulaCheck;

	UPROPERTY(Config)
	FString LiveSpectatorEulaKey;

	UPROPERTY(Config)
	bool bEnableNaviationToChat;

	UPROPERTY(Config)
	bool bEnableLanguageSetting;

	UPROPERTY(Config)
	bool bEnableFriendCodeSetting;

	UPROPERTY(Config)
	bool bEnableEarlyAccessLoadingScreenBanner;

	UPROPERTY(Config)
	bool bClientIgnoreIsTournamentCheck;

	UPROPERTY(Config)
	int32 CampaignMatchEndRetryCount;

	UPROPERTY(Config)
	uint8 MinJoinablePartySize;

	UPROPERTY(Config)
	uint8 MinJoinablePartyFriends;

	UPROPERTY(Config)
	int32 StWTutorialDownloadAttempts;

	UPROPERTY(Config)
	bool bShopPurchaseConfirmation;

	UPROPERTY(Config)
	bool bShopPurchaseConfirmationJapanPS4;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bToyMessagingEnabled;

	UPROPERTY(BlueprintReadOnly, Category="FortRuntimeOptions")
	bool bAllowAccessToAllEmotesForTesting;

	UPROPERTY(BlueprintReadOnly, Category="FortRuntimeOptions")
	bool bAllowAccessToStWHeroOutfitsAndBackblingForTesting;

	UPROPERTY(Config)
	bool bRequireEmoteOwnershipInPIE;

	UPROPERTY(Config)
	bool bEnableSTWLootDrops;

	UPROPERTY(Config)
	bool bEnableSTWContainerItemCacheDrops;

	UPROPERTY(Config)
	bool bEnableSTWEnemyItemCacheDrops;

	UPROPERTY(Config)
	bool bEnableHoldToPickupUI;

	UPROPERTY(Config)
	bool bSkipTrailerMovie;

	UPROPERTY(Config)
	bool bAlwaysPlayTrailerMovie;

	UPROPERTY(Config)
	bool bHideUnaffordableMtxPurchases;

	UPROPERTY(Config)
	bool bDisableCTAInMtxStoreSelection;

	UPROPERTY(Config)
	bool bAthenaFrontEndUsePushPopMTXStore;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bHidePlusOnVbucksButton;

	UPROPERTY(Config)
	bool bAllowXboxStwAccessDuringLiveStoreOutage;

	UPROPERTY(Config)
	bool bShowReplayTrailerButton_Athena;

	UPROPERTY(Config)
	bool bEnableAlterationModification;

	UPROPERTY(Config)
	bool bEnableSchematicRarityUpgrade;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableMissionActivationVote;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableLtmRetrieveTheData;

	UPROPERTY(Config)
	bool bEnableUpgradesVideos;

	UPROPERTY(Config)
	bool bEnableExternalRichPresence;

	UPROPERTY(Config)
	bool bShowEnableMFAModalAtStartupAthena;

	UPROPERTY(Config)
	bool bShowEnableMFAModalAtStartupSTW;

	UPROPERTY(Config)
	bool bEnableAIBuildingHitFX;

	UPROPERTY(Config)
	int32 LevelToStartShowingMFAModal;

	UPROPERTY(Config)
	int32 DaysBetweenEnableMFAModalPrompts;

	UPROPERTY(Config)
	float DelayGiftButtonWhenMFANotEnabledSeconds;

	UPROPERTY(Config)
	int32 LevelToAutoOpenBattlePassOnNewSeason;

	UPROPERTY(Config)
	int32 ForceSeasonRefreshCounter;

	UPROPERTY(Config)
	int32 ForceVideoRefreshCounter;

	UPROPERTY(Config)
	bool bForceBattlePassPreview;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bCanShowSTWUpsellInBR;

	UPROPERTY(Config)
	bool bShowLeaderboardPrivacySettings;

	UPROPERTY(Config)
	bool bEnableServerScoreboardLog;

	UPROPERTY(Config)
	bool bEnableAsyncScoreboardFlush;

	UPROPERTY(Config)
	bool bEnableInputBasedMatchmaking;

	UPROPERTY(Config)
	bool bUsingAlternateMatchmakingModel;

	UPROPERTY(Config)
	bool bNotifyBlockedInput;

	UPROPERTY(Config)
	int32 NumberOfFramesBeforeWarnInputBlocked;

	UPROPERTY(Config)
	bool bDisableVideoOptions;

	UPROPERTY(Config)
	bool bEnableBattlePassWatchVideoActionOnCell;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableBattlePassReplayCinematicAction;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCareerReplayCinematicAction;

	UPROPERTY(Config)
	float RadioInputDebounceSeconds;

	UPROPERTY(Config)
	float RadioTuningRetryTime;

	UPROPERTY(Config)
	int32 RadioTuningRetryCount;

	UPROPERTY(Config)
	bool bEnableBattlePassSocialFriends;

	UPROPERTY(Config)
	bool bEnableBattlePassSocialFriendsOfDifferentPlatforms;

	UPROPERTY(Config)
	bool bEnableBattlePassSocialFriendsServerSide;

	UPROPERTY(Config)
	bool bEnableSimulatedXPForBattlePassSocialFriends;

	UPROPERTY(Config)
	bool bEnableBattlePassPreviewOnRewardScreen;

	UPROPERTY(Config)
	int32 BattleStarsNeededToShowRewardPreview;

	UPROPERTY(Config)
	int32 ShowBattlePassTracker;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisplayBattlePassRewardsIndividually;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisplayOnlyBattlePassFAQ;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableBPVideo;

	UPROPERTY(Config)
	bool bEnableUEKGameSelect;

	UPROPERTY(Config)
	bool bCompletelyDisableUEKGameSelect;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAlwaysPlayBPVideo;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableGRL;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowBPPreviewVideo;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowBPTrack_TimeLeft;

	UPROPERTY(Config)
	bool bDisplayAllCharactersOnBattlePassPreviewScreen;

	UPROPERTY(Config)
	bool bRefreshBattlePassCatalogOnSeasonDataLoaded;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableChallengeHolidayVideo;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCareerScreenVideo;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableSpecialEventVideo;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCNVideo;

	UPROPERTY(Config)
	bool bDisableElectraViaPlayerLimits;

	UPROPERTY(Config)
	bool bEnableWinterfestPurchaseButton;

	UPROPERTY(Config)
	bool bEnableWinterfestGiftButton;

	UPROPERTY(Config)
	bool bForceWinterfestInfoModalButtonVisible;

	UPROPERTY(Config)
	int32 NumViewsToDisplayWinterfestInfoModalButton;

	UPROPERTY(Config)
	bool bCheckForPatchUpdateOnMatchmakingPlayClick;

	UPROPERTY(Config)
	bool bCheckForPatchUpdateOnItemShopActivate;

	UPROPERTY(Config)
	FString DefaultHabaneroIslandCode;

	UPROPERTY(Config)
	TArray<FString> HiddenSettings;

	UPROPERTY(Config)
	bool bDisplayPlayerReportingRoles;

	UPROPERTY(Config)
	bool bDisplayRelevantPlayersForPlayerReporting;

	UPROPERTY(Config)
	bool bPreventMultipleReportsOfSamePlayer;

	UPROPERTY(Config)
	bool bAllowReportingFeaturedIslands;

	UPROPERTY(Config)
	bool bForceGamepadPlaytest;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableHUDPresetSelection;

	UPROPERTY(Config)
	bool bEnableAddFriendWhileSpectating;

	UPROPERTY(Config)
	bool bEnableFriendLink;

	UPROPERTY(Config)
	float PlatformChatToastDisplaySeconds;

	UPROPERTY(Config)
	float HPMicrophoneToastDisplaySeconds;

	UPROPERTY(Config)
	FString FriendLinkURL;

	UPROPERTY(Config)
	bool bAllowForceTouchFire;

	UPROPERTY(Config)
	float VehicleSessionMinTimeUsed;

	UPROPERTY(Config)
	float RebootChipExpirationTime;

	UPROPERTY(Config)
	float RebootDirectiveDisplayTime;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDonutIdleGameEnabled;

	UPROPERTY(Config)
	bool bRebootEnableInventoryDisplay;

	UPROPERTY(Config)
	bool bUseHordeStormShield;

	UPROPERTY(Config)
	float HordeStormShieldStartingRadiusOverride;

	UPROPERTY(Config)
	float HordeStormShieldEndingRadiusOverride;

	UPROPERTY(Config)
	float HordeStormShieldBreatherRadiusOverride;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bUseHordeRespawnAtLastPawnLocation;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowHordePlayerTriggeredRespawn;

	UPROPERTY(Config)
	int32 MaxQuickScopeAimAssistPulls;

	UPROPERTY(Config)
	float MaxQuickScopeAimAssistPullWatchTime;

	UPROPERTY(Config)
	bool bShouldDisablePickaxeFXFrontendPreview;

	UPROPERTY(Config)
	bool bRegisterPawnsWithSignificanceManagerInFrontEnd;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnPS4;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnXB1;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnSwitch;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnPS4_STWOnly;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnXB1_STWOnly;

	UPROPERTY(Config)
	bool bHideExclusiveCosmeticsFromOtherPlatformsOnSwitch_STWOnly;

	UPROPERTY(Config)
	bool bSimpleHeistVanEntrance;

	UPROPERTY(Config)
	FString LobbyGenericLinkButtonURL;

	UPROPERTY(Config)
	bool bEnableLobbyGenericLinkButton;

	UPROPERTY(Config)
	FRuntimeOptionLocalizableString LobbyGenericLinkButtonText;

	UPROPERTY(Config)
	int32 HighlightClipRewindTimeInSeconds;

	UPROPERTY(Config)
	bool bEnableAntiTaxi;

	UPROPERTY(Config)
	float StopFlyingParachuteCooldownTime;

	UPROPERTY(Config)
	float FlushLoadingScreenRefreshSeconds;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableVehicleSpawnMissionInStw;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableDownTierCraftingInStw;

	UPROPERTY(Config)
	bool bShowBugReportsButton;

	UPROPERTY(Config)
	bool bShowCommentReportsButton;

	UPROPERTY(Config)
	bool bShowContentReportsButton;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableItemRefundingInStw;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableCareerStatsButton;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableCareerLeaderboardButton;

	UPROPERTY(Config)
	bool bDisableCareerStatsPagePlatformProfileButton;

	UPROPERTY(Config)
	bool bUsePlatformSpecificTextOnCareerPage;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bDisableViewOtherProfilesFromCompLeaderboards;

	UPROPERTY(Config)
	bool bShowOtherPlayerStatsOnCareerPage;

	UPROPERTY(Config)
	bool bShowFeatsOnClient;

	UPROPERTY(Config)
	bool bShowHardcoreModifiers;

	UPROPERTY(Config)
	int32 InputMethodThrashingLimit;

	UPROPERTY(Config)
	float InputMethodThrashingWindowInSeconds;

	UPROPERTY(Config)
	bool bEnableLogUploadForTokenHolders;

	UPROPERTY(Config)
	float TokenHolderLogTailSizeKb;

	UPROPERTY(Config)
	bool bAllowPartialBackgroundAudio;

	UPROPERTY(Config)
	bool bDuplicateRemovedPlayersOnClient;

	UPROPERTY(Config)
	FPlayerMarkerConfig PlayerMarkerConfig;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bIsCreativeMultiSelectEnabled;

	UPROPERTY(Config)
	bool bEnableUserProfilePictures;

	UPROPERTY(Config)
	bool bEnableChannelsServiceLoadTesting;

	UPROPERTY(Config)
	bool bAllowMimicingEmotes;

	UPROPERTY(Config)
	bool bAllowMimicingEmotesInFrontend;

	UPROPERTY(Config)
	bool bAllowAsyncTooltipLoading;

	UPROPERTY(Config)
	bool bAllowListViewAsyncLoading;

	UPROPERTY(Config)
	bool bEnableBackToPartyHubButton;

	UPROPERTY(Config)
	bool bEnableMobileAvailableLootingListView;

	UPROPERTY(Config)
	bool bEnableDisambiguateLoading;

	UPROPERTY(Config)
	int32 NumDaysToSnoozeGooglePlayRating;

	UPROPERTY(Config)
	int32 NumDaysAllowedToDelayGoogleRating;

	UPROPERTY(Config)
	bool bEnableMobileInGameAppRating;

	UPROPERTY(Config)
	int32 PreloadRevision;

	UPROPERTY(Config)
	bool bEnableLiveStoreTilePreviews;

	UPROPERTY(Config)
	bool bUseLegacyItemShopOfferDetails;

	UPROPERTY(Config)
	bool bEnableLiveStoreTilePreviews_InGame;

	UPROPERTY(Config)
	bool bAllowedToEnableUIGlobalInvalidation;

	UPROPERTY(Config)
	bool bEnableAutoMulchInStW;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllStWMoonbeamHUD;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 MaxCharactersInTextEntry;

	UPROPERTY(Config)
	TArray<FString> IllegalIslandTitleCharacters;

	UPROPERTY(Config)
	TArray<int32> IllegalIslandTitleChars;

	UPROPERTY(Config)
	bool bEnableCreativeUserTextSanitizationWithToxicityService;

	UPROPERTY(Config)
	bool bEnableCreativeUserTextSanitizationWithPlatformSanitizer;

	UPROPERTY(Config)
	bool bEnableCreativeUserTextSanitizationWithChatSanitizer;

	UPROPERTY(Config)
	bool bUseToxicityAsCreativeMainTextSanitizer;

	UPROPERTY(Config)
	bool bUseLegacyAsyncSanitizationLogicInCreative;

	UPROPERTY(Config)
	float KeepPlayingTogetherDuration;

	UPROPERTY(Config)
	float KeepPlayingTogetherTickFrequency;

	UPROPERTY(Config)
	TMap<FGameplayTag, float> PawnVisibilityDurationOverrides;

	UPROPERTY(Config)
	TMap<FString, FString> QuestTagByUnlockProperty;

	UPROPERTY(Config, meta=(DisplayName="Hotfix Version"))
	int32 HotfixVersionId;

	UPROPERTY(Config)
	int32 AutoConfirmEditMode;

	UPROPERTY(Config)
	bool bCanTurboBuildOutsideBuildModeWithBuildTool;

	UPROPERTY(Config)
	float MaxBuildingIntoTerrainIntersectionPercentage;

	UPROPERTY(Config)
	bool bUsingBuildingExtraPiece;

	UPROPERTY(Config)
	int32 AnalyticsBuildingWallTooLowLocations;

	UPROPERTY(Config)
	bool bDisableClientEngagementsAnalytics;

	UPROPERTY(Config)
	float AnalyticsClientEngagementsTimeoutSeconds;

	UPROPERTY(Config)
	int32 AnalyticsClientEngagementsMaxSendPerMinute;

	UPROPERTY(Config)
	int32 AnalyticsClientEngagementsMaxSendOnCleanup;

	UPROPERTY(Config)
	bool bAnalyticsClientEngagementsRequireTimeToReturnFireToSend;

	UPROPERTY(Config)
	int32 AnalyticsClientEngagementsParticipationPercent;

	UPROPERTY(Config)
	bool PublishingEnabledForWhitelistedAccounts;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString IslandCodeLinkMnemonicExampleText;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString IslandCodeLinkURLText;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FString FeaturedCreativeLTMAffiliateName;

	UPROPERTY(Config)
	bool bEnableDynamicTileSizing;

	UPROPERTY(Config)
	bool bEnableCreativeLTMSupportCreator;

	UPROPERTY(Config)
	FString CreativePublishCodeURLPrefix;

	UPROPERTY(Config)
	bool bCreativeMinimapRendering;

	UPROPERTY(Config)
	bool bCreativeMinimapCaptureLighting;

	UPROPERTY(Config)
	bool bCreativeMapRenderingInHub;

	UPROPERTY(Config)
	bool bCreativeMapWaitForVolumeReady;

	UPROPERTY(Config)
	TArray<FString> CuratedLinkCodes;

	UPROPERTY(Config)
	TArray<FString> CuratedIslandTemplateCodes;

	UPROPERTY(Config)
	TMap<FString, FFortPlaylistCuratedContent> PlaylistCuratedContent;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableIslandCheckpoints;

	UPROPERTY(Config)
	bool bEnableIslandLoadNetSafeGuards;

	UPROPERTY(Config)
	TMap<FString, FString> PlaylistCuratedHub;

	UPROPERTY(Config)
	TMap<FString, FString> CreativeIslandImageURLOverrides;

	UPROPERTY(Config)
	FString CreativeIslandGeneratedImageURLOverride;

	UPROPERTY(Config)
	bool bLoadingScreenInputPreprocessorEnabled;

	UPROPERTY(Config)
	bool AllowInputTypeFilterForAccessibility;

	UPROPERTY(Config)
	bool AllowLockPrimaryInputMethodToMouseForAccessibility;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bEnableLiveStream;

	UPROPERTY(Config)
	bool bEnableLiveStreamCountdown;

	UPROPERTY(Config)
	FDateTime LiveStreamStartTime;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bEnableLiveStreamInMatch;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bShowLiveStreamInMatchByDefault;

	UPROPERTY(Config)
	bool bCaptureTeamFrontendFlag;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName VideoHolidayName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName VideoBattlePassName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName VideoCareerScreenName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName VideoChallengeScreenName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FName VideoFrontEndName;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float FTUESeasonTrailerBoundary;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float VideoDurationOffsetFromTransition;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float VideoDurationOffsetFromEnd;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	FSeasonVideoIDs SeasonVideoIDs;

	UPROPERTY(Config)
	int32 EOSGCVerticalRes;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 EOSGCLength;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableGCBeforeVideoPlayback;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableFTUEVideoForcedGC;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableMediaSegmentCaching;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bForceMediaSegmentCaching;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float EOneVideoLength;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	float ETwoVideoLength;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	TArray<float> MediaCDNDistribution;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 MaxNumberOfMediaDecoderResources;

	UPROPERTY(Config)
	TArray<FString> VideoEVMap;

	UPROPERTY(Config)
	FString MediaPartnerRegionControl;

	UPROPERTY(Config)
	int32 LiveStreamPiPMemoryRequired;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	int64 ShouldShowLiveStreamPiPInMatchCounter;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bEnableNewPIP;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableRiskyReelsStreaming;

	UPROPERTY(Config)
	bool bDisableBlastURLStreamSource;

	UPROPERTY(Config)
	int32 StreamPlaylistFetchMethodOrder;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bHiddenButEnabledLiveStreamInMatch;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	float TimedEventsJIPStartDelay;

	UPROPERTY(Config)
	bool bEnableEOSGC;

	UPROPERTY(Config)
	bool bEnableHomer;

	UPROPERTY(BlueprintReadWrite, Category="FortRuntimeOptions")
	bool bInputActionHolding;

	UPROPERTY(Config)
	FPictureInPictureInfo PictureInPictureState;

	UPROPERTY(Config)
	bool bEnableSplineReticulationById;

	UPROPERTY(Config)
	bool bUseSingleHUDUpdatePerFrame;

	UPROPERTY(Config)
	int64 MinInteractionScoreForFriendToBeConsideredClose;

	UPROPERTY(Config)
	int64 MinIntervalBetweenInviteToPartyNotificationsInSeconds;

	UPROPERTY(Config)
	bool bSendPartyLeftNotificationsFromManager;

	UPROPERTY(Config)
	float DelayBetweenStartOfPostGameAndShowDelayedNotificationsInSeconds;

	UPROPERTY(Config)
	int32 AndroidStoreCounter;

	UPROPERTY(Config)
	bool bHideCharacterCustomizationNullTile;

	UPROPERTY(Config)
	bool bEnablePlaylistRequireCrossplay;

	UPROPERTY(Config)
	bool bRequireCrossplayOptInForFill;

	UPROPERTY(Config)
	bool bUseConcurrentCrossplayPromptGuard;

	UPROPERTY(Config)
	int32 MaxSquadSize;

	UPROPERTY(Config)
	int32 MaxPartySizeCampaign;

	UPROPERTY(Config)
	int32 MaxPartySizeAthena;

	UPROPERTY(Config)
	bool bShouldFollowersSendSquadMatchmakingInfo;

	UPROPERTY(Config)
	bool bAllowAthenaNavSystemForCreative;

	UPROPERTY(Config)
	bool bEnablePlayerSurveys;

	UPROPERTY(Config)
	bool bEnablePlayerStatsPrecache;

	UPROPERTY(Config)
	bool bEnableStreamingReplayViewingUI;

	UPROPERTY(Config)
	float LiveReplayDiscoverabilityDelay;

	UPROPERTY(Config)
	bool bReplayBattleMapCameraMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bReplayKeepLocalClientEvents;

	UPROPERTY(Config)
	bool bReplaySampleAthenaPawnMovement;

	UPROPERTY(Config)
	float ReplaySampleAthenaPawnTimeRate;

	UPROPERTY(Config)
	float ReplaySampleAthenaPawnSpaceRate;

	UPROPERTY(Config)
	float ReplaySampleAthenaPawnUpdateTimeRate;

	UPROPERTY(Config)
	bool bDisablePartyJoinInOutpost;

	UPROPERTY(Config)
	TMap<FString, int32> MashSpecialScores;

	UPROPERTY(Config)
	bool bEnableMissedInvitesEntry;

	UPROPERTY(Config)
	bool bOnlyShowMissedInvitesEntryIfMissedInvites;

	UPROPERTY(Config)
	bool bEnableSidekick;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableSidekickFeature1;

	UPROPERTY(Config)
	bool bEnableSidekickFOMO;

	UPROPERTY(Config)
	bool bEnableSidekickAvatars;

	UPROPERTY(Config)
	bool bSidekickDisablesScreenRecord;

	UPROPERTY(Config)
	bool bSidekickEnableExitFNButton;

	UPROPERTY(Config)
	bool bEnableSidekickFaceAreaInvalidation;

	UPROPERTY(Config)
	bool bSidekickDisabledByNightNight;

	UPROPERTY(Config)
	bool bSidekickForcesSingleChannelMode;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCampaignBatchLevelingUI;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowSimultaneousChannelConnections;

	UPROPERTY(Config)
	bool bExpandNotListeningChannels;

	UPROPERTY(Config)
	uint32 MaxSetFriendSubscriptionSettingsAttempts;

	UPROPERTY(Config)
	uint32 MaxQueryFriendSubscriptionSettingsAttempts;

	UPROPERTY(Config)
	int32 NumDaysBetweenPlayingNotifications;

	UPROPERTY(Config)
	int32 NumHoursBetweenPlayingNotifications;

	UPROPERTY(Config)
	int32 NumMinutesBetweenPlayingNotifications;

	UPROPERTY(Config)
	bool bForceAutoChangeMaterialOn;

	UPROPERTY(Config)
	bool bActiveDisplayDeviceTemperature;

	UPROPERTY(Config)
	bool bAllowOfflineInvites;

	UPROPERTY(Config)
	bool bEnablePlatformVoiceLeave;

	UPROPERTY(Config)
	bool bEnablePlatformVoicePrompts;

	UPROPERTY(Config)
	bool bEnableVoiceChatEnablePrompt;

	UPROPERTY(Config)
	float PlaylistGameVoiceChannelRecommendationDisplayTime;

	UPROPERTY(Config)
	bool bEnablePlaylistGameChannelRecommendationToast;

	UPROPERTY(Config)
	bool bEnableQuickHealing;

	UPROPERTY(Config)
	bool bAllowDeferredPedestalPawnSpawn;

	UPROPERTY(Config)
	bool bRunUnicornOnServer;

	UPROPERTY(Config)
	bool bShowSamsungSensorButtonWarning;

	UPROPERTY(Config)
	int32 SamsungSensorButtonGamesPerWarning;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	TArray<FString> CatabaExclusiveCountryCodes;

	UPROPERTY(Config)
	bool bEnableItemShopDynamicBackground;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool EnableCommunityVotingScreen;

	UPROPERTY(Config)
	int32 CommunityVotingTutorialVersion;

	UPROPERTY(Config)
	float CommunityVotingRevealDelay;

	UPROPERTY(Config)
	float CommunityVotingTimerRefreshDelay;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool ScrollToWinnerTileAfterReveal;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool EnableStandaloneStorefront;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableBattlePassStorefront;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableItemPreviewInStore;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCurrencyInspectScreenBonusText;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableCurrencyBonusBanner;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableItemShopInvalidationBox;

	UPROPERTY(Config)
	bool ScrollToStandaloneSectionOnPopupClosed;

	UPROPERTY(Config)
	TArray<EFortItemShopSection> ItemShopOrdering;

	UPROPERTY(Config)
	bool bEnableItemShopSectionBangs;

	UPROPERTY(Config)
	bool bEnableItemShopCommunityVotingSectionBang;

	UPROPERTY(Config)
	TArray<FAthenaItemShopSectionPriority> ItemShopDefaultLandingPriority;

	UPROPERTY(Config)
	TArray<FAthenaItemShopSectionOverrideDisplayData> ItemShopOverrideDisplayDataList;

	UPROPERTY(Config)
	EFortItemShopSection ItemShopDefaultLanding;

	UPROPERTY(Config)
	float ItemShopOfferSeenThreshold;

	UPROPERTY(Config)
	bool CommunityVotingTileAnimated;

	UPROPERTY(Config)
	bool ScrollToComTileOnEventPopupClosed;

	UPROPERTY(Config)
	bool EnableThanksVotingPopup;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bUseItemPresentationScreenOnItemPurchased;

	UPROPERTY(Config)
	float CommunityVotingThanksPopupDelay;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	TArray<FString> ReloadMtxExclusiveCountryCodes;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableReloadMtx;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnableDynamicReloadMtx;

	UPROPERTY(Config)
	bool bEnableInGameReloadMtx;

	UPROPERTY(Config)
	bool bEnableCrew;

	UPROPERTY(Config)
	bool bEnableSubscriptionInspectScreen;

	UPROPERTY(Config)
	bool bEnableBattlePassViolatorEarnedCurrency;

	UPROPERTY(Config)
	float InGameCosmeticItemBangRefreshRate;

	UPROPERTY(Config)
	bool bUseContentPatchingRestartFlow;

	UPROPERTY(Config)
	bool bAthenaAutoPickupStackables;

	UPROPERTY(Config)
	TArray<FRuntimeOptionScheduledNotification> ScheduledNotifications;

	UPROPERTY(Config)
	bool bEnableUnicornHighlightsOnClient;

	UPROPERTY(Config)
	bool bEnableHighlightsPromptInCompeteScreen;

	UPROPERTY(Config)
	bool bUseReturnToKairosLoadingScreen;

	UPROPERTY(Config)
	bool bForceReturnToKairosLoadingScreen;

	UPROPERTY(Config)
	bool bDebugForceLoginRelaunch;

	UPROPERTY(Config)
	bool bEnableDADUpdateCheckOnRTMM;

	UPROPERTY(Config)
	bool bShouldAllowNightNightMode;

	UPROPERTY(Config)
	FString NightNightPluginName;

	UPROPERTY(Config)
	FString NightNightCalendarEventName;

	UPROPERTY(Config)
	bool bEnableFrontendMeshRockyRidgeCheck;

	UPROPERTY(Config)
	bool bForceAllowFrontendMeshRockyRidgeCheck;

	UPROPERTY(Config)
	FString FrontendMeshRockyRidgeMetadataKey;

	UPROPERTY(Config)
	FString FrontendMeshRockyRidgeCanaryKey;

	UPROPERTY(Config)
	float FrontendMeshRockyRidgeInitialIntervalSeconds;

	UPROPERTY(Config)
	float FrontendMeshRockyRidgeFailureMultiplier;

	UPROPERTY(Config)
	float FrontendMeshRockyRidgeMaxIntervalSeconds;

	UPROPERTY(Config)
	FName FrontendMeshRockyRidgeMeshName;

	UPROPERTY(Config)
	bool bForceEverybodyToGoNightNight;

	UPROPERTY(Config)
	bool bQueryKeychainBeforeGoingNightNight;

	UPROPERTY(Config)
	bool bSkipSubGameDuringNightNight;

	UPROPERTY(Config)
	bool bAllowCampaignFrontendToGoNightNight;

	UPROPERTY(Config)
	bool bShouldAllowForcedIntro;

	UPROPERTY(Config)
	FName ForcedIntroName;

	UPROPERTY(Config)
	bool bShowMovieInGameplayIntro;

	UPROPERTY(Config)
	bool bSkipSubgameSelectDuringForcedIntro;

	UPROPERTY(Config)
	bool bForcedPlaylistEnabled;

	UPROPERTY(Config)
	FName ForcedPlaylistPluginName;

	UPROPERTY(Config)
	FString FrontendMeshForcedPlaylistMetadataKey;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	bool bSkipToEndGameplayIntroOutroVideos;

	UPROPERTY(BlueprintReadWrite, Config, Category="FortRuntimeOptions")
	float MaxGameplayCinematicLength;

	UPROPERTY(Config)
	bool bUseAthenaArmory;

	UPROPERTY(Config)
	bool bEnableLiveSpectateButton;

	UPROPERTY(Config)
	bool bEnableGuidedTutorialDefensiveBuilding;

	UPROPERTY(Config)
	bool bEnableSafeZoneEditor;

	UPROPERTY(Config)
	bool bEnableSafeZoneEditorOnLogin;

	UPROPERTY(Config)
	bool bEnableSafeZoneEditorWhenNotInApolloIntro;

	UPROPERTY(Config)
	float LoginFlowCMSRefreshWaitTime;

	UPROPERTY(Config)
	bool bEnableAppResumeCMSUpdate;

	UPROPERTY(Config)
	bool bEnableMOTDAnalytics;

	UPROPERTY(Config)
	bool bEnableTabTransitionMOTDAnalyticsEvent;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowStoreSkipOpenAnimation;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowInGameStore;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bPostGameStoreNoLeto;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bPostGameStoreTriggerIncrementalGC;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowInGameLocker;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowInGameCareer;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bAllowInGameActivityBrowser;

	UPROPERTY(Config)
	bool bEnableGuidedTutorialDirectFlush;

	UPROPERTY(Config)
	bool bEnableGuidedTutorialABTesting;

	UPROPERTY(Config)
	bool bEnableHighlightPlayButtonABTesting;

	UPROPERTY(Config)
	bool bEnableSkipGuidedTutorialABTesting;

	UPROPERTY(Config)
	int32 MaxFrontendFlowStatQueries;

	UPROPERTY(Config)
	bool ApolloIntroShowMovie;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bRunDeimosSpawnTimelines;

	UPROPERTY(Config)
	bool bEnableAddFriendUserSearchDarkTraffic;

	UPROPERTY(Config)
	bool bEnableExtendedUserSearchUI;

	UPROPERTY(Config)
	bool bEnableRecursiveMatchAssignmentSearchForTeam;

	UPROPERTY(Config)
	bool bEnableBackfillCheckForHighestTeamScore;

	UPROPERTY(Config)
	bool bEnableBackfillCheckForTeamScoreDifference;

	UPROPERTY(Config)
	TMap<FString, int32> BackfillCheckForHighestTeamScorePlaylistOverrides;

	UPROPERTY(Config)
	TMap<FString, float> BackfillCheckForScoreDiscrepancyPlaylistOverrides;

	UPROPERTY(Config)
	bool bDisableTdmBackfilledPlayerTeleport;

	UPROPERTY(Config)
	bool bDisableWarmupRequiredPlayerCountCheck;

	UPROPERTY(Config)
	bool bAIDirectorTreatBotsAsPlayersForLOD;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bEnablePhoenix;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bBuildingPossessionShown;

	UPROPERTY(Config)
	FSoftObjectPath LoadingContentModalWidget;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bBacchusFrontendEnabled;

	UPROPERTY(Config)
	FGameplayTagContainer MobileExcludedButtonsTags;

	UPROPERTY(Config)
	TArray<FName> InvalidCreativeItemTags;

	UPROPERTY(Config)
	FString ValkyrieMajMinPatchQueryParams;

	UPROPERTY(Config)
	bool bSprintingStrafeSnapEnabled;

	UPROPERTY(Config)
	bool bExplicitSprintableInputRange;

	UPROPERTY(Config)
	float MinForwardForSprint;

	UPROPERTY(Config)
	float MinForwardForSprintSnapping;

	UPROPERTY(Config)
	float AccelerationStrafeMultiplierSprintOverride;

	UPROPERTY(Config)
	float KeyboardDiagonalSprintForwardOverride;

	UPROPERTY(Config)
	float KeyboardSprintInputWindUpTime;

	UPROPERTY(Config)
	float KeyboardMoveInputWindUpTime;

	UPROPERTY(Config)
	bool bPlayerControlledKeyboardDiagonalsEnabled;

	UPROPERTY(Config)
	bool bPlayerControlledKeyboardStrafeDirectionEnabled;

	UPROPERTY(Config)
	bool bMouseEditAndBuildMultipliersEnabled;

	UPROPERTY(Config)
	bool bEnableWebAuthFNMobileOnClassicBuild;

	UPROPERTY(Config)
	bool bPortraitWebAuthFNMobileOnClassicBuild;

	UPROPERTY(Config)
	bool bAllowPortraitModePurchaseScreenForMobile;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bBacchusFrontendLabelShown;

	UPROPERTY(Config)
	int32 NoWeaponZoneMaxDestroyCount;

	UPROPERTY(Config)
	float NoWeaponZoneResetDestroyCountRate;

	UPROPERTY(Config)
	bool bAllowCurieIfCreativeOrPlayground;

	UPROPERTY(Config)
	bool bEnableServerSendPlayerInteractions;

	UPROPERTY(Config)
	float ServerSendPlayerInteractionsIntervalSeconds;

	UPROPERTY(Config)
	bool bEnableServerSendPlayerInteractionsRankInCreativeMode;

	UPROPERTY(Config)
	bool bEnableServerPlayerInteractionIdleTracking;

	UPROPERTY(Config)
	bool bEnableNonFriendSquadInteractionTracking;

	UPROPERTY(Config)
	double MinInteractionDurationForDispatch;

	UPROPERTY(EditAnywhere, Config, Category="FortRuntimeOptions")
	TSoftClassPtr<UFortMissionGenerator> DefaultMissionGen;

	UPROPERTY(Config)
	bool bGyroV2Enabled;

	UPROPERTY(Config)
	bool bFlickStickEnabled;

	UPROPERTY(Config)
	int32 GyroAimAssistMode;

	UPROPERTY(Config)
	bool bJoyConSelectEnabled;

	UPROPERTY(Config)
	bool bForceMotionControlsEnabled;

	UPROPERTY(Config)
	bool bAdvancedCameraResetEnabled;

	UPROPERTY(Config)
	bool bEnableBacchusDialogSystem;

	UPROPERTY(Config)
	bool bBacchusDialogSystemSkipConfirmationStep;

	UPROPERTY(Config)
	bool bMobileDisableResolutionReset;

	UPROPERTY(Config)
	bool bMotionAxisMobileDefaultToYaw;

	UPROPERTY(Config)
	bool bFollowCameraOptionAvailable;

	UPROPERTY(Config)
	bool bAutoCenterOptionAvailable;

	UPROPERTY(Config)
	bool bShouldRestartCreativeServersForCalendarEventChanges;

	UPROPERTY(Config)
	bool bCreativeEmoteControllerUseWhitelist;

	UPROPERTY(Config)
	TArray<FString> CreativeEmoteControllerWhitelist;

	UPROPERTY(Config)
	TArray<FVector4> CreativeRoyaleSafeZoneBlockList;

	UPROPERTY(Config)
	bool bPreventLateJoiningPlayersAfterAircraft;

	UPROPERTY(Config)
	TArray<FString> AllowedPMRStatuses;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	bool bShowRMTPurchaseSpecialInfo;

	UPROPERTY(Config)
	bool bQuickWeaponBindAvailable;

	UPROPERTY(Config)
	bool bQuickWeaponAlwaysShowIcons;

	UPROPERTY(Config)
	bool bHoldToBuildBindAvailable;

	UPROPERTY(Config)
	bool bVehicleStickAccelerationSettingEnabled;

	UPROPERTY(Config)
	bool bVehiclesUse2DSteering;

	UPROPERTY(Config)
	float OuterDeadzone2DSteering;

	UPROPERTY(Config)
	bool bMobileRebootToReconnect;

	UPROPERTY(Config)
	bool bEnableCosmeticDownloadSpinner;

	UPROPERTY(Config)
	bool bHideItemPreviewsDuringDownload;

	UPROPERTY(Config)
	bool bEnableMatchmakingAutoRestarting;

	UPROPERTY(Config)
	bool bEnableFireModeDataCloudSave;

	UPROPERTY(Config)
	bool bEnableFireModeSelectionReminder;

	UPROPERTY(Config)
	bool bEnableMobileFireModeSelectionScreen;

	UPROPERTY(Config)
	bool bEnableMobileFireModeSelectionScreenFTUEFlow;

	UPROPERTY(Config)
	int32 MatchesBeforeDisplayingFireModeSelectionReminder;

	UPROPERTY(Config)
	TArray<ECommonPlatformType> PlatformMovieDenyList;

	UPROPERTY(Config)
	TArray<FString> ActivityMovieDenyList;

	UPROPERTY(Config)
	bool bEnableMmsV1LinkMetadataOverrideOnMatchAssignment;

	UPROPERTY(Config)
	bool bEnableMmsV2LinkMetadataOverrideOnMatchAssignment;

	UPROPERTY(Config)
	bool bEnableLinkMetadataPlaylistOverrideOnMatchAssignment;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortRuntimeOptions")
	int32 DecreasedFontSizeInDiscoveryTileTitles;

	UPROPERTY(Config)
	FDateTime ShowAllRatingsNotSeenAfterThisTime;

	UPROPERTY(Config)
	bool bForceAsyncLoadFlushAfterMeshKeychainLoad;

	UPROPERTY(Config)
	bool bForceLevelStreamingFlushAfterMeshKeychainLoad;

	UPROPERTY(Config)
	bool bQueryKeychainBeforeServerTravel;

protected:
	UPROPERTY(Config)
	TArray<FString> PlaylistConditionalFlags;

private:
	UPROPERTY(Config)
	TArray<FRuntimeOptionTabStateInfo> DisabledFrontendNavigationTabs;

	UPROPERTY(Config)
	TArray<FRuntimeOptionTabStateInfo> DisabledTabsForOutOfSeason;

	UPROPERTY(Config)
	TArray<FRuntimeOptionTabStateInfo> TournamentDisabledFrontendNavigationTabs;

	UPROPERTY(Config)
	TArray<FString> DisabledMatchmakingKnobs;

	UPROPERTY(Config)
	TArray<FString> HiddenMatchmakingKnobs;

	UPROPERTY(Config)
	TArray<FRuntimeOptionDisabledGameplayMessage> DisabledGameplayMessages;

	UPROPERTY(Config)
	int32 NumGameplayMessageChannels;

	UPROPERTY(Config)
	TArray<FString> AffiliateNames;

	UPROPERTY(Config)
	bool bHabaneroEnabled;

	UPROPERTY(Config)
	bool bEnableSidebarExpressYourSupport;

	UPROPERTY(Config)
	bool bEnableSocialTags;

	UPROPERTY(Config)
	bool bUseJoinablePartyEntry_2;

	UPROPERTY(Config)
	bool bEnableRebootRally;

	UPROPERTY(Config)
	bool bEnableRebootRallyData;

	UPROPERTY(Config)
	bool bIsUserChoiceAllowedForForcedAndroidStore;

	UPROPERTY(Config)
	float MatchMakingMaxWaitingForServerInitializationTimeSeconds;

	UPROPERTY(Config)
	bool bAthenaGCAllowEliminatingGarbageReferences;

	UPROPERTY(Config)
	bool bCampaignGCAllowEliminatingGarbageReferences;

	UPROPERTY(Config)
	bool bEnableDiscoverInLobby;

	UPROPERTY(Config)
	bool bEnableSearchTabInTopNavigationBar;

	UPROPERTY(Config)
	bool bEnableDiscoverTabInTopNavigationBar;

	UPROPERTY(Config)
	bool bEnableLibraryTabInTopNavigationBar;

	UPROPERTY(Config)
	int32 SearchForLinkCodesDigitThreshold;

	UPROPERTY(Config)
	bool bIsBacchusTabNavOnTop;

};

