// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AISubsystem.h"
#include "Math/MathFwd.h"
#include "AthenaAISpawner.generated.h"

class AActor;
class APawn;
class UFortAthenaAISpawnerDataComponentList;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnPreFinishSpawningDynamicEvent, APawn*, Pawn, const int32, RequestID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnSpawnedDynamicEvent, APawn*, Pawn, const int32, RequestID);

UCLASS(BlueprintType)
class UAthenaAISpawner : public UAISubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool CancelRequest(const int32 RequestID);

	UFUNCTION(BlueprintCallable)
	void QueueForDespawn(AActor* ActorToDespawn);

	UFUNCTION(BlueprintCallable)
	int32 RequestSpawn(UFortAthenaAISpawnerDataComponentList* AISpawnerComponentList, const FTransform& SpawnTransform, const bool bUrgentRequest = false);

protected:
	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Pawn Pre Finish Spawning"))
	FOnPawnPreFinishSpawningDynamicEvent OnPawnPreFinishSpawningEvent;

	UPROPERTY(BlueprintAssignable, meta=(DisplayName="On Pawn Spawned"))
	FOnPawnSpawnedDynamicEvent OnPawnSpawnedEvent;

};

