// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/ContentBeaconClientV2.h"
#include "Net/UnrealNetwork.h"

void AContentBeaconClientV2::ClientNotifyDisconnect_Implementation(bool bCleanupContent)
{
}

void AContentBeaconClientV2::ClientNotifyOfServerScriptDiagnosticMessage_Implementation(const FScriptDiagnosticMessage& Message)
{
}

void AContentBeaconClientV2::ClientNotifyOfServerScriptScreenLogMessage_Implementation(const FScriptScreenLogMessage& Message)
{
}

void AContentBeaconClientV2::ClientNotifyOfServerScriptScreenLogMessageWithLocalization_Implementation(const FScriptScreenLogMessageWithLocalization& Message)
{
}

void AContentBeaconClientV2::ClientOnHostError_Implementation(const FContentBeaconError& Error, bool bClientDisconnect, bool bServerShutdown)
{
}

void AContentBeaconClientV2::ClientOnInitializeSettings_Implementation(bool bInShouldErrorOnAdditionalContentFailure, bool bInHostRequiresAdditionalContent, bool bInNeedsDownloadBeforeJoin)
{
}

void AContentBeaconClientV2::ClientSetClientReadiness_Implementation(EClientContentReadinessV2 InClientReadiness)
{
}

void AContentBeaconClientV2::OnClientReadinessChanged()
{
}

void AContentBeaconClientV2::OnRep_ClientAdditionalContentBundles()
{
}

void AContentBeaconClientV2::ServerBeginDisconnect_Implementation()
{
}

void AContentBeaconClientV2::ServerFinishDisconnect_Implementation()
{
}
bool AContentBeaconClientV2::ServerFinishDisconnect_Validate()
{
	return true;
}

void AContentBeaconClientV2::ServerOnClientError_Implementation(const FContentBeaconError& Error, bool bClientDisconnecting)
{
}

void AContentBeaconClientV2::ServerOnLocalModuleError_Implementation(const FClientModuleId& ModuleId, const FContentBeaconError& Error, bool bFatal)
{
}

void AContentBeaconClientV2::ServerOnLocalModuleStateChanged_Implementation(const FClientModuleId& ModuleId, EContentRequestInstallState CurrentState)
{
}

void AContentBeaconClientV2::ServerRegisterClient_Implementation(const FString& ClientConsumerFilterPlatform, const FString& InCompatibilityBranchVersion, bool bInIsAllowedToLoad)
{
}
bool AContentBeaconClientV2::ServerRegisterClient_Validate(const FString& ClientConsumerFilterPlatform, const FString& InCompatibilityBranchVersion, bool bInIsAllowedToLoad)
{
	return true;
}

void AContentBeaconClientV2::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AContentBeaconClientV2, ContentMessagesArray);
	DOREPLIFETIME(AContentBeaconClientV2, DebugRootIdentiferString);
	DOREPLIFETIME(AContentBeaconClientV2, bIsClientInSync);
	DOREPLIFETIME(AContentBeaconClientV2, ClientContentModules);
}
