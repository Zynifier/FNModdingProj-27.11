// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_ActorMemoryTracker.generated.h"

class AActor;

UCLASS(Config=ActorMemoryTracking, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlayspaceComponent_ActorMemoryTracker : public UPlayspaceComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_MemoryThreshold();

	UPROPERTY(Config)
	TArray<TSubclassOf<AActor>> TrackedActorClasses;

	UPROPERTY(Config)
	TArray<TSubclassOf<AActor>> ExcludedActorClasses;

	UPROPERTY(Config, ReplicatedUsing=OnRep_MemoryThreshold)
	int32 MemoryThreshold;

	UPROPERTY(Config)
	int32 ScaledMemoryRange;

};

