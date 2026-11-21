// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"
#include "FortAthenaVehicleDashboardWidget_Ferret.generated.h"

class AFortAthenaFerretVehicle;

UCLASS(Abstract)
class UFortAthenaVehicleDashboardWidget_Ferret : public UFortAthenaVehicleDashboardWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortAthenaFerretVehicle* GetFerretVehicle() const;

};

