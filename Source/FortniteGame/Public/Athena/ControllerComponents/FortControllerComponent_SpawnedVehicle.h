// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_SpawnedVehicle.generated.h"

class AActor;
class AFortAthenaVehicle;
class AFortPlayerPawn;
class AFortPlayerStateAthena;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SpawnedVehicle : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleDeferredExitSpawnVehicle();

	UFUNCTION()
	void HandlePlayerDisconnectedChanged(AFortPlayerStateAthena* DisconnectingPlayerState, bool bIsDisconnected);

	UFUNCTION()
	void HandleTestStillAttached();

	UFUNCTION()
	void HandleVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION()
	void OnRep_SpawnedVehicle();

	UPROPERTY(ReplicatedUsing=OnRep_SpawnedVehicle)
	TObjectPtr<AFortAthenaVehicle> SpawnedVehicle;

};

