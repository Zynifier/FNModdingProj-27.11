// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerControllerZone.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerControllerZone::AllowLoadoutRefresh()
{
}

bool AFortPlayerControllerZone::AreResurrectionAndRespawnTimeRemainingValid() const
{
	return false;
}

void AFortPlayerControllerZone::ClientAckLoadoutConfig_Implementation(int32 LoadoutSeed)
{
}

void AFortPlayerControllerZone::ClientClearDeathNotification_Implementation()
{
}

void AFortPlayerControllerZone::ClientDebugReceiveTagDiscrepancyResponse_Implementation(const TArray<uint8>& CompressedTags, bool bAllDataSent)
{
}
bool AFortPlayerControllerZone::ClientDebugReceiveTagDiscrepancyResponse_Validate(const TArray<uint8>& CompressedTags, bool bAllDataSent)
{
	return true;
}

void AFortPlayerControllerZone::ClientHandleCatalogOutOfDate_Implementation()
{
}

void AFortPlayerControllerZone::ClientHandlePurchaseCatalogEntryFailure_Implementation()
{
}

void AFortPlayerControllerZone::ClientOnPawnDied_Implementation(FFortPlayerDeathReport DeathReport)
{
}

void AFortPlayerControllerZone::ClientOnPawnRevived_Implementation(AController* EventInstigator)
{
}

void AFortPlayerControllerZone::ClientOnPawnSpawned_Implementation()
{
}

void AFortPlayerControllerZone::ClientOnZoneEndScoreReports_Implementation(const TArray<FFortPlayerScoreReport>& ScoreReports)
{
}

void AFortPlayerControllerZone::ClientSendPartyJoinInfoToPlayer_Implementation(const FString& JoinInfoStr)
{
}

void AFortPlayerControllerZone::ClientSubmitLogs_Implementation(const FGuid& ParentReportId) const
{
}

void AFortPlayerControllerZone::ClientUpdatePlaylistFlags_Implementation(const TArray<uint8>& Buffer)
{
}

void AFortPlayerControllerZone::ClientVoiceChatSendJoinToken_Implementation(int32 RequestId, bool bSuccess, const FString& Error, const FString& Token, const FString& ChannelName)
{
}

void AFortPlayerControllerZone::DisableRangedWeaponScopeFX()
{
}

void AFortPlayerControllerZone::DumpPhysicsVehicleBuffer(const FString& Command)
{
}

int32 AFortPlayerControllerZone::GetVehicleSeatTransitionTargetIndex() const
{
	return int32();
}

bool AFortPlayerControllerZone::IsClientNotifiedOfPawnDied() const
{
	return false;
}

bool AFortPlayerControllerZone::IsShowingSeasonLevel() const
{
	return false;
}

bool AFortPlayerControllerZone::IsUsingAnonymousCharacterMode() const
{
	return false;
}

bool AFortPlayerControllerZone::IsUsingAnonymousMode() const
{
	return false;
}

void AFortPlayerControllerZone::KillAllVehicles(const FString& Command)
{
}

void AFortPlayerControllerZone::OnRep_VoiceChatChannel()
{
}

void AFortPlayerControllerZone::PopDeathInputComponent()
{
}

void AFortPlayerControllerZone::PostMCPUpdateRequestLoadoutRefresh()
{
}

void AFortPlayerControllerZone::PushDeathInputComponent()
{
}

void AFortPlayerControllerZone::ResetExecuteJetpackToggle()
{
}

void AFortPlayerControllerZone::RespawnPlayer()
{
}

void AFortPlayerControllerZone::ResurrectPlayer()
{
}

void AFortPlayerControllerZone::RewindVehicle(const FString& Command)
{
}

void AFortPlayerControllerZone::ServerActivateMission_Implementation()
{
}

void AFortPlayerControllerZone::ServerAttemptExitVehicle_Implementation()
{
}

void AFortPlayerControllerZone::ServerBeginGameplayVote_Implementation(EFortVoteType VoteType, FFortVoteConfig VoteConfig)
{
}

void AFortPlayerControllerZone::ServerDebugSendDiscrepancyRequestData_Implementation()
{
}
bool AFortPlayerControllerZone::ServerDebugSendDiscrepancyRequestData_Validate()
{
	return true;
}

void AFortPlayerControllerZone::ServerDebugSendTagDiscrepancyRequest_Implementation()
{
}
bool AFortPlayerControllerZone::ServerDebugSendTagDiscrepancyRequest_Validate()
{
	return true;
}

void AFortPlayerControllerZone::ServerDestroyFromRemoteControlledPawn_Implementation()
{
}

void AFortPlayerControllerZone::ServerDetachFromRemoteControlledPawn_Implementation()
{
}

void AFortPlayerControllerZone::ServerEndGameplayVote_Implementation(EFortVoteType VoteType)
{
}

void AFortPlayerControllerZone::ServerPurchaseCatalogEntry_Implementation(const FString& GameNamespace, const FString& OfferId, const FString& DevName, const FCatalogItemPrice& Price, const FString& AppStoreOfferId, const FString& EpicOfferId, int32 Quantity, int32 ExpectedPrice, const FString& NotificationId, const int32 CommonCoreClientRevision, const int32 AthenaClientRevision, const FStoreOfferInfo& StoreOfferInfo)
{
}

void AFortPlayerControllerZone::ServerRequestLoadoutRefresh_Implementation(bool bForceResfresh)
{
}

void AFortPlayerControllerZone::ServerRequestSeatChange_Implementation(int32 TargetSeatIndex)
{
}

void AFortPlayerControllerZone::ServerSendLoadoutConfig_Implementation(int32 LoadoutSeed, const TArray<uint8>& Loadout)
{
}

void AFortPlayerControllerZone::ServerSendPartyJoinInfoToPlayer_Implementation(const FUniqueNetIdRepl& RecipientId, const FString& JoinInfoStr)
{
}

void AFortPlayerControllerZone::ServerSetShouldDisablePlayerTeleportingDuringMissionResults_Implementation()
{
}

void AFortPlayerControllerZone::ServerSetVehicleHealth_Implementation(float NewHealth)
{
}

void AFortPlayerControllerZone::ServerSpectateActor_Implementation(AActor* NewViewTarget, const bool bAllowStateChange)
{
}
bool AFortPlayerControllerZone::ServerSpectateActor_Validate(AActor* NewViewTarget, const bool bAllowStateChange)
{
	return true;
}

void AFortPlayerControllerZone::ServerSpectatePlayerState_Implementation(AFortPlayerStateZone* PlayerToSpectate, const bool bAllowStateChange)
{
}
bool AFortPlayerControllerZone::ServerSpectatePlayerState_Validate(AFortPlayerStateZone* PlayerToSpectate, const bool bAllowStateChange)
{
	return true;
}

void AFortPlayerControllerZone::ServerSubmitGameplayVote_Implementation(EFortVoteType VoteType, int32 VoteDecision)
{
}

void AFortPlayerControllerZone::ServerVoiceChatRequestJoinToken_Implementation(int32 RequestId, const FString& ChannelName)
{
}

void AFortPlayerControllerZone::SetDontChangeReticleColorForEnemy(bool bDontChangeForEnemy)
{
}

void AFortPlayerControllerZone::SetVehicleHealth(float NewHealth)
{
}

void AFortPlayerControllerZone::SpectateOnDeath()
{
}

void AFortPlayerControllerZone::TestVehicleVelocity(const FString& Command)
{
}

void AFortPlayerControllerZone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerControllerZone, PlayerLeecherStatus);
	DOREPLIFETIME(AFortPlayerControllerZone, VoiceChatChannel);
	DOREPLIFETIME(AFortPlayerControllerZone, DesyncNotifyList);
}

UAbilitySystemComponent* AFortPlayerControllerZone::GetAbilitySystemComponent() const
{
	return nullptr;
}
