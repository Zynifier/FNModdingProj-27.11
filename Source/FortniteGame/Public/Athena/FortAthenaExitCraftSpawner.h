// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAthenaExitCraftSpawner.generated.h"

class ABuildingSMActor;
class UCapsuleComponent;
class UFortAthenaExitCraftInfo;

UCLASS()
class AFortAthenaExitCraftSpawner : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void DestroyBlockingActors();

	UFUNCTION(BlueprintCallable)
	void StartExitCraftSpawnTimer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Vehicle", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> DestructionOverlapCapsule;

	UPROPERTY()
	TObjectPtr<UFortAthenaExitCraftInfo> ExitCraftInfo;

	UPROPERTY()
	TArray<TObjectPtr<ABuildingSMActor>> BuildingActorsToDestroy;

	UPROPERTY(Transient)
	FName SpawnerSpecialActorID;

};

