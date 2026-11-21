// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelSaveSpawnableInterface.generated.h"

class AActor;

UENUM(BlueprintType)
enum class ELevelSaveCategory : uint8
{
	ActorInstance = 0,
	VolumeInfoActor = 1,
};

UINTERFACE(MinimalAPI, BlueprintType)
class ULevelSaveSpawnable : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool CanBeDeletedFromCreativeVolume() const;

	UFUNCTION(BlueprintNativeEvent)
	bool CanBeSavedToCreativeVolume() const;

	UFUNCTION(BlueprintNativeEvent)
	bool CanBeSavedToPlayset() const;

	UFUNCTION(BlueprintNativeEvent)
	void PostFinishSpawning();

	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	void PostFinishSpawningInEditor();

	UFUNCTION(BlueprintNativeEvent)
	void PostLevelSaveSpawnCleanup();

	UFUNCTION(BlueprintNativeEvent)
	void PreFinishSpawning(AActor* VolumeSpawnedWithin);

	UFUNCTION(BlueprintNativeEvent)
	void PreSaveBaseActorRecord();

	UFUNCTION(BlueprintNativeEvent)
	void PreSaveToQuickbar();

};

