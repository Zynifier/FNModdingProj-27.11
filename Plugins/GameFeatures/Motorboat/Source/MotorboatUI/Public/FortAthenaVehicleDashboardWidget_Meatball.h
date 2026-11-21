// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"
#include "FortAthenaVehicleDashboardWidget_Meatball.generated.h"

class AFortMeatballVehicle;

UCLASS(Abstract)
class UFortAthenaVehicleDashboardWidget_Meatball : public UFortAthenaVehicleDashboardWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortMeatballVehicle* GetMeatballVehicle() const;

};

