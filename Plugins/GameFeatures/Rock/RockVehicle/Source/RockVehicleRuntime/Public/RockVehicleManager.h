// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Subsystems/WorldSubsystem.h"
#include "RockVehicleManager.generated.h"

class ARockVehicle;
class ARockVehicleManager;

UCLASS()
class ROCKVEHICLERUNTIME_API ARockVehicleManager : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<ARockVehicle*> RockVehicles;

};

UCLASS()
class URockVehicleWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<ARockVehicleManager> VehicleManager;

};

