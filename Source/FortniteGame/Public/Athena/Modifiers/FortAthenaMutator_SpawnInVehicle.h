// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SpawnInVehicle.generated.h"

class AFortAthenaVehicle;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpawnInVehicle : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawnInVehicle")
	TSubclassOf<AFortAthenaVehicle> VehicleClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawnInVehicle")
	bool bPlacePawnInVehicleOnLoad;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawnInVehicle")
	FScalableFloat bSpawnInTeammateVehicle;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SpawnInVehicle")
	FScalableFloat VehicleSpawnZOffset;

};

