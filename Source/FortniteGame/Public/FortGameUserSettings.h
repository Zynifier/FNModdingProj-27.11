// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/DateTime.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortCustomMatchOptions.h"
#include "FortInventoryFilterEnum.h"
#include "FortPlaylistTypes.h"
#include "Items/FortPersistentTypes.h"
#include "Mobile/LayoutProfile/FortMobileHUDProfile.h"
#include "UI/HUDLayoutTool/HUDLayoutToolTypes.h"
#include "FortGameUserSettings.generated.h"

enum class EFortMobileFPSMode : uint8;
enum class EFortScalabilityMode : uint8;
enum class ERHIType : uint8;

UENUM()
enum class EFortAllowCosmeticStreaming : uint8
{
	CodeSet_Enabled = 0,
	CodeSet_Disabled = 1,
	UserSet_Enabled = 2,
	UserSet_Disabled = 3,
	Default = 0,
};

UENUM()
enum class EFortAllowDownloadHighResMipsBehavior : uint8
{
	//used when this feature is permanently turned off. IE: The user changes the setting in the menu. 
//This is not overwritten by a Disabled_Temp setting and takes precedence.

	Disabled_Permanent = 0,
	//used when FN has decided to disable this feature. IE: When an error is occured and we need to temporarily disable this behavior until the user takes some action. 
//Attempting to set to this when the current value is Disabled_Permanent will do nothing as that value takes precedence.

	Disabled_Temp = 1,
	//Feature is fully enabled

	Enabled = 2,
};

UENUM()
enum class EFortAntiAliasingMethod : uint8
{
	// Disable anti aliasing method

	Disabled = 0,
	// Uses UE4's Fast Approximate Anti-Aliasing

	FXAA = 1,
	// Uses UE4's Temporal Anti-Aliasing

	TAA = 2,
	// Uses UE5's Temporal Super Resolution

	TSRLow = 3,
	TSRMedium = 4,
	TSRHigh = 5,
	TSREpic = 6,
	TSR = 6,
	// Uses NVIDIA's DLSS plugin (NVIDIA RTX hardware only)

	DLSS = 7,
	Num = 8,
	Default = 6,
};

UENUM(BlueprintType)
enum class EFortContentQualityLevel : uint8
{
	Unset = 0,
	Quality_Base = 1,
	Quality_Medium = 2,
	Quality_High = 3,
	Num = 4,
};

UENUM(BlueprintType)
enum class EFortMobileFPSMode : uint8
{
	Mode_20Fps = 0,
	Mode_30Fps = 1,
	Mode_45Fps = 2,
	Mode_60Fps = 3,
	Mode_90Fps = 4,
	Mode_120Fps = 5,
	Num = 6,
};

UENUM(BlueprintType)
enum class EFortOfferSeenLevel : uint8
{
	Unseen = 0,
	Notification = 1,
	ItemShopVisited = 2,
	OfferSectionVisited = 3,
	Purchased = 4,
};

UENUM(BlueprintType)
enum class EFortScalabilityMode : uint8
{
	LowPower = 0,
	Frontend = 1,
};

UENUM()
enum class EFortTemporalSuperResolutionSetting : uint8
{
	Recommended = 0,
	Performance = 1,
	Balanced = 2,
	Quality = 3,
	Native = 4,
	Custom = 5,
	Num = 6,
	Default = 0,
};

UENUM()
enum class ERHIType : uint8
{
	D3D11 = 0,
	D3D12 = 1,
	Performance = 2,
};

UENUM(BlueprintType)
enum class ESavedAccountType : uint8
{
	/** No choice made yet */
	None = 0,
	/** Facebook auth creds */
	Facebook = 1,
	/** Google creds */
	Google = 2,
	/** Epic account(email) / token */
	Epic = 3,
	/** Device auth credentials (userid) / token (device/secret) */
	Device = 4,
	/** Headless account(userid) / token */
	Headless = 5,
	/** Saves account(relative) / refresh token (CHOICE ALREADY STORED IN INI) */
	Refresh = 6,
};

UENUM()
enum class EShowInGamePictureInPicture : uint8
{
	Default = 0,
	Hide = 1,
	Show = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAllowVideoPlaybackChanged, bool, bAllowed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScalabilityChanged);

USTRUCT()
struct FFortScalabilityModeSettings
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortSimpleGameStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 GamesPlayed;

	UPROPERTY()
	int32 SecondsPlayed;

	UPROPERTY()
	int32 KillCount;

	UPROPERTY()
	int32 BestResult;

	UPROPERTY()
	FDateTime LastReviewPromptDay;

	UPROPERTY()
	int32 CampaignGamesPlayed;

};

USTRUCT()
struct FSavedCredentials
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ESavedAccountType Type;

	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString Token;

};

USTRUCT()
struct FShopSectionSeenStateResetDateInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FSocialStatusSerialized
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl LocalUserId;

	UPROPERTY()
	FUniqueNetIdRepl OtherUserId;

	UPROPERTY()
	FFortPresenceSocialStatus SocialStatus;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFUNCTION()
	int32 GetAntiAliasingMethod() const;

	UFUNCTION(BlueprintPure, Category="Settings")
	FString GetAudioOutputDeviceId() const;

	UFUNCTION()
	bool GetAutoDownloadHighResTextures() const;

	UFUNCTION()
	int32 GetCachedAlienStylePoints() const;

	UFUNCTION()
	int32 GetCachedBattleStars() const;

	UFUNCTION()
	int32 GetCachedClaimableRewards(const FString& ClaimableRewardsPageType) const;

	UFUNCTION()
	int32 GetCachedHighestBattlePassUnlockedPage() const;

	UFUNCTION()
	int32 GetCachedPlayerLevel() const;

	UFUNCTION()
	int32 GetCachedStylePoints() const;

	UFUNCTION()
	bool GetCosmeticStreamingEnabled() const;

	UFUNCTION()
	float GetDisplayGamma() const;

	UFUNCTION()
	bool GetDLSSFrameGenerationEnabled() const;

	UFUNCTION()
	int32 GetDLSSQuality() const;

	UFUNCTION(BlueprintPure)
	const FFireModeData& GetFireModeData() const;

	UFUNCTION()
	int32 GetGlobalIlluminationQualityForGameMode() const;

	UFUNCTION()
	bool GetHardwareRayTracingEnabled() const;

	UFUNCTION(BlueprintPure)
	bool GetHasSeenCreativeHeatmapTutorial() const;

	UFUNCTION(BlueprintPure)
	bool GetHasSeenCreativePhoneTutorial() const;

	UFUNCTION(BlueprintPure)
	bool GetHasSeenPanningTip() const;

	UFUNCTION(BlueprintPure)
	bool GetHasSeenTapToShoot() const;

	UFUNCTION()
	uint32 GetInstalledTextureQuality() const;

	UFUNCTION()
	bool GetLastSelectedFillOption() const;

	UFUNCTION()
	int32 GetMeshQuality() const;

	UFUNCTION()
	bool GetNaniteEnabled() const;

	UFUNCTION()
	bool GetPredownloadCosmeticsEnabled() const;

	UFUNCTION()
	int32 GetReflectionQualityForGameMode() const;

	UFUNCTION()
	ERHIType GetRenderingAPI() const;

	UFUNCTION()
	ERHIType GetRenderingAPISelection() const;

	UFUNCTION()
	float GetResolutionFraction() const;

	UFUNCTION()
	float GetSafeZone() const;

	UFUNCTION()
	bool GetShowActorsWithSeasonItemTagMapIndicators() const;

	UFUNCTION()
	bool GetShowCareerTabBang() const;

	UFUNCTION()
	bool GetShowTemperature() const;

	UFUNCTION()
	bool GetStopRenderingInBackground() const;

	UFUNCTION()
	int32 GetTemporalSuperResolutionQuality() const;

	UFUNCTION()
	bool GetUseGPUCrashDebugging() const;

	UFUNCTION()
	bool GetUseLatencyFlash() const;

	UFUNCTION()
	bool GetUseLatencyTweak1() const;

	UFUNCTION()
	int32 GetUseLatencyTweak2() const;

	UFUNCTION()
	float GetUserInterfaceContrast() const;

	UFUNCTION()
	int32 GetViewDistanceAndFoliageQuality() const;

	UFUNCTION()
	bool GetWillBeLetoGame() const;

	UFUNCTION(BlueprintPure)
	bool HasRecordedStat(const FName& RecordName) const;

	UFUNCTION()
	bool IsDynamicResolutionSupported() const;

	UFUNCTION()
	bool IsEnergySavingEnabledFocusLoss() const;

	UFUNCTION()
	bool IsEnergySavingEnabledIdle() const;

	UFUNCTION(BlueprintPure, Category="Settings")
	bool IsHeadphoneModeEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsInPerformanceMode() const;

	UFUNCTION()
	bool IsLowInputLatencyModeEnabled() const;

	UFUNCTION(BlueprintCallable)
	bool IsVideoPlaybackAllowed();

	UFUNCTION(BlueprintCallable)
	void ResetScalabilityModes();

	UFUNCTION(BlueprintCallable)
	void ResetToDefaultDeviceScalability();

	UFUNCTION()
	void SetAntiAliasingMethod(int32 InFrameResolveMethod);

	UFUNCTION()
	void SetAudioOutputDeviceId(const FString& InAudioOutputDeviceId);

	UFUNCTION()
	void SetAutoDownloadHighResTexturesBool(bool bValue);

	UFUNCTION()
	void SetCachedAlienStylePoints(int32 Value);

	UFUNCTION()
	void SetCachedBattleStars(int32 Value);

	UFUNCTION()
	void SetCachedClaimableRewards(const FString& ClaimableRewardsPageType, const int32 ClaimableRewards);

	UFUNCTION()
	void SetCachedHighestBattlePassUnlockedPage(int32 Value);

	UFUNCTION()
	void SetCachedPlayerLevel(int32 Value);

	UFUNCTION()
	void SetCachedStylePoints(int32 Value);

	UFUNCTION()
	void SetCosmeticStreamingEnabled_ByUser(bool bValue);

	UFUNCTION()
	void SetDisplayGamma(float InGamma);

	UFUNCTION()
	void SetDLSSFrameGenerationEnabled(bool bEnabled);

	UFUNCTION()
	void SetDLSSQuality(int32 InDLSSQuality);

	UFUNCTION(BlueprintCallable)
	void SetDonutShopSequenceMarkedAsSeen(bool bHasSeen);

	UFUNCTION()
	void SetEnergySavingEnabledFocusLoss(bool bEnable);

	UFUNCTION()
	void SetEnergySavingEnabledIdle(bool bEnable);

	UFUNCTION()
	void SetGlobalIlluminationQualityForGameMode(int32 NewGlobalIlluminationQuality);

	UFUNCTION()
	void SetHardwareRayTracingEnabled(bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SetHasSeenCreativeHeatmapTutorial(bool bHasSeenCreativeHeatmapTutorial);

	UFUNCTION(BlueprintCallable)
	void SetHasSeenCreativePhoneTutorial(bool bHasSeenCreativePhoneTutorial);

	UFUNCTION(BlueprintCallable)
	void SetHasSeenLobbyModeChangedNotification(bool bHasSeen);

	UFUNCTION(BlueprintCallable)
	void SetHasSeenPanningTip(bool bHasSeenIt);

	UFUNCTION(BlueprintCallable)
	void SetHasSeenTapToShoot(bool bHasSeenIt);

	UFUNCTION()
	void SetInstalledTextureQuality(uint32 Value);

	UFUNCTION()
	void SetLastSelectedFillOption(bool FillOption);

	UFUNCTION()
	void SetMeshQuality(int32 Value);

	UFUNCTION(BlueprintCallable)
	void SetMobileFPSMode(const EFortMobileFPSMode Mode);

	UFUNCTION()
	void SetNaniteEnabled(bool bEnable);

	UFUNCTION()
	void SetPredownloadCosmeticsEnabled(bool bValue);

	UFUNCTION()
	void SetReflectionQualityForGameMode(int32 NewReflectionQuality);

	UFUNCTION()
	void SetRenderingAPISelection(ERHIType InRenderingAPI);

	UFUNCTION()
	void SetResolutionFraction(float ResolutionFraction);

	UFUNCTION()
	void SetSafeZone(float Value);

	UFUNCTION()
	void SetShowActorsWithSeasonItemTagMapIndicators(const bool bInShowActorsWithSeasonItemTagMapIndicators);

	UFUNCTION()
	void SetShowCareerTabBang(bool Value);

	UFUNCTION()
	void SetShowTemperature(bool bNewValue);

	UFUNCTION()
	void SetStopRenderingInBackground(bool bStop);

	UFUNCTION()
	void SetTemporalSuperResolutionQuality(int32 InTSRQuality);

	UFUNCTION()
	void SetUseGPUCrashDebugging(bool bEnabled);

	UFUNCTION()
	void SetUseLatencyFlash(bool bEnabled);

	UFUNCTION()
	void SetUseLatencyTweak1(bool bEnabled);

	UFUNCTION()
	void SetUseLatencyTweak2(int32 InLatencyTweak2);

	UFUNCTION()
	void SetUserInterfaceContrast(float InContrast);

	UFUNCTION()
	void SetViewDistanceAndFoliageQuality(int32 NewViewDistanceAndFoliageQuality);

	UFUNCTION(BlueprintCallable)
	void ToggleScalabilityMode(EFortScalabilityMode Mode, bool bEnabled, bool bForceApply = false, bool bApplyImmediately = true);

	UPROPERTY(Config)
	FString CustomVoiceChatInputDevice;

	UPROPERTY(Config)
	FString CustomVoiceChatOutputDevice;

	UPROPERTY(Config)
	FString CustomVoiceChatInputDeviceId;

	UPROPERTY(Config)
	FString CustomVoiceChatOutputDeviceId;

	UPROPERTY(Config)
	bool bMotionBlur;

	UPROPERTY(Config)
	bool bShowGrass;

	UPROPERTY(Config)
	bool bShowFPS;

	UPROPERTY(Config)
	bool bUseGPUCrashDebugging;

	UPROPERTY(Config)
	bool bStopRenderingInBackground;

	UPROPERTY(Transient)
	bool bUserRenderingAPIWasMigratedThisSession;

	UPROPERTY(Config)
	bool bLatencyTweak1;

	UPROPERTY(Config)
	int32 LatencyTweak2;

	UPROPERTY(Config)
	bool bLatencyFlash;

	UPROPERTY(Config)
	EFortAntiAliasingMethod FortAntiAliasingMethod;

	UPROPERTY(Config)
	bool bEnableDLSSFrameGeneration;

	UPROPERTY(Config)
	EFortTemporalSuperResolutionSetting TemporalSuperResolutionQuality;

	UPROPERTY(Config)
	int32 DLSSQuality;

	UPROPERTY(Config)
	bool bUseNanite;

	UPROPERTY(Config)
	int32 DesiredGlobalIlluminationQuality;

	UPROPERTY(Config)
	int32 DesiredReflectionQuality;

	UPROPERTY(Config)
	int32 PreNaniteGlobalIlluminationQuality;

	UPROPERTY(Config)
	int32 PreNaniteReflectionQuality;

	UPROPERTY(Config)
	bool bRayTracing;

	UPROPERTY(Config)
	bool b120FpsMode;

	UPROPERTY(Config)
	int32 FrontendFrameRateLimit;

	UPROPERTY(Config)
	bool bIsEnergySavingEnabledIdle;

	UPROPERTY(Config)
	bool bIsEnergySavingEnabledFocusLoss;

	UPROPERTY(Config)
	int32 EnergySavingLevelFocusLoss;

	UPROPERTY(Transient)
	bool bDesiredHeadphoneMode;

	UPROPERTY(Config)
	int32 InitialBenchmarkState;

	UPROPERTY(Config)
	bool bDisableMouseAcceleration;

	UPROPERTY(Config)
	ESavedAccountType ChosenLoginType;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnViewDistanceQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnShadowQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnGlobalIlluminationQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnReflectionQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnAntiAliasingQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnTextureQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnEffectsQualityChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScalabilityChanged OnPostProcessQualityChanged;

	UPROPERTY(Config)
	int32 SocialImportOptedOutVersion;

	UPROPERTY(Config)
	int32 VKImportOptedOutVersion;

	UPROPERTY(Config)
	bool bHasSeenErebusSocialImport;

	UPROPERTY(Config)
	bool bHasSeenFriendImportToast;

	UPROPERTY(Config)
	FDateTime LastSocialImportPromptTime;

	UPROPERTY(Config)
	bool bAutoImportFriendEnabled;

	UPROPERTY(Config)
	bool bSeenLetoSellModal;

	UPROPERTY(Config)
	int32 SocialImportPromptCountCurrentVersion;

	UPROPERTY(Config)
	int32 SocialImportPromptCountAllVersions;

	UPROPERTY(Config)
	int32 VKImportPromptCountCurrentVersion;

	UPROPERTY(Config)
	int32 VKImportPromptCountAllVersions;

	UPROPERTY(Transient)
	bool bSocialImportDisplayed;

	UPROPERTY(Transient)
	bool bAccountItemWarningShownThisLaunch;

	UPROPERTY(Config)
	FDateTime LastAccountItemWarningTime;

	UPROPERTY(Config)
	bool bMultiFactorAuthModalOpOut;

	UPROPERTY(Config)
	FDateTime LastEnableMFAModalPromptTime;

	UPROPERTY(Config)
	FDateTime LastVKImportPromptTime;

	UPROPERTY(Config)
	FDateTime LastAffiliateToastTime;

	UPROPERTY(Config)
	TMap<FString, FDateTime> FailedInviteMap;

	UPROPERTY(Config)
	int32 MobileRecommendationDismissedVersion;

	UPROPERTY(BlueprintReadOnly, Config, Category="FortGameUserSettings")
	EShowInGamePictureInPicture ShowLiveStreamPictureInPictureInMatchV2;

	UPROPERTY(Config)
	int64 CurrentLivePiPStreamOverrideCounter;

	UPROPERTY(Config)
	FString SelectedFrontEnd;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FString SelectedFrontEnd_PIE;
#endif

	UPROPERTY(Transient)
	bool bDesiredAllowLowPowerMode;

	UPROPERTY(BlueprintAssignable)
	FOnAllowVideoPlaybackChanged OnAllowVideoPlaybackChanged;

	UPROPERTY(Config)
	bool bHasMigratedDownloadSettings;

	UPROPERTY(Config)
	bool bSendAppsFlyerEventOnInstallation;

	UPROPERTY(Config)
	bool bAllowCellularDownload;

	UPROPERTY(Config)
	EFortAllowDownloadHighResMipsBehavior AutoDownloadHighResTexturesBehavior;

	UPROPERTY(Config)
	int64 LastAutoDownloadHighResTextureReminder;

	UPROPERTY(Config)
	EFortAllowCosmeticStreaming CosmeticStreamingEnabled;

	UPROPERTY(Transient)
	bool bResumeUserCanceledOrPausedDownload;

	UPROPERTY(Transient)
	bool bForceNoPatchingForDownloads;

	UPROPERTY(Config)
	bool bAutoLaunchFullGame;

	UPROPERTY(Config)
	bool bAllowDownloadHighResMips;

	UPROPERTY(Config)
	EFortContentQualityLevel ContentQualityLevelSelected;

	UPROPERTY(Config)
	TArray<int32> ScheduledNotifications;

	UPROPERTY(Config)
	bool LowInputLatencyModeIsEnabled;

private:
	UPROPERTY(Config)
	float MouseSensitivity;

	UPROPERTY(Config)
	int32 FortniteReleaseVersion;

	UPROPERTY(Config)
	bool UnlockConsoleFPS;

	UPROPERTY(Transient)
	bool LastAppliedUnlockConsoleFPS;

	UPROPERTY(Transient)
	FString CurrentFpsModeString;

	UPROPERTY(Transient)
	FString CurrentDeviceProfileOverrideSuffix;

	UPROPERTY(Config)
	int32 SubGameSelectCount_Athena;

	UPROPERTY(Config)
	FDateTime SubGameLastSelectedTime_Athena;

	UPROPERTY(Config)
	int32 SubGameSelectCount_Campaign;

	UPROPERTY(Config)
	FDateTime SubGameLastSelectedTime_Campaign;

	UPROPERTY(Config)
	FDateTime LastTimeSettingsSnapshotUploaded;

	UPROPERTY(Config)
	FDateTime FirstLoginOnDevice;

	UPROPERTY(Config)
	float SafeZone;

	UPROPERTY(Config)
	bool bIsSafeZoneSet;

	UPROPERTY(Config)
	int32 CachedPlayerLevel;

	UPROPERTY(Config)
	bool bShowActorsWithSeasonItemTagMapIndicators;

	UPROPERTY(Config)
	int32 CachedBattleStars;

	UPROPERTY(Config)
	int32 CachedAlienStylePoints;

	UPROPERTY(Config)
	int32 CachedStylePoints;

	UPROPERTY(Config)
	TMap<FString, int32> CachedClaimableRewards;

	UPROPERTY(Config)
	int32 CachedHighestBattlePassUnlockedPage;

	UPROPERTY(Config)
	bool bShowCareerTabBang;

	UPROPERTY(Config)
	float DisplayGamma;

	UPROPERTY(Config)
	float UserInterfaceContrast;

	UPROPERTY(Config)
	TMap<FName, FDateTime> NamedTimes;

	UPROPERTY(Config)
	TMap<FName, int32> NamedCounts;

	UPROPERTY(Config)
	int32 BattlePassOverrideTracker;

	UPROPERTY(Config)
	FString NewestProgressiveCosmeticSetSeen;

	UPROPERTY(Config)
	TMap<EAthenaCustomizationCategory, EInventoryContentSortType> CurrentLockerSorts;

	UPROPERTY(Config)
	bool bHasUsedBattlePassCrewUpsellNavButton;

	UPROPERTY(Config)
	bool bHasUserSeenQuickSaveTooltip;

	UPROPERTY(Config)
	bool bHasUserSeenLockerActionBarTooltip;

	UPROPERTY(Config)
	bool bHasSeenLockerTemporaryItemsTooltip;

	UPROPERTY(Config)
	FDateTime LastExpectedShopRefreshTime;

	UPROPERTY(Config)
	bool bHasSeenItemShop;

	UPROPERTY(Config)
	bool bHasSeenDonutShopSequence;

	UPROPERTY(Config)
	float DonutIdleGameHighScore;

	UPROPERTY(Config)
	TMap<FString, EFortOfferSeenLevel> DisplayAssetPathToOfferSeenLevel;

	UPROPERTY(Config)
	TMap<FName, EFortOfferSeenLevel> RowIdToOfferSeenLevel;

	UPROPERTY(Config)
	TMap<FName, FDateTime> ItemShopSectionsSeenStateLastResetDates;

	UPROPERTY(Config)
	FPlaylistData LastSelectedPlaylist;

	UPROPERTY(Config)
	bool LastSelectedFillOption;

	UPROPERTY(Config)
	bool bLastSelectedPrivateMatchOption;

	UPROPERTY(Config)
	TMap<FName, FSavedCustomMatchOptions> CustomMatchOptions;

	UPROPERTY(Config)
	TMap<FName, int32> CreativeOptions;

	UPROPERTY(Config)
	bool bHasSeenCreativePhoneTutorial;

	UPROPERTY(Config)
	bool bHasSeenCreativeHeatmapTutorial;

	UPROPERTY(Config)
	int32 CreativeOptionLastUsedCategory;

	UPROPERTY(Config)
	int32 CreativeOptionLastUsedIndexInCategory;

	UPROPERTY(Config)
	TMap<FString, FString> LastSelectedChildActivityMap;

	UPROPERTY(Config)
	FString LastNewsVersionViewedBR;

	UPROPERTY(Config)
	FString LastNewsVersionViewedCreative;

	UPROPERTY(Config)
	FString LastNewsVersionViewedSTW;

	UPROPERTY(Config)
	FString LastPRMEtag;

	UPROPERTY(Transient)
	FString LastPlaylistInfoVersionViewedBR;

	UPROPERTY(Config, meta=(ArraySizeEnum="/Script/FortniteGame.EDynamicBackgroudKey"))
	FString LastFrontEndBackPlateStageUsed[2];

	UPROPERTY(Config)
	bool bEulaAccepted;

	UPROPERTY(Config)
	FString EulaAcceptedUserId;

	UPROPERTY(Config)
	FDateTime LastEulaCheckTime;

	UPROPERTY(Config, meta=(ArraySizeEnum="/Script/FortniteGame.ELayoutDataType"))
	FHUDLayoutData HUDLayoutData[3];

	UPROPERTY(Config)
	FFortMobileHUDProfileIdentifier ActiveHUDProfileIdentifier;

	UPROPERTY(Config)
	int32 bTimesSeenBacchusLoadTutorial;

	UPROPERTY(Config)
	bool bHasSeenTapToShoot;

	UPROPERTY(Config)
	int32 NumTimesSeeingPanningTip;

	UPROPERTY(Config)
	FFireModeData FireModeData;

	UPROPERTY(Config)
	FFortSimpleGameStats SimpleMobileStats;

	UPROPERTY(Config)
	FString AudioOutputDeviceId;

	UPROPERTY(Config)
	bool bUseHeadphoneMode;

	UPROPERTY(Config)
	TArray<FSavedCredentials> Credentials;

	UPROPERTY(Config)
	bool bNeverShowMobileLink;

	UPROPERTY(Transient)
	bool bHasShownMobileLink;

	UPROPERTY(Config)
	bool bAllowFullGameDownload;

	UPROPERTY(Transient)
	bool bAllowFullGameDownloadOverride;

	UPROPERTY(Transient)
	bool bAllowElectraPlayerDownload;

	UPROPERTY(Transient)
	bool bAllowElectraPlayerDownloadOverride;

	UPROPERTY(Config)
	bool bAllowLowPowerMode;

	UPROPERTY(Config)
	bool bAllowVideoPlayback;

	UPROPERTY(Config)
	EFortMobileFPSMode MobileFPSMode;

	UPROPERTY(Config)
	FString MobileQualitySettingsResetDefaultsGUID;

	UPROPERTY(Config)
	bool bHasSeenSamsungPressureSensorWarning;

	UPROPERTY(Config)
	bool bNeverDisplaySamsungPressureSensorWarning;

	UPROPERTY(Config)
	bool bHasRecentlySeenBadMatchPopup;

	UPROPERTY(Config)
	int32 MatchesSinceLastBadMatchPopup;

	UPROPERTY(Config)
	bool bHasAlreadyRatedOnGooglePlay;

	UPROPERTY(Config)
	int32 DaysToSnoozeBeforeNextGooglePlayRating;

	UPROPERTY(Config)
	int32 GooglePlayRatingDelayedOccurences;

	UPROPERTY(Config)
	bool bShowTemperature;

	UPROPERTY(Config)
	FDateTime LastGameStartNotificationSentTime;

	UPROPERTY(Config)
	int32 LastYearForcedDisplayWinterfestInfoButton;

	UPROPERTY(Config)
	int32 LastYearWinterfestWasSeen;

	UPROPERTY(Config)
	TArray<FSocialStatusSerialized> FriendSocialStatuses;

	UPROPERTY(Config)
	bool bHasSeenSidekickWelcomePopup;

	UPROPERTY(Config)
	bool bHasSeenLobbyModeSetNotification;

	UPROPERTY(Config)
	bool bHasSeenLobbyModeChangedNotification;

	UPROPERTY(Config)
	bool bHasSeenDiscoveryModeSetNotification;

	UPROPERTY(Config)
	bool bHasSeenDiscoveryCCUModal;

	UPROPERTY(Config)
	TSet<FString> HasSeenDiscoveryDetailsModeSetNotificationMnemonics;

	UPROPERTY(Config)
	bool bHasSeenCreatorPageFirstTimeTooltip;

	UPROPERTY(Config)
	bool bNeedsToSeeFireModeSelectionReminder;

	UPROPERTY(Config)
	int32 MatchesSinceInitialFireModeSelection;

};

