// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "GameplayTagContainer.h"
#include "AI/FortAITypes.h"
#include "FortEncounterDirectionEnum.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Online/FortMcpTypes.h"
#include "OnlineLinkId.h"
#include "FortCheatManager.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class AFortPlayerPawn;
class APlayerController;
class UBuildingTextureData;
enum class EAthenaCustomizationCategory : uint8;
enum class EFortAILODLevel : uint8;
enum class EFortCrucibleWhitelistLevel : uint8;
enum class EFortInputFilterLevel : uint8;
enum class EFortPartyMemberLocation : uint8;
enum class ERiftCosmeticState : uint8;

UENUM()
namespace ERepositionAllPlayers
{
	enum Type
	{
		HumanPlayers = 0,
		HumanPlayersAndPlayerBots = 1,
		HumanPlayersAndPlayerBotsAndNPCs = 2,
		AllControllers = 3,
	};
}

USTRUCT()
struct FSpawnPickupEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TSubclassOf<AActor> PickupClass;

};

UCLASS(MinimalAPI)
class UChildCheatManager : public UCheatManagerExtension
{
	GENERATED_BODY()

};

UCLASS(Config=Game, MinimalAPI)
class UFortCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool AreContextMenusEnabled(const APlayerController* PC);

	UFUNCTION(Exec)
	void BattleLabForceSave();

	UFUNCTION(Exec)
	void BattleLabResetSave();

	UFUNCTION(Exec)
	void BattleLabSetInstanceLimiting(bool bEnable);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void DeleteAllTrackedActors();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void DeleteTrackedActor(const FString& TrackedPawnName);

	UFUNCTION(Exec)
	void DoDAddIslandDependency(const FString& LinkCode = TEXT(""));

	UFUNCTION(Exec)
	void FfToTimeOfDay(float FastForwardTime, float FastForwardSpeed);

	UFUNCTION(Exec)
	void ForceResetLaunchHelper();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveResources(int32 Amount = 50);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveSpecificItem(const FString& ItemPath, int32 ItemAmount = 1, int32 ItemLevel = 0);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveWorldItem(const FString& ItemName, int32 ItemLevel = 0);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GoFast(float NewSpeed = 0.000000f);

	UFUNCTION(Exec)
	void LaunchData_ForceResetHelper();

	UFUNCTION(Exec)
	void LaunchData_JoinSession(const FString& SessionId);

	UFUNCTION(Exec)
	void LaunchData_LaunchLinkCode(const FString& LinkCode);

	UFUNCTION(Exec)
	void LoadAndActivateGameFeaturePlugin(const FString& GameFeaturePluginURL);

	UFUNCTION(Exec)
	void LoadAndActivateGameFeaturePluginViaFeatureName(const FString& GameFeatureName);

	UFUNCTION(Exec)
	void McpCheat() const;

	UFUNCTION(Exec)
	void McpCheatAthena() const;

	UFUNCTION(Exec)
	void McpCheatCampaign() const;

	UFUNCTION(Exec)
	void McpGrantItem(const FString& TemplateId, int32 Count = 1);

	UFUNCTION(Exec)
	void McpGrantItemsFromClipboard();

	UFUNCTION(Exec)
	void McpRefreshProfile();

	UFUNCTION(Exec)
	void MMS(const FString& Command);

	UFUNCTION(Exec)
	void PopLockedLoadingState();

	UFUNCTION(Exec)
	void PrintCurveTable(const FString& CurveTable);

	UFUNCTION(Exec)
	void PrintCurveTableRow(const FString& CurveTable, const FString& RowName);

	UFUNCTION(Exec)
	void ProjectEdit_UpdateContent(const FString& ProjectId);

	UFUNCTION(Exec)
	void PushLockedLoadingState(int32 LoadingState);

	UFUNCTION(Exec)
	void SetDayPhase(const FString& DayPhaseString);

	UFUNCTION(Exec)
	void SetHideSpatialCustomizationIcons(bool bShouldHide);

	UFUNCTION(Exec)
	void SetHideSpatialCustomizationText(bool bShouldHide);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetImprovedDBNO(bool bEnable);

	UFUNCTION(Exec)
	void SetLocalPlayerReady(bool bReady);

	UFUNCTION(Exec)
	void SetRespawnTimerOverride(float TimeUntilRespawn);

	UFUNCTION(Exec)
	void SetTimeOfDay(const FString& NewTimeOfDay);

	UFUNCTION(Exec)
	void SetTimeOfDayAbsoluteSpeed(float NewTimeOfDaySpeed);

	UFUNCTION(Exec)
	void SetTimeOfDayInHours(float TimeOfDayInHours);

	UFUNCTION(Exec)
	void SetTimeOfDaySpeed(float NewTimeOfDaySpeedFactor);

	UFUNCTION(Exec)
	void SetViewportResolution(int32 resx, int32 resy);

	UFUNCTION(BlueprintPure)
	static bool ShouldUseNewHeroLoadoutUI(const APlayerController* PC);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SpawnGroupOfScriptedPawnOnGrid(int32 Rows, int32 Columns, float RowPadding, float ColumnPadding, const FString& ProfileName, const float X, const float Y, const float Z, const float Pitch = 0.000000f, const float Yaw = 0.000000f, const float Roll = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual AFortPlayerPawn* SpawnScriptedPawn(const FString& ProfileName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual AFortPlayerPawn* SpawnScriptedPawnAtLocation(const FString& ProfileName, const float X, const float Y, const float Z, const float Pitch = 0.000000f, const float Yaw = 0.000000f, const float Roll = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SpawnTrackedPawnAtLocation(const FString& TrackedPawnName, bool bFriendly, const float X, const float Y, const float Z, const float Pitch = 0.000000f, const float Yaw = 0.000000f, const float Roll = 0.000000f, const float Health = 100.000000f, const float Shield = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SpawnTrackedPickupAtLocation(const FString& TrackedActorName, const FString& TrackedActorClass, int32 Quantity, const float X, const float Y, const float Z, const float Pitch = 0.000000f, const float Yaw = 0.000000f, const float Roll = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SpawnTrackedVehicleAtLocation(const FString& TrackedActorName, const FString& TrackedActorClass, bool bEnterVehicle, const float X, const float Y, const float Z, const float Pitch = 0.000000f, const float Yaw = 0.000000f, const float Roll = 0.000000f);

	UFUNCTION(Exec)
	void StartGameplayDebugger(const FString ForceClientTrigger);

	UFUNCTION(Exec)
	void TestCheckFavorite();

	UFUNCTION(Exec)
	void ToggleGamepadPlaytest() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleImprovedDBNO();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleQuickEdit();

	UFUNCTION(Exec)
	void ToggleSkipNight();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleSmartBuild();

	UFUNCTION(Exec)
	void UnloadGameFeaturePlugin(const FString& GameFeaturePluginURL);

	UFUNCTION(Exec)
	void UnloadGameFeaturePluginViaFeatureName(const FString& GameFeatureName);

	UFUNCTION(Exec)
	void UploadLogs(const FString& LogPrefix = TEXT("CheatLogUpload"), int32 TailSizeKb = 512);

	UPROPERTY()
	uint8 bDebugInteractTrace : 1;

	UPROPERTY()
	uint8 bDebugPickupSpline : 1;

	UPROPERTY()
	uint8 bEnableScoreboard : 1;

	UPROPERTY()
	uint8 bDebugBounceCurve : 1;

	UPROPERTY(Transient)
	uint8 bDebugBeautyMode : 1;

	UPROPERTY(Transient)
	uint8 bDisplayWindDebugging : 1;

	UPROPERTY(Transient)
	uint8 bDebugStructuralSupportSystem : 1;

	UPROPERTY(Transient)
	uint8 bInfiniteStamina : 1;

	UPROPERTY(Transient)
	uint8 bShowGameDifficultyHUD : 1;

	UPROPERTY(Transient)
	uint8 bShowIntensityHUD : 1;

	UPROPERTY(Transient)
	uint8 bShowMaxAIHUD : 1;

	UPROPERTY(Transient)
	uint8 bShowItemIDsOnCards : 1;

	UPROPERTY(Transient)
	uint8 bEnableContextMenus : 1;

	UPROPERTY(Transient)
	uint8 bUnlimitedHealth : 1;

	UPROPERTY(Transient)
	uint8 bCanExitWorld : 1;

	UPROPERTY(Transient)
	uint8 bUnlimitedAIHealth : 1;

	UPROPERTY(Transient)
	uint8 bFreezeAILOD : 1;

	UPROPERTY(Transient)
	uint8 bForceAILOD : 1;

	UPROPERTY(Transient)
	int32 AbilitySystemCycleCounter;

	UPROPERTY(Transient)
	EFortAILODLevel ForcedAILODValue;

	UPROPERTY(Transient)
	TSoftObjectPtr<UBuildingTextureData> TransparentTextureData;

protected:
	UFUNCTION(Exec)
	void AcceptEULA();

	UFUNCTION(Exec)
	void AddAllScores(int32 Amount);

	UFUNCTION(Exec)
	void AddBuildingScore(int32 Amount);

	UFUNCTION(Exec)
	void AddCombatScore(int32 Amount);

	UFUNCTION(Exec)
	void AddDebugEncounterTag(FName Tag);

	UFUNCTION(Exec)
	void AddDebugSpawnAIGroupTag(FName Tag);

	UFUNCTION(Exec)
	void AddFavoriteIsland(const FOnlineLinkId& IslandLinkId);

	UFUNCTION(Exec)
	void AddKillFeedMessage();

	UFUNCTION(Exec)
	void AddUtilityScore(int32 Amount);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AddWeaponModToCurrentWeapon(const FString& WeaponModName = TEXT(""), bool bIsDynamic = true);

	UFUNCTION(Exec)
	void AdvanceAllMinigameStates();

	UFUNCTION(Exec)
	void AllowRespawn();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ApplyGameplayModifier(const FString& ModifierName);

	UFUNCTION(Exec)
	void AthenaEmote(const FString& EmoteName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AthenaEndlessGame();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AthenaForceVictory(bool bVictory = true);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AthenaForceVictory_Delayed(bool bVictory = true, float DelayTime = 3.000000f);

	UFUNCTION(Exec)
	void AthenaGiveScoreTo(int32 PlayerStateIdx, int32 Score);

	UFUNCTION(Exec)
	void BackpackSetSize(int32 Size);

	UFUNCTION(Exec)
	void Badass();

	UFUNCTION(Exec)
	void BeautyMode();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BotFillUp(int32 Amount = -1);

	UFUNCTION(Exec)
	void BotPOIToggleDebugMiniMap();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void BotSpectate(const FString& BotCommand = TEXT(""));

	UFUNCTION(Exec)
	void BotStartDogpile();

	UFUNCTION(Exec)
	void BotStopDogpile();

	UFUNCTION(Exec)
	void BotToggleDebugMiniMap();

	UFUNCTION(Exec)
	void BounceContainer();

	UFUNCTION(Exec)
	void BringDownWall();

	UFUNCTION(Exec)
	void BuildFree();

	UFUNCTION(Exec)
	void BuildWith(const FString& ResourceTypeAndOrLevel);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CanExitWorld(bool bValue);

	UFUNCTION(Exec)
	void CaptureTeamToggleInput();

	UFUNCTION(Exec)
	void ChangeBotModule(const FString& PilotCategory, const FString& NewModule, bool bResetNow = false);

	UFUNCTION(Exec)
	void ChangeTeam(uint8 NewTeamNum);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CheatMountExitVan();

	UFUNCTION(Exec)
	void ClaimPortal();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ClearAllForcedAthenaCosmeticItem();

	UFUNCTION(Exec)
	void ClearDebugEncounterTags();

	UFUNCTION(Exec)
	void ClearDebugSpawnAIGroupTags();

	UFUNCTION(Exec)
	void ClearEncounterSimulatedNumberOfPlayers();

	UFUNCTION(Exec)
	void ClearEncounterSpawnPointsCap();

	UFUNCTION(Exec)
	void ClearEncounterSpawnPointsCurve();

	UFUNCTION(Exec)
	void ClearFortVolume();

	UFUNCTION(Exec)
	void ClearMapFog();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ClearRespawnTimer();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ClearScriptedPawnVariantChannels();

	UFUNCTION(Exec)
	void Collection_CollectAllFishVariants(float Length = 15.000000f);

	UFUNCTION(Exec)
	void Collection_CollectAllNpcVariants();

	UFUNCTION(Exec)
	void Collection_CollectALoadOfFish();

	UFUNCTION(Exec)
	void Collection_CollectFish(const FString& ExactVariantOrSpeciesCategory, float Length);

	UFUNCTION(Exec)
	void Collection_CollectNextFishVariant(float Length = 15.000000f);

	UFUNCTION(Exec)
	void Collection_CollectNpc(const FString& TagMatch);

	UFUNCTION(Exec)
	void Collection_CollectNpcAllLocations(const FString& TagMatch);

	UFUNCTION(Exec)
	void Collection_CollectNpcIndex(int32 IndexInCollection);

	UFUNCTION(Exec)
	void Collection_FakeMatchEnd();

	UFUNCTION(Exec)
	void Collection_FlushPending();

	UFUNCTION(Exec)
	void Collection_MarkAllFishSeen();

	UFUNCTION(Exec)
	void Collection_MarkOneFishSeen(const FString& ExactVariantOrSpeciesCategory);

	UFUNCTION(Exec)
	void Collection_NpcBulkUpdateCollections(const FString& TagMatch);

	UFUNCTION(Exec)
	void Collection_QueryCharacterFriends();

	UFUNCTION(Exec)
	void Collection_QueryFishyFriends();

	UFUNCTION(Exec)
	void Collection_ShowFishCompletion();

	UFUNCTION(Exec)
	void Collection_ShowFishCount();

	UFUNCTION(Exec)
	void Collection_ShowNpcCount();

	UFUNCTION(Exec)
	void CommunityVotingRefreshVotingState();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ConstructTileWorld(int32 MaxTiles, int32 X, int32 Y);

	UFUNCTION(Exec)
	virtual void CopyPhysicsObjectNameUnderReticle();

	UFUNCTION(Exec)
	virtual void CopyPhysicsObjectsNamesInRadius(float QueryRadiusInMeter = 10.000000f, bool bHighlightPhysicsObjects = true);

	UFUNCTION(Exec)
	void CountPlayerBuiltBuildingActors();

	UFUNCTION(Exec)
	void CraftFree();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CreateProfileGoCollectionForCreativeIslands(int32 GridStepsX = 1, int32 GridStepsY = 1, int32 RotationSteps = 1, int32 Quad = -1);

	UFUNCTION(Exec)
	void CreateProfileGoCollectionForSublevels(const FString& SublevelSearchString, int32 GridStepsX = 1, int32 GridStepsY = 1, int32 RotationSteps = 1, int32 Quad = -1);

	UFUNCTION(Exec)
	void Crucible_SetWhitelisted(EFortCrucibleWhitelistLevel WhitelistLevel);

	UFUNCTION(Exec)
	virtual void CycleCurrentEncounterToDebug();

	UFUNCTION(Exec)
	void CycleDebugAbilitySystem();

	UFUNCTION(Exec)
	void CycleEncounterEQSQueryToDebug();

	UFUNCTION(Exec)
	void CycleTheaterDisplayed();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void DBNO();

	UFUNCTION(Exec)
	virtual void DebugAbilityTags();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DebugAthenaSupplyDropLocations(const FString& SupplyDropInfoName, const bool bShouldCenterGroundCheckAtFoundLocation = false, const float Radius = 2000.000000f, const bool bAvoidWater = true, const bool bAvoidUnwalkableTerrain = true, const int32 NumTests = 10000, const float LifeTime = 5.000000f);

	UFUNCTION(Exec)
	virtual void DebugAttribute(FString& Attribute);

	UFUNCTION(Exec)
	virtual void DebugAttributeClear();

	UFUNCTION(Exec)
	virtual void DebugAttributeModifiers();

	UFUNCTION(Exec)
	void DebugBuildingDetection();

	UFUNCTION(Exec)
	void DebugBuildingGroups();

	UFUNCTION(Exec)
	void DebugForceEnsure();

	UFUNCTION(Exec)
	void DebugHideLoadingScreen();

	UFUNCTION(Exec)
	void DebugHotSpots();

	UFUNCTION(Exec)
	void DebugKickPlayerDueToInactivity();

	UFUNCTION(Exec)
	void DebugLoadingScreen(const FString& MissionGen = TEXT(""), bool bShowBullets = true);

	UFUNCTION(Exec)
	virtual void DebugNativeActions();

	UFUNCTION(Exec)
	virtual void DebugPhysicsObjects();

	UFUNCTION(Exec)
	virtual void DebugSoundLibrariesSelf();

	UFUNCTION(Exec)
	virtual void DebugSoundLibrariesTarget();

	UFUNCTION(Exec)
	virtual void DebugStructuralSupport();

	UFUNCTION(Exec)
	virtual void DebugTargetTags();

	UFUNCTION(Exec)
	virtual void DebugThisAI();

	UFUNCTION(Exec)
	virtual void DebugTraceSurfaceType();

	UFUNCTION(Exec)
	void DebugUseDedicatedServer(bool bUse);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DestroyAllPickups();

	UFUNCTION(Exec)
	void DestroyAllReplaySpotLights();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DestroyAllScriptedPawns();

	UFUNCTION(Exec)
	void DestroyReplaySpotLight();

	UFUNCTION(Exec)
	void DisableAI();

	UFUNCTION(Exec)
	void DisableAllParticleComponents();

	UFUNCTION(Exec)
	void DisableAllReplaySpotLights();

	UFUNCTION(Exec)
	void DisableReplaySpotLight();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DisableWeatherEvents();

	UFUNCTION(Exec)
	void DiscardAILogging();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DoAnalyticsAthenaPlayerEndPhaseReportOnServer();

	UFUNCTION(Exec)
	void DumpActiveGameplayEffects();

	UFUNCTION(Exec)
	void DumpGameStats(const FString& FilterName = TEXT("All"));

	UFUNCTION(Exec)
	void DumpInventory();

	UFUNCTION(Exec)
	void DumpMatchAnalytics();

	UFUNCTION(Exec)
	void DumpQuickbarItemTags();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DumpServerAIProfilingReport();

	UFUNCTION(Exec)
	void DumpTechAnimSettings();

	UFUNCTION(Exec)
	void DuplicateReplaySpotLight();

	UFUNCTION(Exec)
	void EnableAllReplaySpotLights();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableFixedTimeStep(int32 AsIfItWasFPS);

	UFUNCTION(Exec)
	void EnableNewCustomizationPanel(bool bEnable);

	UFUNCTION(Exec)
	void EnableReplaySpotLight();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableServerAIProfiling(const bool bEnable = true);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableServerAIProfilingVerbose(const bool bEnable = true);

	UFUNCTION(Exec)
	void EnableSubtitles(bool bEnable = true);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableWeatherEvents();

	UFUNCTION(Exec)
	void EncounterCurrentUtilities();

	UFUNCTION(Exec)
	void EncounterInitialUtilities();

	UFUNCTION(Exec)
	void EncounterSetDifficultyLevel(float NewDifficulty);

	UFUNCTION(Exec)
	void EncounterSpawnProbabilities();

	UFUNCTION(Exec)
	void EncounterTopUtilityPercentages();

	UFUNCTION(Exec)
	void EndLiveStreamingWindow();

	UFUNCTION(Exec)
	void EnduranceDebug(bool Value);

	UFUNCTION(Exec)
	void EnvPain(float Amount);

	UFUNCTION(Exec)
	void EventsRefreshPlayer();

	UFUNCTION(Exec)
	void ExtAuthReset(bool bWipeDeviceAccountInfo);

	UFUNCTION(Exec)
	void FakeDownHighlight();

	UFUNCTION(Exec)
	void FakeKillHighlight();

	UFUNCTION(Exec)
	void ForceAILODs(EFortAILODLevel inForcedAILODValue);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceAthenaCosmeticItem(const FString& TemplateId);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceAthenaCosmeticItemAllPlayers(const FString& TemplateId);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceAthenaCosmeticItemAllPlayersAndBots(const FString& TemplateId);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceAthenaCosmeticItemAllPlayersAndBotsCIDList();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceAthenaCosmeticItemInSlot(const FString& TemplateId, EAthenaCustomizationCategory Slot, int32 SlotIndex = 0);

	UFUNCTION(Exec)
	void ForceByPassNavMeshForAISpawning(bool bInValue);

	UFUNCTION(Exec)
	void ForceExternalRichPresenceUpdate();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceMatchInputFilter(EFortInputFilterLevel InputFilter);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForcePersonalInputFilter(EFortInputFilterLevel InputFilter);

	UFUNCTION(Exec)
	void ForcePlayerToAssembledMeshSchema(const FString& AssembledMeshSchemaName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ForceReviveFromDBNO();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ForceServerShutdown(int32 ExitCode = 7);

	UFUNCTION(Exec)
	void FortniteForceCharLOD(int32 LOD);

	UFUNCTION(Exec)
	void FortVolumeAsyncTest();

	UFUNCTION(Exec)
	void FortVolumeResetTest();

	UFUNCTION(Exec)
	void GenerateMockMatchReport();

	UFUNCTION(Exec)
	void GeneratePolysInPathingRange(float MaxDistance, float MinDistance = 0.000000f);

	UFUNCTION(Exec)
	void GenerateTravelLogEntries(int32 Count);

	UFUNCTION(Exec)
	void GetAllReplStats();

	UFUNCTION(Exec)
	void GetDiscoveryCreatorPage(const FString& InUserId);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GetFishingEconomyForCurrentLure(int32 NumFishToCatch, bool bWantExplosion = false);

	UFUNCTION(Exec)
	void GetGameStat(const FString& StatName);

	UFUNCTION(Exec)
	void GetPoiInfoForPlayer();

	UFUNCTION(Exec)
	void GetPoiVolumeData();

	UFUNCTION(Exec)
	void GetReplStat(EFortReplicatedStat::Type Stat);

	UFUNCTION(Exec)
	void GetWTFRotations();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAllConsumables(int32 NumItems = 1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAllIngredients(int32 NumIngredients = 50);

	UFUNCTION(Exec)
	void GiveAllMelee();

	UFUNCTION(Exec)
	void GiveAllPistols();

	UFUNCTION(Exec)
	void GiveAllRifles();

	UFUNCTION(Exec)
	void GiveAllShotguns();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAllTraps(int32 NumItems = 1);

	UFUNCTION(Exec)
	void GiveAllWeapons();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAmmo(const FString& AmmoNameAndAmmount = TEXT(""));

	UFUNCTION(Exec)
	void GiveApolloLoadout();

	UFUNCTION(Exec)
	void GiveAthenaAmmo();

	UFUNCTION(Exec)
	void GiveAthenaConsumables();

	UFUNCTION(Exec)
	void GiveAthenaCosmeticPassWeapons();

	UFUNCTION(Exec)
	void GiveAthenaFullKit();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAthenaGadget(const FString& GadgetName, int32 ItemLevel = 0);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAthenaGadgets(const FString& GadgetName, int32 Quantity = 1, int32 ItemLevel = 0);

	UFUNCTION(Exec)
	void GiveAthenaLoadout();

	UFUNCTION(Exec)
	void GiveAthenaTraps();

	UFUNCTION(Exec)
	void GiveAthenaWeapons();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveBars(int32 Amount = 1000);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveBotGE(const FString& GEToApply, const FString& BotCommand);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveConsumable(const FString& ConsumableName = TEXT(""), int32 RequestedLevel = 0, int32 Count = 1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveGadget(const FString& GadgetName, int32 ItemLevel = 0);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveGadgets(const FString& GadgetName, int32 Quantity = 1, int32 ItemLevel = 0);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveGlobalCurrency(int32 Amount = 1000);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveGold(int32 Amount = 100);

	UFUNCTION(Exec)
	void GiveGoodWeapons();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveMetal(int32 Amount = 100);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveMultiItem(const FString& MultiItemName = TEXT(""), int32 RequestedLevel = 0, int32 Count = 1);

	UFUNCTION(Exec)
	void GivePerk(const FString& PerkName = TEXT(""));

	UFUNCTION(Exec)
	void GivePerkRerolls(int32 NumOfRolls);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GivePickaxe(const FString& PickName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveSpecificItemToPlayerBots(const FString& ItemPath, const int32 ItemAmount = 1, const int32 ItemLevel = 0, const bool bResetInventory = true);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveStone(int32 Amount = 100);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveTrap(const FString& TrapName = TEXT(""), int32 RequestedLevel = 0, int32 NumTrapsToGive = 1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveWeapon(const FString& WeaponName = TEXT(""), int32 RequestedLevel = 0, int32 Count = 1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveWeapons(FName Tag);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveWeaponToPlayerBots(const FString WeaponName, const int32 Count = 1, const bool bResetInventory = true);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void GiveWeaponToScriptedPawn(const FString& WeaponName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveWood(int32 Amount = 100);

	UFUNCTION(Exec)
	void GPadV2_ToggleDebugDraw();

	UFUNCTION(Exec)
	void GrantGameplayTag(FName Tag);

	UFUNCTION(Exec)
	void HideGameplayCaptureUI();

	UFUNCTION(Exec)
	void HideHUDElement(FGameplayTag HUDElementTag);

	UFUNCTION(Exec)
	void InGameMapSetActorBoundaries(float ZA, float ZB);

	UFUNCTION(Exec)
	void InGameMapSetCaptureLocation(float X, float Y, float Z);

	UFUNCTION(Exec)
	void Island_Create(const FString& NewIslandTemplateId);

	UFUNCTION(Exec)
	void Island_Destroy(const FString& Island_ItemId);

	UFUNCTION(Exec)
	void Island_MMS(const FOnlineLinkId& IslandCode, FName TargetPlaylistName);

	UFUNCTION(Exec)
	void JoinFriendGame(const FString& FriendId);

	UFUNCTION(Exec)
	void JoinFriendGameAsSpectator(const FString& FriendDisplayName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void KillBots(bool bKillPlayers = true, bool bKillBots = true, uint8 TeamIndex = 0);

	UFUNCTION(Exec)
	virtual void KillPawns(TSubclassOf<AFortPawn> aClass = nullptr);

	UFUNCTION(Exec)
	void KillSkyCap();

	UFUNCTION(Exec)
	void ListActiveEncounters();

	UFUNCTION(Exec)
	void ListAIUtilities();

	UFUNCTION(Exec)
	void ListAllFavoriteIslands();

	UFUNCTION(Exec)
	void ListAmmo();

	UFUNCTION(Exec)
	void ListAthenaEmotes();

	UFUNCTION(Exec)
	void ListAthenaGadgets() const;

	UFUNCTION(Exec)
	void ListBuildingProps(const FString& PropName);

	UFUNCTION(Exec)
	void ListCheats();

	UFUNCTION(Exec)
	void ListConsumables() const;

	UFUNCTION(Exec)
	void ListEmotes();

	UFUNCTION(Exec)
	void ListGadgets() const;

	UFUNCTION(Exec)
	void ListMultiItems() const;

	UFUNCTION(Exec)
	void ListPlayerIDs();

	UFUNCTION(Exec)
	void ListSpawnGroups();

	UFUNCTION(Exec)
	void ListSupplyDrops();

	UFUNCTION(Exec)
	void ListTraps() const;

	UFUNCTION(Exec)
	void ListWeapons() const;

	UFUNCTION(Exec)
	void LiveStreamingSelectedViewers(TArray<FString> Names);

	UFUNCTION(Exec)
	void LoadCreativePlotFromLink(const FOnlineLinkId& LinkId);

	UFUNCTION(Exec)
	void LoadReplaySpotLights(const FString& SaveName, bool bReplaceAllLights);

	UFUNCTION(Exec)
	void LockDebugCamera();

	UFUNCTION(Exec)
	void LogAllMinigameComponents();

	UFUNCTION(Exec)
	void LogAllReplaySpotLights();

	UFUNCTION(Exec)
	void LogItemQuantityForTemplate(const FString& TemplateId);

	UFUNCTION(Exec)
	virtual void LogTargetDebugString();

	UFUNCTION(Exec)
	void MakeAIsGod();

	UFUNCTION(Exec)
	void MakeBuildingActorsGod();

	UFUNCTION(Exec)
	void MakeGods(TSubclassOf<AFortPawn> aClass = nullptr);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void MarkPlayerBots(const bool bMark = true, const float Radius = 7500.000000f);

	UFUNCTION(Exec)
	void MassSuicide();

	UFUNCTION(Exec)
	void McpApplyStash(const FString& StashName);

	UFUNCTION(Exec)
	void McpEarnScore(int32 ScoreAmount);

	UFUNCTION(Exec)
	void McpForceHttpFailRate(float Factor);

	UFUNCTION(Exec)
	void McpGetCurrencyAmount();

	UFUNCTION(Exec)
	void McpGetPrivacySettings();

	UFUNCTION(Exec)
	void McpGetUnredeemedCodes();

	UFUNCTION(Exec)
	void McpGetVersion();

	UFUNCTION(Exec)
	void McpHostGetPlayers();

	UFUNCTION(Exec)
	void McpIssueCodeToken(const FString& TokenId);

	UFUNCTION(Exec)
	void McpJoinFromPartyInviteToken(const FString& Token, bool bIsFromInvite = true);

	UFUNCTION(Exec)
	void McpLogout();

	UFUNCTION(Exec)
	void McpPrintFriendInviteToken(const FString& FriendName, bool OnlyPrintIfJoinable = true);

	UFUNCTION(Exec)
	void McpPrintPartyInviteToken(bool OnlyPrintIfJoinable = true);

	UFUNCTION(Exec)
	void McpRedeemPurchases();

	UFUNCTION(Exec)
	void McpRedeemPurchasesWithParams(const FString& RefreshTypeStr, bool bForceRefreshOfflineAuth);

	UFUNCTION(Exec)
	void McpRefreshCatalog();

	UFUNCTION(Exec)
	void McpTestFriendCodes(const FString& TokenId = TEXT("CodeToken:founderfriendinvite"));

	UFUNCTION()
	void McpTestFriendCodes_OnQueryUnredeemedFriendCodes(bool bSuccess, const TArray<FFriendCode>& FriendCodes);

	UFUNCTION(Exec)
	void McpTestGetClientFeatureKeys();

	UFUNCTION(Exec)
	void McpTestVerifyProfileToken();

	UFUNCTION(Exec)
	void ModItemDurability(float InValue);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void OpenAllContainersAndWriteLootEconomy();

	UFUNCTION(Exec)
	void Pain(float Amount);

	UFUNCTION(Exec)
	void PerfMemStatMonitor(const FString& ToggleState);

	UFUNCTION(Exec)
	void PilotReplaySpotLight();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PlayAthenaEmoteOnScriptedPawn(const FString& EmoteName);

	UFUNCTION(Exec)
	void PreviewSkinWeightProfile(int32 State);

	UFUNCTION(Exec)
	void PrintScriptedActionManagerState();

	UFUNCTION(Exec)
	void PrintShotReport();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintTileWorld();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintValidWeaponMods();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintWeaponModsOnCurrentWeapon();

	UFUNCTION(Exec)
	void QueryHighlightCount();

	UFUNCTION(Exec)
	void ReadLevelSaveComponentsFromDisk();

	UFUNCTION(Exec)
	void ReadSharedPersistenceValue();

	UFUNCTION(Exec)
	void ReAimReplaySpotLight();

	UFUNCTION(Exec)
	void RedoHuskSpecialEventModifiers(float TargetRate);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RefreshAllCalendars();

	UFUNCTION(Exec)
	void RefreshCMS();

	UFUNCTION(Exec)
	void RefreshTheaters();

	UFUNCTION(Exec)
	void RefreshTournamentManager();

	UFUNCTION(Exec)
	void ReInitHUD();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ReleaseAIPawn();

	UFUNCTION(Exec)
	void ReleasePortal();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ReleaseScriptedPawn();

	UFUNCTION(Exec)
	void ReloadLevelStream();

	UFUNCTION(Exec)
	void ReloadUI();

	UFUNCTION(Exec)
	void ReloadUMG();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveBars(int32 Amount = 1000);

	UFUNCTION(Exec)
	void RemoveDebugEncounterTag(FName Tag);

	UFUNCTION(Exec)
	void RemoveDebugSpawnAIGroupTag(FName Tag);

	UFUNCTION(Exec)
	void RemoveFavoriteIsland(const FOnlineLinkId& IslandLinkId);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveGameplayModifier(const FString& ModifierName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveGlobalCurrency(int32 Amount = 1000);

	UFUNCTION(Exec)
	void RemoveGrantedGameplayTag(FName Tag);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveWeaponModFromCurrentWeapon(const FString& WeaponModName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveWeaponModFromCurrentWeaponAtSlot(int32 Index);

	UFUNCTION(Exec)
	void RemoveZiplines(const bool bRemoveZiplinesOn = true);

	UFUNCTION(Exec)
	void RepeatKillAuto(float DelayBetweenKillAll = 3.000000f);

	UFUNCTION(Exec)
	void ReplayLastPerfTest(const FString& Params);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RepositionAllPlayersAndStorm(float X, float Y, float Z, float Pitch, float Yaw, float Roll);

	UFUNCTION(Exec)
	void RequestFullNavigationUpdate();

	UFUNCTION(Exec)
	void RequestNextCarouselOffer();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ReRandomizeTiles();

	UFUNCTION(Exec)
	void ResetEncounterWave();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetForcedAthenaCosmeticItems();

	UFUNCTION(Exec)
	void ResetItemShopSeenOffers();

	UFUNCTION(Exec)
	void ResetMaxAITracking();

	UFUNCTION(Exec)
	void ResetWall();

	UFUNCTION(Exec)
	void RespawnPlayer();

	UFUNCTION(Exec)
	void RespawnPlayerServer();

	UFUNCTION(Exec)
	void RespawnPlayspacePlayer();

	UFUNCTION(Exec)
	virtual void RestartMinigame();

	UFUNCTION(Exec)
	virtual void ReviveFromDBNO();

	UFUNCTION(Exec)
	void RunAllSeasonCheats(const FString& seasonName);

	UFUNCTION(Exec)
	void RunPawnScriptLocally(const FString& ProfileName);

	UFUNCTION(Exec)
	void RunPerfMemCheatScript(bool bStartStatFiles);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SafeTeleport(float X, float Y, float Z, float Pitch, float Yaw, float Roll);

	UFUNCTION(Exec)
	void SaveReplaySpotLights(const FString& SaveName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ScriptedPawnIntervalFiring(float TimeBetweenShots, int32 BurstAmount, float TimeBetweenBursts);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ScriptedPawnStopIntervalFiring();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ScriptedPawnToggleCrouch();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void ScriptedPawnToggleFiringWithInfiniteAmmo();

	UFUNCTION(Exec)
	void SelectNextSpotLight();

	UFUNCTION(Exec)
	void SelectPrevSpotLight();

	UFUNCTION(Exec)
	void SelectSpotLightByNumber(uint32 Number);

	UFUNCTION(Exec)
	void SendRemoteBotCommand(const FString& CommandToSend);

	UFUNCTION(Exec)
	void SendTargetedRemoteBotCommand(const FString& TargetName, const FString& CommandToSend);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ServerStartProfiling();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ServerStopProfiling();

	UFUNCTION(Exec)
	void SetActionMappingEnabled(FName Action, bool bEnabled);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetAimMode(uint32 Mode);

	UFUNCTION(Exec)
	void SetAthenaHero(const FString& NewHeroName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetAthenaHeroOnScriptedPawn(const FString& NewHeroName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetBackpackOnScriptedPawn(const FString& NewBackpack);

	UFUNCTION(Exec)
	void SetBuildFree(const bool bNewValue);

	UFUNCTION(Exec)
	void SetCameraDistanceMultiplier(float XMultiplier = 1.000000f, float YMultiplier = 1.000000f, float ZMultiplier = 1.000000f);

	UFUNCTION(Exec)
	void SetCameraFOVMultiplier(float Multiplier = 1.000000f);

	UFUNCTION(Exec)
	void SetCameraPrototype(FName ProtoName = NAME_None);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetCanBeDamagedOnTraceActor(bool bCanBeDamaged);

	UFUNCTION(Exec)
	void SetCanMeleeOneHitBuildings(const bool bEnabled);

	UFUNCTION(Exec)
	void SetCapturePercentage(float NewCapturePercentage);

	UFUNCTION(Exec)
	void SetCloudAltitude(float CloudAltitude = 5000.000000f);

	UFUNCTION(Exec)
	void SetConsole60FPSMode(bool bEnabled);

	UFUNCTION(Exec)
	void SetCrossplayPreference(int32 NewPreference);

	UFUNCTION(Exec)
	void SetCullValues(float MinCullObjectSize, float MinCullDistance, float MaxCullObjectSize, float MaxCullDistance);

	UFUNCTION(Exec)
	void SetCurrentEncounterToDebug(int32 EncounterIndex);

	UFUNCTION(Exec)
	void SetDifficultyIncreaseRewardTier(int32 RewardTier);

	UFUNCTION(Exec)
	void SetEnableRenderCustomDepthOnAllPlayerPawns(bool bEnable);

	UFUNCTION(Exec)
	void SetEncounterDirections(TArray<TEnumAsByte<EFortEncounterDirection::Type>> Directions);

	UFUNCTION(Exec)
	virtual void SetEncounterGraphsHistoryLength(int32 Seconds = -1);

	UFUNCTION(Exec)
	void SetEncounterSimulatedNumberOfPlayers(int32 NumPlayers);

	UFUNCTION(Exec)
	void SetEncounterSpawnPointsCap(int32 SpawnPointsCap);

	UFUNCTION(Exec)
	void SetEncounterSpawnPointsCurve(const FString& CurveName);

	UFUNCTION(Exec)
	void SetEncounterTopUtilityPercentages(const FString& UtilitiesAndPercentages);

	UFUNCTION(Exec)
	void SetEventCalendarTime(const FString& TimeString);

	UFUNCTION(Exec)
	void SetEventsStyleOverride(const FString& StyleId);

	UFUNCTION(Exec)
	void SetFrameSyncMode(int32 Mode);

	UFUNCTION(Exec)
	void SetGameDifficultyOverride(float GameDifficultyOverrideValue);

	UFUNCTION(Exec)
	void SetGameStat(const FString& StatName, int32 Amount);

	UFUNCTION(Exec)
	void SetGlobalWind(float Magnitude, float HeadingDegrees = 0.000000f);

	UFUNCTION(Exec)
	void SetHeadHealthPercent(float HealthPercent);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetHealthPercent(float Percent = 1.000000f);

	UFUNCTION(Exec)
	void SetHideEnemyIndicators(const bool bEnabled);

	UFUNCTION(Exec)
	void SetHideNonEnemyIndicators(const bool bEnabled);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetInfiniteAmmo(bool bInValue);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetInfiniteConsumables(bool bInValue);

	UFUNCTION(Exec)
	void SetInputPresetName(const FString& PresetName);

	UFUNCTION(Exec)
	void SetInteractExtent(float Extent);

	UFUNCTION(Exec)
	void SetInteractionDistances(float InteractionDistance, float InteractionHighlightDistance);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetJumpStaminaCost(FName ModeName = NAME_None);

	UFUNCTION(Exec)
	void SetLFG(bool bLFG);

	UFUNCTION(Exec)
	void SetMaxClouds(int32 MaxClouds = -1);

	UFUNCTION(Exec)
	void SetMinigameClassSlot(int32 ClassSlotIndex);

	UFUNCTION(Exec)
	void SetNavIndestructibility(bool bMakeIndestructible);

	UFUNCTION(Exec)
	void SetPartyLocation(EFortPartyMemberLocation NewLocation);

	UFUNCTION(Exec)
	void SetPersistenceSharedProject(const FString& ProjectId);

	UFUNCTION(Exec)
	void SetReplaySpotLightAngles(float InnerAngle, float OuterAngle);

	UFUNCTION(Exec)
	void SetReplaySpotLightColor(int32 R, int32 G, int32 B);

	UFUNCTION(Exec)
	void SetReplaySpotLightIntensity(float Intensity);

	UFUNCTION(Exec)
	void SetReplaySpotLightRadius(float Radius);

	UFUNCTION(Exec)
	void SetReplaySpotLightTemperature(float Temp);

	UFUNCTION(Exec)
	void SetReplStat(EFortReplicatedStat::Type Stat, int32 Amount);

	UFUNCTION(Exec)
	void SetRiftCosmeticState(ERiftCosmeticState NewValue);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetScriptedPawnLocation(float X, float Y, float Z);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetScriptedPawnRotation(float Yaw);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetScriptedPawnTargeting(bool bIsTargeting);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetScriptedPawnVariantChannel(const FString& ChannelTag, const FString& ActiveTag);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetShieldPercent(float Percent = 1.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetSignalInStormPercent(float Percent = 1.000000f);

	UFUNCTION(Exec)
	void SetTeam(int32 TeamIndex);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void SetTeamOnScriptedPawn(int32 NewTeamIndex);

	UFUNCTION(Exec)
	void SetUnlimitedHealth(bool bInValue);

	UFUNCTION(Exec)
	void SetVehicleConfigVariable(const FString& VehicleName, const FString& ConfigName, float ConfigValue);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetVehicleFuel(float FuelAmount);

	UFUNCTION(Exec)
	void SetVehicleTricksEnabled(const bool bNewValue);

	UFUNCTION(Exec)
	void SetWallTimer(float Seconds);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetWeaponModToCurrentWeaponAtSlot(const FString& WeaponModName, int32 Index);

	UFUNCTION(Exec)
	void SetWorldDaysElapsed(float days);

	UFUNCTION(Exec)
	void ShowActiveGameplayModifiers();

	UFUNCTION(Exec)
	void ShowAllMinimapIcons();

	UFUNCTION(Exec)
	void ShowEventsDebugInfo(bool bShowDebugInfo);

	UFUNCTION(Exec)
	void ShowFakeError(const FString& DisplayString = TEXT(""), const FString& ErrorCode = TEXT(""));

	UFUNCTION(Exec)
	void ShowGameplayCaptureUI();

	UFUNCTION(Exec)
	void ShowHighlightSummary();

	UFUNCTION(Exec)
	void ShowHUDElement(FGameplayTag HUDElementTag);

	UFUNCTION(Exec)
	void ShowLootPlacement(const FGameplayTag& InTag);

	UFUNCTION(Exec)
	void SimulateAuthTickenExpiration();

	UFUNCTION(Exec)
	void SimulateLoot(const FName TierGroup, int32 LootTier, int32 LootLevel);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SimulateLootDrops();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnAIFromSpawnerData(const FString& AISpawnerDataName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnAIFromSpawnerDataAtLocation(const FString& AISpawnerDataName, const float X, const float Y, const float Z, const float Pitch, const float Yaw, const float Roll);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnAIFromSpawnerDataInFormation(const FString& AISpawnerDataName, int32 RowWidth = 1, int32 ColumnDepth = 1, float Spacing = 500.000000f);

	UFUNCTION(Exec)
	void SpawnAIGroup(const FString& SpawnGroupName = TEXT(""));

	UFUNCTION(Exec)
	void SpawnAIGroupFromExternalSpawner(const FString& SpawnGroupName);

	UFUNCTION(Exec)
	void SpawnAIGroupWithUpgrade(const FString& SpawnGroupName, const FString& UpgradeName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnAndDriveVehicle(const FString& VehicleName = TEXT(""), int32 ForcedMaterialVariantIndex = -1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnAthenaSupplyDrop(const FString& SupplyDropInfoName, const bool bShouldCenterGroundCheckAtFoundLocation = false, const float Radius = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnBot(const FString& BotArchetype = TEXT(""));

	UFUNCTION(Exec)
	void SpawnContainer(const FString& ContainerClassName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	AFortPlayerPawn* SpawnEnemyPlayer(float MaxHealth = 99999.000000f, float MaxShield = 0.000000f, int32 TeamIndex = 1);

	UFUNCTION(Exec)
	void SpawnFoodFightObjective();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	AFortPlayerPawn* SpawnFriendlyPlayer(float MaxHealth = 99999.000000f, float MaxShield = 0.000000f);

	UFUNCTION(Exec)
	virtual AFortPawn* SpawnPawn(const FString& PawnType = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnPhysicsProp(const FString& PropName, int32 Count = 1, bool bSpawnAwake = true, bool bCanBeDamaged = true, bool bRotate90Degrees = false);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnPhysicsPropOverhead(const FString& PropName, int32 Count = 1, bool bSpawnAwake = true, bool bCanBeDamaged = true, bool bRotate90Degrees = false, float OverheadSpawnHeightOffset = 1000.000000f, float SpawnMassOverride = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnPhysicsPropScaled(const FString& PropName, float ScaleX, float ScaleY, float ScaleZ, bool bSpawnAwake = true, bool bCanBeDamaged = true, bool bRotate90Degrees = false);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	AFortPickup* SpawnPickup(const FString& ItemName, int32 NumItems = 1, float SpawnDistance = 500.000000f, float SpawnRotation = 0.000000f);

	UFUNCTION(Exec)
	void SpawnReplaySpotLight();

	UFUNCTION(Exec)
	void SpawnReplaySpotLightEx(float X, float Y, float Z, float Yaw, float Pitch, int32 R, int32 G, int32 B, float InnerAngle, float OuterAngle, float Intensity, float Radius, float Temp);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnScriptedPawnsInFormation(const FString& ProfileName, int32 RowWidth = 1, int32 ColumnDepth = 1, float Spacing = 500.000000f, float Health = 100.000000f, float Shields = 100.000000f);

	UFUNCTION()
	AFortPlayerPawn* SpawnSimplePawn();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	AActor* SpawnVehicle(const FString& VehicleName = TEXT(""), int32 ForcedMaterialVariantIndex = -1, float GroundHeightOffset = 64.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpawnWeaponWithModSets(const FString& WeaponName = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SpendBars(int32 Amount = 1000);

	UFUNCTION(Exec)
	void StartFillFloorMovement();

	UFUNCTION(Exec)
	void StartLavaMovement();

	UFUNCTION(Exec)
	void StartLiveStreamingWindow(float Seconds = 11700.000000f);

	UFUNCTION(Exec)
	void StartMinigame();

	UFUNCTION(Exec)
	void StartWeatherEvent(int32 WeatherEventIndex, float Duration);

	UFUNCTION(Exec)
	void Stats_ClearCohortLeaderboardCache();

	UFUNCTION(Exec)
	void Stats_ClearGlobalLeaderboardCache();

	UFUNCTION(Exec)
	void Stats_ClearPlayerStatsCache();

	UFUNCTION(Exec)
	void StopDummyDebugEncounter();

	UFUNCTION(Exec)
	void StopHighlights();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SummonLoadIfNeeded(const FString& ClassName, float ZOffset = 0.000000f, float YRotation = 0.000000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SwitchTeam();

	UFUNCTION(Exec)
	void TakeGameplayAutomationScreenshot(const FString& ScreenshotName, const FString& MapName = TEXT(""), const float& MaxGlobalError = 0.020000f, const float& MaxLocalError = 0.120000f);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void TakeoverAIPawn();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	virtual void TakeoverScriptedPawn();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportAllPlayerControlledCharactersToSelf();

	UFUNCTION(Exec)
	void TeleportToActor(const FString& ClassOrInstanceName = TEXT(""));

	UFUNCTION(Exec)
	void TeleportToLocation(float X, float Y, float Z);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToMapMarker();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToMapMarkerAir();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToMapMarkerGround();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToMe();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToSafeZone();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TeleportToSafeZoneNext();

	UFUNCTION(Exec)
	void TestAllDevPartyMembers();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestCalendarEvents(const FString& EventsString);

	UFUNCTION(Exec)
	void TestCancelLobby();

	UFUNCTION(Exec)
	void TestChangePartyPrivacy(bool bPrivate, bool bLeaderFriendsOnly, bool bLeaderInvitesOnly);

	UFUNCTION(Exec)
	void TestChangePartySize(int32 NewSize);

	UFUNCTION(Exec)
	void TestDisconnect();

	UFUNCTION(Exec)
	void TestEncryptAPI(const FString& InUserId, const FString& InSessionId);

	UFUNCTION(Exec)
	void TestFindTeleport(float X, float Y, float Z);

	UFUNCTION(Exec)
	void TestJoin();

	UFUNCTION(Exec)
	void TestLeaveGame();

	UFUNCTION(Exec)
	void TestPartyMember(const FString& ContextName, const FString& OptionalFriend = TEXT(""));

	UFUNCTION(Exec)
	void TestPartyMemberRange(int32 StartIndex, int32 EndIndex);

	UFUNCTION(Exec)
	void TestRegenId();

	UFUNCTION(Exec)
	void TestSafeZoneLocations(int32 NumPasses, int32 PhaseToDraw = -1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TestSuddenPortChange(uint32 NumConnections);

	UFUNCTION(Exec)
	void TestTournamentOver();

	UFUNCTION(Exec)
	void ToggleAIAnim();

	UFUNCTION(Exec)
	void ToggleAIDespawning();

	UFUNCTION(Exec)
	void ToggleAIDirectorLogging();

	UFUNCTION(Exec)
	void ToggleAISpawnCap();

	UFUNCTION(Exec)
	void ToggleAISpawning();

	UFUNCTION(Exec)
	virtual void ToggleAutoRestartMinigame();

	UFUNCTION(Exec)
	void ToggleBuildingActorsTransparency();

	UFUNCTION(Exec)
	void ToggleBuildingHighlights();

	UFUNCTION(Exec)
	void ToggleContextMenus();

	UFUNCTION(Exec)
	void ToggleDebugHUDObjectiveHeight();

	UFUNCTION(Exec)
	void ToggleDrawRunVariationDebug();

	UFUNCTION(Exec)
	void ToggleDrawTargetSelectionDebug();

	UFUNCTION(Exec)
	void ToggleDrawTargetSelectionDebugByClass(TSubclassOf<AActor> TargetSelectionDebugSourceClass);

	UFUNCTION(Exec)
	void ToggleDrawTurnTransitionDebug();

	UFUNCTION(Exec)
	void ToggleEncounterEQSDebug();

	UFUNCTION(Exec)
	void ToggleEncounterModifierTags();

	UFUNCTION(Exec)
	void ToggleExplorationBadgeView();

	UFUNCTION(Exec)
	void ToggleExplorationLogging();

	UFUNCTION(Exec)
	void ToggleFreezeAILOD();

	UFUNCTION(Exec)
	void ToggleGameDifficultyHUD();

	UFUNCTION(Exec)
	void ToggleHeroVisibility();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleIgnoreAll();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleInfiniteAmmo();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleInfiniteConsumables();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleInfiniteDurability();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleInfiniteStamina();

	UFUNCTION(Exec)
	virtual void ToggleIntensityGraph();

	UFUNCTION(Exec)
	void ToggleIntensityHUD();

	UFUNCTION(Exec)
	void ToggleInteractTrace();

	UFUNCTION(Exec)
	void ToggleInWorldScoreNumbers();

	UFUNCTION(Exec)
	void ToggleIsLobbyTimerPaused();

	UFUNCTION(Exec)
	void ToggleItemIdsOnCards();

	UFUNCTION(Exec)
	void ToggleLogCharacterCustomization();

	UFUNCTION(Exec)
	void ToggleMaxAIHUD();

	UFUNCTION(Exec)
	void ToggleMustUseJetpackToggle();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleNoCoolDown();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TogglePhoebeIgnorePlayers();

	UFUNCTION(Exec)
	void TogglePickupSpline();

	UFUNCTION(Exec)
	virtual void TogglePIDContributionsGraph();

	UFUNCTION(Exec)
	virtual void TogglePIDValuesGraph();

	UFUNCTION(Exec)
	virtual void TogglePlayerNames();

	UFUNCTION(Exec)
	void ToggleRBAN();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleShotLogging();

	UFUNCTION(Exec)
	void ToggleSimulatedSquadSpeaking();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ToggleSpawningEnabled();

	UFUNCTION(Exec)
	void ToggleSpawnPointsHUD();

	UFUNCTION(Exec)
	void ToggleTreeVisibility();

	UFUNCTION(Exec)
	void ToggleUnlimitedAIHealth();

	UFUNCTION(Exec)
	void ToggleUnlimitedHealth();

	UFUNCTION(Exec)
	void ToggleUseNewItemCards();

	UFUNCTION(Exec)
	virtual void ToggleUtilitiesGraph();

	UFUNCTION(Exec)
	void ToggleVoiceDebug();

	UFUNCTION(Exec)
	void ToggleWalkOnWalls();

	UFUNCTION(Exec)
	void ToggleWindDebugDeltaBoundsDisplay();

	UFUNCTION(Exec)
	void ToggleWindDebugDisplay(float NewRefreshRate = -1.000000f);

	UFUNCTION(Exec)
	void ToggleWindDebugVolumeDisplay();

	UFUNCTION(Exec)
	void ToggleWorldRendering(bool bIsWorldRendering);

	UFUNCTION(Exec)
	void TriggerDelayReturnToLobby(int32 MinTime, int32 MaxTime);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void TriggerEndOfMatch();

	UFUNCTION(Exec)
	void TriggerOutOfStaminaFeedback();

	UFUNCTION(Exec)
	void TurnOffAllReplaySpotLightsDebugDraw();

	UFUNCTION(Exec)
	void TurnOnAllReplaySpotLightsDebugDraw();

	UFUNCTION(Exec)
	void TutorialAddHidden(FName Hidden);

	UFUNCTION(Exec)
	void TutorialAddHighlight(FName Highlight);

	UFUNCTION(Exec)
	void TutorialListAll();

	UFUNCTION(Exec)
	void TutorialListHidden();

	UFUNCTION(Exec)
	void TutorialListHighlights();

	UFUNCTION(Exec)
	void TutorialRemoveHidden(FName Hidden);

	UFUNCTION(Exec)
	void TutorialRemoveHighlight(FName Highlight);

	UFUNCTION(Exec)
	void UnforceAILODs();

	UFUNCTION(Exec)
	void UnlockDebugCamera();

	UFUNCTION(Exec)
	void UnlockPerk(int32 Count = 1);

	UFUNCTION(Exec)
	void ViewStuck();

	UFUNCTION(Exec)
	void VkPalette_AddLinkCode(const FOnlineLinkId& LinkId);

	UFUNCTION(Exec)
	void VkPalette_Clear();

	UFUNCTION(Exec)
	void VkPalette_RemoveLinkCode(const FOnlineLinkId& LinkId);

	UFUNCTION(Exec)
	void WannaGun();

	UFUNCTION(Exec)
	void WargameDebug(bool Value);

	UFUNCTION(Exec)
	void WriteLevelSaveComponentsToDisk();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void WriteLootReport();

	UFUNCTION(Exec)
	void WriteSharedPersistenceValue();

private:
	UFUNCTION(Exec)
	void ClearAgeRatingIDOverride();

	UFUNCTION(Exec)
	void LogAssetClassCost(const FString& AssetPath = TEXT(""));

	UFUNCTION(Exec)
	void LogSelectedActorCost();

	UFUNCTION(Exec)
	void SetAgeRatingIDOverride(const FString& OverrideAgeRatingID);

};

