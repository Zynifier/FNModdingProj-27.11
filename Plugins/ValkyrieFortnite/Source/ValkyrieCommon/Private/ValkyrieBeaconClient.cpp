// Copyright Epic Games, Inc. All Rights Reserved.

#include "ValkyrieBeaconClient.h"
#include "Net/UnrealNetwork.h"

void AValkyrieBeaconClient::AddPrewarmCompatibilityVersion_Implementation(const FString& ClientVersion)
{
}

void AValkyrieBeaconClient::ClientDisallowedLiveEditTransactionEncountered_Implementation(bool bSuppressLiveEdit)
{
}

void AValkyrieBeaconClient::ClientHandleCookFailure_Implementation(const FString& CookJobId)
{
}

void AValkyrieBeaconClient::ClientHandleError_Implementation(const FText& ErrorMessage)
{
}

void AValkyrieBeaconClient::ClientHandleTransactionFinalizedEvent_Implementation(FConcertTransactionFinalizedEvent Event)
{
}

void AValkyrieBeaconClient::ClientLogSummaryMessage_Implementation(const FString& LogMessage)
{
}

void AValkyrieBeaconClient::ClientNotifyOfServerScriptDiagnosticMessage_Implementation(const FScriptDiagnosticMessage& Message)
{
}

void AValkyrieBeaconClient::ClientNotifyOfServerShutdown_Implementation()
{
}

void AValkyrieBeaconClient::ClientProcessDebugMessage_Implementation(const FSolarisDebugMessage& Message)
{
}

void AValkyrieBeaconClient::ClientUpdateContentUpdateState_Implementation(const EContentUpdateState NewContentUpdateState)
{
}

void AValkyrieBeaconClient::ClientVerseUploadComplete_Implementation(const FString& InSnapshotId, EVerseUploadState Result)
{
}

void AValkyrieBeaconClient::HandleVkCheatConsoleCommand(const TArray<FString>& Args)
{
}

void AValkyrieBeaconClient::ServerContentUpdated_Implementation(const FString& ProjectId, const FString& Snapshot, const TArray<FVkModuleVersion>& Modules_Legacy)
{
}
bool AValkyrieBeaconClient::ServerContentUpdated_Validate(const FString& ProjectId, const FString& Snapshot, const TArray<FVkModuleVersion>& Modules_Legacy)
{
	return true;
}

void AValkyrieBeaconClient::ServerOnContentBeaconHostError_Implementation(const FContentBeaconError& ContentBeaconError)
{
}

void AValkyrieBeaconClient::ServerProcessDebugMessage_Implementation(const FSolarisDebugMessage& Message)
{
}
bool AValkyrieBeaconClient::ServerProcessDebugMessage_Validate(const FSolarisDebugMessage& Message)
{
	return true;
}

void AValkyrieBeaconClient::ServerRefreshMemoryTracker_Implementation()
{
}

void AValkyrieBeaconClient::ServerRespawnAllPlayers_Implementation()
{
}
bool AValkyrieBeaconClient::ServerRespawnAllPlayers_Validate()
{
	return true;
}

void AValkyrieBeaconClient::ServerSendGameFlowMessage_Implementation(const FString& Message, const EVkEditStatus VkEditStatus)
{
}
bool AValkyrieBeaconClient::ServerSendGameFlowMessage_Validate(const FString& Message, const EVkEditStatus VkEditStatus)
{
	return true;
}

void AValkyrieBeaconClient::ServerSetPublishingMemoryLimit_Implementation(int32 PublishingMemoryLimit)
{
}

void AValkyrieBeaconClient::ServerSetUseLiveEditProxyActors_Implementation(bool bEnabled)
{
}

void AValkyrieBeaconClient::ServerStartGame_Implementation()
{
}

void AValkyrieBeaconClient::ServerStartMemorySampling_Implementation(const FOnlineLinkId& LinkCode)
{
}

void AValkyrieBeaconClient::ServerStopGame_Implementation()
{
}

void AValkyrieBeaconClient::ServerSubmitConnectedClientLogs_Implementation(const FGuid& ParentReportId)
{
}

void AValkyrieBeaconClient::ServerTeleportPlayer_Implementation(uint32 i, FVector Location, FRotator Rotation)
{
}

void AValkyrieBeaconClient::ServerVkCheatMessage_Implementation(const FVerseGameplayStringDebugMessage& Message)
{
}
bool AValkyrieBeaconClient::ServerVkCheatMessage_Validate(const FVerseGameplayStringDebugMessage& Message)
{
	return true;
}

void AValkyrieBeaconClient::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AValkyrieBeaconClient, PlayerList);
}
