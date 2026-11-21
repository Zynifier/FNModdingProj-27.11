// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "CommonInputTypeEnum.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortSubGameTypes.h"
#include "FortGlobals.generated.h"

class AActor;
class AFortPlayerController;
class UObject;
enum class EContentInstallState : uint8;
enum class EFortAccountLinkingUIConfig : uint8;
enum class EFortClientUpdateType : uint8;
enum class EFortGameFeature : uint8;
enum class EFortStartupPhase : uint8;
enum class ESubGame : uint8;
enum class ETimeLimitForReplayCinematic : uint8;

UENUM(BlueprintType)
enum class EContentInstallState : uint8
{
	NotInstalled = 0,
	// Content has not been installed

	Pending = 1,
	// Content installation is pending or chunk is being installed

	Installed = 2,
	// Content has been installed

	Unknown = 3,
	// Content install state is unknown

	Error = 4,
};

UENUM(BlueprintType)
enum class EFortAccountLinkingUIConfig : uint8
{
	Disabled = 0,
	// Account linking tab won't even show in the UI

	Default = 1,
	// Account linking with login button will show

	ExternalViewerOnly = 2,
	// Account linking with message about viewer quests and recommendation to link @ website will show

	FullExternal = 3,
};

UENUM(BlueprintType)
enum class EFortClientUpdateType : uint8
{
	Client = 0,
	// The client executable is out of date

	ContentOnly = 1,
};

UENUM(BlueprintType)
enum class EFortGlobalAction : uint8
{
	TrapConfirm = 0,
	TrapPicker = 1,
	BuildConfirm = 2,
	PerformBuildingEditInteraction = 3,
	PerformBuildingImprovementInteraction = 4,
	SwitchQuickBar = 5,
	Use = 6,
	Reload = 7,
	InventoryOrChatHold = 8,
	GamepadChangeMaterialOrHarvestHold = 9,
	GamepadNextWeaponOrHarvestHold = 10,
	GamepadNextWeaponOrAltInteractOrHarvestHold = 11,
	ChangeMaterial = 12,
	Fire = 13,
	RotatePrimitiveClockwise = 14,
	Gadget1 = 15,
	Gadget2 = 16,
	Ability1 = 17,
	Ability2 = 18,
	Ability3 = 19,
	ToggleFullScreenMap = 20,
	ToggleInventory = 21,
	Jump = 22,
	Crouch = 23,
	ShoppingCartCoast = 24,
	GolfCartEBrake = 25,
	GolfCartForward = 26,
	GolfCartReverse = 27,
	GolfCartHonk = 28,
	GamepadToggleHarvestOrHoldCreativePhone = 29,
	GamepadToggleCreativePhoneWeapon = 30,
	Count = 31,
};

UENUM(BlueprintType)
enum class ETimeLimitForReplayCinematic : uint8
{
	OpenTimeLimit = 0,
	DurationTimeLimit = 1,
	DurationExtraTime = 2,
};

USTRUCT(BlueprintType)
struct FContentInstallError
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ContentInstallError")
	FString ErrorCode;

	UPROPERTY(BlueprintReadOnly, Category="ContentInstallError")
	FText ErrorText;

};

USTRUCT(BlueprintType)
struct FFortGlobalActionDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGlobalActionDetails")
	FName ActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGlobalActionDetails")
	bool HoldStatus;

};

USTRUCT(BlueprintType)
struct FFortGlobalActionDetailsFunctionContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortGlobalActionDetailsFunctionContext")
	ECommonInputType OverrideInputType;

};

USTRUCT()
struct FGameplayMessageRouterBool
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bValue;

};

USTRUCT()
struct FKairosSubmitLogOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Type;

	UPROPERTY()
	bool bSubmitLogs;

	UPROPERTY()
	bool bSubmitSecondaryLogs;

	UPROPERTY()
	int32 LogTailKb;

	UPROPERTY()
	float LogSubmitChance;

	UPROPERTY()
	TArray<FString> SubmitErrors;

};

USTRUCT()
struct FORTNITEGAME_API FLogoutLogSubmitOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSubmitLogsDuringLogin;

};

USTRUCT()
struct FPartyFailureLogSubmitReason
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Reason;

	UPROPERTY()
	FString SubReason;

	UPROPERTY()
	float LogSubmitChance;

};

USTRUCT()
struct FPartyFailureLogSubmit
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSubmitLogs;

	UPROPERTY()
	bool bSubmitSecondaryLogs;

	UPROPERTY()
	int32 LogTailKb;

	UPROPERTY()
	TArray<FPartyFailureLogSubmitReason> Reasons;

};

USTRUCT()
struct FPurchaseFailureLogSubmitOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSubmitLogs;

	UPROPERTY()
	bool bSubmitSecondaryLogs;

	UPROPERTY()
	int32 LogTailKb;

	UPROPERTY()
	float LogSubmitChance;

	UPROPERTY()
	TArray<FString> DoNotUploadReasons;

};

USTRUCT()
struct FSubGameAccess
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ESubGame SubGame;

	UPROPERTY()
	ESubGameAccessStatus AccessStatus;

	UPROPERTY()
	ESubGameMatchmakingStatus MatchmakingStatus;

};

USTRUCT()
struct FVoiceChatLogUploadRule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float LogSubmitChance;

	UPROPERTY()
	FString VoiceEvent;

	UPROPERTY()
	FString ErrorCode;

};

USTRUCT()
struct FVoiceChatLogSubmitOptions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSubmitLogs;

	UPROPERTY()
	bool bSubmitSecondaryLogs;

	UPROPERTY()
	int32 LogTailKb;

	UPROPERTY()
	TArray<FVoiceChatLogUploadRule> IncludeRules;

	UPROPERTY()
	TArray<FVoiceChatLogUploadRule> ExcludeRules;

};

UCLASS(Config=Game, MinimalAPI)
class UFortGlobals : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool AllowContainersInCreativeItemLists();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool AreFriendCodesEnabled();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static float ContentInstallationProgress(const ESubGame SubGame);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static float GameFeatureContentInstallationProgress(const EFortGameFeature GameFeature);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static EFortAccountLinkingUIConfig GetAccountLinkingUIConfig();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static FString GetAccountLinkingUIURL();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static ESubGame GetCurrentSubGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(WorldContext="WorldContextObject"))
	static float GetDoubleClickTime(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetForceBuildingActorRecordUpdatesEnabled();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static EContentInstallState GetGameFeatureContentInstallState(const EFortGameFeature GameFeature);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static float GetGlobalSnowAltitude();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static FVector GetGlobalSnowOrigin();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static float GetGlobalSnowRadius();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetIronCityEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetIronCityEndlessEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static const TArray<FName>& GetIronCityWargameTagList();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static FContentInstallError GetLastOnDemandContentInstallError();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static int32 GetMaxTheaterListRefreshDelay();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static int64 GetMemoryRequirementForMediaStreamingMB();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static int32 GetMinTheaterListRefreshDelay();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static EContentInstallState GetOnDemandContentInstallState(const ESubGame SubGame);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetPapayaSpeakersEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static FGameplayTagContainer GetRiskyReelsPlaylistDenylistFilter();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static EFortStartupPhase GetStartupPhase();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static EContentInstallState GetStWTutorialContentInstallState();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static EPhysicalSurface GetSurfaceType(const FHitResult& Hit, const UObject* WorldContextObject = nullptr);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static float GetTimeLimitForReplayCinematic(ETimeLimitForReplayCinematic TimeLimitForReplayCinematic);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static float GetTimeLimitForWatchBattlePassMovie(ETimeLimitForReplayCinematic TimeLimitForWatchBattlePassMovie);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetUseLegacyMediaSource();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool GetUseLegacyMediaSourceForCreative();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static void HandleClientUpdateRequired(EFortClientUpdateType Type, bool RequestExit);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool InstallAllOnDemandContent(const ESubGame SubGame);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool InstallGameFeatureContent(const EFortGameFeature GameFeature);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool InstallStWTutorialContent();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsAccountLinkingEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsAccountLinkingUIURLButtonEnabled();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool IsAllContentInstalled(const ESubGame SubGame);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsBROnly();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsEnduranceDebugEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsErebus();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsErebusOrErebusPreview();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsErebusPreview();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsFirstShotAccuracyDisabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DisplayName="Is Frontend Crafting Enabled"))
	static bool IsFrontendCraftingEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DisplayName="Is Frontend Storage Enabled"))
	static bool IsFrontendStorageEnabled();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool IsGameFeatureContentInstalled(const EFortGameFeature GameFeature);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsHeroLoadoutSystemEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsHestiaEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsInAthena(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsInPhoenixZone(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool IsInSubGame(const UObject* WorldContextObject, const ESubGame SubGame);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsIronCityAutoAmplifierPlacementEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(WorldContext="WorldContextObject"))
	static bool IsMobileGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsNewRewardFlowEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsRunningInCloud();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool IsStWContentInstalled();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static bool IsStWTutorialContentInstalled();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsTencentBuild();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsTouchControlsActive(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsTouchInputPlatform();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(WorldContext="WorldContextObject"))
	static bool IsUsingTouch(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool IsWargameDebugEnabled();

	UFUNCTION(BlueprintPure, Category="FortGlobals", meta=(DisplayName="Is WIFE Enabled"))
	static bool IsWIFEEnabled();

	UFUNCTION(Category="FortGlobals", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static void SetCurrentSubGame(const UObject* WorldContextObject, const ESubGame SubGame);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static void SetGlobalSnowAltitude(float Altitude);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static void SetGlobalSnowOrigin(FVector Origin);

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static void SetGlobalSnowRadius(float Radius);

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldDelayStartupLoading();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldDisableParticleEffectsDuringMissionResults();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldDisablePlayerTeleportDuringMissionResults();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldFlushGPUWhenPlayerIsTeleportedAtEndOfZone();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldShowMissionResultsMovies();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShouldStreamOutTextureDataWhenPlayerIsTeleportedAtEndOfZone();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool ShowExtendedBattlePassMovie();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static float StWTutorialContentInstallationProgress();

	UFUNCTION(BlueprintCallable, Category="FortGlobals")
	static void UpdateAllGameFeaturesOnPauseChanged();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool UseElectraForReplayCinematic();

	UFUNCTION(BlueprintPure, Category="FortGlobals")
	static bool UseElectraForWatchBattlePassMovie();

	UPROPERTY(Config)
	FString LobbyMap;

	UPROPERTY(Config)
	FString BRMapFullName;

	UPROPERTY(Config)
	int32 MinTheaterListRefreshDelay;

	UPROPERTY(Config)
	int32 MaxTheaterListRefreshDelay;

	UPROPERTY(Config)
	float MinCullObjectSize;

	UPROPERTY(Config)
	float MinCullDistance;

	UPROPERTY(Config)
	float MaxCullObjectSize;

	UPROPERTY(Config)
	float MaxCullDistance;

	UPROPERTY(Config)
	float MinRespawnHeightForEnvironmentDeath;

	UPROPERTY(Config)
	float MaxRespawnInAirHeight;

	UPROPERTY(Config)
	bool bEnablePlayerTriggeredRespawn;

	UPROPERTY(Config)
	bool bEnableNewCustomizationPanel;

	UPROPERTY(Config)
	bool bEnableInfluenceMap;

	UPROPERTY(Config)
	bool bEnableAIDespawning;

	UPROPERTY(Config)
	bool bEnableDBNO;

	UPROPERTY(Config)
	bool bEnableIronCity;

	UPROPERTY(Config)
	bool bEnableForceBuildingActorRecordUpdates;

	UPROPERTY(Config)
	TArray<FName> IronCityWargameTagList;

	UPROPERTY(Config)
	bool bEnableIronCityCoast;

	UPROPERTY(Config)
	bool bEnableMaydayStrangeLands;

	UPROPERTY(Config)
	bool bForceMaydayStrangeLands;

	UPROPERTY(Config)
	bool bEnableInWorldScoreNumbers;

	UPROPERTY(Config)
	bool bMustUseToggleJetpackExecute;

	UPROPERTY(Config)
	bool bEnableNewRewardFlow;

	UPROPERTY(Config)
	bool bEnableWIFE;

	UPROPERTY(Config)
	bool bEnableFrontendCrafting;

	UPROPERTY(Config)
	bool bEnableFrontendStorage;

	UPROPERTY(Config)
	bool bEnableLazyASC;

	UPROPERTY(Config)
	bool bEnableFriendCodes;

	UPROPERTY(Config)
	bool bEnableCreativeMode;

	UPROPERTY(Config)
	bool bEnableCreativeModeLimitedAccess;

	UPROPERTY(Config)
	bool bEnableCreativeModeLimitedAccessForFounders;

	UPROPERTY(Config)
	float FlyVerificationInterval;

	UPROPERTY(Config)
	float InvulnerableVerificationInterval;

	UPROPERTY(Config)
	float ModeratorModeVerificationInterval;

	UPROPERTY(Config)
	FString CreativeModeLimitedAccessEndTime;

	UPROPERTY(Config)
	bool bEnableCreativeModeTutorials;

	UPROPERTY(Config)
	float CreativeTutorialSkydivingDelay;

	UPROPERTY(Config)
	float CreativeReturnToHubTutorialDelay;

	UPROPERTY(Config)
	FLogoutLogSubmitOptions LogoutFailureOptions;

	UPROPERTY(Config)
	FPurchaseFailureLogSubmitOptions RealMoneyPurchaseFailureOptions;

	UPROPERTY(Config, meta=(DisplayName="If true, then logs will be uploaded from client due to return to main menu reasons"))
	bool bSubmitReturnToMenuErrorLogs;

	UPROPERTY(Config, meta=(DisplayName="If true, then logs will be uploaded from secondary users on the client due to return to main menu reasons"))
	bool bSubmitSecondaryReturnToMenuErrorLogs;

	UPROPERTY(Config, meta=(DisplayName="Size in KBytes of the last portion of logs to upload on return to menu error"))
	int32 ReturnToMenuErrorLogTailKb;

	UPROPERTY(Config, meta=(DisplayName="Chance to upload logs (0.0 to 1.0"))
	float ReturnToMenuErrorLogSubmitChance;

	UPROPERTY(Config, meta=(DisplayName="Log submit on party join failure settings"))
	FPartyFailureLogSubmit PartyJoinFailureLogSubmit;

	UPROPERTY(Config)
	TArray<FKairosSubmitLogOptions> KairosSubmitOptions;

	UPROPERTY(Config)
	FVoiceChatLogSubmitOptions VoiceChatSubmitOptions;

	UPROPERTY(Config)
	bool bShowMissionResultsMovies;

	UPROPERTY(Config)
	bool bDisablePlayerTeleportDuringMissionResults;

	UPROPERTY(Config)
	bool bDisableParticleEffectsDuringMissionResults;

	UPROPERTY(Config)
	bool bFlushGPUWhenPlayerIsTeleportedAtEndOfZone;

	UPROPERTY(Config)
	bool bStreamOutTextureDataWhenPlayerIsTeleportedAtEndOfZone;

	UPROPERTY(Config)
	bool bAllowContainersInCreativeItemLists;

	UPROPERTY(Config)
	bool bAccountLinkingEnabled;

	UPROPERTY(Config)
	EFortAccountLinkingUIConfig AccountLinkingUIConfig;

	UPROPERTY(Config)
	FString AccountLinkingUIURL;

	UPROPERTY(Config)
	bool bEnableAccountLinkingUIURLButton;

	UPROPERTY(Config)
	bool bAllowStreamerSafetyCharacterReplication;

	UPROPERTY(Config)
	bool bAnonymousCharacterModeSafetyCharacterReplication;

	UPROPERTY(Config)
	bool bTournamentSafetyCharacterReplication;

	UPROPERTY(Config)
	bool bAllowSafetyCharacterReplicationToUseVariantItems;

	UPROPERTY(Config)
	bool bAllowLogout;

	UPROPERTY(Config)
	bool bAllowQuit;

	UPROPERTY(Config)
	bool bHasWorldMap;

	UPROPERTY(Config)
	float PlayerJoinServerTimeoutSeconds;

	UPROPERTY(Config)
	float PlayerUnregistrationFailsafeTimer;

	UPROPERTY(Config)
	float PollForDedicatedServerReadyToShutdownInterval;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FString PIEZoneOptions;
#endif

	UPROPERTY(Config)
	bool bUploadAthenaStatsV2;

	UPROPERTY(Config)
	bool bAthenaStatsFrontendEnabled;

	UPROPERTY(Config)
	bool bAthenaLeaderboardFrontEndEnabled;

	UPROPERTY(Config)
	bool bAthenaSquadQuickChatEnabled;

	UPROPERTY(Config)
	bool bAthenaSquadRequestEnabled;

	UPROPERTY(Config)
	bool bAthenaNPCCommandEnabled;

	UPROPERTY(Config)
	bool bAthenaCreativeNPCCommandEnabled;

	UPROPERTY(Config)
	bool bAthenaNPCAttackCommandEnabled;

	UPROPERTY(Config)
	bool bSendPingCommandToLastHired;

	UPROPERTY(Config)
	float AthenaQuickChatRangeForNonSquadTeamMembers;

	UPROPERTY(Config)
	bool bGlobalLeaderboardsFrontEndEnabled;

	UPROPERTY(Config)
	int32 TimeBetweenLeaderboardRequestsMinutes;

	UPROPERTY(Config)
	bool bFirstShotAccuracyDisabled;

	UPROPERTY(Config)
	bool bAllowProjectileRethrow;

	UPROPERTY(Config)
	bool bPapayaSpeakersEnabled;

	UPROPERTY(Config)
	bool bAthenaSpatialUIDeferMarkingItemsSeen;

	UPROPERTY(Config)
	bool bAthenaUsesSimCollision;

	UPROPERTY(Config)
	bool bPawnsUseProbeCollision;

	UPROPERTY(Config)
	bool bAthenaSimVehicles;

	UPROPERTY(Config)
	bool bAthenaSubstepping;

	UPROPERTY(Config)
	bool bCampaignSubstepping;

	UPROPERTY(Config)
	bool bCampaignUsesSimCollision;

	UPROPERTY(Config)
	bool bCampaignSimVehicles;

	UPROPERTY(Config)
	float MaximumCharacterVelocity;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> AthenaReferencedObjects;

	UPROPERTY(Transient)
	int32 NumOutstandingAthenaAsyncRequests;

	UPROPERTY(Transient)
	int32 TotalAthenaAsyncRequests;

	UPROPERTY(Transient)
	TSoftClassPtr<AActor> AthenaAlwaysLoadedContentHack;

	UPROPERTY(Config)
	bool bAllowXboxStwToken;

	UPROPERTY(Config)
	bool bUsePlatformProfanityFilterForChat;

	UPROPERTY(Config)
	bool bShouldSendSettingsSnapshotOnLogin;

	UPROPERTY(Config)
	bool bShouldForceAllowBroadcasting;

	UPROPERTY(Config)
	bool bUseLegacyMediaSource;

	UPROPERTY(Config)
	bool bUseLegacyMediaSourceForCreative;

	UPROPERTY(Config)
	bool bDisableMediaStreamingOnWindows7;

	UPROPERTY(Config)
	bool bAllowElectraForCellStreaming;

	UPROPERTY(Config)
	int32 MaxElectraVerticalResolutionOf60fpsVideos;

	UPROPERTY(Config)
	float MaxElectraFpsVideos;

	UPROPERTY(Config)
	int32 MaxElectraVerticalResolutionOfWindowsSWD;

	UPROPERTY(Config)
	float ElectraLivePresentationOffset;

	UPROPERTY(Config)
	float ElectraLiveAudioPresentationOffset;

	UPROPERTY(Config)
	bool bElectraLiveUseConservativePresentationOffset;

	UPROPERTY(Config)
	bool bElectraUseDedicatedMediaSegmentDownloadThreads;

	UPROPERTY(Config)
	bool bAllowElectraForReplayCinematic;

	UPROPERTY(Config)
	bool bDisableElectraForReplayCinematicOnWin7;

	UPROPERTY(Config)
	bool bDisableElectraForReplayCinematicOnWin7AndWin8;

	UPROPERTY(Config)
	float ProbabilityOfUsingElectraForReplayCinematic;

	UPROPERTY(Config)
	float OpenTimeLimitForReplayCinematic;

	UPROPERTY(Config)
	float DurationTimeLimitForReplayCinematic;

	UPROPERTY(Config)
	float DurationExtraTimeForReplayCinematic;

	UPROPERTY(Config)
	bool bAllowElectraForWatchBattlePassMovie;

	UPROPERTY(Config)
	bool bShowExtendedBattlePassMovie;

	UPROPERTY(Config)
	float ProbabilityOfUsingElectraForWatchBattlePassMovie;

	UPROPERTY(Config)
	float OpenTimeLimitForWatchBattlePassMovie;

	UPROPERTY(Config)
	bool bAllowForceDefaultAudioTrack;

	UPROPERTY(Config)
	int64 MemoryRequirementForMediaStreamingMB;

	UPROPERTY(Config)
	TArray<FString> LiveStreamingCDNs;

	UPROPERTY(Config)
	TArray<FString> VODStreamingCDNs;

	UPROPERTY(Config)
	TArray<FString> LiveStreamingCDNsCN;

	UPROPERTY(Config)
	TArray<FString> VODStreamingCDNsCN;

	UPROPERTY(Config)
	int32 MaxResolutionForMediaStreaming;

	UPROPERTY(Config)
	int32 MaxResolutionForStandalonePlayer;

	UPROPERTY(Config)
	TArray<FString> RiskyReelsPlaylistDenylistFilter;

	UPROPERTY(Config)
	TArray<FString> RadioPlaylistDenylistFilter;

	UPROPERTY(Config)
	bool bRegionCN;

	UPROPERTY(Transient)
	float GlobalSnowAltitude;

	UPROPERTY(Transient)
	float GlobalSnowRadius;

	UPROPERTY(Transient)
	FVector GlobalSnowOrigin;

protected:
	UPROPERTY(Config)
	bool bEnableHestia;

	UPROPERTY(Config)
	bool bEnableIronCityAutoAmplifierPlacement;

	UPROPERTY(Config)
	bool bEnableWargameDebug;

	UPROPERTY(Config)
	bool bEnableEnduranceDebug;

	UPROPERTY(Config)
	bool bEnableTrapScoringCrafting;

	UPROPERTY(Config)
	bool bEnableTrapScoringPlacement;

	UPROPERTY(Config)
	bool bEnableTrapScoringActivation;

private:
	UPROPERTY(Config)
	TArray<FSubGameAccess> SubGameAccess;

};

