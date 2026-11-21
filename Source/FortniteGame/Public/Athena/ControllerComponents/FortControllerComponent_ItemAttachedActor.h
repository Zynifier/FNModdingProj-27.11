// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_ItemAttachedActor.generated.h"

class AFortPickup;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class APawn;
class UFortItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ItemAttachedActor : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromPickupSpawnsQueuedMap(UFortItemDefinition* ItemDefinition);

private:
	UFUNCTION()
	void OnPlayerCreatedPickup(const AFortPlayerController* PlayerController, AFortPickup* Pickup);

	UFUNCTION()
	void OnPlayerCreatedPickupProjectile(const AFortPlayerControllerAthena* PlayerController, const UFortItemDefinition* ItemDefinition);

	UFUNCTION()
	void OnPlayerPossessedPawn(APawn* PossessedPawn);

};

