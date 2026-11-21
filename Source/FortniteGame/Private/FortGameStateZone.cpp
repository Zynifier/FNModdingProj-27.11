// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameStateZone.h"
#include "Net/UnrealNetwork.h"

void AFortGameStateZone::AddKillFeedEntry(const FText& KillFeedText, float ExtraDisplaySeconds, const FGameplayTag Tag)
{
}

void AFortGameStateZone::ApplyPlayerAbilityRestriction()
{
}

void AFortGameStateZone::BindDelegateOnGameplayVoteUpdated(EFortVoteType VoteType, FOnGameplayVotesUpdated Delegate)
{
}

void AFortGameStateZone::GetActiveModifiers(TArray<UFortGameplayModifierItemDefinition*>& OutActiveModifiers) const
{
}

bool AFortGameStateZone::GetCurrentVoters(EFortVoteType VoteType, TArray<FVoter>& Voters) const
{
	return false;
}

float AFortGameStateZone::GetFailedVoteLockOutDuration(EFortVoteType VoteType) const
{
	return float();
}

float AFortGameStateZone::GetGameDifficulty() const
{
	return float();
}

TArray<FUniqueNetIdRepl> AFortGameStateZone::GetGameplayVotesForChoice(EFortVoteType VoteType, int32 VoteChoice) const
{
	return TArray<FUniqueNetIdRepl>();
}

bool AFortGameStateZone::GetIsDBNODeathEnabled() const
{
	return false;
}

int32 AFortGameStateZone::GetNumAllowedDifficultyIncreases() const
{
	return int32();
}

int32 AFortGameStateZone::GetNumSurvivorsDead() const
{
	return int32();
}

int32 AFortGameStateZone::GetNumSurvivorsRescued() const
{
	return int32();
}

int32 AFortGameStateZone::GetNumSurvivorsSpawned() const
{
	return int32();
}

FText AFortGameStateZone::GetSupressedCraftingDisplayText_Implementation() const
{
	return FText();
}

const FGameplayTagContainer& AFortGameStateZone::GetTheaterTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

AFortThreatParticleActor* AFortGameStateZone::GetThreatParticleActor() const
{
	return nullptr;
}

float AFortGameStateZone::GetTimeElapsedSinceBeginVote(EFortVoteType VoteType) const
{
	return float();
}

float AFortGameStateZone::GetTimeElapsedSinceEndVote(EFortVoteType VoteType) const
{
	return float();
}

float AFortGameStateZone::GetTimeRemainingToEndFailedVoteLockout(EFortVoteType VoteType) const
{
	return float();
}

float AFortGameStateZone::GetTimeRemainingToEndVote(EFortVoteType VoteType) const
{
	return float();
}

int32 AFortGameStateZone::GetTotalScore(EStatCategory ScoreCategory) const
{
	return int32();
}

AFortInGameMapManager* AFortGameStateZone::GetUIMapManager()
{
	return nullptr;
}

bool AFortGameStateZone::GetVoteArbitratorType(EFortVoteType VoteType, EFortVoteArbitratorType& ArbitratorType) const
{
	return false;
}

float AFortGameStateZone::GetVoteDuration(EFortVoteType VoteType) const
{
	return float();
}

bool AFortGameStateZone::GetVoteEndTime(EFortVoteType VoteType, float& VoteEndTime) const
{
	return false;
}

bool AFortGameStateZone::GetVoteInstigator(EFortVoteType VoteType, FUniqueNetIdRepl& InstigatorNetId) const
{
	return false;
}

bool AFortGameStateZone::GetVoteStartTime(EFortVoteType VoteType, float& VoteStartTime) const
{
	return false;
}

EFortCompletionResult AFortGameStateZone::GetZoneCompletionResult() const
{
	return EFortCompletionResult();
}

void AFortGameStateZone::GloballyBlockAbilitiesWithTags(FGameplayTagContainer TagsToBlock)
{
}

void AFortGameStateZone::GloballyUnblockAbilitiesWithTags(FGameplayTagContainer TagsToUnblock)
{
}

bool AFortGameStateZone::HasActiveGameplayModifiers() const
{
	return false;
}

bool AFortGameStateZone::IsAnyGameplayVoteActive() const
{
	return false;
}

bool AFortGameStateZone::IsBuildingAtLayoutRequirementsAllowed() const
{
	return false;
}

bool AFortGameStateZone::IsBuildingWithoutLayoutRequirementsAllowed() const
{
	return false;
}

bool AFortGameStateZone::IsGameplayVoteActive(EFortVoteType VoteType) const
{
	return false;
}

bool AFortGameStateZone::IsGameplayVoteInProgress(EFortVoteType VoteType) const
{
	return false;
}

bool AFortGameStateZone::IsGameplayVoteLocked(EFortVoteType VoteType) const
{
	return false;
}

bool AFortGameStateZone::IsRespawningAllowed(AFortPlayerState* PlayerState) const
{
	return false;
}

void AFortGameStateZone::NotifyEndFailedGameplayVoteLockout_Implementation(EFortVoteType VoteType)
{
}

void AFortGameStateZone::NotifySurvivorDead()
{
}

void AFortGameStateZone::NotifySurvivorRescued(AFortPlayerController* Rescuer, const FString& SurvivorName)
{
}

void AFortGameStateZone::NotifySurvivorSpawned()
{
}

void AFortGameStateZone::OnRep_ActiveGameplayModifiers()
{
}

void AFortGameStateZone::OnRep_AllSpawnGroupUpgradeModifierDefs()
{
}

void AFortGameStateZone::OnRep_bGlobalCeaseFire()
{
}

void AFortGameStateZone::OnRep_ClientPreloadMissionClasses()
{
}

void AFortGameStateZone::OnRep_CompletionResult()
{
}

void AFortGameStateZone::OnRep_DifficultyIncreaseRewards()
{
}

void AFortGameStateZone::OnRep_DifficultyIncreaseRewardTier()
{
}

void AFortGameStateZone::OnRep_ExplicitGloballyBlockedAbilityTags()
{
}

void AFortGameStateZone::OnRep_GameDifficulty()
{
}

void AFortGameStateZone::OnRep_GameplayVotes()
{
}

void AFortGameStateZone::OnRep_MissionAlertData()
{
}

void AFortGameStateZone::OnRep_MissionGenerator()
{
}

void AFortGameStateZone::OnRep_MissionRewards()
{
}

void AFortGameStateZone::OnRep_NumSurvivorsRescued()
{
}

void AFortGameStateZone::OnRep_PlayerBuildingSkillLevel()
{
}

void AFortGameStateZone::OnRep_PlayerSharedTrapAttributes()
{
}

void AFortGameStateZone::OnRep_PlayerStructuresChanged()
{
}

void AFortGameStateZone::OnRep_ServerGameplayTagIndexHash()
{
}

void AFortGameStateZone::OnRep_TheaterUniqueId()
{
}

void AFortGameStateZone::OnRep_ZoneDifficultyInfoRow()
{
}

void AFortGameStateZone::OnRepServerUnstableFramerate()
{
}

void AFortGameStateZone::OnWaveBasedModifiersAppliedMulticast_Implementation(const TArray<UFortGameplayModifierItemDefinition*>& ModifiersApplied)
{
}

void AFortGameStateZone::OnWaveEncounterStarted(const FTieredWaveSetData& WaveData, const FText& LevelText, int32 Level, const FText& WaveText, int32 WaveNum)
{
}

void AFortGameStateZone::OnWaveStart_Implementation(const FText& LevelText, int32 Level, const FText& WaveText, int32 WaveNum)
{
}

FActiveGameplayModifierHandle AFortGameStateZone::RegisterGameplayModifier(const UFortGameplayModifierItemDefinition* InModifierToRegister, int32 Expiration)
{
	return FActiveGameplayModifierHandle();
}

void AFortGameStateZone::RemovePlayerAbilityRestriction()
{
}

void AFortGameStateZone::ServerBeginGameplayVote(EFortVoteType VoteType, const FUniqueNetIdRepl& PlayerNetId, FFortVoteConfig VoteConfig)
{
}

void AFortGameStateZone::ServerEndGameplayVote(EFortVoteType VoteType, const FUniqueNetIdRepl& PlayerNetId)
{
}

void AFortGameStateZone::ServerFireAIDirectorEvent_Implementation(EFortAIDirectorEvent Event, UObject* EventSource, UObject* EventTarget, float EventMultiplier)
{
}
bool AFortGameStateZone::ServerFireAIDirectorEvent_Validate(EFortAIDirectorEvent Event, UObject* EventSource, UObject* EventTarget, float EventMultiplier)
{
	return true;
}

void AFortGameStateZone::ServerFireAIDirectorEventBatch_Implementation(const TArray<FFortAIDirectorEvent>& Payload)
{
}

void AFortGameStateZone::ServerSubmitGameplayVote(EFortVoteType VoteType, int32 VoteDecision, const FUniqueNetIdRepl& PlayerNetId)
{
}

void AFortGameStateZone::SetBuildingAllowed(bool bBuildingAtLayoutRequirementsAllowed, bool bBuildingWithoutLayoutRequirementsAllowed)
{
}

bool AFortGameStateZone::SetDifficultyIncreaseRewardTier(int32 InDifficultyIncreaseTier)
{
	return false;
}

void AFortGameStateZone::SetIsDBNODeathEnabled(bool NewValue)
{
}

void AFortGameStateZone::SetMissionRewardLootLevelOverride(int32 LootLevel)
{
}

void AFortGameStateZone::SetMissionRewardOverrideTag(FText MissionRewardOverrideTag)
{
}

void AFortGameStateZone::SetWorldLootLevel(const int32 NewLootLevel)
{
}

void AFortGameStateZone::SetZoneCompletionResult(EFortCompletionResult NewCompletionResult)
{
}

bool AFortGameStateZone::ShouldDisablePlayerTeleportingDuringMissionResults() const
{
	return false;
}

void AFortGameStateZone::UnbindDelegateOnGameplayVoteUpdated(EFortVoteType VoteType, FOnGameplayVotesUpdated Delegate)
{
}

void AFortGameStateZone::UnregisterGameplayModifier(const FActiveGameplayModifierHandle& InHandleToUnregister)
{
}

void AFortGameStateZone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameStateZone, WaitingToLeaveZoneTimeLeft);
	DOREPLIFETIME(AFortGameStateZone, HostilityMeterPercent);
	DOREPLIFETIME(AFortGameStateZone, IntensityPercent);
	DOREPLIFETIME(AFortGameStateZone, SpawnPointsCap);
	DOREPLIFETIME(AFortGameStateZone, SpawnPointsAllocated);
	DOREPLIFETIME(AFortGameStateZone, MaxTotalAI);
	DOREPLIFETIME(AFortGameStateZone, MaxEncounterAI);
	DOREPLIFETIME(AFortGameStateZone, MaxEncounterSP);
	DOREPLIFETIME(AFortGameStateZone, ReplicatedMontageMap);
	DOREPLIFETIME(AFortGameStateZone, AllSpawnGroupUpgradeModifierDefs);
	DOREPLIFETIME(AFortGameStateZone, CompletionResult);
	DOREPLIFETIME(AFortGameStateZone, PlayerBuildingSkillLevel);
	DOREPLIFETIME(AFortGameStateZone, PlayerSharedMaxTrapAttributes);
	DOREPLIFETIME(AFortGameStateZone, ExplicitGloballyBlockedAbilityTags);
	DOREPLIFETIME(AFortGameStateZone, bInvitesRestricted);
	DOREPLIFETIME(AFortGameStateZone, bDBNODeathEnabled);
	DOREPLIFETIME(AFortGameStateZone, ServerGameplayTagIndexHash);
	DOREPLIFETIME(AFortGameStateZone, TotalPlayerStructures);
	DOREPLIFETIME(AFortGameStateZone, MaxPlayerStructures);
	DOREPLIFETIME(AFortGameStateZone, bGlobalCeaseFire);
	DOREPLIFETIME(AFortGameStateZone, GlobalEnvironmentAbilityActor);
	DOREPLIFETIME(AFortGameStateZone, ActiveGameplayModifiers);
	DOREPLIFETIME(AFortGameStateZone, ZoneDifficultyInfoRow);
	DOREPLIFETIME(AFortGameStateZone, ZoneTheme);
	DOREPLIFETIME(AFortGameStateZone, MissionGeneratorClass);
	DOREPLIFETIME(AFortGameStateZone, MissionRewards);
	DOREPLIFETIME(AFortGameStateZone, DifficultyIncreaseRewards);
	DOREPLIFETIME(AFortGameStateZone, MissionAlertData);
	DOREPLIFETIME(AFortGameStateZone, ClientPreloadMissionClasses);
	DOREPLIFETIME(AFortGameStateZone, ThreatVisualsManager);
	DOREPLIFETIME(AFortGameStateZone, ThreatParticleActor);
	DOREPLIFETIME(AFortGameStateZone, GameDifficulty);
	DOREPLIFETIME(AFortGameStateZone, bIsGroupContent);
	DOREPLIFETIME(AFortGameStateZone, DifficultyIncreaseRewardTier);
	DOREPLIFETIME(AFortGameStateZone, UIMapManager);
	DOREPLIFETIME(AFortGameStateZone, TheaterUniqueId);
	DOREPLIFETIME(AFortGameStateZone, MissionLogDebugString);
	DOREPLIFETIME(AFortGameStateZone, bAllowBuildingAtLayoutRequirements);
	DOREPLIFETIME(AFortGameStateZone, bAllowBuildingWithoutLayoutRequirements);
	DOREPLIFETIME(AFortGameStateZone, bAllowLayoutRequirementsFeature);
	DOREPLIFETIME(AFortGameStateZone, NumSurvivorsRescued);
	DOREPLIFETIME(AFortGameStateZone, ServerStability);
	DOREPLIFETIME(AFortGameStateZone, GameplayVotesArray);
	DOREPLIFETIME(AFortGameStateZone, CreativeRealEstatePlotManager);
}
