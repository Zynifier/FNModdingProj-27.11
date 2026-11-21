// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaMarkedActorIndicator.h"
#include "Building/BuildingGameplayActorSpawnMachine.h"
#include "AthenaRebootVanIndicator.generated.h"

UCLASS(Abstract)
class UAthenaRebootVanIndicator : public UAthenaMarkedActorIndicator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawnMachineStateChanged();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resurrection")
	int32 SpawnMachineIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resurrection")
	ESpawnMachineState SpawnMachineState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resurrection")
	float SpawnMachineCooldownStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Resurrection")
	float SpawnMachineCooldownEndTime;

};

