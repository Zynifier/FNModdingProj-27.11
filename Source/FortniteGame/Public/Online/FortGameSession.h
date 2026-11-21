// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/OnlineReplStructs.h"
#include "OnlineBeaconReservation.h"
#include "UObject/SoftObjectPath.h"
#include "FortGameSession.generated.h"

class AContentBeaconHostObjectV2;
class AFortLobbyBeaconHost;
class AFortMeshBeaconClient;
class AFortMeshBeaconHost;
class AFortMeshBeaconHostObject;
class AFortPartyBeaconHost;
class AFortSpectatorBeaconHost;
class AOnlineBeaconHostObject;

UENUM()
enum class EFortServerGameMode : uint8
{
	/** Simply idle waiting for users */
	Idle = 0,
	/** In a lobby waiting on players */
	LobbyPvE = 1,
	/** In a lobby waiting on players */
	LobbyPvP = 2,
	/** In a PvP game */
	ZonePvP = 3,
	/** In a PvE game */
	ZonePvE = 4,
};

UENUM()
enum class EFortServerStatus : uint8
{
	/** Server is starting up and has not reached idle state yet */
	Launching = 0,
	/** Server is at or has returned to the idle/empty state */
	Idle = 1,
	/** Server has called InitGame() but has not HandleStartMatch() */
	StartingMode = 2,
	/** Server has started the match and users are playing */
	Running = 3,
	/** Server is currently traveling */
	ServerTravel = 4,
	/** Server is attempting to shutdown and should RequestExit() soon */
	ShuttingDown = 5,
	/** Server is in the process of returning to the idle state */
	Restarting = 6,
	/** Server is running an update/patch check */
	UpdateCheck = 7,
};

USTRUCT()
struct FFortDisconnectedPlayerReservation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SessionName;

	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

};

USTRUCT()
struct FFortHostSessionParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SessionName;

	UPROPERTY()
	int32 ControllerId;

};

USTRUCT()
struct FMeshGamePluginEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PluginName;

	UPROPERTY()
	FString MapFilter;

};

USTRUCT(BlueprintType)
struct FMeshServiceMetadata
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameSession : public AGameSession
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	virtual void DumpReservations() const;

	UPROPERTY(Config)
	TArray<FMeshGamePluginEntry> MeshNetworkGameFeaturePluginsToLoad;

protected:
	UPROPERTY(Transient)
	FFortHostSessionParams CurrentSessionParams;

	UPROPERTY(Transient)
	TSubclassOf<AOnlineBeaconHostObject> ReservationBeaconHostClass;

	UPROPERTY(Transient)
	TSubclassOf<AOnlineBeaconHostObject> SpectatorBeaconHostClass;

	UPROPERTY(Transient)
	TObjectPtr<AFortPartyBeaconHost> ReservationBeaconHost;

	UPROPERTY(Transient)
	TObjectPtr<AFortLobbyBeaconHost> LobbyBeaconHost;

	UPROPERTY(Transient)
	TObjectPtr<AFortSpectatorBeaconHost> SpectatorBeaconHost;

	UPROPERTY(Transient)
	TArray<FFortDisconnectedPlayerReservation> DisconnectedPlayerReservations;

	UPROPERTY(Config)
	FSoftClassPath ContentBeaconHostV2ClassPath;

	UPROPERTY(Transient)
	TObjectPtr<AContentBeaconHostObjectV2> ContentBeaconHostV2;

	UPROPERTY(Transient)
	TArray<FPlayerReservation> PlayersToRegister;

	UPROPERTY(Config)
	float BulkUnregisterTimerDelay;

	UPROPERTY(Config)
	int32 MaxBroadcasters;

private:
	UPROPERTY(Config)
	float DisconnectedReservationTimeout;

	UPROPERTY(Config)
	bool bEnableMeshNetwork;

	UPROPERTY(Config)
	TArray<FString> DisabledMeshNodeTypes;

	UPROPERTY(Config)
	TArray<FString> DisabledMeshRegions;

	UPROPERTY(Transient)
	TObjectPtr<AFortMeshBeaconHost> MeshBeaconHost;

	UPROPERTY(Transient)
	TObjectPtr<AFortMeshBeaconHostObject> MeshBeaconHostObject;

	UPROPERTY(Transient)
	TObjectPtr<AFortMeshBeaconClient> MeshBeaconClient;

	UPROPERTY(Config)
	float RetryMeshConnectDelay;

	UPROPERTY(Config)
	float MaxMeshConnectDelay;

	UPROPERTY(Config)
	float MeshNetworkServerStatusEventRate;

};

