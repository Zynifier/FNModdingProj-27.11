// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortTankAnimFunctionLibrary.h"
#include "Vehicles/FortTreadVehicleAnimInstance.h"
#include "Vehicles/VehicleSeats.h"
#include "FortTankVehicleAnimInstance.generated.h"

class AFortTankVehicle;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortTankVehicleAnimInstance : public UFortTreadVehicleAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	TObjectPtr<AFortTankVehicle> TankVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	FRotator CurrentAimRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	FRotator CurrentTurretAimRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	FRotator SmoothedTurretDeltaRotation;

	UPROPERTY(BlueprintReadWrite, Category="Tank")
	float InterpolationRate;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tank")
	bool bEngineOverheated;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	bool bHasPassenger;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	bool bIsFired;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	bool bIsReady;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Tank")
	bool bDriverCoverOnCooldown;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float LeftTreadPower;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float RightTreadPower;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float TurretYawAlpha;

	UPROPERTY(BlueprintReadWrite, Category="Tank")
	float TurretYawAlphaSmoothingRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float CannonYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float CannonPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float TurretYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float TurretPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	FLinearColor MIDTreadPositionColor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDTreadDamageLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDTreadDamageRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDExhaustShakeSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDExhaustShakeAmp;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDEngineBoostGlow;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Tank")
	float MIDEngineHealthRatio;

private:
	UFUNCTION(BlueprintCallable, Category="Tank")
	void UpdateMIDEngineProperties(const float DeltaSeconds, const float EngineHealthRatio);

	UPROPERTY(Transient)
	TMap<EVehicleSeats, FTankAnimAimingData> AimingData;

	UPROPERTY(Transient)
	FRotator PreviousTurretAimRotation;

};

