// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "FortPlayspaceComponent_SingleUserMultiplayer.generated.h"

class AActor;
class AController;
class AFortMinigame;
class APawn;
class UFortAthenaAISpawnerData;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPlayspaceComponent_SingleUserMultiplayer : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void ApplyCachedTeamToPlayer(APawn* Pawn);

	UFUNCTION()
	void OnBotControllerDestroyed(AActor* Actor);

	UFUNCTION()
	void OnPlayerBotSpawned(AActor* Actor, const int32 InSpawnRequestID);

	UFUNCTION()
	void OnPlayerRemovedFromMinigame(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

private:
	UPROPERTY(EditAnywhere, Category="FortPlayspaceComponent_SingleUserMultiplayer")
	TSubclassOf<UFortAthenaAISpawnerData> AISpawnerDataClass;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AController>> CurrentControllers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AController>> ControllersBeingDestroyed;

	UPROPERTY(Transient)
	TObjectPtr<AController> CachedModeratorController;

	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> CachedMinigame;

};

