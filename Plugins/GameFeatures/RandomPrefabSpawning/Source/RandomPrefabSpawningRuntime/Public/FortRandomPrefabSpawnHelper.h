// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkInitStateInterface.h"
#include "Components/GameStateComponent.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortRandomPrefabSpawnHelper.generated.h"

class AFortLevelInstancePrefab;

USTRUCT()
struct FFortRandomPrefabData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortRandomPrefabData")
	TSubclassOf<AFortLevelInstancePrefab> Prefab;

	UPROPERTY(EditDefaultsOnly, Category="FortRandomPrefabData")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="FortRandomPrefabData")
	FScalableFloat bEnabled;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortRandomPrefabSpawnHelper : public UGameStateComponent, public IGameFrameworkInitStateInterface
{
	GENERATED_BODY()

public:
	UFortRandomPrefabSpawnHelper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	TArray<FFortRandomPrefabData> AllPrefabs;

	UPROPERTY(Transient)
	TArray<FFortRandomPrefabData> PrefabPool;

	UPROPERTY(EditDefaultsOnly, Category="Spawning")
	FScalableFloat bAcceptDuplicatesWhenOutOfUniquePrefabs;

};

