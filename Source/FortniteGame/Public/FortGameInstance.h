// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Misc/Guid.h"
#include "UObject/SoftObjectPath.h"
#include "WebJSFunction.h"
#include "Diagnostics/ScriptDiagnosticMessage.h"
#include "FortPlaylistTypes.h"
#include "McpCatalogEnums.h"
#include "OnlineAccount.h"
#include "FortGameInstance.generated.h"

class AActor;
class AContentBeaconClientV2;
class AFortGameState;
class UCurveTable;
class UDAD_CreativeUserOptionsCollection;
class UDAD_IslandQuerier;
class UDataAssetDirectoryManager;
class UDataTable;
class UFortAppActivationSoundMixManager;
class UFortChat;
class UFortCreativeDiscoverySurfaceManager;
class UFortInteractabilityTracker;
class UFortInventoryManager;
class UFortIslandLockManager;
class UFortIslandManager;
class UFortLinkDataManager;
class UFortLocalPlayer;
class UFortLockerConfigManager;
class UFortMatchAnalytics;
class UFortMatchmaking;
class UFortMatchmakingV2;
class UFortMaterialCacheManager;
class UFortMissionGenerator;
class UFortPartySpectateAnalytics;
class UFortPlaylistManager;
class UFortPushNotificationManager;
class UFortRatingDataManager;
class UFortRegisteredPlayerInfo;
class UFortRejoinCheck;
class UFortSeasonalEventManager;
class UFortSocialManager;
class UFortTooltipManager;
class UFortTournamentManager;
class UFortUpdateManager;
class UMcpProfileManager;
class UPegasusDriver;
class UReplayVideoManager;
class USaveFrameworkInventorySys;
class USidecarSys;
class UVideoExtractionBootstrapper;
enum class EClientContentReadinessV2 : uint8;
enum class EFortGameFeature : uint8;
enum class ESubGame : uint8;

UENUM()
namespace EDynamicSoundOverride
{
	enum Type
	{
		Cue = 0,
		Wave = 1,
		Class = 2,
	};
}

UENUM(BlueprintType)
enum class EPlayerQueueType : uint8
{
	Player = 0,
	BroadcastSpectator = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortKairosLoadElectraPlayerDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortOnSubGameChangedBP, ESubGame, NewSubGame);

USTRUCT(BlueprintType)
struct FAthenaDataTableSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UDataTable> LootTierData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UDataTable> LootPackages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UDataTable> RangedWeapons;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UCurveTable> GameData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UCurveTable> ResourceRates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UCurveTable> VehicleData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Playlist")
	TObjectPtr<UCurveTable> AILootOnDeathData;

};

USTRUCT()
struct FAudioDynamicSoundData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Name;

	UPROPERTY()
	TEnumAsByte<EDynamicSoundOverride::Type> SoundOverrideType;

	UPROPERTY()
	float Volume;

};

UCLASS(MinimalAPI)
class UFortGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceResponse(MCP))
	bool CancelUninstallAllOptionalContentOnNextBoot();

	UFUNCTION(ServiceResponse(MCP))
	bool CancelUninstallFortniteBROnNextBoot();

	UFUNCTION(Exec)
	void ChangeActiveGameFeature(const FString& FeatureString);

	UFUNCTION(ServiceResponse(MCP))
	void CheckLatestClient(FWebJSResponse Response);

	UFUNCTION(BlueprintCallable)
	void ClearOverrideCurrentMusicFFT();

	UFUNCTION(Exec)
	void ContinueDelayedStartup();

	UFUNCTION(Exec)
	void DebugCreateBackgroundPlayer(int32 ControllerId);

	UFUNCTION(Exec)
	void DebugCreatePlayerWithLoginInfo(int32 ControllerId, const FString& Email, const FString& Password);

	UFUNCTION(ServiceResponse(MCP))
	void GetAnalyticsSessionDetails(FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void GetContentState(EFortGameFeature Feature, FWebJSResponse Response);

	UFUNCTION(BlueprintPure)
	UDAD_CreativeUserOptionsCollection* GetDADCreativeUserOptionsCollection() const;

	UFUNCTION(BlueprintPure)
	UDAD_IslandQuerier* GetDADIslandQuerier() const;

	UFUNCTION(BlueprintPure)
	UDataAssetDirectoryManager* GetDataAssetDirectoryManager() const;

	UFUNCTION(BlueprintPure)
	UFortSeasonalEventManager* GetEventManager() const;

	UFUNCTION(ServiceResponse(MCP))
	void GetFeatureRequiredSizes(EFortGameFeature Feature, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void GetFeatureRequiredSizesOptionalOnly(EFortGameFeature Feature, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void GetFeatureRequiredSizesRequiredOnly(EFortGameFeature Feature, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void GetHotfixHasApplied(FWebJSResponse Response);

	UFUNCTION(BlueprintPure)
	UFortIslandLockManager* GetIslandLockManager() const;

	UFUNCTION(BlueprintPure)
	UFortLinkDataManager* GetLinkDataManager() const;

	UFUNCTION(ServiceResponse(MCP))
	void GetProjectVersion(FWebJSResponse Response);

	UFUNCTION(BlueprintPure)
	UFortRatingDataManager* GetRatingDataManager() const;

	UFUNCTION(ServiceResponse(MCP))
	void GetUserSetting(const FString& Key, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void IsContentUpToDate(EFortGameFeature Feature, FWebJSResponse Response);

	UFUNCTION(BlueprintPure)
	bool IsCurrentlyShowingLoadingScreen() const;

	UFUNCTION(ServiceResponse(MCP))
	void KairosSubmitBugReport(const FString& Subject, const FString& Body, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	void OpenUpdateApp();

	UFUNCTION(ServiceResponse(MCP))
	void RequestBroadcast();

	UFUNCTION(ServiceResponse(MCP))
	void SetErrorSimulationCommands(const FString& CommandLine);

	UFUNCTION(ServiceResponse(MCP))
	void SetFeatureStatusCallback(FWebJSFunction Callback);

	UFUNCTION(ServiceResponse(MCP))
	void SetHotfixCompleteCallback(FWebJSFunction Callback);

	UFUNCTION(ServiceResponse(MCP))
	void SetMultipleUserSettings(const TMap<FString, FString>& Settings, FWebJSResponse Response);

	UFUNCTION(BlueprintCallable)
	void SetOverrideCurrentMusicFFT(float FFT100hz, float FFT2000hz);

	UFUNCTION(ServiceResponse(MCP))
	void SetUserSetting(const FString& Key, const FString& Value, FWebJSResponse Response);

	UFUNCTION(ServiceResponse(MCP))
	bool UninstallAllOptionalContentOnNextBoot(bool bRestartApp, bool bPromptForRestart);

	UFUNCTION(ServiceResponse(MCP))
	bool UninstallFortniteBROnNextBoot(bool bRestartApp, bool bPromptForRestart);

	UPROPERTY(BlueprintAssignable)
	FFortKairosLoadElectraPlayerDelegate OnKairosLoadElectraPlayer;

	UPROPERTY(Config)
	TSet<FName> EventFlagsForcedOnByHotfix;

	UPROPERTY(Config)
	TSet<FName> EventFlagsForcedOffByHotfix;

	UPROPERTY(Config)
	TSet<FString> CosmeticsBlacklistedByHotfix;

	UPROPERTY(Config)
	TSet<FString> CosmeticsBlacklistedByHotfixInCompetitive;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfixInCampaign;

	UPROPERTY(Config)
	TSet<FString> CosmeticsProhibitedByHotfixInAthena;

	UPROPERTY(Config)
	TSet<FString> NiagaraAssetsBlacklistedByHotfix;

	UPROPERTY(Config)
	TSet<FString> CascadeAssetsBlockedByHotfix;

	UPROPERTY(Config)
	bool bBattleRoyaleMatchmakingEnabled;

	UPROPERTY(Config)
	bool bCreativeModeProfileEnabled;

	UPROPERTY(Config)
	TArray<FPlaylistOverrideData> PlaylistOverrides;

	UPROPERTY(Config)
	TArray<FAudioDynamicSoundData> DynamicSoundData;

	UPROPERTY(Config)
	TArray<FPlaylistFrontEndSettings> FrontEndPlaylistData;

	UPROPERTY(Config)
	bool bDeprecatePlaylistAccessData;

	UPROPERTY()
	FAthenaDataTableSet AthenaDataTables;

	UPROPERTY(Transient)
	TMap<TSoftObjectPtr<UDataTable>, TObjectPtr<UDataTable>> CachedBaseDataTables;

	UPROPERTY(Transient)
	TMap<TSoftObjectPtr<UCurveTable>, TObjectPtr<UCurveTable>> CachedBaseCurveTables;

	UPROPERTY(Transient)
	bool bOverridingCurrentEmoteMusicFFT;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameInstance")
	float CurrentEmoteMusicFFT100hz;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameInstance")
	float CurrentEmoteMusicFFT2000hz;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortGameInstance")
	float EmoteMusicEnvelopeBeatCount;

private:
	UFUNCTION()
	void OnContentBeaconGameFeatureActive(const FString& ContentURL);

	UFUNCTION()
	void OnContentBeaconGameFeatureDeactive(const FString& ContentURL);

	UFUNCTION()
	void OnContentMessageAdded(const FString& NewContentMessage);

	UFUNCTION()
	void OnContentReadinessChanged(EClientContentReadinessV2 ContentReadiness);

	UFUNCTION()
	void OnGameStateSetInternalCallback(AFortGameState* GameState);

	UFUNCTION()
	void OnScriptDiagnosticMessage(const FScriptDiagnosticMessage& Message);

	UFUNCTION()
	void OnScriptScreenLogMessage(const FScriptScreenLogMessage& Message);

	UFUNCTION()
	void OnScriptScreenLogMessageWithLocalization(const FScriptScreenLogMessageWithLocalization& Message);

	UFUNCTION()
	void OnTournamentDataRefreshed();

	UPROPERTY(Transient)
	TSet<FString> LoadedGameFeaturePluginURLsForActivePlaylist;

	UPROPERTY()
	TObjectPtr<UMcpProfileManager> ProfileManager;

	UPROPERTY()
	TObjectPtr<UFortInventoryManager> InventoryManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortMatchmaking> Matchmaking;

	UPROPERTY(Transient)
	TObjectPtr<UFortMatchmakingV2> MatchmakingV2;

	UPROPERTY(Transient)
	TObjectPtr<UFortRejoinCheck> RejoinCheck;

	UPROPERTY(Transient)
	TObjectPtr<UFortSocialManager> SocialManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortIslandManager> IslandManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortMatchAnalytics> MatchAnalytics;

	UPROPERTY(Transient)
	TObjectPtr<UFortPartySpectateAnalytics> PartySpectateAnalytics;

	UPROPERTY(Transient)
	TObjectPtr<USidecarSys> SidecarSys;

	UPROPERTY(Transient)
	TObjectPtr<USaveFrameworkInventorySys> SaveFrameworkInventorySys;

	UPROPERTY(Transient)
	FGuid GlobalUnregistrationSaveGUID;

	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipManager> TooltipManager;

	UPROPERTY()
	TArray<TObjectPtr<UFortRegisteredPlayerInfo>> RegisteredPlayers;

	UPROPERTY(Transient)
	TObjectPtr<UFortUpdateManager> UpdateManager;

	UPROPERTY(Transient)
	TObjectPtr<UDataAssetDirectoryManager> DataAssetDirectoryManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortInteractabilityTracker> InteractabilityTracker;

	UPROPERTY(Transient, Instanced)
	TObjectPtr<UFortChat> ChatRoom;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UFortRegisteredPlayerInfo>> RegisteredPlayerInfosAwaitingRefresh;

	UPROPERTY(Transient)
	FString LastGameHighlightGroupId;

	UPROPERTY(Transient)
	TObjectPtr<UFortSeasonalEventManager> SeasonalEventManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortTournamentManager> TournamentManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortPushNotificationManager> MobilePushNotificationManager;

	UPROPERTY(Config)
	float BroadcastFeatureStatusRate;

	UPROPERTY(Transient)
	TObjectPtr<UFortMissionGenerator> CurrentMissionGenerator;

	UPROPERTY(Transient, BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FFortOnSubGameChangedBP OnSubGameChangedBP;

	UPROPERTY(Transient)
	TObjectPtr<UFortAppActivationSoundMixManager> AppActivationSoundMixManager;

	UPROPERTY(Config)
	int32 KairosUIResX;

	UPROPERTY(Config)
	int32 KairosUIResY;

	UPROPERTY(Config)
	TArray<FWebEnvUrl> KairosWebUrls;

	UPROPERTY(Config)
	int32 KairosMinSupportedAppVersion;

	UPROPERTY(Config)
	float KairosHotfixCheckTimer;

	UPROPERTY(Config)
	float KairosHotfixCheckVariance;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistManager> PlaylistManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortLockerConfigManager> LockerConfigManager;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortLocalPlayer>> LoggedInPlayers;

	UPROPERTY(Config)
	TArray<EAppStore> StoreSupport;

	UPROPERTY(Config)
	TArray<EAppStore> StoreSupport_Android_Samsung;

	UPROPERTY(Config)
	TArray<EAppStore> StoreSupport_Android_SideloadSamsung;

	UPROPERTY(Config)
	TArray<EAppStore> StoreSupport_Android_SideloadOther;

	UPROPERTY(Config)
	TArray<EAppStore> StoreSupportPartner;

	UPROPERTY(Transient)
	TObjectPtr<UFortMaterialCacheManager> MaterialCacheManager;

	UPROPERTY(Transient)
	TObjectPtr<UReplayVideoManager> ReplayVideoManager;

	UPROPERTY(Transient)
	TObjectPtr<UVideoExtractionBootstrapper> ExtractionBootstrapper;

	UPROPERTY(Transient)
	TObjectPtr<UPegasusDriver> PegasusDriver;

	UPROPERTY(Config)
	FSoftClassPath ContentBeaconClientV2ClassPath;

	UPROPERTY(Transient)
	TWeakObjectPtr<AContentBeaconClientV2> ContentBeaconClientV2;

	UPROPERTY(Transient)
	TWeakObjectPtr<AContentBeaconClientV2> MatchmakingContentBeacon;

	UPROPERTY(Transient)
	TObjectPtr<UDAD_IslandQuerier> DADIslandQuerier;

	UPROPERTY(Transient)
	TObjectPtr<UDAD_CreativeUserOptionsCollection> DADCreativeUserOptionsCollection;

	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeDiscoverySurfaceManager> CreativeDiscoverySurfaceManager;

	UPROPERTY(Config)
	TArray<TSoftClassPtr<AActor>> DisabledPhysicsAssets;

};

