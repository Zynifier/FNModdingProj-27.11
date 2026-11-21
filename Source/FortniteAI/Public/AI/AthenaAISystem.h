// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAISystem.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "AthenaAISystem.generated.h"

class AActor;
class AAthenaAIController;
class AController;
class AFortPawn;
class AFortPlayerPawn;
class UAthenaAIDropper;
class UAthenaAIPerceptionManager;
class UAthenaAIPopulationTracker;
class UAthenaAIVehicleAvoidanceManager;
class UAthenaPathFollowingComponent;

UCLASS(MinimalAPI)
class UAthenaAISystem : public UFortAISystem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AIProfiling_OnGamePhaseChanged(const FFortGamePhaseUpdatedEvent& Event);

	UFUNCTION()
	void AIProfiling_OnSafeZoneUpdated(const FFortSafeZonePhaseUpdatedEvent& Event);

protected:
	UFUNCTION()
	void HandlePlayerExitAircraft(AController* ExitingController);

	UFUNCTION()
	void OnAIPawnDestroyed(AFortPawn* DestroyedPawn);

	UFUNCTION()
	void OnAIPawnDied(AController* KilledController, bool bIsABot, AFortPawn* KilledAIPawn, AFortPlayerPawn* KilledPlayerPawn, AController* KillerController);

	UFUNCTION()
	void OnAIPawnSpawned(AController* SpawnedController, bool bIsABot, AFortPawn* FortAIPawn, AFortPlayerPawn* PlayerPawn);

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIPerceptionManager> PerceptionManager;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIDropper> AIDropper;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIPopulationTracker> AIPopulationTracker;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaAIVehicleAvoidanceManager> AIVehicleAvoidanceManager;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AAthenaAIController>> AIControllers;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaPathFollowingComponent>> PathFollowingComponents;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> RegisteredAISpawners;

	UPROPERTY(Transient)
	uint8 bUnlimitedAIHealth : 1;

	UPROPERTY(Transient)
	uint8 bNavigationReady : 1;

};

