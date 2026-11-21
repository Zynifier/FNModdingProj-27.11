// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PegasusGameEventCollector.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortPlayerStateAthena;

UCLASS(Config=Game)
class UPegasusGameEventCollector : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleOwnerAthenaPlaceChanged(AFortPlayerStateAthena* Sender, int32 NewPlace);

	UFUNCTION()
	void HandleOwnerBeginSkyDiving();

	UFUNCTION()
	void HandleOwnerEndSkyDiving();

	UFUNCTION()
	void HandleOwnerVehicleStateChange(AFortPlayerPawn* Sender, AActor* NewVehicle, AActor* OldVehicle);

	UPROPERTY(Config)
	float InventoryChangesTimeSpan;

	UPROPERTY(Config)
	float EndSkydivePlayerCheckRadius;

	UPROPERTY(Config)
	float WeaponExecutedTimeSpan;

	UPROPERTY(Config)
	float BuildingBeginPlayTimeSpan;

	UPROPERTY(Config)
	float ExpensiveTestInterval;

	UPROPERTY(Config)
	float SquadCohesionTestRadius;

	UPROPERTY(Config)
	float PlayerResourceEventsTimeSpan;

	UPROPERTY(Config)
	float EliminationEventsTimeSpan;

};

