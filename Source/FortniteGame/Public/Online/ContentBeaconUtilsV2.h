// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/Guid.h"
#include "ContentBeaconUtilsV2.generated.h"

UENUM()
enum class EClientModuleType : uint8
{
	Local = 0,
	Remote = 1,
};

UENUM()
enum class EContentBeaconErrorCode : uint8
{
	Success = 0,
	FailedToConnect = 1,
	FailedToGenerateContentPackage = 2,
	FailedToCreateContentPackageResolver = 3,
	RequestInvalid = 4,
	ContentPackageResolverBecameInvalid = 5,
	PackageResolveFlowCancelled = 6,
	FailedToBuildManifestServer = 7,
	FailedToBuildManifestClient = 8,
	FailedToInstallModule = 9,
	InvalidStateRequested = 10,
	DuplicateClientConnected = 11,
	// timeout errors

	TimeoutUnspecifiedClientTransition = 12,
	TimeoutUnspecifiedRequestTransition = 13,
	TimeoutRequestTransitionHostActive = 14,
	// timed out while trying to set the host as active

	TimeoutRequestTransitionClientsActive = 15,
	// timed out while trying to set the clients to active

	TimeoutRequestTransitionClientsUninstalled = 16,
	// timed out while trying to uninstall on clients

	TimeoutClientTransitionAllLoaded = 17,
	TimeoutClientTransitionUninstalled = 18,
	ClientCancelledDownload = 19,
	UnauthorizedClient = 20,
	FailedToSetProjectId = 21,
	Unknown = 22,
};

UENUM()
enum class EContentBeaconErrorResponse : uint8
{
	None = 0,
	DisconnectClient = 1,
	CancelRequest = 2,
	Shutdown = 3,
};

UENUM()
enum class EContentBeaconErrorSource : uint8
{
	Unknown = 0,
	Host = 1,
	Client = 2,
};

UENUM()
enum class EContentRequestInstallState : uint8
{
	None = 0,
	// client has no state, requests are not in this state this is uninitialized, NOTREQUESTABLE STATE

	Initialized = 1,
	//BuildingManifests, // in the process of building manifests, NOTREQUESTABLE STATE

	ManifestsBuilt = 2,
	// manifests are built but no modules have been created, REQUESTABLE STATE
//ModulesCreated, // modules are created for all the client requests

	Installed = 3,
	// these are only valid for requests, (not client requests), they indicate the clients are in a different state then the server

	HostLoadedClientsInstalled = 4,
	HostActiveClientsInstalled = 5,
	// completely loaded states

	Loaded = 6,
	// installed and loaded in the game feature subsystem (REQUESTABLE STATE)

	Active = 7,
	// active and usable, REQUESTABLE STATE

	ClientsUninstalled = 8,
	// clients are uninstalled host could be loaded or active

	Uninstalled = 9,
	// registered and has manifests but is not installed, REQUESTABLE STATE

	COMPLETELYLOADED = 7,
};

UENUM()
enum class EInnerErrorType : uint8
{
	None = 0,
	ContentServiceError = 1,
	ContentSentryUnknownError = 2,
	ProjectDuplicationError = 3,
	CookFailure = 4,
	CookFailureOutOfMemory = 5,
	CookUnknownError = 6,
	CookBadInput = 7,
	StagingFailure = 8,
	Unknown = 9,
};

USTRUCT()
struct FClientModuleId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl ClientName;

	UPROPERTY()
	FString ModuleId;

};

USTRUCT()
struct FContentBeaconErrorParam
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Key;

	UPROPERTY()
	FString Value;

};

USTRUCT()
struct FContentRequestId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid Guid;

};

USTRUCT()
struct FContentBeaconError
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EContentBeaconErrorCode ErrorCode;

	UPROPERTY()
	FString InnerErrorCode;

	UPROPERTY()
	EContentBeaconErrorSource ErrorSource;

	UPROPERTY()
	FString DebugString;

	UPROPERTY()
	FText InnerErrorMessage;

	UPROPERTY()
	TArray<FContentBeaconErrorParam> AdditionalErrorParams;

	UPROPERTY()
	FContentRequestId RequestId;

	UPROPERTY()
	FUniqueNetIdRepl ClientId;

	UPROPERTY()
	FClientModuleId ModuleId;

	UPROPERTY()
	FString ModuleURL;

	UPROPERTY()
	FString VkProjectId;

	UPROPERTY()
	FString VkModuleId;

	UPROPERTY()
	bool IsLocalError;

private:
	UPROPERTY()
	EInnerErrorType CachedInnerErrorType;

};

