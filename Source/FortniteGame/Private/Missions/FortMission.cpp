// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMission.h"
#include "Net/UnrealNetwork.h"

void AFortMission::AddCompletionTag(FGameplayTag NewCompletionTag)
{
}

void AFortMission::AddCompletionTags(FGameplayTagContainer NewCompletionTagContainer)
{
}

void AFortMission::AddGoalsToAssignment(UFortAIAssignment* Assignment, const TArray<FFortAIGoalInfo>& GoalInfos)
{
}

void AFortMission::AddGoalsToEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const TArray<FFortAIGoalInfo>& GoalInfos)
{
}

void AFortMission::AddGoalToAssignment(UFortAIAssignment* Assignment, const FFortAIGoalInfo& GoalInfo)
{
}

void AFortMission::AddGoalToEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const FFortAIGoalInfo& GoalInfo)
{
}

void AFortMission::AddOrRemoveTimerTime_Implementation(float TimeToAdd)
{
}

bool AFortMission::AddParticipantAccount(AFortPlayerController* PlayerController)
{
	return false;
}

void AFortMission::ApplyTieredModifierSet(const TArray<FTieredModifierSetData>& ModifierSetData, int32 Tier, int32 WaveNum, bool bDeferTemporaryModifiers, TArray<FActiveGameplayModifierHandle>& OutAppliedModifiers)
{
}

void AFortMission::AttemptMissionSave(const FString& OptionalSaveName)
{
}

bool AFortMission::BlueprintCanPlayerParticipate_Implementation(AFortPlayerController* PlayerController) const
{
	return false;
}

FFortMissionWeightedReward AFortMission::ChooseRandomReward()
{
	return FFortMissionWeightedReward();
}

EAssignmentCreationResult AFortMission::CreateEncounterAssignment(const FGameplayTagContainer& AssignmentTags, UFortAIEncounterInfo* const& Encounter, UFortAIAssignmentSettings* AssignmentSettings, TSubclassOf<UFortAIGoalProvider> GoalProvider, FFortAIAssignmentIdentifier& AssignmentIdentifier)
{
	return EAssignmentCreationResult();
}

UFortAIEncounterSequence* AFortMission::CreateEncounterSequence(const FGameplayTagContainer& SequenceTags)
{
	return nullptr;
}

UFortAIEncounterSequence* AFortMission::CreateEncounterSequenceByIndex(int32 EncounterSequenceIndex)
{
	return nullptr;
}

void AFortMission::FindGoalLocationsForEncounterAssignment(const FFortAIAssignmentIdentifier& AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, TArray<FVector>& OutGoalLocations)
{
}

void AFortMission::FocusThisMission(FText FocusDisplayText, float FocusPercentage)
{
}

bool AFortMission::GetActorsSpawnedMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnedActors) const
{
	return false;
}

TArray<AFortObjectiveBase*> AFortMission::GetAllObjectives() const
{
	return TArray<AFortObjectiveBase*>();
}

TSubclassOf<AFortClientAnnouncement_Basic> AFortMission::GetAnnouncementClassOverride() const
{
	return TSubclassOf<AFortClientAnnouncement_Basic>();
}

FAvailableTierLayout AFortMission::GetAvailableTiers(UFortTieredCollectionLayout* TieredCollectionLayout, int32 MaxTierUnlocked)
{
	return FAvailableTierLayout();
}

int32 AFortMission::GetBuildingDamageLootTier(AFortPlayerController* PlayerController) const
{
	return int32();
}

UFortMissionConfigData* AFortMission::GetConfigData(FGameplayTagContainer InContainer)
{
	return nullptr;
}

int32 AFortMission::GetCurrentBluGloRewards_Implementation() const
{
	return int32();
}

FText AFortMission::GetCurrentFocusDisplayText() const
{
	return FText();
}

float AFortMission::GetCurrentFocusPercentage() const
{
	return float();
}

int32 AFortMission::GetDaysRemainingBeforeOverPar() const
{
	return int32();
}

float AFortMission::GetExpectedCompletionTime_Implementation() const
{
	return float();
}

FText AFortMission::GetMissionCompletionResultText_Implementation(EFortCompletionResult Result)
{
	return FText();
}

FGuid AFortMission::GetMissionGuid() const
{
	return FGuid();
}

FText AFortMission::GetMissionName() const
{
	return FText();
}

AFortObjectiveBase* AFortMission::GetObjectiveByHandle(const FGameplayTagContainer& ObjectiveHandle) const
{
	return nullptr;
}

TArray<FGameplayTagContainer> AFortMission::GetObjectiveHandlesWithTag(FGameplayTag ObjectiveTag, int32 MaxNumberOfObjectives) const
{
	return TArray<FGameplayTagContainer>();
}

EFortObjectiveStatus AFortMission::GetObjectiveStatusByHandle(const FGameplayTagContainer& ObjectiveHandle) const
{
	return EFortObjectiveStatus();
}

TArray<AFortPlayerController*> AFortMission::GetParticipatingMissionControllers() const
{
	return TArray<AFortPlayerController*>();
}

int32 AFortMission::GetPawnDamageLootTier(AFortPlayerController* PlayerController) const
{
	return int32();
}

FText AFortMission::GetRespawnTextOverride_Implementation() const
{
	return FText();
}

void AFortMission::GetRewardItemsByTag(const FGameplayTag RewardTag, TArray<UFortWorldItemDefinition*>& OutRewardItems)
{
}

void AFortMission::GetSpawningDistanceMinMaxOverrideForAIEncounter_Implementation(const UFortAIEncounterInfo* Encounter, float& OutSpawningDistanceMin, float& OutSpawningDistanceMax) const
{
}

bool AFortMission::GetSpawnLocationActorsMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<AActor*>& SpawnLocationActors) const
{
	return false;
}

bool AFortMission::GetSpawnLocationsMatchingQuery(const FGameplayTagQuery& TagQuery, TArray<FVector>& SpawnLocations) const
{
	return false;
}

void AFortMission::GetTieredModifierSet(FName TieredModifierSetName, TArray<FTieredModifierSetData>& OutModifierSetData)
{
}

bool AFortMission::GetTierOutputForSelectedTier(int32 Tier, const UFortTieredCollectionLayout* TieredCollectionLayout, FFortTierCollectionLayoutOutput& Output) const
{
	return false;
}

bool AFortMission::GetValidTierCollectionLayoutOutputs(UFortTieredCollectionLayout* TieredCollectionLayout, int32 MaxTierUnlocked, TArray<FFortTierCollectionLayoutOutput>& OutTiers, TArray<FFortTierCollectionLayoutOutput>& OutLockedTiers)
{
	return false;
}

void AFortMission::GrantRewardsByTag(const FGameplayTag RewardTag, EFortRewardType::Type RewardType)
{
}

void AFortMission::HandleEncounterEnemyAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy)
{
}

bool AFortMission::HasMissionPar() const
{
	return false;
}

bool AFortMission::HasSuccessfullyInitializedActorsForMission() const
{
	return false;
}

bool AFortMission::InitializeActorsForMission(AFortMission* Mission, TArray<AActor*>& OutActorsInitialized)
{
	return false;
}

bool AFortMission::InitializeActorsForMissionMatchingItemIdentifyingQuery(AFortMission* Mission, const FGameplayTagQuery& TagQuery, TArray<AActor*>& OutActorsInitialized)
{
	return false;
}

void AFortMission::InitializeModifiersRRV(int32 Seed)
{
}

bool AFortMission::IsPlayerParticipating(AFortPlayerController* PlayerController) const
{
	return false;
}

void AFortMission::LoadMissionsManually(TArray<FGuid>& OutAddedMissionGuids, TArray<UFortMissionInfo*>& MissionsToLoad)
{
}

void AFortMission::LoadPossibleMissionsManually(TArray<FGuid>& OutAddedMissionGuids, TArray<FFortPossibleMission>& PossibleMissionsToLoad)
{
}

void AFortMission::MissionTimerSet_Implementation()
{
}

void AFortMission::OnRep_ActiveObjectives()
{
}

void AFortMission::OnRep_bIsMissionVisible()
{
}

void AFortMission::OnRep_CurrentFocusDisplayData()
{
}

void AFortMission::OnRep_MissionInfo()
{
}

void AFortMission::OnRep_MissionStatus()
{
}

void AFortMission::OnRep_PotentialBadgesArray()
{
}

void AFortMission::OnRep_QuestOwnerAccount()
{
}

void AFortMission::OnRep_UIIndex()
{
}

void AFortMission::OnWaveCompleted(int32 Tier, int32 Wave, EFortCompletionResult Result)
{
}

void AFortMission::ProvideAllPotentialBadges(const TArray<FGameplayTag>& BadgeTags)
{
}

void AFortMission::RecordResourceActorSpawn(AActor* SpawnedActor)
{
}

void AFortMission::RegisterForBuildingHarvestedByPlayerEvent(FOnMissionBuildingSMActorHarvestedEvent Delegate, const FGameplayTagQuery& HarvestedBuildingRequirements)
{
}

void AFortMission::RegisterForContainerSearchedEvent(FOnMissionContainerSearchedEvent Delegate, const FGameplayTagQuery& ContainerRequirements)
{
}

void AFortMission::RemoveGoalFromEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const FFortAIGoalInfo& GoalInfo)
{
}

void AFortMission::RemoveGoalsFromEncounterAssignment(FFortAIAssignmentIdentifier AssignmentIdentifier, UFortAIEncounterInfo* const& Encounter, const TArray<FFortAIGoalInfo>& GoalInfos)
{
}

bool AFortMission::RemoveParticipantAccount(FUniqueNetIdRepl& AbandoningPlayerId)
{
	return false;
}

bool AFortMission::RestartAllPlayers()
{
	return false;
}

void AFortMission::SendBotLogicMessage(const FString& EventName)
{
}

void AFortMission::SetMissionGameDifficulty(float GameDifficultyValue)
{
}

void AFortMission::SetRespawnTextOverride(const FText& NewText)
{
}

void AFortMission::SetTimerComponent(UFortMissionTimerComponent* InTimerComponent)
{
}

void AFortMission::SetTimerElapsedComponent(UFortMissionTimerComponent* InTimerElapsedComponent)
{
}

void AFortMission::SetToSilentDestroy()
{
}

void AFortMission::SetUiVisibility(bool bInIsMissionVisible)
{
}

TArray<AActor*> AFortMission::SpawnAtPlacementActorsAsArray(AFortMission* Mission, bool& bSucceeded)
{
	return TArray<AActor*>();
}

UFortAIEncounterInfo* AFortMission::StartMissionAIEncounter(TSubclassOf<UFortAIEncounterInfo> EncounterTemplate, const TArray<AActor*>& TargetActors, UFortAIAssignmentSettings* AssignmentSettings, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay)
{
	return nullptr;
}

UFortAIEncounterInfo* AFortMission::StartMissionAIEncounterFromGeneratedProfile(int32 GeneratedEncounterProfileIndex, const TArray<AActor*>& TargetActors, UFortAIAssignmentSettings* AssignmentSettings, FEncounterEnvironmentQueryInfo EnvironmentQueryInfo, AActor* QueryActor, FGameplayTagContainer InjectedTags, FFortEncounterSettings EncounterSettings, int32 ActivationDelay, bool bUseAssignments)
{
	return nullptr;
}

void AFortMission::StopEncounterSequence(UFortAIEncounterSequence* SequenceToStop)
{
}

void AFortMission::StopMissionAIEncounter(UFortAIEncounterInfo* EncounterToStop)
{
}

void AFortMission::UpdatePlayerTierCompletions(UFortTieredCollectionLayout* TieredCollectionLayout, int32 CompletedTier)
{
}

void AFortMission::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMission, MissionInfo);
	DOREPLIFETIME(AFortMission, MissionCategory);
	DOREPLIFETIME(AFortMission, UIIndex);
	DOREPLIFETIME(AFortMission, QuestOwnerAccount);
	DOREPLIFETIME(AFortMission, MissionActivationTime);
	DOREPLIFETIME(AFortMission, CurrentFocusData);
	DOREPLIFETIME(AFortMission, bSilentDestroyNextFrame);
	DOREPLIFETIME(AFortMission, ActiveObjectives);
	DOREPLIFETIME(AFortMission, ParticipatingAccounts);
	DOREPLIFETIME(AFortMission, ParticipatingButDisconnectedAccounts);
	DOREPLIFETIME(AFortMission, MissionStatus);
	DOREPLIFETIME(AFortMission, bIsMissionVisible);
	DOREPLIFETIME(AFortMission, MissionAudibility);
	DOREPLIFETIME(AFortMission, MissionGuid);
	DOREPLIFETIME(AFortMission, StartingDay);
	DOREPLIFETIME(AFortMission, ChosenRewardIdx);
	DOREPLIFETIME(AFortMission, PotentialBadgesArray);
}
