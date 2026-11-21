// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "Athena/FortCameraMode_AthenaVehicle.h"
#include "RockVehicleCameraMode.generated.h"

class ARockVehicle;
class URockVehicleAbility_Jump;

USTRUCT(BlueprintType)
struct FRockCameraSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float FOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float Pitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float Stiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float SwivelSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockCameraSettings")
	float TransitionSpeed;

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class URockVehicleCameraMode : public UFortCameraMode_AthenaVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float SwivelPitchMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float SwivelYawMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float GroundNormalInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float GroundNormalAirInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float GroundYawRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float WallYawRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float InterpToGroundTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float InterpToAirTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float AverageVelocityInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	FRuntimeFloatCurve AirRotationInterpRateForSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float FocusOffsetInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float DistanceSpeedScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float DistanceOffsetMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float DistanceOffsetMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float DistanceInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float MaxSpeedFOVOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float SupersonicFOVOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category="Camera")
	float FOVInterpRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Config, Category="Camera")
	FRockCameraSettings CameraSettings;

private:
	UPROPERTY(Transient)
	TObjectPtr<ARockVehicle> VehicleTarget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URockVehicleAbility_Jump> JumpAbility;

};

