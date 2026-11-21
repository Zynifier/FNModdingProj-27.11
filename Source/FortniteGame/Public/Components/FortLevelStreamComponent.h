// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFeatureStateChangeObserver.h"
#include "FortLevelStreamComponent.generated.h"

class AFortPlayerState;
class ULevelStreaming;
class ULevelStreamingDynamic;
class UWorld;
class UWorldPartitionLevelStreamingDynamic;

UENUM(BlueprintType)
enum class EUnableToLoadReason : uint8
{
	None = 0,
	PackageDoesNotExist = 1,
	EndPlay = 2,
	// Levels will be unloaded when this component cleans up

	UnableToUnload = 3,
};

UENUM(BlueprintType)
enum class EUnableToUnloadReason : uint8
{
	None = 0,
	EndPlay = 1,
};

USTRUCT()
struct FFortLevelStreamingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PackageName;

	UPROPERTY()
	FName UniquePackageName;

	UPROPERTY()
	bool bShownOnServerHasBeenCalled;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortLevelStreamComponent : public UActorComponent, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ClientHasFinishedLevelStreaming(AFortPlayerState* StreamedInPlayer);

	UFUNCTION(BlueprintPure, Category="Level Stream")
	bool IsLoaded() const;

	UFUNCTION(BlueprintPure, Category="Level Stream")
	bool IsLoading() const;

	UFUNCTION(BlueprintPure, Category="Level Stream")
	bool IsUnloaded() const;

	UPROPERTY(EditAnywhere, Category="Level Stream")
	uint8 bAutoLoadLevel : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Stream")
	uint8 bAllowUnload : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortLevelStreamComponent")
	bool bWaitForClientsInSessionBeforeConsideringComplete;

	UPROPERTY(EditDefaultsOnly, Category="FortLevelStreamComponent")
	bool bGarbageCollectionClusteringEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FortLevelStreamComponent")
	bool bEnableSynchronousLoading;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Playset")
	uint8 bPreviewLevelInEditor : 1;
#endif

private:
	UFUNCTION()
	void OnLevelLoaded();

	UFUNCTION()
	void OnLevelShown();

	UFUNCTION()
	void OnRep_LevelStreamingData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Level Stream", meta=(AllowPrivateAccess="TRUE"))
	TArray<TSoftObjectPtr<UWorld>> LevelsToLoad;

	UPROPERTY(Transient)
	TMap<ULevelStreamingDynamic*, FFortLevelStreamingData> StreamedLevels;

	UPROPERTY(Transient)
	TSet<UWorldPartitionLevelStreamingDynamic*> WorldPartitionLevelsStreamingOut;

	UPROPERTY(ReplicatedUsing=OnRep_LevelStreamingData)
	TArray<FFortLevelStreamingData> LevelStreamingData;

	UPROPERTY(Transient)
	TArray<AFortPlayerState*> ReceivedLoadedPlayerStates;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<ULevelStreaming*> PreviewLevelStreams;
#endif

};

