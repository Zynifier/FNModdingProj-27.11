// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortReleaseVersion.h"
#include "GameData/FortTableCache.h"
#include "FortPlaylist.generated.h"

class AInfo;
class UCurveTable;
class UDataTable;
class UFortConditionalAssetGroup;
class UFortGameplayModifierItemDefinition;
class UFortItemDefinition;
class UFortSharedAssetGroup;
class UFortSharedAssetList;
class UFortWorldItemDefinition;
class UPlaylistUserOptions;
class USoundBase;
class UWorld;

UENUM(BlueprintType)
enum class EDBNOType : uint8
{
	// Normal DBNO rules

	On = 0,
	// Never any DBNO

	Off = 1,
	// DBNO will only happen when respawning is not on

	NotWhenRespawning = 2,
};

UENUM()
enum class EFortGameType : int32
{
	BR = 0,
	ZeroBuild = 1,
	Creative = 2,
	CreativeLTM = 3,
	Playground = 4,
	STW = 5,
	BRArena = 6,
	BRLTM = 7,
	Social = 8,
	VKEdit = 9,
	VKPlay = 10,
	//always at the end

	MAX = 11,
};

UENUM(BlueprintType)
enum class EFriendlyFireType : uint8
{
	Off = 0,
	On = 1,
};

UCLASS()
class UFortConditionalAssetGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TMap<FString, TObjectPtr<UFortSharedAssetList>> ConditionalAssetsToLoad;

};

UCLASS(Config=Game, PerObjectConfig, MinimalAPI)
class UFortPlaylist : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion", meta=(Patchable))
	FFortReleaseVersion FortReleaseVersion;
#endif

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Playlist", meta=(Patchable))
	int32 PlaylistId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="Playlist", meta=(Patchable))
	FName PlaylistName;

	UPROPERTY(EditDefaultsOnly, Category="Playlist", meta=(Patchable))
	EFortGameType GameType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MinPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bUnderfillMatchmaking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(EditCondition="bUnderfillMatchmaking", Patchable))
	int32 UnderfilledMaxPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bOverrideMaxPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(EditCondition="bOverrideMaxPlayers", Patchable))
	int32 MaxHumanAndBotParticipants;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxTeamCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxTeamSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxSocialPartySize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxSquadSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 MaxSquads;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool EnforceSquadFill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowSquadFillOption;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(EditCondition="!bAllowSquadFillOption", Patchable))
	bool bShouldFillWhenNoSquadFillOption;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Playlist", meta=(Patchable))
	bool bAllowJoinInProgress;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	FText JoinInProgressMatchType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 EndOfMatchXpFirstElim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	int32 EndOfMatchXpMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist")
	TObjectPtr<UPlaylistUserOptions> UserOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bEnableBackfillDuringWarmupPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(EditCondition="bEnableBackfillDuringWarmupPhase", Patchable))
	float TimeAfterWarmupToDisableBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	FName RichPresenceAssetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowKeepPlayingTogether;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowPartyRift;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowSquadSizeTracking;

	UPROPERTY(EditDefaultsOnly, Category="Level")
	TSoftObjectPtr<UWorld> PreloadPersistentLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Level")
	TArray<TSoftObjectPtr<UWorld>> AdditionalLevels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Level")
	TArray<TSoftObjectPtr<UWorld>> AdditionalLevelsServerOnly;

	UPROPERTY(EditDefaultsOnly, Config, Category="Gameplay", meta=(Patchable))
	TArray<FString> BuiltInGameFeaturePluginsToLoad;

	UPROPERTY(Config, Transient)
	FString OverrideLinkIdToDownload;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortPlaylist")
	FString GameFeaturePluginToActivateUntilDownloadedContentIsPresent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	uint8 DefaultFirstTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	uint8 DefaultLastTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	FGameplayTagContainer GameplayTagContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	EFriendlyFireType FriendlyFireType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	bool bUseFriendlyFireAimAssist;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable, PlayerMax="3", PlayerMin="1"))
	int32 LootLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	FGameplayTagQuery LootTagQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	int32 BuildingLevelOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	EDBNOType DBNOType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	FScalableFloat SpawnImmunityTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	TArray<EAthenaGamePhaseStep> SkippedGamePhaseNotification;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(AssetBundles="Equipped", Patchable))
	TArray<TSoftObjectPtr<UFortGameplayModifierItemDefinition>> ModifierList;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(AssetBundles="Equipped", MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> TimeOfDayManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	bool bIgnoreWeatherEvents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TArray<TObjectPtr<UFortItemDefinition>> ItemsToFullyLoad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TObjectPtr<UFortSharedAssetGroup> SharedAssetGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TObjectPtr<UFortConditionalAssetGroup> ConditionalAssetGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI", meta=(Patchable))
	bool bIsDefaultPlaylist;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI", meta=(Patchable))
	FText UIDisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI", meta=(MultiLine="TRUE", Patchable))
	FText UIDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	FGameplayTagContainer HUDElementsToHide;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	bool bUseCustomInGameState;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> RangedWeapons;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped", Patchable))
	TSoftObjectPtr<UCurveTable> GameData;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UCurveTable> ResourceRates;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> SkydiveMusic;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> SkydiveMusicOutroStinger;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<USoundBase> RespawnStinger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Audio", meta=(AssetBundles="Client"))
	TSoftObjectPtr<USoundBase> MatchMakingSucceededSound;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	float GarbageCollectionFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	float ServerPerformanceEventFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	float ServerMetricsEventFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Localization", meta=(Patchable))
	bool bUseLocalizationService;

	UPROPERTY(EditDefaultsOnly, Config, Category="Gameplay", meta=(Patchable))
	TArray<FString> GameFeaturePluginURLsToLoad;

protected:
	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped", Patchable))
	TSoftObjectPtr<UDataTable> LootTierData;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped", Patchable))
	TSoftObjectPtr<UDataTable> LootPackages;

	UPROPERTY(EditDefaultsOnly, Category="EditDefaultsOnly", meta=(AssetBundles="Client,Server"))
	TArray<FFortPlaylistBaseCurveTableOverride> BaseCurveTableOverrides;

	UPROPERTY(EditDefaultsOnly, Category="EditDefaultsOnly", meta=(AssetBundles="Client,Server"))
	TArray<FFortPlaylistBaseDataTableOverride> BaseDataTablesOverride;

};

UCLASS()
class UFortSharedAssetGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TArray<TObjectPtr<UFortSharedAssetList>> SharedAssetsToLoad;

};

UCLASS()
class UFortSharedAssetList : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TArray<TObjectPtr<UFortWorldItemDefinition>> SharedItemsToFullyLoad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Level")
	TArray<TSoftObjectPtr<UWorld>> SharedAdditionalLevels;

};

