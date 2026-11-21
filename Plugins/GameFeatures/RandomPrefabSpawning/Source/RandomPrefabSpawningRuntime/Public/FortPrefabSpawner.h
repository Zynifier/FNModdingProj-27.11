// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortInitializationInterface.h"
#include "FortPrefabSpawner.generated.h"

class AFortLevelInstancePrefab;
class UFortRandomPrefabSpawnHelper;

UCLASS(BlueprintType, Blueprintable)
class AFortPrefabSpawner : public AActor, public IFortInitializationInterface
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(Category="Debug", meta=(CallInEditor="true"))
	void PreviewCompatiblePrefabs();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Debug", meta=(CallInEditor="true"))
	void PreviewNextPrefab();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Debug", meta=(CallInEditor="true"))
	void PreviewPreviousPrefab();
#endif

#if WITH_EDITOR
	UFUNCTION(Category="Debug", meta=(CallInEditor="true"))
	void StopPreviewingCompatiblePrefabs();
#endif

private:
#if WITH_EDITOR
	UFUNCTION()
	void UpdateShownPrefab();
#endif

	UPROPERTY(EditAnywhere, Category="Spawning")
	FGameplayTagContainer RequiredProperties;

	UPROPERTY(Transient)
	bool bWorldReadyCalled;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleInstanceOnly, Category="Debug")
	TObjectPtr<AFortLevelInstancePrefab> CurrentPreviewerActor;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleInstanceOnly, Category="Debug")
	TArray<TSubclassOf<AFortLevelInstancePrefab>> CompatiblePrefabs;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Debug")
	TSubclassOf<UFortRandomPrefabSpawnHelper> PrefabListSourceClass;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Category="Debug")
	int32 PreviewIndex;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	int32 LastShownPreviewIndex;
#endif

};

