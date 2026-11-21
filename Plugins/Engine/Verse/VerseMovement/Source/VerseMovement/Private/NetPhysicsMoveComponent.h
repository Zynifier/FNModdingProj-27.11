// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NetPhysicsMoveSimulation.h"
#include "NetPhysicsMoveComponent.generated.h"

class APlayerController;
class UNetPhysicsMoveConfig;

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UNetPhysicsMoveComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UNetPhysicsMoveConfig> MoveConfig;

	// Automatically marshalled complete copy of the latest object state

	UPROPERTY()
	FNetPhysicsMoveObject SimOutput;

	//UPROPERTY(Replicated)
//FNetworkPredictionAsyncProxy ReplicatedObject;

	UPROPERTY(Transient)
	TObjectPtr<APlayerController> CachedPC;

};

