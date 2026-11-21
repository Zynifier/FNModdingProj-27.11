// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "AI/FortAITypes.h"
#include "AI/Goals/FortAIGoal.h"
#include "Abilities/FortAbilityTypes.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "FortEventName.h"
#include "FortMissionTimerInterface.h"
#include "Items/FortPersistentTypes.h"
#include "Missions/FortBadgeCount.h"
#include "Missions/FortMissionEventDelegateHolder.h"
#include "Missions/FortMissionGenerationCategory.h"
#include "Missions/FortMissionState.h"
#include "Missions/FortMissionWeightedRewards.h"
#include "Missions/FortPlacementActorDataProviderInterface.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "Missions/MissionTypes.h"
#include "STW/FortTieredCollectionLayout.h"
#include "STW/GameDataSTW.h"
#include "UI/FrontEnd/FortMissionGenerator.h"
#include "FortMission.generated.h"

class AActor;
class AFortAIPawn;
class AFortClientAnnouncement_Basic;
class AFortMission;
class AFortObjectiveBase;
class AFortPawn;
class AFortPlayerController;
class UAudioComponent;
class UDataAsset;
class UFortAIAssignment;
class UFortAIAssignmentSettings;
class UFortAIEncounterInfo;
class UFortAIEncounterSequence;
class UFortAIGoalProvider;
class UFortBotMissionLogic;
class UFortItemDefinition;
class UFortMissionConfigData;
class UFortMissionEventParams;
class UFortMissionGenerator;
class UFortMissionInfo;
class UFortMissionTimerComponent;
class UFortTieredCollectionLayout;
class UFortWorldItemDefinition;
class UObject;
enum class EAssignmentCreationResult : uint8;
enum class EFortCompletionResult : uint8;
enum class EFortMissionStatus : uint8;
enum class EFortObjectiveStatus : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMissionInfoSet);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnObjectivesUpdated);

USTRUCT()
struct FFortMissionFocusDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText CurrentFocusDisplayText;

	UPROPERTY()
	float CurrentFocusPercentage;

};

USTRUCT()
struct FFortMissionPlacementActorPreferredTagInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorPreferredTagInfo")
	FDataTableRowHandle DifficultyInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortMissionPlacementActorPreferredTagInfo")
	FGameplayTagContainer PlacementActorPreferredTags;

	UPROPERTY(Transient)
	float Difficulty;

};

UCLASS(Config=Game, NotPlaceable, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class AFortMission : public AFortMissionState, public IFortPlacementActorDataProviderInterface, public IFortMissionTimerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void AddCompletionTag(FGameplayTag NewCompletionTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void AddCompletionTags(FGameplayTagContainer NewCompletionTagContainer);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction))
	void AddGoalsToAssignment(UFortAIAssignment* Assignment, const TArray<FFortAIGoalInfo>& GoalInfos);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	void AddGoalsToEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const TArray<FFortAIGoalInfo>& GoalInfos);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(DeprecatedFunction))
	void AddGoalToAssignment(UFortAIAssignment* Assignment, const FFortAIGoalInfo& GoalInfo);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	void AddGoalToEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const FFortAIGoalInfo& GoalInfo);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Mission Timer")
	void AddOrRemoveTimerTime(float TimeToAdd);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	bool AddParticipantAccount(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="EncounterModifier")
	void ApplyTieredModifierSet(const TArray<FTieredModifierSetData>& ModifierSetData, int32 Tier, int32 WaveNum, bool bDeferTemporaryModifiers, TArray<FActiveGameplayModifierHandle>& OutAppliedModifiers);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void AttemptMissionSave(const FString& OptionalSaveName);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Missions")
	bool BlueprintCanPlayerParticipate(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintInternalUseOnly="true"))
	void BlueprintCustomHandleMissionEvent(UPARAM(DisplayName="MissionGuid") FGuid InMissionGuid, FGameplayTagContainer ObjectiveHandle, UFortMissionEventParams* Params, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, UObject* EventFocus, const UDataAsset* EventContent, AActor* EventInstigator, int32 GenericInt, float GenericFloat, const FText& GenericText, FGameplayTagContainer GameplayTags, const FFortMissionEvent& MissionEvent);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(DisplayName="OnMissionLoaded"))
	void BlueprintOnActivated();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(DisplayName="OnMissionEnd"))
	void BlueprintOnMissionEnd(EFortMissionStatus Status);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(DisplayName="OnMissionStartPlaying"))
	void BlueprintOnStartPlaying();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions")
	FFortMissionWeightedReward ChooseRandomReward();

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	EAssignmentCreationResult CreateEncounterAssignment(const FGameplayTagContainer& AssignmentTags, UFortAIEncounterInfo* const& Encounter, UFortAIAssignmentSettings* AssignmentSettings, TSubclassOf<UFortAIGoalProvider> GoalProvider, FFortAIAssignmentIdentifier& AssignmentIdentifier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterSequence* CreateEncounterSequence(const FGameplayTagContainer& SequenceTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterSequence* CreateEncounterSequenceByIndex(int32 EncounterSequenceIndex);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	void FindGoalLocationsForEncounterAssignment(const FFortAIAssignmentIdentifier& AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, TArray<FVector>& OutGoalLocations);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void FocusThisMission(FText FocusDisplayText, float FocusPercentage = -1.000000f);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	bool GetActorsSpawnedMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnedActors) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	int32 GetAdditionalMissionCompletionMissionPoints(EFortMissionStatus CompletionStatus) const;

	UFUNCTION(BlueprintPure, Category="Mission")
	TArray<AFortObjectiveBase*> GetAllObjectives() const;

	UFUNCTION(BlueprintPure, Category="Announcement")
	TSubclassOf<AFortClientAnnouncement_Basic> GetAnnouncementClassOverride() const;

	UFUNCTION(BlueprintCallable, Category="Tier")
	FAvailableTierLayout GetAvailableTiers(UFortTieredCollectionLayout* TieredCollectionLayout, int32 MaxTierUnlocked);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions")
	int32 GetBuildingDamageLootTier(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	UFortMissionConfigData* GetConfigData(FGameplayTagContainer InContainer);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Missions")
	int32 GetCurrentBluGloRewards() const;

	UFUNCTION(BlueprintPure, Category="Missions")
	FText GetCurrentFocusDisplayText() const;

	UFUNCTION(BlueprintPure, Category="Missions")
	float GetCurrentFocusPercentage() const;

	UFUNCTION(BlueprintPure, Category="Mission")
	int32 GetDaysRemainingBeforeOverPar() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Missions")
	float GetExpectedCompletionTime() const;

	UFUNCTION(BlueprintNativeEvent, Category="Mission")
	FText GetMissionCompletionResultText(EFortCompletionResult Result);

	UFUNCTION(BlueprintPure, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	FGuid GetMissionGuid() const;

	UFUNCTION(BlueprintPure, Category="Mission")
	virtual FText GetMissionName() const;

	UFUNCTION(BlueprintPure, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	AFortObjectiveBase* GetObjectiveByHandle(const FGameplayTagContainer& ObjectiveHandle) const;

	UFUNCTION(BlueprintPure, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	TArray<FGameplayTagContainer> GetObjectiveHandlesWithTag(FGameplayTag ObjectiveTag, int32 MaxNumberOfObjectives = -1) const;

	UFUNCTION(BlueprintPure, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	EFortObjectiveStatus GetObjectiveStatusByHandle(const FGameplayTagContainer& ObjectiveHandle) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	TArray<AFortPlayerController*> GetParticipatingMissionControllers() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions")
	int32 GetPawnDamageLootTier(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="UI")
	FText GetRespawnTextOverride() const;

	UFUNCTION(BlueprintCallable, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	void GetRewardItemsByTag(const FGameplayTag RewardTag, TArray<UFortWorldItemDefinition*>& OutRewardItems);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="AIEncounter")
	void GetSpawningDistanceMinMaxOverrideForAIEncounter(const UFortAIEncounterInfo* Encounter, float& OutSpawningDistanceMin, float& OutSpawningDistanceMax) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	bool GetSpawnLocationActorsMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	bool GetSpawnLocationsMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<FVector>& SpawnLocations) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="EncounterModifier")
	void GetTieredModifierSet(FName TieredModifierSetName, TArray<FTieredModifierSetData>& OutModifierSetData);

	UFUNCTION(BlueprintPure, Category="Tier")
	bool GetTierOutputForSelectedTier(int32 Tier, const UFortTieredCollectionLayout* TieredCollectionLayout, FFortTierCollectionLayoutOutput& Output) const;

	UFUNCTION(BlueprintCallable, Category="Tier")
	bool GetValidTierCollectionLayoutOutputs(UFortTieredCollectionLayout* TieredCollectionLayout, int32 MaxTierUnlocked, TArray<FFortTierCollectionLayoutOutput>& OutTiers, TArray<FFortTierCollectionLayoutOutput>& OutLockedTiers);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void GrantRewardsByTag(const FGameplayTag RewardTag, EFortRewardType::Type RewardType);

	UFUNCTION()
	void HandleEncounterEnemyAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	void HandleEnemyKilled(AFortPlayerController* KilledBy, AFortPawn* KilledPawn, const FGameplayTagContainer& SourceTags);

	UFUNCTION(BlueprintPure, Category="Mission")
	bool HasMissionPar() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions", meta=(WorldContext="Mission"))
	bool HasSuccessfullyInitializedActorsForMission() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	bool InitializeActorsForMission(AFortMission* Mission, TArray<AActor*>& OutActorsInitialized);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	bool InitializeActorsForMissionMatchingItemIdentifyingQuery(AFortMission* Mission, const FGameplayTagQuery& TagQuery, TArray<AActor*>& OutActorsInitialized);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="EncounterModifier")
	void InitializeModifiersRRV(int32 Seed);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Missions")
	bool IsPlayerParticipating(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	void LoadMissionsManually(TArray<FGuid>& OutAddedMissionGuids, UPARAM(ref) TArray<UFortMissionInfo*>& MissionsToLoad);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	void LoadPossibleMissionsManually(TArray<FGuid>& OutAddedMissionGuids, UPARAM(ref) TArray<FFortPossibleMission>& PossibleMissionsToLoad);

	UFUNCTION(BlueprintNativeEvent, Category="Mission Timer")
	void MissionTimerSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Mission Timer")
	void MissionTimerVisibilityOverrideSet();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Mission")
	void OnEncounterEnemyAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(WorldContext="Mission"))
	void RecordResourceActorSpawn(AActor* SpawnedActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	void RegisterForBuildingHarvestedByPlayerEvent(UPARAM(DisplayName="Event") FOnMissionBuildingSMActorHarvestedEvent Delegate, const FGameplayTagQuery& HarvestedBuildingRequirements);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(UnsafeDuringActorConstruction="true"))
	void RegisterForContainerSearchedEvent(UPARAM(DisplayName="Event") FOnMissionContainerSearchedEvent Delegate, const FGameplayTagQuery& ContainerRequirements);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	void RemoveGoalFromEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const FFortAIGoalInfo& GoalInfo);

	UFUNCTION(BlueprintCallable, Category="AI|GoalSelection")
	void RemoveGoalsFromEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const TArray<FFortAIGoalInfo>& GoalInfos);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	bool RemoveParticipantAccount(FUniqueNetIdRepl& AbandoningPlayerId);

	UFUNCTION(BlueprintCallable, Category="Players")
	bool RestartAllPlayers();

	UFUNCTION(BlueprintCallable, Category="AI")
	void SendBotLogicMessage(const FString& EventName);

	UFUNCTION(BlueprintCallable, Category="Mission")
	void SetMissionGameDifficulty(float GameDifficultyValue);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetRespawnTextOverride(const FText& NewText);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void SetToSilentDestroy();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true", UnsafeDuringActorConstruction="true"))
	void SetUiVisibility(bool bInIsMissionVisible);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(WorldContext="Mission"))
	static TArray<AActor*> SpawnAtPlacementActorsAsArray(AFortMission* Mission, bool& bSucceeded);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterInfo* StartMissionAIEncounter(TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, const TArray<AActor*>& TargetActors, UFortAIAssignmentSettings* AssignmentSettings, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter", meta=(AdvancedDisplay="8"))
	UFortAIEncounterInfo* StartMissionAIEncounterFromGeneratedProfile(int32 GeneratedEncounterProfileIndex, const TArray<AActor*>& TargetActors, UFortAIAssignmentSettings* AssignmentSettings, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay = 0, bool bUseAssignments = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	void StopEncounterSequence(UFortAIEncounterSequence* SequenceToStop);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	void StopMissionAIEncounter(UFortAIEncounterInfo* EncounterToStop);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Tier")
	void UpdatePlayerTierCompletions(UFortTieredCollectionLayout* TieredCollectionLayout, int32 CompletedTier);

	UPROPERTY()
	TObjectPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY(BlueprintReadOnly, SaveGame, Replicated, Category="Mission Info")
	TEnumAsByte<EMissionGenerationCategory::Type> MissionCategory;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_UIIndex)
	int32 UIIndex;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_QuestOwnerAccount)
	FUniqueNetIdRepl QuestOwnerAccount;

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, AdvancedDisplay, Category="FortMission")
	TArray<FFortMissionEventName> MissionEventNames;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnObjectivesUpdated OnObjectivesUpdated;

	UPROPERTY(BlueprintAssignable, Category="Mission")
	FOnMissionInfoSet OnMissionInfoSet;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMission", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> MissionCompletionStinger;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions", meta=(DisplayName="PostMissionLoad"))
	void BlueprintPostMissionLoad();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Missions")
	bool GetAdditionalMissionSuccessBadges(TArray<UFortWorldItemDefinition*>& SuccessItems) const;

	UFUNCTION()
	void OnRep_ActiveObjectives();

	UFUNCTION()
	virtual void OnRep_bIsMissionVisible();

	UFUNCTION()
	void OnRep_CurrentFocusDisplayData();

	UFUNCTION()
	void OnRep_MissionInfo();

	UFUNCTION()
	virtual void OnRep_MissionStatus();

	UFUNCTION()
	void OnRep_PotentialBadgesArray();

	UFUNCTION()
	virtual void OnRep_QuestOwnerAccount();

	UFUNCTION()
	virtual void OnRep_UIIndex();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions", meta=(BlueprintProtected="true"))
	void OnWaveCompleted(int32 Tier, int32 Wave, EFortCompletionResult Result);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Missions")
	void ProvideAllPotentialBadges(const TArray<FGameplayTag>& BadgeTags);

	UFUNCTION(BlueprintCallable, Category="Mission Timer")
	void SetTimerComponent(UFortMissionTimerComponent* InTimerComponent);

	UFUNCTION(BlueprintCallable, Category="Mission Timer")
	void SetTimerElapsedComponent(UFortMissionTimerComponent* InTimerElapsedComponent);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MissionInfo, Category="Mission Info")
	TObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditDefaultsOnly, Category="Mission Info")
	TSubclassOf<UFortBotMissionLogic> BotLogicClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortBotMissionLogic> BotLogic;

	UPROPERTY(EditDefaultsOnly, Category="Mission Info")
	TArray<TSoftObjectPtr<UFortItemDefinition>> MissionPreloadAssets;

	UPROPERTY(EditDefaultsOnly, Category="Announcement")
	TSubclassOf<AFortClientAnnouncement_Basic> AnnouncementClassOverride;

	UPROPERTY(EditDefaultsOnly, Category="FortMission")
	TArray<FFortMissionPlacementActorPreferredTagInfo> PlacementActorPreferredTagData;

	UPROPERTY(Transient)
	bool bLoadedFromRecord;

	UPROPERTY(Transient)
	bool bFiredParTimeEvent;

	UPROPERTY(Config)
	bool bAreNonpublicMatchesLeecherExempt;

	UPROPERTY(Config)
	float LeecherPity;

	UPROPERTY(Config)
	float LeecherMinMultiplier;

	UPROPERTY(Config)
	float LeecherCutoff;

	UPROPERTY(Config)
	float LeecherTimeScalingCutoff;

	UPROPERTY(Config)
	float LeecherTimeScalingPenaltyMultipler;

	UPROPERTY(Config)
	float LeecherCombatScoreMultiplier;

	UPROPERTY(Config)
	float LeecherBuildingScoreMultiplier;

	UPROPERTY(Config)
	float LeecherUtilityScoreMultiplier;

	UPROPERTY(Config)
	int32 LeecherCombatLowBar;

	UPROPERTY(Config)
	int32 LeecherBuildingLowBar;

	UPROPERTY(Config)
	int32 LeecherUtilityLowBar;

	UPROPERTY(Transient, Replicated)
	float MissionActivationTime;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentFocusDisplayData)
	FFortMissionFocusDisplayData CurrentFocusData;

	UPROPERTY(SaveGame, Replicated)
	bool bSilentDestroyNextFrame;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveObjectives)
	TArray<TObjectPtr<AFortObjectiveBase>> ActiveObjectives;

	UPROPERTY(Transient, Replicated)
	TArray<FUniqueNetIdRepl> ParticipatingAccounts;

	UPROPERTY(Transient, Replicated)
	TArray<FUniqueNetIdRepl> ParticipatingButDisconnectedAccounts;

	UPROPERTY(BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_MissionStatus, Category="Mission")
	EFortMissionStatus MissionStatus;

	UPROPERTY(BlueprintReadOnly, Category="FortMission")
	FGameplayTagContainer MissionCompletionTags;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_bIsMissionVisible)
	bool bIsMissionVisible;

	UPROPERTY(SaveGame, Replicated)
	EFortMissionAudibility MissionAudibility;

	UPROPERTY(SaveGame)
	int32 CurrentObjectiveBlockIndex;

	UPROPERTY(SaveGame)
	bool bIsMissionVisibleOverride;

	UPROPERTY(SaveGame, Replicated)
	FGuid MissionGuid;

	UPROPERTY(SaveGame, Replicated)
	int32 StartingDay;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Mission Timer", meta=(EditInline="true"))
	TObjectPtr<UFortMissionTimerComponent> TimerComponent;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Mission Timer", meta=(EditInline="true"))
	TObjectPtr<UFortMissionTimerComponent> TimerElapsedComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Missions")
	bool bObjectiveTimerExpireShouldFailObjectives;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Missions")
	bool bMissionTimerExpireShouldFailMission;

	UPROPERTY(EditDefaultsOnly, Category="Missions")
	bool bNeedsEnemyKilledEventForAllPawns;

	UPROPERTY(SaveGame, Replicated)
	int32 ChosenRewardIdx;

	UPROPERTY(Transient)
	bool bSuccessfullyInitializedActorsForMission;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PotentialBadgesArray)
	FFortBadgeCountArray PotentialBadgesArray;

	UPROPERTY()
	FFortGeneratedDifficultyOptions GeneratedMissionOptions;

private:
	UPROPERTY(Transient)
	FFortMissionInstancedConfigData ConfigData;

};

