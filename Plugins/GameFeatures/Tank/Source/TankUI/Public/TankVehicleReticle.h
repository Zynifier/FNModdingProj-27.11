// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortAthenaVehicle.h"
#include "Athena/FortVehicleConfigs.h"
#include "Athena/Vehicles/FortAthenaVehicleDashboardWidget.h"
#include "Vehicles/FortTreadVehicle.h"
#include "TankVehicleReticle.generated.h"

class AActor;
class AFortTankVehicle;
class AFortWeaponRanged;

UCLASS()
class UTankVehicleReticle : public UFortAthenaVehicleDashboardWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCannonFired(const float RateTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankDistanceUpdate(const float Distance, const float DistancePercent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankEngineHealthChanged(const float EngineHealth, const float EngineHealthMax, const bool bNewlyDisabled, const bool bNewlyEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankHatchHealthChanged(const float HatchHealth, const float HatchHealthMax, const bool bNewlyDisabled, const bool bNewlyEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankRotationValueChanged(const float TankValue, const float TurretValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankTargetingPressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankTargetingReleased();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankTurretAimPitchValueChanged(const float Pitch, const float PitchPercent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTankTurretAimYawValueChanged(const float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTreadEnabledChanged(const bool bEnabled, const ETreadSide::Type Side);

	UFUNCTION(BlueprintCallable)
	void SetupVehicleFromBP(AActor* NewVehicle);

	UPROPERTY(BlueprintReadOnly, Category="TankVehicle")
	TObjectPtr<AFortTankVehicle> OwningTankVehicle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TankVehicleReticle")
	float MinTurretPitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TankVehicleReticle")
	float MaxTurretPitch;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TankVehicleReticle")
	bool bDistanceMeterEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TankVehicleReticle")
	bool bTankOrientationEventsEnabled;

private:
	UFUNCTION()
	void HandleOnDamageablePartHealthChanged(const FVehicleDamageablePartConfig& PartConfig, const FVehicleDamageablePart& Part, const bool bNewlyDisabled, const bool bNewlyEnabled);

	UFUNCTION()
	void HandleOnEquipMountedWeapon(AFortWeaponRanged* EquippedMountedWeapon);

};

