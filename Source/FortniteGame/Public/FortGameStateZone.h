// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "UObject/SoftObjectPath.h"
#include "Abilities/FortAbilityTypes.h"
#include "Building/BuildingTypes.h"
#include "FortCombatTypes.h"
#include "FortCompletionResult.h"
#include "FortGameState.h"
#include "FortItemQuantityPair.h"
#include "FortServerStability.h"
#include "FortVoteConfig.h"
#include "STW/TieredWaveSet.h"
#include "FortGameStateZone.generated.h"

class ABuildingActor;
class ABuildingSMActor;
class AFortAIPawn;
class AFortCreativePortalManager;
class AFortCreativeRealEstatePlotManager;
class AFortGameplayMutator;
class AFortGlobalEnvironmentAbilityActor;
class AFortInGameMapManager;
class AFortPlayerController;
class AFortPlayerState;
class AFortThreatParticleActor;
class AFortThreatVisualsManager;
class UAnimMontage;
class UBuildingEditModeMetadata;
class UBuildingStructuralSupportSystem;
class UFortAbilitySystemComponent;
class UFortCharacterCosmeticManager;
class UFortGameStateComponent_AffiliationManager;
class UFortGameStateComponent_SurfaceOverride;
class UFortGameplayModifierItemDefinition;
class UFortMissionGenerator;
class UFortSkinWeightOverrideManager;
class UFortZoneTheme;
class UObject;
enum class EFortAIDirectorEvent : uint8;
enum class EFortCompletionResult : uint8;
enum class EFortItemType : uint8;
enum class EFortVoteArbitratorType : uint8;
enum class EFortVoteStatus : uint8;
enum class EFortVoteType : uint8;
enum class EStatCategory : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCompletionResult);

USTRUCT(BlueprintType)
struct FVoter
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Voter")
	int32 VoteDecision;

	UPROPERTY(BlueprintReadOnly, Transient, NotReplicated, Category="Voter")
	int32 LastVoteDecision;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Voter")
	FUniqueNetIdRepl NetId;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Voter")
	int32 NumVotesCast;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnGameplayVotesUpdatedInternal, EFortVoteType, VoteType, EFortVoteStatus, VoteStatus, int32, VoteResult, const TArray<FVoter>&, Voters);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_FourParams(FOnGameplayVotesUpdated, EFortVoteType, VoteType, EFortVoteStatus, VoteStatus, int32, VoteResult, const TArray<FVoter>&, Voters);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNumSurvivorsRescuedChanged, int32, NumSurvivorsRescued);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScoreTotalsChanged);

USTRUCT()
struct FActiveGameplayModifier : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameplayModifierItemDefinition> ModifierDef;

	UPROPERTY(Transient, NotReplicated)
	FActiveGameplayModifierHandle ModifierHandle;

	UPROPERTY(Transient, NotReplicated)
	TArray<TObjectPtr<AFortGameplayMutator>> Mutators;

	UPROPERTY(Transient, NotReplicated)
	int32 Expiration;

};

USTRUCT()
struct FActiveGameplayModifierArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FActiveGameplayModifier> Items;

	UPROPERTY(Transient, NotReplicated)
	TArray<FActiveGameplayModifier> DeferredGameplayModifiers;

	UPROPERTY(Transient, NotReplicated)
	int32 ModifierHandleGenerator;

	UPROPERTY(Transient, NotReplicated)
	bool bSupportRuntimeModifierShutdown;

};

USTRUCT()
struct FFortZoneDifficultyIncreaseRewardData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortItemQuantityPair> Rewards;

};

USTRUCT()
struct FFortZoneMissionAlertData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortItemQuantityPair> MissionAlertRewards;

	UPROPERTY(Transient)
	FString MissionAlertCategoryName;

	UPROPERTY(Transient)
	FString MissionAlertID;

};

USTRUCT()
struct FPlayerBuildableClassContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingSMActor>> BuildingClasses;

};

USTRUCT()
struct FPlayerBuildableClassFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(Transient)
	TEnumAsByte<EFortBuildingType::Type> BuildingType;

	UPROPERTY(Transient)
	int32 Level;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingEditModeMetadata> EditModeMetadata;

};

USTRUCT()
struct FReplicatedMontageIndexPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY()
	int32 Index;

};

USTRUCT()
struct FReplicatedMontageMap
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FReplicatedMontageIndexPair> Mappings;

};

USTRUCT()
struct FVoteData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	EFortVoteType VoteType;

	UPROPERTY(Transient)
	FUniqueNetIdRepl VoteInstigatorNetId;

	UPROPERTY(Transient)
	FFortVoteConfig VoteConfig;

	UPROPERTY(Transient)
	float VoteStartTime;

	UPROPERTY(Transient)
	float VoteEndTime;

	UPROPERTY(Transient)
	TArray<FVoter> Voters;

	UPROPERTY(Transient)
	int32 NumVotersWithMaxVotes;

	UPROPERTY(Transient)
	FTimerHandle EndVoteTimerHandle;

	UPROPERTY(Transient)
	EFortVoteStatus VoteStatus;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameState_InGame : public AFortGameState
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateZone : public AFortGameState_InGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="KillFeed", meta=(CPP_Default_ExtraDisplaySeconds="0.000000", CPP_Default_Tag="()"))
	virtual void AddKillFeedEntry(const FText& KillFeedText, float ExtraDisplaySeconds, const FGameplayTag Tag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Abilities")
	void ApplyPlayerAbilityRestriction();

	UFUNCTION(BlueprintCallable, Category="Voting")
	void BindDelegateOnGameplayVoteUpdated(EFortVoteType VoteType, FOnGameplayVotesUpdated Delegate);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Modifiers")
	void GetActiveModifiers(TArray<UFortGameplayModifierItemDefinition*>& OutActiveModifiers) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool GetCurrentVoters(EFortVoteType VoteType, TArray<FVoter>& Voters) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetFailedVoteLockOutDuration(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Difficulty")
	float GetGameDifficulty() const;

	UFUNCTION(BlueprintPure, Category="Voting")
	TArray<FUniqueNetIdRepl> GetGameplayVotesForChoice(EFortVoteType VoteType, int32 VoteChoice) const;

	UFUNCTION(BlueprintPure, Category="Respawn")
	bool GetIsDBNODeathEnabled() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Difficulty")
	int32 GetNumAllowedDifficultyIncreases() const;

	UFUNCTION(BlueprintPure, Category="Survivors")
	int32 GetNumSurvivorsDead() const;

	UFUNCTION(BlueprintPure, Category="Survivors")
	int32 GetNumSurvivorsRescued() const;

	UFUNCTION(BlueprintPure, Category="Survivors")
	int32 GetNumSurvivorsSpawned() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Crafting")
	FText GetSupressedCraftingDisplayText() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Crafting")
	void GetSupressedCraftingFilterNames(TArray<FName>& OutNames) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Crafting")
	void GetSupressedCraftingItemTypes(TArray<EFortItemType>& OutItemTypes) const;

	UFUNCTION(BlueprintPure, Category="Theater")
	const FGameplayTagContainer& GetTheaterTags() const;

	UFUNCTION(BlueprintPure, Category="Storm")
	AFortThreatParticleActor* GetThreatParticleActor() const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetTimeElapsedSinceBeginVote(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetTimeElapsedSinceEndVote(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetTimeRemainingToEndFailedVoteLockout(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetTimeRemainingToEndVote(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Score")
	int32 GetTotalScore(EStatCategory ScoreCategory) const;

	UFUNCTION(BlueprintCallable, Category="InGameMap")
	virtual AFortInGameMapManager* GetUIMapManager();

	UFUNCTION(BlueprintPure, Category="Voting")
	bool GetVoteArbitratorType(EFortVoteType VoteType, EFortVoteArbitratorType& ArbitratorType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	float GetVoteDuration(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool GetVoteEndTime(EFortVoteType VoteType, float& VoteEndTime) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool GetVoteInstigator(EFortVoteType VoteType, FUniqueNetIdRepl& InstigatorNetId) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool GetVoteStartTime(EFortVoteType VoteType, float& VoteStartTime) const;

	UFUNCTION(BlueprintPure)
	EFortCompletionResult GetZoneCompletionResult() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Abilities")
	void GloballyBlockAbilitiesWithTags(FGameplayTagContainer TagsToBlock);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Abilities")
	void GloballyUnblockAbilitiesWithTags(FGameplayTagContainer TagsToUnblock);

	UFUNCTION(BlueprintPure, Category="Modifiers")
	bool HasActiveGameplayModifiers() const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool IsAnyGameplayVoteActive() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	bool IsBuildingAtLayoutRequirementsAllowed() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Building")
	bool IsBuildingWithoutLayoutRequirementsAllowed() const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool IsGameplayVoteActive(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool IsGameplayVoteInProgress(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Voting")
	bool IsGameplayVoteLocked(EFortVoteType VoteType) const;

	UFUNCTION(BlueprintPure, Category="Respawn")
	virtual bool IsRespawningAllowed(AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Survivors")
	void NotifySurvivorDead();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Survivors")
	void NotifySurvivorRescued(AFortPlayerController* Rescuer, const FString& SurvivorName);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Survivors")
	void NotifySurvivorSpawned();

	UFUNCTION()
	void OnRep_NumSurvivorsRescued();

	UFUNCTION()
	virtual void OnRep_PlayerStructuresChanged();

	UFUNCTION()
	void OnRepServerUnstableFramerate();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="WaveBasedEncounter")
	virtual void OnWaveEncounterStarted(const FTieredWaveSetData& WaveData, const FText& LevelText, int32 Level, const FText& WaveText, int32 WaveNum);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Modifiers")
	FActiveGameplayModifierHandle RegisterGameplayModifier(const UFortGameplayModifierItemDefinition* InModifierToRegister, int32 Expiration = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Abilities")
	void RemovePlayerAbilityRestriction();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Voting")
	void ServerBeginGameplayVote(EFortVoteType VoteType, const FUniqueNetIdRepl& PlayerNetId, FFortVoteConfig VoteConfig);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Voting")
	void ServerEndGameplayVote(EFortVoteType VoteType, const FUniqueNetIdRepl& PlayerNetId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerFireAIDirectorEvent(EFortAIDirectorEvent Event, UObject* EventSource, UObject* EventTarget, float EventMultiplier);

	UFUNCTION(Server, Reliable)
	void ServerFireAIDirectorEventBatch(const TArray<FFortAIDirectorEvent>& Payload);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Voting")
	void ServerSubmitGameplayVote(EFortVoteType VoteType, int32 VoteDecision, const FUniqueNetIdRepl& PlayerNetId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void SetBuildingAllowed(bool bBuildingAtLayoutRequirementsAllowed, bool bBuildingWithoutLayoutRequirementsAllowed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Difficulty")
	bool SetDifficultyIncreaseRewardTier(int32 InDifficultyIncreaseTier);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Respawn")
	void SetIsDBNODeathEnabled(bool NewValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Rewards")
	void SetMissionRewardLootLevelOverride(int32 LootLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Rewards")
	void SetMissionRewardOverrideTag(FText MissionRewardOverrideTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Loot Level")
	void SetWorldLootLevel(const int32 NewLootLevel);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Respawn")
	void SetZoneCompletionResult(EFortCompletionResult NewCompletionResult);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Mission Results")
	bool ShouldDisablePlayerTeleportingDuringMissionResults() const;

	UFUNCTION(BlueprintCallable, Category="Voting")
	void UnbindDelegateOnGameplayVoteUpdated(EFortVoteType VoteType, FOnGameplayVotesUpdated Delegate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Modifiers")
	void UnregisterGameplayModifier(const FActiveGameplayModifierHandle& InHandleToUnregister);

	UPROPERTY(Transient)
	int32 PawnIDCount;

	UPROPERTY(Replicated)
	int32 WaitingToLeaveZoneTimeLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="HostilityMeter")
	float HostilityMeterPercent;

	UPROPERTY(Transient, Replicated)
	float IntensityPercent;

	UPROPERTY(Transient, Replicated)
	int32 SpawnPointsCap;

	UPROPERTY(Transient, Replicated)
	int32 SpawnPointsAllocated;

	UPROPERTY(Transient, Replicated)
	int32 MaxTotalAI;

	UPROPERTY(Transient, Replicated)
	int32 MaxEncounterAI;

	UPROPERTY(Transient, Replicated)
	int32 MaxEncounterSP;

	UPROPERTY(Transient, Replicated)
	FReplicatedMontageMap ReplicatedMontageMap;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AllSpawnGroupUpgradeModifierDefs)
	TArray<TObjectPtr<UFortGameplayModifierItemDefinition>> AllSpawnGroupUpgradeModifierDefs;

	UPROPERTY(ReplicatedUsing=OnRep_CompletionResult)
	EFortCompletionResult CompletionResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	bool bDrawRunVariationDebug;

	UPROPERTY(Transient)
	TArray<TSubclassOf<ABuildingActor>> AllPlayerBuildableClasses;

	UPROPERTY(Transient)
	TMap<TSubclassOf<ABuildingActor>, int32> AllPlayerBuildableClassesIndexLookup;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FPlayerBuildableClassContainer PlayerBuildableClasses[6];

	UPROPERTY(BlueprintAssignable)
	FOnScoreTotalsChanged OnScoreTotalsChanged;

	UPROPERTY(Transient, ReplicatedUsing=OnRepServerUnstableFramerate)
	EServerStability ServerStability;

protected:
	UFUNCTION(NetMulticast, Reliable)
	void NotifyEndFailedGameplayVoteLockout(EFortVoteType VoteType);

	UFUNCTION()
	void OnRep_ActiveGameplayModifiers();

	UFUNCTION()
	void OnRep_bGlobalCeaseFire();

	UFUNCTION()
	void OnRep_ClientPreloadMissionClasses();

	UFUNCTION()
	void OnRep_DifficultyIncreaseRewards();

	UFUNCTION()
	void OnRep_DifficultyIncreaseRewardTier();

	UFUNCTION()
	void OnRep_ExplicitGloballyBlockedAbilityTags();

	UFUNCTION()
	virtual void OnRep_GameDifficulty();

	UFUNCTION()
	void OnRep_GameplayVotes();

	UFUNCTION()
	void OnRep_MissionAlertData();

	UFUNCTION()
	void OnRep_MissionGenerator();

	UFUNCTION()
	void OnRep_MissionRewards();

	UFUNCTION()
	virtual void OnRep_PlayerBuildingSkillLevel();

	UFUNCTION()
	virtual void OnRep_PlayerSharedTrapAttributes();

	UFUNCTION()
	void OnRep_ServerGameplayTagIndexHash();

	UFUNCTION()
	void OnRep_TheaterUniqueId();

	UFUNCTION()
	void OnRep_ZoneDifficultyInfoRow();

	UFUNCTION(NetMulticast, Reliable)
	void OnWaveBasedModifiersAppliedMulticast(const TArray<UFortGameplayModifierItemDefinition*>& ModifiersApplied);

	UFUNCTION(NetMulticast, Reliable)
	void OnWaveStart(const FText& LevelText, int32 Level, const FText& WaveText, int32 WaveNum);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerBuildingSkillLevel)
	float PlayerBuildingSkillLevel;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerSharedTrapAttributes)
	TArray<float> PlayerSharedMaxTrapAttributes;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> GameplayMutatorObservers;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ExplicitGloballyBlockedAbilityTags)
	FGameplayTagContainer ExplicitGloballyBlockedAbilityTags;

	UPROPERTY(Transient, Replicated)
	bool bInvitesRestricted;

	UPROPERTY(Transient, Replicated)
	bool bDBNODeathEnabled;

	UPROPERTY(ReplicatedUsing=OnRep_ServerGameplayTagIndexHash)
	uint32 ServerGameplayTagIndexHash;

	UPROPERTY(Config)
	bool bDisconnectOnServerGameplayTagIndexHashMismatch;

	UPROPERTY(ReplicatedUsing=OnRep_PlayerStructuresChanged)
	int32 TotalPlayerStructures;

	UPROPERTY(ReplicatedUsing=OnRep_PlayerStructuresChanged)
	int32 MaxPlayerStructures;

	UPROPERTY(ReplicatedUsing=OnRep_bGlobalCeaseFire)
	bool bGlobalCeaseFire;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortGlobalEnvironmentAbilityActor> GlobalEnvironmentAbilityActor;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortAbilitySystemComponent>> GlobalGameplayEventListeners;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveGameplayModifiers)
	FActiveGameplayModifierArray ActiveGameplayModifiers;

	UPROPERTY(Transient)
	bool bSupportRuntimeShutdownOfGameplayModifiers;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingStructuralSupportSystem> StructuralSupportSystem;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ZoneDifficultyInfoRow)
	FDataTableRowHandle ZoneDifficultyInfoRow;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortZoneTheme> ZoneTheme;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MissionGenerator)
	TSoftClassPtr<UFortMissionGenerator> MissionGeneratorClass;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MissionRewards)
	TArray<FFortItemQuantityPair> MissionRewards;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DifficultyIncreaseRewards)
	TArray<FFortZoneDifficultyIncreaseRewardData> DifficultyIncreaseRewards;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_MissionAlertData)
	FFortZoneMissionAlertData MissionAlertData;

	UPROPERTY(ReplicatedUsing=OnRep_ClientPreloadMissionClasses)
	TArray<FSoftObjectPath> ClientPreloadMissionClasses;

	UPROPERTY()
	uint8 bAllowedToUpdateBackendDifficulty : 1;

	UPROPERTY()
	uint8 bAllowedToOverrideBackendRewards : 1;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortInGameMapManager> UIMapManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortCharacterCosmeticManager> CharacterCosmeticManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortSkinWeightOverrideManager> SkinWeightManager;

	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	FName ScoringTableRowName;

	UPROPERTY(Transient)
	int32 TotalCombatScore;

	UPROPERTY(Transient)
	int32 TotalBuildingScore;

	UPROPERTY(Transient)
	int32 TotalUtilityScore;

	UPROPERTY(ReplicatedUsing=OnRep_TheaterUniqueId)
	FString TheaterUniqueId;

	UPROPERTY(Replicated)
	FString MissionLogDebugString;

	UPROPERTY(EditDefaultsOnly, Category="FOB")
	uint8 bAllowBuildingCostMods : 1;

	UPROPERTY(EditDefaultsOnly, Category="FOB")
	uint8 bFreeBuildingRepairs : 1;

	UPROPERTY(Transient, Replicated)
	bool bAllowBuildingAtLayoutRequirements;

	UPROPERTY(Transient, Replicated)
	bool bAllowBuildingWithoutLayoutRequirements;

	UPROPERTY(Transient, Replicated)
	bool bAllowLayoutRequirementsFeature;

	UPROPERTY(Config, Transient)
	bool bAllowBuildingThroughBlockingObjects;

	UPROPERTY(Transient)
	int32 NumSurvivorsSpawned;

	UPROPERTY(Transient)
	int32 NumSurvivorsDead;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NumSurvivorsRescued)
	int32 NumSurvivorsRescued;

	UPROPERTY(BlueprintAssignable, Category="Survivors")
	FOnNumSurvivorsRescuedChanged OnNumSurvivorsRescuedChangedDelegate;

	UPROPERTY(Transient)
	TObjectPtr<AFortCreativePortalManager> CreativePortalManager;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortCreativeRealEstatePlotManager> CreativeRealEstatePlotManager;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameStateZone")
	bool bUseMaxBackpackSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortGameStateZone", meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> AffiliationManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_SurfaceOverride> SurfaceOverrideComponent;

private:
	UFUNCTION()
	void OnRep_AllSpawnGroupUpgradeModifierDefs();

	UFUNCTION()
	void OnRep_CompletionResult();

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnCompletionResult OnCompletionResultEvent;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortThreatVisualsManager> ThreatVisualsManager;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AFortThreatParticleActor> ThreatParticleActor;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortAIPawn>> PawnVariationList;

	UPROPERTY(Transient)
	int32 VariationIndex;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_GameDifficulty)
	float GameDifficulty;

	UPROPERTY(Transient, Replicated)
	bool bIsGroupContent;

	UPROPERTY(ReplicatedUsing=OnRep_DifficultyIncreaseRewardTier)
	int32 DifficultyIncreaseRewardTier;

	UPROPERTY(EditDefaultsOnly, Category="Building")
	bool bShouldPreCachePlayerBuildableClasses;

	UPROPERTY(ReplicatedUsing=OnRep_GameplayVotes)
	TArray<FVoteData> GameplayVotesArray;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameState_InGame_Custom : public AFortGameState_InGame
{
	GENERATED_BODY()

};

