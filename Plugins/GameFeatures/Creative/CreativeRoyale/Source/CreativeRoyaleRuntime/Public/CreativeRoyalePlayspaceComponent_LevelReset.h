// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "PlayspaceComponent.h"
#include "CreativeRoyalePlayspaceComponent_LevelReset.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortMinigame;
class UFortPoiSwapManager;
class ULevel;
class ULevelSaveRecord;
class UObject;
class UPrimitiveComponent;
enum class EFortMinigameState : uint8;

USTRUCT()
struct FAttachedBuildingActorGuids
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FGuid> AttachedBuildingActorGuids;

};

USTRUCT()
struct FSpawnBuildingActorParameters
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UClass* SpawnClass;

	UPROPERTY()
	TWeakObjectPtr<ULevel> SpawnLevel;

	UPROPERTY()
	FTransform SpawnTransform;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class CREATIVEROYALERUNTIME_API UCreativeRoyalePlayspaceComponent_LevelReset : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddActorToTrack(AActor* ActorToTrack);

protected:
	UFUNCTION()
	void CachePoiSwapManager();

	UFUNCTION()
	UFortPoiSwapManager* GetPoiSwapManager();

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortPoiSwapManager> CachedPoiSwapManager;

private:
	UFUNCTION()
	void BindActorToCallbacks(AActor* Actor);

	UFUNCTION()
	void ClearFoundActors();

	UFUNCTION()
	void DestroyDamagedActors();

	UFUNCTION()
	ULevelSaveRecord* GetLevelSaveRecord();

	UFUNCTION()
	void HandleBuildingDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleBuildingDestroyed(const TWeakObjectPtr<ABuildingActor> DestroyedBuilding);

	UFUNCTION()
	void HandleBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION()
	void OnPlotLoadComplete();

	UFUNCTION()
	void OnSpawningFromSaveFinish();

	UFUNCTION()
	void RespawnDeadActors();

	UFUNCTION()
	void RestoreAttachedBuildingActors(FGuid SpawnableActorGuid, AActor* Actor);

	UFUNCTION()
	void SaveActorToBeRespawned(AActor* ActorToBeRespawned, const bool bRemoveDamagedActor);

	UFUNCTION()
	void SaveDamagedActor(AActor* DamagedActor);

	UFUNCTION()
	void SaveParentToAttachToInformation(FGuid ActorToAttachGuid, AActor* ActorToAttach);

	UPROPERTY(Transient)
	TWeakObjectPtr<ULevelSaveRecord> CachedLevelSaveRecord;

	UPROPERTY(Transient)
	bool bSpawnFromGameplay;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> SavedFoundActors;

	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AActor>, FSpawnBuildingActorParameters> SavedDeadActors;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> SavedDamagedActors;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> FoundActorsDied;

	UPROPERTY(Transient)
	TArray<FGuid> FoundActorsDiedGuid;

	UPROPERTY(Transient)
	TMap<FGuid, FAttachedBuildingActorGuids> SavedParentWithAttachedBuildings;

	UPROPERTY(Transient)
	TMap<FGuid, TWeakObjectPtr<AActor>> CurrentActorForBuildingGuid;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> FoundActorsDamaged;

	UPROPERTY(Transient)
	TArray<FGuid> FoundActorsDamagedGuid;

};

