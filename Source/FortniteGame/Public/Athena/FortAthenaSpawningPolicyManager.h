// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Modifiers/GameplayMutatorRegistryInterface.h"
#include "FortAthenaSpawningPolicyManager.generated.h"

class AFortAthenaMutator_SpawningPolicyBase;
class AFortGameModeAthena;
class AFortGameStateAthena;

UCLASS()
class AFortAthenaSpawningPolicyManager : public AActor, public IGameplayMutatorObserverInterface
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<AFortAthenaMutator_SpawningPolicyBase>> SpawningPolicyMutatorList;

	UPROPERTY()
	TObjectPtr<AFortGameModeAthena> GameModeAthena;

	UPROPERTY()
	TObjectPtr<AFortGameStateAthena> GameStateAthena;

};

