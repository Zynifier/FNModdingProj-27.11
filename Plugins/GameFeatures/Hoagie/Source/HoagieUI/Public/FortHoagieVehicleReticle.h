// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"
#include "FortHoagieVehicleReticle.generated.h"

class AFortHoagieVehicle;

UCLASS()
class UFortHoagieVehicleReticle : public UFortAthenaVehicleDashboardWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Updates", meta=(DisplayName="Setup MID"))
	void OnSetupComplete(bool bVehicleUsesFuelSystem);

	UPROPERTY(BlueprintReadOnly, Category="Hoagie")
	TObjectPtr<AFortHoagieVehicle> OwningHoagieVehicle;

};

