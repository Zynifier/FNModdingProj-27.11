// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "ScalableFloat.h"
#include "FortInteractInterface.h"
#include "Vehicles/FortTreadVehicleConfigs.h"
#include "FortTankVehicleConfigs.generated.h"

UENUM()
enum ETankAimingMode
{
	/** Uses the camera rotation with no trace. */
	CameraRotationNoTrace = 0,
	/** Uses trace from the camera starting at the pivot socket. */
	CameraTraceFromPivotSocket = 1,
	/** Uses trace from the camera starting at a position calculated by the AimingCameraToMuzzleDistanceScalar. */
	CameraTraceFromDistanceScalar = 2,
};

USTRUCT()
struct FTankWeaponAimingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData")
	int32 SeatIndex;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData")
	bool bAimRotationLerpWithEasing;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData", meta=(EditCondition="bAimRotationLerpWithEasing == false"))
	FScalableFloat AimRotationLerpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData", meta=(EditCondition="bAimRotationLerpWithEasing == true"))
	FRuntimeFloatCurve AimYawRotationEasingCurve;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData", meta=(EditCondition="bAimRotationLerpWithEasing == true"))
	FRuntimeFloatCurve AimPitchRotationEasingCurve;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData")
	TEnumAsByte<ETankAimingMode> AimingMode;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData", meta=(EditCondition="AimingMode == ETankAimingMode::CameraTraceFromDistanceScalar"))
	FScalableFloat AimingCameraToMuzzleDistanceScalar;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData", meta=(EditCondition="AimingMode == ETankAimingMode::CameraTraceFromDistanceScalar"))
	FScalableFloat AimingWhileTargetingCameraToMuzzleDistanceScalar;

	UPROPERTY(EditDefaultsOnly, Category="TankWeaponAimingData")
	FScalableFloat AimingPitchAdjust;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortTankVehicleConfigs : public UFortTreadVehicleConfigs
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="Tank|Animation")
	TArray<FTankWeaponAimingData> TankWeaponAimingData;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tank|Interact")
	FText SecondInteractText;

	UPROPERTY(EditDefaultsOnly, Config, Category="Tank|Interact")
	TEnumAsByte<TInteractionType> SecondInteractType;

	UPROPERTY(EditDefaultsOnly, Category="Tank|Interact", meta=(EditCondition="SecondInteractType == TInteractionType::IT_LongPress"))
	FScalableFloat SecondInteractDuration;

};

