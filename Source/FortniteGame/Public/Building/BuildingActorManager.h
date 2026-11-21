// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "BuildingActorManager.generated.h"

class ABuildingActor;

UCLASS()
class UBuildingActorManager : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> BuildingsToTick;

	UPROPERTY(Transient)
	int32 LastBuildingTickIndex;

	UPROPERTY(Transient)
	int32 BuildingTickIndex;

	UPROPERTY(Transient)
	int32 MaxBuildingTickIndex;

};

