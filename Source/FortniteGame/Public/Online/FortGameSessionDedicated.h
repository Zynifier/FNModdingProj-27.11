// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Online/FortGameSession.h"
#include "FortGameSessionDedicated.generated.h"

UENUM()
enum class EFortBanHammerNotificationAction : uint8
{
	/** Kick + ban */
	BanAndKick = 0,
	/** Just kick the player from the server */
	Kick = 1,
};

UENUM()
enum class EFortServerContentRestartReason : uint8
{
	None = 0,
	/** default */
	CreativeCuratedHubChanged = 1,
	/** (Creative) curated hub changed via hotfix or calendar event */
	CreativeFeaturedIslandsChanged = 2,
	/** (Creative) featured island list changed via hotfix or calendar event */
	CreativePreloadRevisionChanged = 4,
	/** (Creative) preload revision number changed via hotfix */
	CreativePlaylistConditionalFlagsChanged = 8,
	/** (Creative) PlaylistConditionalFlags changed via hotfix */
	GameFeaturePluginDisabled = 16,
	/** a game feature plugin was disabled that wasn't disabled before the fork point */
	ForceRestartEventFlagsChanged = 32,
	/** an event flag was added or removed from the list of flags that force a parent restart */
	ForceRestartFlagActiveStateChanged = 64,
};

UENUM()
enum class EServerRestartReason : uint8
{
	/** the hotfix manager has changed config/assets and needs to restart */
	HotfixApplied = 0,
	/** the server wants to gracefully shut down */
	GracefulShutdown = 1,
	/** a client has joined a beacon while we are trying to die */
	BeaconJoinDelayRestart = 2,
	/** something else */
	Other = 3,
};

USTRUCT()
struct FClientIdRestrictions
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ClientId;

	UPROPERTY()
	TArray<FString> RestrictedPlatforms;

};

USTRUCT()
struct FFortBanHammerStrike
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl AccountId;

	UPROPERTY()
	FString Reason;

	UPROPERTY()
	EFortBanHammerNotificationAction Action;

	UPROPERTY()
	FString Source;

	UPROPERTY()
	FString Offense;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameSessionDedicated : public AFortGameSession
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	bool bEnforceCrossplayRestrictions;

	UPROPERTY(Config)
	float HotfixCheckTimer;

	UPROPERTY(Config)
	float HotfixCheckVariance;

	UPROPERTY(Config)
	float DataAssetDirectoryUpdateCheckTimer;

	UPROPERTY(Config)
	float DataAssetDirectoryUpdateCheckVariance;

	UPROPERTY(Config)
	float ReservationAbandonmentTime;

	UPROPERTY(Config)
	float IdleResetShortTimer;

	UPROPERTY(Config)
	TArray<FString> CalendarEventsRequiringNewForkedMasterProcess;

	UPROPERTY(Config)
	bool bEnableWaitingForMatchAssignmentTimeout;

	UPROPERTY(Config)
	float WaitingForMatchAssignmentRestartDelay;

private:
	UPROPERTY(Config)
	bool bRequestEOSClientAuthToken;

	UPROPERTY(Config)
	int32 WaitForEOSClientAuthTokenRetries;

	UPROPERTY(Config)
	float WaitForEOSClientAuthTokenInterval;

	UPROPERTY(Config)
	float ConsoleSessionRetryWaitSeconds;

	UPROPERTY(Config)
	FString ServerManifestDestination;

	UPROPERTY(Config)
	FString HostAPIBaseUrl;

	UPROPERTY(Config)
	TArray<FClientIdRestrictions> ClientIdRestrictions;

};

