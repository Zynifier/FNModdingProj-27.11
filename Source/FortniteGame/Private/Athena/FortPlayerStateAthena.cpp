// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerStateAthena.h"
#include "Net/UnrealNetwork.h"

bool AFortPlayerStateAthena::CanBeResurrected() const
{
	return false;
}

bool AFortPlayerStateAthena::CanEditCreativeIsland() const
{
	return false;
}

void AFortPlayerStateAthena::Client_OnNewLevel_Implementation(int32 NewLevel)
{
}

void AFortPlayerStateAthena::ClientAddKillFeedErrorMessage_Implementation(const TArray<FFortCreativeMessageDispatcherErrorMessage>& ErrorMessages)
{
}

void AFortPlayerStateAthena::ClientNotifyMatchEntered_Implementation(const FEventTournamentIds& EventIds)
{
}

void AFortPlayerStateAthena::ClientReportDBNO_Implementation(const AFortPlayerStateAthena* Player)
{
}

void AFortPlayerStateAthena::ClientReportKill_Implementation(const AFortPlayerStateAthena* Player)
{
}

void AFortPlayerStateAthena::ClientReportTeamKill_Implementation(int32 TeamKills)
{
}

void AFortPlayerStateAthena::ClientReportTournamentStatUpdate_Implementation(const FFortTournamentStatInfo& TournamentStatInfo) const
{
}

ECreativePersistenceErrorTypes AFortPlayerStateAthena::GetCurrentPersistenceErrorType() const
{
	return ECreativePersistenceErrorTypes();
}

const FDeathInfo& AFortPlayerStateAthena::GetDeathInfo() const
{
	static FDeathInfo Dummy;
	return Dummy;
}

bool AFortPlayerStateAthena::GetInventoriesInLocalOnlyMode() const
{
	return false;
}

bool AFortPlayerStateAthena::GetInventoriesInNonPersistenceMode() const
{
	return false;
}

bool AFortPlayerStateAthena::GetInventoriesRequiredWithNoPersistence() const
{
	return false;
}

int32 AFortPlayerStateAthena::GetKillScore() const
{
	return int32();
}

FLinearColor AFortPlayerStateAthena::GetPinColor() const
{
	return FLinearColor();
}

FLinearColor AFortPlayerStateAthena::GetPinColorBySquadMemberIndex(int32 SquadIndex)
{
	return FLinearColor();
}

float AFortPlayerStateAthena::GetRemainingResurrectionChipExpirationTime() const
{
	return float();
}

float AFortPlayerStateAthena::GetResurrectionChipExpirationLength() const
{
	return float();
}

TSoftObjectPtr<UTexture2D> AFortPlayerStateAthena::GetSocialAvatarBrush(const bool bSmallImage) const
{
	return TSoftObjectPtr<UTexture2D>();
}

uint8 AFortPlayerStateAthena::GetSquadId() const
{
	return uint8();
}

int32 AFortPlayerStateAthena::GetSquadMemberIndex() const
{
	return int32();
}

uint8 AFortPlayerStateAthena::GetTeam() const
{
	return uint8();
}

UFortControllerComponent_TransientQuests* AFortPlayerStateAthena::GetTransientQuestsComponent() const
{
	return nullptr;
}

bool AFortPlayerStateAthena::IsAnAthenaGameParticipant() const
{
	return false;
}

bool AFortPlayerStateAthena::IsDisconnected() const
{
	return false;
}

bool AFortPlayerStateAthena::IsInSquad() const
{
	return false;
}

bool AFortPlayerStateAthena::IsRespawningWithRespawnData() const
{
	return false;
}

bool AFortPlayerStateAthena::IsResurrectingNow() const
{
	return false;
}

bool AFortPlayerStateAthena::IsResurrectionChipAvailable() const
{
	return false;
}

bool AFortPlayerStateAthena::IsSquadDead() const
{
	return false;
}

void AFortPlayerStateAthena::NetMulticastTriggerCustomFeedMessage_Implementation(const FGameplayTag CustomFeedMessageGeneratorID)
{
}

void AFortPlayerStateAthena::NetMulticastTriggerCustomFeedMessageWithContext_Implementation(const FGameplayTag CustomFeedMessageGeneratorID, FCustomFeedMessageContext Context)
{
}

void AFortPlayerStateAthena::OnInteractionEventOccurred(FGameplayTagContainer& InteractionTargetTags)
{
}

void AFortPlayerStateAthena::OnRep_AIKills()
{
}

void AFortPlayerStateAthena::OnRep_ChangeTeamInfo()
{
}

void AFortPlayerStateAthena::OnRep_DeathInfo()
{
}

void AFortPlayerStateAthena::OnRep_DidNotThankBusDriver()
{
}

void AFortPlayerStateAthena::OnRep_Downs()
{
}

void AFortPlayerStateAthena::OnRep_InteractingRebootVan()
{
}

void AFortPlayerStateAthena::OnRep_IsContributingToOverbudgetHeatmap()
{
}

void AFortPlayerStateAthena::OnRep_KeepPlayingTogetherMatchmakingRegion()
{
}

void AFortPlayerStateAthena::OnRep_KeepPlayingTogetherVotingStatus()
{
}

void AFortPlayerStateAthena::OnRep_Kills()
{
}

void AFortPlayerStateAthena::OnRep_MatchAbandonState(const EMatchAbandonState PrevMatchAbandonState)
{
}

void AFortPlayerStateAthena::OnRep_MetricInformation()
{
}

void AFortPlayerStateAthena::OnRep_NumAmmoCansOpened()
{
}

void AFortPlayerStateAthena::OnRep_NumBronzeCoinsCollected()
{
}

void AFortPlayerStateAthena::OnRep_NumChestsOpened()
{
}

void AFortPlayerStateAthena::OnRep_NumForagedItemsConsumed()
{
}

void AFortPlayerStateAthena::OnRep_NumGoldCoinsCollected()
{
}

void AFortPlayerStateAthena::OnRep_NumLlamasOpened()
{
}

void AFortPlayerStateAthena::OnRep_NumMinutesAlive()
{
}

void AFortPlayerStateAthena::OnRep_NumSilverCoinsCollected()
{
}

void AFortPlayerStateAthena::OnRep_NumSupplyDropsOpened()
{
}

void AFortPlayerStateAthena::OnRep_PersistenceErrorType()
{
}

void AFortPlayerStateAthena::OnRep_Place()
{
}

void AFortPlayerStateAthena::OnRep_PreserveSquad()
{
}

void AFortPlayerStateAthena::OnRep_RebootCounter()
{
}

void AFortPlayerStateAthena::OnRep_ReplicatedTeamMemberState()
{
}

void AFortPlayerStateAthena::OnRep_ResurrectingNow(const bool bPreviousResurrectingNow)
{
}

void AFortPlayerStateAthena::OnRep_ResurrectionChipReplicated()
{
}

void AFortPlayerStateAthena::OnRep_SeasonLevelUIDisplay()
{
}

void AFortPlayerStateAthena::OnRep_SimpleMetricInformation()
{
}

void AFortPlayerStateAthena::OnRep_SquadId()
{
}

void AFortPlayerStateAthena::OnRep_StormSurgeEffectCount()
{
}

void AFortPlayerStateAthena::OnRep_TeamAverageDamageDealt()
{
}

void AFortPlayerStateAthena::OnRep_TeamIndex(uint8 OldVal)
{
}

void AFortPlayerStateAthena::OnRep_TeamKillScore()
{
}

void AFortPlayerStateAthena::OnRep_TeamScore()
{
}

void AFortPlayerStateAthena::OnRep_TeamScorePlacement()
{
}

void AFortPlayerStateAthena::OnRep_ThankedBusDriver()
{
}

void AFortPlayerStateAthena::OnRep_TotalPlayerScore()
{
}

void AFortPlayerStateAthena::OnSquadSpecificActorDestroyed(const uint8 AlwaysRelevantForSquadId, AActor* DestroyedActor)
{
}

void AFortPlayerStateAthena::OnSquadSpecificActorSpawned(const uint8 AlwaysRelevantForSquadId, AActor* SpawnedActor)
{
}

void AFortPlayerStateAthena::Server_SetCanEditCreativeIsland_Implementation(bool bCanEdit, const TArray<FString>& WhiteList)
{
}
bool AFortPlayerStateAthena::Server_SetCanEditCreativeIsland_Validate(bool bCanEdit, const TArray<FString>& WhiteList)
{
	return true;
}

void AFortPlayerStateAthena::Server_SetKeepPlayingTogetherVotingStatus_Implementation(EKeepPlayingTogetherVotingStatus NewStatus)
{
}
bool AFortPlayerStateAthena::Server_SetKeepPlayingTogetherVotingStatus_Validate(EKeepPlayingTogetherVotingStatus NewStatus)
{
	return true;
}

void AFortPlayerStateAthena::Server_TogglePreserveSquad_Implementation()
{
}
bool AFortPlayerStateAthena::Server_TogglePreserveSquad_Validate()
{
	return true;
}

void AFortPlayerStateAthena::ServerSetKeepPlayingTogetherMatchmakingRegion_Implementation(const FString& NewRegion)
{
}

void AFortPlayerStateAthena::SetIsContributingToOverbudgetHeatmap(bool bContributingToOverbudget)
{
}

EDeathCause AFortPlayerStateAthena::ToDeathCause(const FGameplayTagContainer& InTags, bool bWasDBNO)
{
	return EDeathCause();
}

void AFortPlayerStateAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerStateAthena, PersonalLobbyAction);
	DOREPLIFETIME(AFortPlayerStateAthena, ReplicatedTeamMemberState);
	DOREPLIFETIME(AFortPlayerStateAthena, TeamKillScore);
	DOREPLIFETIME(AFortPlayerStateAthena, TeamIndex);
	DOREPLIFETIME(AFortPlayerStateAthena, TeamScorePlacement);
	DOREPLIFETIME(AFortPlayerStateAthena, TeamScore);
	DOREPLIFETIME(AFortPlayerStateAthena, Place);
	DOREPLIFETIME(AFortPlayerStateAthena, DownScore);
	DOREPLIFETIME(AFortPlayerStateAthena, KillScore);
	DOREPLIFETIME(AFortPlayerStateAthena, SeasonLevelUIDisplay);
	DOREPLIFETIME(AFortPlayerStateAthena, NumChestsOpened);
	DOREPLIFETIME(AFortPlayerStateAthena, NumAmmoCansOpened);
	DOREPLIFETIME(AFortPlayerStateAthena, NumSupplyDropsOpened);
	DOREPLIFETIME(AFortPlayerStateAthena, NumLlamasOpened);
	DOREPLIFETIME(AFortPlayerStateAthena, NumForagedItemsConsumed);
	DOREPLIFETIME(AFortPlayerStateAthena, NumMinutesAlive);
	DOREPLIFETIME(AFortPlayerStateAthena, NumBronzeCoinsCollected);
	DOREPLIFETIME(AFortPlayerStateAthena, NumSilverCoinsCollected);
	DOREPLIFETIME(AFortPlayerStateAthena, NumGoldCoinsCollected);
	DOREPLIFETIME(AFortPlayerStateAthena, TotalPlayerScore);
	DOREPLIFETIME(AFortPlayerStateAthena, StormSurgeEffectCount);
	DOREPLIFETIME(AFortPlayerStateAthena, TeamAverageDamageDealt);
	DOREPLIFETIME(AFortPlayerStateAthena, SquadId);
	DOREPLIFETIME(AFortPlayerStateAthena, bThankedBusDriver);
	DOREPLIFETIME(AFortPlayerStateAthena, bDidNotThankBusDriver);
	DOREPLIFETIME(AFortPlayerStateAthena, bUsingAnonymousMode);
	DOREPLIFETIME(AFortPlayerStateAthena, bUsingAnonymousCharacterMode);
	DOREPLIFETIME(AFortPlayerStateAthena, bShowingSeasonLevel);
	DOREPLIFETIME(AFortPlayerStateAthena, PlayerNameCustomOverride);
	DOREPLIFETIME(AFortPlayerStateAthena, bHidingOtherPlayersNames);
	DOREPLIFETIME(AFortPlayerStateAthena, MetricInformation);
	DOREPLIFETIME(AFortPlayerStateAthena, SimpleMetricInformation);
	DOREPLIFETIME(AFortPlayerStateAthena, bIsDisconnected);
	DOREPLIFETIME(AFortPlayerStateAthena, DeathInfo);
	DOREPLIFETIME(AFortPlayerStateAthena, ChangeTeamInfo);
	DOREPLIFETIME(AFortPlayerStateAthena, ResurrectionChipAvailable);
	DOREPLIFETIME(AFortPlayerStateAthena, bResurrectingNow);
	DOREPLIFETIME(AFortPlayerStateAthena, bRespawningFromRespawnData);
	DOREPLIFETIME(AFortPlayerStateAthena, RebootCounter);
	DOREPLIFETIME(AFortPlayerStateAthena, InteractingRebootVan);
	DOREPLIFETIME(AFortPlayerStateAthena, MatchAbandonState);
	DOREPLIFETIME(AFortPlayerStateAthena, bIsAnAthenaGameParticipant);
	DOREPLIFETIME(AFortPlayerStateAthena, bIsContributingToOverbudgetHeatmap);
	DOREPLIFETIME(AFortPlayerStateAthena, BotUniqueId);
	DOREPLIFETIME(AFortPlayerStateAthena, bPreserveSquad);
	DOREPLIFETIME(AFortPlayerStateAthena, KeepPlayingTogetherVotingStatus);
	DOREPLIFETIME(AFortPlayerStateAthena, KeepPlayingTogetherMatchmakingRegion);
	DOREPLIFETIME(AFortPlayerStateAthena, InitialSquadSize);
	DOREPLIFETIME(AFortPlayerStateAthena, SquadSizeIncrements);
	DOREPLIFETIME(AFortPlayerStateAthena, SquadSizeDecrements);
	DOREPLIFETIME(AFortPlayerStateAthena, PersistenceErrorType);
}
