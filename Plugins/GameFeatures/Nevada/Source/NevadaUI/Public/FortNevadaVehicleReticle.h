// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"
#include "FortNevadaVehicleReticle.generated.h"

class AFortNevadaVehicle;
class UNevadaTargetIndicator;
enum class ENevadaFlightStates : uint8;

UCLASS()
class UFortNevadaVehicleReticle : public UFortAthenaVehicleDashboardWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBatteryChanged(float BatteryLevel);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnergyCannonEnabledChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnergyCanonFired(const float Cooldown);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamAttached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamChargeStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamDeactivated(const float Cooldown);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamDetached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTractorBeamEnabledChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnVehicleStateChanged(const ENevadaFlightStates VehicleState);

	UPROPERTY(EditAnywhere, Category="Classes")
	TSubclassOf<UNevadaTargetIndicator> NevadaTargetIndicatorClass;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UNevadaTargetIndicator> TargetIndicator;

	UPROPERTY(BlueprintReadOnly, Category="Nevada")
	TObjectPtr<AFortNevadaVehicle> OwningNevadaVehicle;

private:
	UPROPERTY(Transient)
	FUserWidgetPool IndicatorPool;

};

