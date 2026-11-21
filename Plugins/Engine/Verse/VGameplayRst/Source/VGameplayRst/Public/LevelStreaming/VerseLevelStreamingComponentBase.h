// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/SoftObjectPath.h"
#include "EntityActorComponent.h"
#include "VerseLevelStreamingComponentBase.generated.h"

class ULevelStreamingDynamic;
class UVerseAssetPtr;
class UVerseLevelStreamingComponentBase;

// A struct to ensure atomic synchronization of both the level to load and its unique instance ID

USTRUCT()
struct FVerseLevelStreamingLevelIdentifier
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FSoftObjectPath LevelPath;

	UPROPERTY()
	FString LevelNameOverride;

};

USTRUCT()
struct FVerseLevelStreamingLevelStatus
{
	GENERATED_BODY()

public:
	// NOTE: This is the only property on this struct which exists on the client

	UPROPERTY()
	TObjectPtr<ULevelStreamingDynamic> Streamer;

	UPROPERTY()
	TObjectPtr<UVerseAssetPtr> LevelAsset;

};

UCLASS(Abstract)
class UVerseLevelStreamingComponentBase : public UEntityActorComponent
{
	GENERATED_BODY()

public:
	// Client-side callback from the world for level loading completion

	UFUNCTION()
	void OnLevelShown_Client();

	// Called on the server when level streaming completes (from the World's point of view)
// notifies clients of the level to load

	UFUNCTION()
	void OnLevelShown_Server();

	// Client-side callback from the world for level unloading completion

	UFUNCTION()
	void OnLevelUnloaded_Client();

	// Called on the server when level unloading completes (from the World's point of view)
// notifies clients of the level to unload 

	UFUNCTION()
	void OnLevelUnloaded_Server();

	// Handles new level load/unload requests on the client

	UFUNCTION()
	void OnRep_NewLevel();

	UPROPERTY(ReplicatedUsing=OnRep_NewLevel)
	FVerseLevelStreamingLevelIdentifier NewLevel;

private:
	// Tracking data for in-progress requests

	UPROPERTY()
	FVerseLevelStreamingLevelStatus LevelStatus;

};

// Helper class added to the player controller to enable client->server RPC

UCLASS()
class UVerseLevelStreamingPlayerControllerRpcComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void TellServer_ClientLevelLoaded(UVerseLevelStreamingComponentBase* LevelStreamingComponent);

	UFUNCTION(Server, Reliable)
	void TellServer_ClientLevelUnloaded(UVerseLevelStreamingComponentBase* LevelStreamingComponent);

};

