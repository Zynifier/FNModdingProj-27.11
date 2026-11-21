// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/TimerHandle.h"
#include "Quests/Processors/EventObjectiveTypes.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "FortControllerComponent_QuestDistanceTraveledUpdater.generated.h"

class ACharacter;
class APawn;
class UFortObjectiveProcessor_DistanceTraveled;

USTRUCT()
struct FObjectiveArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FEventCacheID> Objectives;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuestDistanceTraveledUpdater : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerComponent_QuestDistanceTraveledUpdater(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void HandlePawnPossessed(APawn* Pawn);

private:
	UFUNCTION()
	void HandleMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void HandlePawnTeleported(APawn* TeleportedPawn);

	UPROPERTY()
	TMap<EDistanceTravelMode, FObjectiveArray> ObjectivesByMode;

	UPROPERTY()
	TWeakObjectPtr<UFortObjectiveProcessor_DistanceTraveled> DistanceTravelledObjectiveProcessor;

	UPROPERTY()
	FTimerHandle MovementTimerHandle;

	UPROPERTY(Config)
	float ProcessingTimer;

};

