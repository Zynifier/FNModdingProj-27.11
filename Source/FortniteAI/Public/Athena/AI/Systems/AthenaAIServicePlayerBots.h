// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "AI/DebugMinimapData.h"
#include "Athena/AI/Datatables/MMRSpawningBracketTable.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "Athena/AI/Systems/FortBotPOI.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/FortBotItemDataTable.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "AthenaAIServicePlayerBots.generated.h"

class AActor;
class ABuildingFoundation;
class AController;
class AFortAIBotDebugActor;
class AFortAIBotPOIDebugActor;
class AFortAthenaAIBotController;
class AFortGameStateAthena;
class AFortPawn;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStartWarmup;
class AFortPlayerStateAthena;
class AFortPoiVolume;
class AFortTeamInfoAthena;
class AFortWeapon;
class APawn;
class IFortAIAimingManagerInterface;
class UAthenaAIPopulationTracker;
class UAthenaAIServicePlayerBots;
class UBehaviorTree;
class UCacheSafeZoneLocation;
class UCurveFloat;
class UDataRegistry;
class UDataTable;
class UEnvQuery;
class UFortAthenaAIBotNameDataAsset;
class UFortAthenaAISpawnerData;
class UFortAthenaAISpawnerDataComponentList;
class UFortAthenaAISpawnerDataComponent_SpawnParamsBase;
class UFortAthenaBeaconComponent;
class UFortGameStateComponent_BattleRoyaleGamePhaseLogic;
class UFortPlaylist;

UENUM(BlueprintType)
enum EAthenaAIServicePOIList
{
	/** BattleBusTagQueryPOIList */
	MainBusDrop = 0,
	/** SecondaryBattleBusTagQueryPOIList */
	SecondaryBusDrop = 1,
	/** OnGroundTagQueryPOIList */
	OnGround = 2,
};

USTRUCT(BlueprintType)
struct FBattleBusPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="POI Selection")
	FScalableFloat IsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="POI Selection")
	FGameplayTagQuery POIFilterQuery;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPoiVolume>> ValidPOIVolumeList;

};

USTRUCT()
struct FCachedPOIVolumeLocations
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortPoiVolume> POIVolume;

};

USTRUCT()
struct FFortBotBackfillSpawnRequest
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortBotDisablePOIRequest
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIServicePlayerBots> CachedAIServicePlayerBots;

};

USTRUCT()
struct FFortServerBotInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> BotController;

	UPROPERTY(Transient)
	TObjectPtr<AFortPoiVolume> SelectedPoiVolume;

};

USTRUCT()
struct FMMRSpawningInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FMMRSpawningPlayerBotsRuntimeInfo : public FMMRSpawningBaseRuntimeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FMMRSpawningInfo> SpawningInfos;

};

USTRUCT(BlueprintType)
struct FNavigationPOI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="POI Selection")
	FScalableFloat IsEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="POI Selection")
	FGameplayTagQuery POIFilterQuery;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPoiVolume>> ValidPOIVolumeList;

};

USTRUCT()
struct FUpdateBotSkillInfo
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UAthenaAIServicePlayerBots : public UAthenaAIService, public INavAgentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API int32 FetchNextCustomBotCosmeticVariantID(const AFortPlayerPawnAthena* BotPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEAI_API bool IsWeaponSupported(AFortWeapon* FortWeapon);

	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void JoinTeam(const AController* SourceTeamController, AController* DestinationTeamController);

	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void KillBots(bool bKillPlayers, bool bKillNPCs, uint8 TeamIndex, AActor* BotOwner);

	UFUNCTION(BlueprintCallable, meta=(DeprecatedFunction, DeprecationMessage="This function is no longer supported.  Use AthenaAISpawner (GetAISpawner in BP) to request an async bot spawn request instead."))
	FORTNITEAI_API APawn* SpawnAI(const FVector& InSpawnLocation, const FRotator& InSpawnRotation, const UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList);

protected:
	UFUNCTION()
	FORTNITEAI_API virtual void OnAgentGameOver(AFortAthenaAIBotController* AIBotController, AFortPawn* Pawn, AController* Instigator);

	UFUNCTION()
	FORTNITEAI_API virtual void OnGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event);

	UFUNCTION()
	FORTNITEAI_API virtual void OnGamePhaseLogicReady(const FFortBattleRoyaleGamePhaseLogicComponentReadyEvent& Event);

	UFUNCTION()
	FORTNITEAI_API void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

private:
	UFUNCTION(BlueprintCallable)
	FORTNITEAI_API void AddPOIVolume(AFortPoiVolume* POIVolume, EAthenaAIServicePOIList POIList);

	UFUNCTION()
	FORTNITEAI_API void OnAIPawnSpawned(AController* SpawnedController, bool bIsABot, AFortPawn* FortAIPawn, AFortPlayerPawn* PlayerPawn);

	UFUNCTION()
	FORTNITEAI_API void OnSafeZoneUpdated(const FFortSafeZonePhaseUpdatedEvent& Event);

	UFUNCTION()
	FORTNITEAI_API void OnServerGameMemberRemoved(uint8 InSquadId, uint8 InTeamIndex, AFortPlayerStateAthena* ChangedPS);

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAISpawnerDataComponentList> DefaultAISpawnerDataComponentList;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAISpawnerDataComponent_SpawnParamsBase> DefaultAISpawnComponent;

	UPROPERTY(Transient)
	TArray<FFortServerBotInfo> DeadBots;

	UPROPERTY(Transient)
	TArray<FFortServerBotInfo> PlayerBotsRestartLeft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ziplines", meta=(AllowPrivateAccess="true"))
	FVector ZiplineOctreeCenter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ziplines", meta=(AllowPrivateAccess="true"))
	FScalableFloat ZiplineOctreeRadius;

	UPROPERTY(EditDefaultsOnly, Category="Ziplines")
	FScalableFloat UseZiplines;

	UPROPERTY(EditDefaultsOnly, Category="Debugging", meta=(AllowPrivateAccess="true"))
	FDebugMinimapData DebugMinimapData;

	UPROPERTY(EditDefaultsOnly, Category="Debugging")
	FName MarkPlayerBotsAggressiveStencilName;

	UPROPERTY(EditDefaultsOnly, Category="Debugging")
	FName MarkPlayerBotsDefensiveStencilName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	bool bBotHostileToHumanPlayersOnly;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseAllBattleBusPOIsSquadRatio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UCurveFloat> TagQueryWeightChance;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> FindLocationsAroundPOIQuery;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true", DisplayName="Main Bus Drop POIs"))
	TArray<FBattleBusPOI> BattleBusTagQueryPOIList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true", DisplayName="Secondary Bus Drop POIs"))
	TArray<FBattleBusPOI> SecondaryBattleBusTagQueryPOIList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Navigation", meta=(AllowPrivateAccess="true"))
	TArray<FNavigationPOI> OnGroundTagQueryPOIList;

	UPROPERTY(EditDefaultsOnly, Category="Construction", meta=(AllowPrivateAccess="true", ArraySizeEnum="/Script/FortniteAI.EConstructionBuildingType"))
	FConstructionBuildingInfo ConstructionBuildingInfo[6];

	UPROPERTY(EditDefaultsOnly, Category="Items")
	FScalableFloat UseCustomSupportedItemList;

	UPROPERTY(EditDefaultsOnly, Category="Items")
	TObjectPtr<UDataTable> BotItemDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Items")
	FName AugmentsRegistryName;

	UPROPERTY(EditDefaultsOnly, Category="Item Behaviors")
	TObjectPtr<UDataRegistry> ItemBehaviorsRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Item Behaviors")
	TArray<TObjectPtr<UBehaviorTree>> InjectionSupportingBehaviors;

	UPROPERTY(EditDefaultsOnly, Category="Visibility")
	TObjectPtr<UDataRegistry> VisibilitySettingsRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Visibility")
	FGameplayTagContainer PerceivedActorTagsToAdd;

	UPROPERTY(EditDefaultsOnly, Category="Names")
	FScalableFloat UseRegionalNameList;

	UPROPERTY(EditDefaultsOnly, Category="Names")
	FScalableFloat MaxAnonymousBotCount;

	UPROPERTY(EditDefaultsOnly, Category="Names", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaAIBotNameDataAsset> BotNameDataAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	FScalableFloat CosmeticVariationCount;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat ThankBusDriverProbability;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat ThankBusDriverMinTime;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat ThankBusDriverMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat TriggerEndGameBehaviorMinTime;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat TriggerEndGameBehaviorMaxTime;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat ShowSeasonLevelProbability;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FScalableFloat SpectateOthersOnDeath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxNumberOfBotsToSpawnAroundPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	float MaxAroundBotDistanceToSearchPOIToLand;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Backfill", meta=(AllowPrivateAccess="true"))
	FScalableFloat BackfillEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Backfill", meta=(AllowPrivateAccess="true"))
	FScalableFloat UsePlayerCosmeticForBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Backfill", meta=(AllowPrivateAccess="true"))
	FScalableFloat UsePlayerInventoryForBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Backfill", meta=(AllowPrivateAccess="true"))
	FScalableFloat OnlyUseBackfillDuringSafezones;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Backfill", meta=(AllowPrivateAccess="true"))
	TSoftClassPtr<UFortAthenaAISpawnerData> BackfillSpawnerData;

	UPROPERTY(Transient)
	FGameplayTagContainer SupportedItemTags;

	UPROPERTY(Transient)
	TArray<FCachedPOIVolumeLocations> CachedValidPOIVolumeLocations;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingFoundation>> CachedBuildingFoundations;

	UPROPERTY(Transient)
	TArray<FFortBotAugmentsDataTableRow> CachedSupportedAugments;

	UPROPERTY(Transient)
	TScriptInterface<IFortAIAimingManagerInterface> CachedAIAimingManager;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStartWarmup> LastTeamPlayerStart;

	UPROPERTY(Transient)
	TMap<int32, TObjectPtr<UCacheSafeZoneLocation>> CacheSafeZoneLocationsMap;

	UPROPERTY(EditDefaultsOnly, Category="Cleanup", meta=(AllowPrivateAccess="true"))
	bool bCleanupBotsRegardlessOfRemainingSquadMembers;

	UPROPERTY(EditDefaultsOnly, Category="Cleanup", meta=(AllowPrivateAccess="true"))
	float DeadBotCleanupMinDelay;

	UPROPERTY(Transient)
	TSet<FString> ReservedPlayerNames;

	UPROPERTY(Transient)
	TArray<int32> LocationsInSafeZoneFreeIndices;

	UPROPERTY(Transient)
	TObjectPtr<AFortTeamInfoAthena> CurrentFillingTeam;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Names", meta=(AllowPrivateAccess="true"))
	FScalableFloat BotsUniqueIDUseValidAccountID;

	UPROPERTY(Transient)
	int32 CurrentBotControllerUID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortAthenaBeaconComponent>> BeaconList;

	UPROPERTY(EditDefaultsOnly, Category="Map Sampling", meta=(AllowPrivateAccess="true"))
	uint8 bWaitForNavmeshToBeLoaded : 1;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	uint8 bDoSpawnBotFlow : 1;

	UPROPERTY(EditDefaultsOnly, Category="Map Sampling", meta=(AllowPrivateAccess="true"))
	uint8 bDoMapSampling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	EAthenaGamePhase GamePhaseToStartSpawning;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaAISpawnerData> DefaultBotAISpawnerData;

	UPROPERTY(EditDefaultsOnly, Category="Map Sampling", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> EQSMapSampling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanReviveDownedSquad;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIPopulationTracker> CachedAIPopulationTracker;

	UPROPERTY(Transient)
	TArray<FFortServerBotInfo> PlayerBots;

	UPROPERTY(Transient)
	TArray<FFortServerBotInfo> NonAthenaParticipantBots;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UDataTable> MMRSpawnTable;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	TArray<TSoftObjectPtr<UDataTable>> MMRSpawnTableOverrides;

	UPROPERTY(Transient)
	FMMRSpawningPlayerBotsRuntimeInfo CachedMMRSpawningInfo;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FScalableFloat OverridePOISpreadingSquadCount;

	UPROPERTY(EditDefaultsOnly, Category="General", meta=(AllowPrivateAccess="true"))
	FScalableFloat OnlyPickPOIsInSafeZone;

	UPROPERTY(EditDefaultsOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	FVector KillVolumeOverlapCheckHalfExtent;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="Dynamic BotPOI Enabled"))
	FScalableFloat DynamicBotPOIEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="BotPOI EQS"))
	TSoftObjectPtr<UEnvQuery> BotPOIEQS;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Minimum Weight For Squad Members"))
	FScalableFloat BotPOIMinimumWeightForSquadMembers;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="Next POI Duration Second By Weight"))
	FScalableFloat BotPOINextPOIDurationSecondByWeight;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="Next POI Min Duration"))
	FScalableFloat BotPOINextPOIMinDuration;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="Next POI Max Duration"))
	FScalableFloat BotPOINextPOIMaxDuration;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Excluded Zones Table"))
	TObjectPtr<UDataRegistry> BotPOIExcludedZonesDataRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI", meta=(AllowPrivateAccess="true", DisplayName="Dynamic POI Point Provider Tags"))
	FGameplayTagContainer DynamicPOIPointProviderTags;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Bus Phase", meta=(AllowPrivateAccess="true", DisplayName="JumpOffBus With Dynamic POI Enabled"))
	FScalableFloat JumpOffBusWithDynamicPOIEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Bus Phase", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Jump Main POI Count Max"))
	FScalableFloat BotPOIJumpMainPOICountMax;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Bus Phase", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Squad Jump On Main POI Count Max"))
	FScalableFloat BotPOISquadJumpOnMainPOICountMax;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Bus Phase", meta=(AllowPrivateAccess="true", DisplayName="Deny JumpBusBotPOI By Proximity Enabled"))
	FScalableFloat DenyJumpBusBotPOIByProximityEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Bus Phase", meta=(AllowPrivateAccess="true", DisplayName="Deny JumpBusBotPOI Distance"))
	FScalableFloat DenyJumpBusBotPOIDistance;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="Navigation With Dynamic POI Enabled"))
	FScalableFloat NavigationWithDynamicPOIEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="Fail To Reach BotPOI CountMax"))
	FScalableFloat FailToReachBotPOICountMax;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Scoring Weight Factor"))
	FScalableFloat BotPOIScoringWeightFactor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Scoring Distance Factor"))
	FScalableFloat BotPOIScoringDistanceFactor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Scoring Occupancy Factor"))
	FScalableFloat BotPOIScoringOccupancyFactor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="BotPOI Scoring Visited Factor"))
	FScalableFloat BotPOIScoringVisitedFactor;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic POI - Navigation", meta=(AllowPrivateAccess="true", DisplayName="Chance To Use Next SafeZone"))
	FScalableFloat ChanceToUseNextSafeZone;

	UPROPERTY(Transient)
	int32 BotPOIIdCount;

	UPROPERTY(Transient)
	int32 BotPOISquadJumpedOnMainPOICount;

	UPROPERTY(Transient)
	TArray<int32> StartupPOIPendingEQSRequestIDList;

	UPROPERTY(Transient)
	TArray<FBotPOI> BotPOIList;

	UPROPERTY(Transient)
	TArray<FBotPOI> CachedMainJumpBotPOIList;

	UPROPERTY(Transient)
	TArray<FBotPOI> CachedSecondaryJumpBotPOIList;

	UPROPERTY(Transient)
	TArray<FBotPOIExcludedZone> CachedBotPOIExcludedZonesList;

	UPROPERTY(Transient)
	bool bIsBotPOIJumpListSplit;

	UPROPERTY(Transient)
	bool bIsExcludedZoneGenerated;

	UPROPERTY(Transient)
	TObjectPtr<AFortAIBotPOIDebugActor> BotPOIDebugDebugActor;

	UPROPERTY(Transient)
	bool bCheatBotPOIDebugMiniMapEnabled;

	UPROPERTY(Transient)
	TObjectPtr<AFortAIBotDebugActor> BotDebugDebugActor;

	UPROPERTY(Transient)
	bool bCheatBotDebugMiniMapEnabled;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_BattleRoyaleGamePhaseLogic> CachedGamePhaseLogic;

};

UCLASS()
class UCacheSafeZoneLocation : public UObject
{
	GENERATED_BODY()

};

