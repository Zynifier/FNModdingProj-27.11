// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "OnlineBeaconClient.h"
#include "Diagnostics/ScriptDiagnosticMessage.h"
#include "Online/ContentBeaconUtilsV2.h"
#include "ContentBeaconClientV2.generated.h"

enum class EClientContentReadinessV2 : uint8;
enum class EContentRequestInstallState : uint8;

UENUM()
enum class EClientContentReadinessV2 : uint8
{
	NotConnected = 0,
	/** The Content Beacon client is awaiting a response from the server. */
	AwaitingServerResponse = 1,
	/** in the process of generating manifests 
	 * we could be delayed at this point if the contentbeacon is not ready for clients to join
	 */
	GeneratingManifests = 2,
	/** in the process of mounting the content */
	MountingContent = 3,
	/** The client loaded content but isn't ready to join yet */
	LoadedContent = 4,
	/** The server either didn't need content, or the Client has it now, and we are ready to join.*/
	ReadyToJoin = 5,
	/** The client is in sync with the servers content right now.  Client can switch between this and ready to join. */
	AllRequestsComplete = 6,
	/** client is in the process of disconnecting */
	Disconnecting = 7,
	/** Failsafe state. */
	None = 8,
};

UENUM()
enum class EServerContentReadinessV2 : uint8
{
	Initializing = 0,
	GeneratingManifests = 1,
	WaitingForClient = 2,
	ReadyToJoin = 3,
	Disconnecting = 4,
};

USTRUCT()
struct FContentBeaconClientReplicatedModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ContentURL;

	UPROPERTY()
	FString DebugModuleIdString;

	UPROPERTY()
	FClientModuleId ModuleId;

	UPROPERTY()
	EContentRequestInstallState DesiredState;

	UPROPERTY()
	bool bActiveOnServer;

};

USTRUCT()
struct FContentMessageItemEntryV2 : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ContentMessage;

};

USTRUCT()
struct FContentMessageArrayV2 : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FContentMessageItemEntryV2> Items;

};

UCLASS(MinimalAPI)
class AContentBeaconClientV2 : public AOnlineBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientNotifyDisconnect(bool bCleanupContent);

	UFUNCTION(Client, Reliable)
	void ClientNotifyOfServerScriptDiagnosticMessage(const FScriptDiagnosticMessage& Message);

	UFUNCTION(Client, Reliable)
	void ClientNotifyOfServerScriptScreenLogMessage(const FScriptScreenLogMessage& Message);

	UFUNCTION(Client, Reliable)
	void ClientNotifyOfServerScriptScreenLogMessageWithLocalization(const FScriptScreenLogMessageWithLocalization& Message);

	UFUNCTION(Server, Reliable)
	void ServerBeginDisconnect();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerFinishDisconnect();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRegisterClient(const FString& ClientConsumerFilterPlatform, const FString& InCompatibilityBranchVersion, bool bInIsAllowedToLoad);

	UPROPERTY(Transient, Replicated)
	FContentMessageArrayV2 ContentMessagesArray;

protected:
	UFUNCTION()
	void OnClientReadinessChanged();

	UFUNCTION()
	void OnRep_ClientAdditionalContentBundles();

	UPROPERTY()
	FString DestSessionId;

	UPROPERTY()
	FString DestConnectionInfoString;

	UPROPERTY(Transient, Replicated)
	FString DebugRootIdentiferString;

	UPROPERTY(Transient, Replicated)
	bool bIsClientInSync;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ClientAdditionalContentBundles)
	TArray<FContentBeaconClientReplicatedModule> ClientContentModules;

private:
	UFUNCTION(Client, Reliable)
	void ClientOnHostError(const FContentBeaconError& Error, bool bClientDisconnect, bool bServerShutdown);

	UFUNCTION(Client, Reliable)
	void ClientOnInitializeSettings(bool bInShouldErrorOnAdditionalContentFailure, bool bInHostRequiresAdditionalContent, bool bInNeedsDownloadBeforeJoin);

	UFUNCTION(Client, Reliable)
	void ClientSetClientReadiness(EClientContentReadinessV2 InClientReadiness);

	UFUNCTION(Server, Reliable)
	void ServerOnClientError(const FContentBeaconError& Error, bool bClientDisconnecting);

	UFUNCTION(Server, Reliable)
	void ServerOnLocalModuleError(const FClientModuleId& ModuleId, const FContentBeaconError& Error, bool bFatal);

	UFUNCTION(Server, Reliable)
	void ServerOnLocalModuleStateChanged(const FClientModuleId& ModuleId, EContentRequestInstallState CurrentState);

};

