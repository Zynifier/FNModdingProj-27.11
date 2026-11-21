// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AsyncTaskQueue.h"
#include "LevelSaveComponent.generated.h"

class AActor;
class ULevelSaveRecord;

UENUM()
enum class ELevelSaveRollback : uint8
{
	// Cleanup any actors/resources that might leak into a new level but do not reload the existing level.
// This is expected to be complete by the time the function returns.

	Cleanup = 0,
	// Cleanup any actors/resources that might leak into a new level and then reload the level.
// This may take multiple frames to execute.

	Reload = 1,
};

UCLASS(MinimalAPI)
class ULevelSaveBaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void LoadLevelRecord();

	UFUNCTION()
	virtual void RegisterCreationToRollback(AActor* Actor);

	UFUNCTION()
	virtual bool RegisterDeletedActor(AActor* Actor);

	UFUNCTION()
	virtual void RegisterDeletionToRollback(AActor* Actor);

	UFUNCTION()
	virtual void RegisterModificationToRollback(AActor* Actor);

	UFUNCTION()
	virtual bool RegisterNewActor(AActor* Actor);

	UFUNCTION()
	virtual bool ResaveActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	virtual void SaveOutLevelRecord();

	UFUNCTION()
	void StartPeriodicSaveTimer();

	UFUNCTION()
	void StopPeriodicSaveTimer();

protected:
	UPROPERTY(EditAnywhere, Category="Level Save")
	FString ExplicitSaveFile;

	UPROPERTY(EditAnywhere, Category="Level Save")
	float TimeBetweenSaves;

	UPROPERTY(EditAnywhere, Category="Level Save")
	uint8 bAutoLoadRecord : 1;

	UPROPERTY(EditDefaultsOnly, Category="Level Save")
	uint8 bApplySaveToRootSpatialOwner : 1;

	UPROPERTY(Transient)
	TObjectPtr<ULevelSaveRecord> LevelRecord;

private:
	UFUNCTION()
	void ConstructNewLevelRecord(AActor* Owner);

	UFUNCTION()
	void OnFinishedRecordWrite(const FAsyncTaskResult& Result);

	UFUNCTION()
	void OnFinishSpawning(const FAsyncTaskResult& Result);

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> ActorToAddAfterWrite;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class ULevelSaveComponent : public ULevelSaveBaseComponent
{
	GENERATED_BODY()

};

