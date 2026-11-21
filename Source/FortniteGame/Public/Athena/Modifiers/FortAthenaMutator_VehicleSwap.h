// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_VehicleSwap.generated.h"

class AFortAthenaVehicle;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_VehicleSwap : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_VehicleSwap")
	FString RequiredCalendarEvent;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_VehicleSwap")
	TSoftClassPtr<AFortAthenaVehicle> OldVehicleClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_VehicleSwap")
	TSoftClassPtr<AFortAthenaVehicle> NewVehicleClass;

};

