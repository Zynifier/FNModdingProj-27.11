// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConcertTransactionEvents.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "OnlineBeaconClient.h"
#include "Diagnostics/ScriptDiagnosticMessage.h"
#include "Online/ContentBeaconUtilsV2.h"
#include "OnlineLinkId.h"
#include "SolarisDebugMessage.h"
#include "VerseGameplayDebugTypes.h"
#include "VkContentServiceTypes.h"
#include "ValkyrieBeaconClient.generated.h"

class UObject;
enum class EContentUpdateState : uint8;
enum class EVerseUploadState : int32;
enum class EVkEditStatus : uint8;

UENUM()
enum class EContentChanges : uint8
{
	None = 0,
	Assets = 1,
	// Asset changes (always need to be pushed to the content service)

	VerseContentService = 2,
	// Verse changes that need to be pushed to the content service

	VerseServer = 4,
	// Verse changes that can be pushed directly to the server (Verse Hot-Reload)

	VerseAssets = 8,
	// Make sure to keep compund flags up to date

	Verse = 14,
	All = 15,
};

UENUM()
enum class EContentUpdateState : uint8
{
	None = 0,
	DistributingToConnectedSession = 1,
	UnloadingOldContent = 2,
	LoadingNewContent = 3,
	NewContentFinishedLoadingServer = 4,
	NewContentFinishedLoadingClients = 5,
	NewContentFinishedLoadingAll = 6,
	ContentError = 7,
};

UENUM()
enum class EVerseUploadState : int32
{
	None = 0,
	InProgress = 1,
	Success = 2,
	FailedValidation = 3,
	NoHost = 4,
	NoEditComponent = 5,
	NoValidPackages = 6,
	ContentFailure = 7,
	RuntimeFailure = 8,
	CompileError = 9,
	ReloadFailed = 10,
	CancelledByUploadRequest = 11,
};

USTRUCT()
struct FValkyrieConcertTransactionFinalizedEvent : public FConcertTransactionFinalizedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TitleString;

	UPROPERTY()
	TArray<FString> PlaceholderAssets;

	UPROPERTY()
	TMap<FString, int32> PlaceholderAssetMappings;

	UPROPERTY()
	TArray<FVkModuleVersion> ReferencedExternalModules;

};

USTRUCT()
struct FValkyriePlayerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	FVector CameraPos;

	UPROPERTY()
	FRotator CameraRot;

};

UCLASS()
class VALKYRIECOMMON_API AValkyrieBeaconClient : public AOnlineBeaconClient
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientDisallowedLiveEditTransactionEncountered(bool bSuppressLiveEdit);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientHandleCookFailure(const FString& CookJobId);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientHandleError(const FText& ErrorMessage);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientHandleTransactionFinalizedEvent(FConcertTransactionFinalizedEvent Event);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientLogSummaryMessage(const FString& LogMessage);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientNotifyOfServerScriptDiagnosticMessage(const FScriptDiagnosticMessage& Message);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientNotifyOfServerShutdown();

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientProcessDebugMessage(const FSolarisDebugMessage& Message);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientVerseUploadComplete(const FString& InSnapshotId, EVerseUploadState Result);

	UFUNCTION(Server, Reliable, WithValidation, meta=(CallInEditor="true"))
	void ServerProcessDebugMessage(const FSolarisDebugMessage& Message);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerRefreshMemoryTracker();

	UFUNCTION(Server, Reliable, WithValidation, meta=(CallInEditor="true"))
	void ServerRespawnAllPlayers();

	UFUNCTION(Server, Reliable, WithValidation, meta=(CallInEditor="true"))
	void ServerSendGameFlowMessage(const FString& Message, const EVkEditStatus VkEditStatus);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerSetPublishingMemoryLimit(int32 PublishingMemoryLimit);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerSetUseLiveEditProxyActors(bool bEnabled);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerStartGame();

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerStartMemorySampling(const FOnlineLinkId& LinkCode);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerStopGame();

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerSubmitConnectedClientLogs(const FGuid& ParentReportId);

	UFUNCTION(Server, Reliable, meta=(CallInEditor="true"))
	void ServerTeleportPlayer(uint32 i, FVector Location, FRotator Rotation);

private:
	UFUNCTION(Server, Reliable)
	void AddPrewarmCompatibilityVersion(const FString& ClientVersion);

	UFUNCTION(Client, Reliable, meta=(CallInEditor="true"))
	void ClientUpdateContentUpdateState(const EContentUpdateState NewContentUpdateState);

	UFUNCTION()
	void HandleVkCheatConsoleCommand(const TArray<FString>& Args);

	UFUNCTION(Server, Reliable, WithValidation, meta=(CallInEditor="true"))
	void ServerContentUpdated(const FString& ProjectId, const FString& Snapshot, const TArray<FVkModuleVersion>& Modules_Legacy);

	UFUNCTION(Server, Reliable)
	void ServerOnContentBeaconHostError(const FContentBeaconError& ContentBeaconError);

	UFUNCTION(Server, Reliable, WithValidation, meta=(CallInEditor="true"))
	void ServerVkCheatMessage(const FVerseGameplayStringDebugMessage& Message);

	UPROPERTY(Transient)
	TArray<UObject*> VerseGeneratedObjectsList;

	UPROPERTY(Config)
	TArray<FString> SupportedTransactionsPrefixList;

	UPROPERTY(Config)
	int32 MaxTransactionQueueBytes;

	UPROPERTY(Transient, Replicated)
	TArray<FValkyriePlayerInfo> PlayerList;

	UPROPERTY(Config)
	bool bAllowVerseHotReload;

};

