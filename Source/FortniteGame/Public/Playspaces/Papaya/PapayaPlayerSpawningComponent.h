// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayspaceComponent_PlayerSpawning.h"
#include "PapayaPlayerSpawningComponent.generated.h"

class AFortPlayerStartWarmup;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UPapayaPlayerSpawningComponent : public UPlayspaceComponent_PlayerSpawning
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStartWarmup>> BestSpawnPoints;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerStartWarmup>> HighPrioritySpawnPoints;

};

