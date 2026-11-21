// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Online/FortGameSessionDedicated.h"
#include "FortGameSessionDedicatedAthena.generated.h"

class AFortGameModeAthena;

UENUM()
enum class EActionOnSaveDataFailed : uint8
{
	// No action upon save data failure

	Skip = 0,
	// Players are kicked when failing to save data

	KickPlayer = 1,
	// Players are kicked when failing to save data
// Session is terminated

	TerminateSession = 2,
	MAX = 3 UMETA(Hidden),
};

USTRUCT()
struct FFortSaveFrameworkConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bRegisterSaveDataCallback;

	UPROPERTY()
	EActionOnSaveDataFailed ActionOnSaveDataFailed;

	UPROPERTY()
	uint8 MaxConsecutiveErrors;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameSessionDedicatedAthena : public AFortGameSessionDedicated
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleExitingSpawningStartup();

protected:
	UFUNCTION()
	void HandleAllPlaylistLevelsVisible();

	UFUNCTION()
	void HandlePlaylistInitialized(AFortGameModeAthena* GMA);

	UFUNCTION()
	void HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

private:
	UPROPERTY(Config)
	bool bDownloadEventsAfterHotfixCheck;

	UPROPERTY(Config)
	float ReconnectToMMSDelay;

	UPROPERTY(Config)
	float MaxReconnectToMMSDelay;

	UPROPERTY(Config)
	FString MMSVersionCompatability;

	UPROPERTY(Config)
	FString MMSTicketURLServer;

	UPROPERTY(Config)
	float MMSPingInterval;

	UPROPERTY(Config)
	int32 QueryUserMode;

	UPROPERTY(Config)
	bool bAutoConnectToMMS;

	UPROPERTY(Config)
	bool bUseSessionTokens;

	UPROPERTY(Config)
	bool bEnableMMSBackfill;

	UPROPERTY(Config)
	bool bDisableBackfillDuringGracefulShutdown;

	UPROPERTY(Config)
	TArray<FName> DisabledPlaylistsDuringGracefulShutdown;

	UPROPERTY(Config)
	float PostBackfillAssignmentUpdateDelay;

	UPROPERTY(Config)
	bool bEnableFlushInventoriesOnShutdown;

	UPROPERTY(Config)
	float FullMeshRetryDelay;

	UPROPERTY(Config)
	float MeshNetworkGCTimerRate;

	UPROPERTY(Config)
	float MeshNetworkServerPerfTimerRate;

	UPROPERTY(Config)
	FFortSaveFrameworkConfig SaveFrameworkConfig;

};

