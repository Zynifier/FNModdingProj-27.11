// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_PlayerSpawning.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class PLAYSPACESYSTEM_API UPlayspaceComponent_PlayerSpawning : public UPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Spawn Logic | Data")
	bool bQueueUserForSpawnWhenAdded;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Logic | Data")
	float SpawnDelayMin;

	UPROPERTY(EditDefaultsOnly, Category="Spawn Logic | Data")
	float SpawnDelayMax;

};

