// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelInstance/LevelInstanceLevelStreaming.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "ScalableFloat.h"
#include "WorldConditionQuery.h"
#include "Building/LevelInstance/FortLevelInstancePrefab.h"
#include "FortAthenaLivingWorldEventData.h"
#include "FortAthenaLivingWorldPrefab.generated.h"

class AActor;
class ABuildingActor;
class AFortAthenaLivingWorldPrefab;
class UFortSnapOnSurfaceComponent;
class UObject;

USTRUCT()
struct FFortAthenaLivingWorldPrefabActorSpawnerData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid ActorSpawnerGuid;

	UPROPERTY()
	FFortAthenaLivingWorldActorSpawnDescription ActorDescription;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortAthenaLivingWorldPrefab : public AFortLevelInstancePrefab
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAllActorSpawned, const TArray<AActor*>&, SpawnedActors);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAllActorSpawnedDelegate, const TArray<AActor*>&, SpawnedActors);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnBuildingInLevelBoundsDestroyed);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	LAGERRUNTIME_API void AllowSpawnerToSpawn();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="DelegateToCall"))
	LAGERRUNTIME_API void CallWhenAllActorHaveSpawned(const FOnAllActorSpawnedDelegate& DelegateToCall);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="FinishedDelegate"))
	LAGERRUNTIME_API void DestroyBuildingsInLevelBounds(const FOnBuildingInLevelBoundsDestroyed& FinishedDelegate);

	UFUNCTION(BlueprintPure)
	LAGERRUNTIME_API FBox GetLevelBounds() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(WorldContext="WorldContextObject"))
	static LAGERRUNTIME_API AFortAthenaLivingWorldPrefab* GetOwningLivingWorldPrefab(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	LAGERRUNTIME_API void MakeLevelVisible();

	UFUNCTION(BlueprintCallable)
	LAGERRUNTIME_API void RemoveFoliageInsideLevelBound();

protected:
#if WITH_EDITOR
	UFUNCTION(Category="LivingWorld", meta=(CallInEditor="true"))
	LAGERRUNTIME_API void ApplyTemplateToActorsWithoutComponent();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="LivingWorld", meta=(CallInEditor="true"))
	LAGERRUNTIME_API void ApplyTemplateToAllActors();
#endif

#if WITH_EDITOR
	UFUNCTION()
	LAGERRUNTIME_API void OnActorSpawnedInWorldEditor(AActor* SpawnedActor);
#endif

	UFUNCTION()
	LAGERRUNTIME_API void OnRep_ShouldLevelBeVisible();

	UPROPERTY()
	TArray<FFortAthenaLivingWorldPrefabActorSpawnerData> ActorSpawnerDatas;

	UPROPERTY()
	FBox LocalLevelBounds;

	UPROPERTY()
	FBox LocalGrassRemovalBox;

	UPROPERTY(Transient)
	FOnAllActorSpawned OnAllActorSpawnedDelegate;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<ABuildingActor>> BuildingsToKill;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> SpawnedActors;

	UPROPERTY(Transient)
	FOnBuildingInLevelBoundsDestroyed FinishedDestroyingBuildingCallback;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldPrefab")
	bool bHasFinishedSpawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaLivingWorldPrefab")
	bool bHasRemovedFoliage;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FScalableFloat bIsEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaLivingWorldPrefab")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_ShouldLevelBeVisible, Category="LivingWorld")
	bool bShouldLevelBeVisible;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	bool bShouldSpawnerBeAllowedToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	bool bShouldAlwaysSnapAboveLandscape;

	UPROPERTY(EditDefaultsOnly, Category="LivingWorld")
	FWorldConditionQueryDefinition CanSpawnCondition;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Instanced, Category="LivingWorld")
	TObjectPtr<UFortSnapOnSurfaceComponent> SnapOnSurfaceTemplate;
#endif

};

UCLASS(MinimalAPI)
class UFortAthenaLivingWorldPrefabLevelStreaming : public ULevelStreamingLevelInstance
{
	GENERATED_BODY()

};

