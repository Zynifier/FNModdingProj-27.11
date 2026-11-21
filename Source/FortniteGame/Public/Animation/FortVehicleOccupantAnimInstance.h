// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_VehicleDriverAnimAsset.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimInstance.h"
#include "FortVehicleOccupantAnimInstance.generated.h"

class UFortVehicleAnimSet;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleOccupantAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VehicleOccupant")
	FFortAnimInput_SocketBasedIKTarget RightHandIKTarget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VehicleOccupant")
	FFortAnimInput_SocketBasedIKTarget LeftHandIKTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleOccupant")
	FFortAnimInput_VehicleDriverAnimAsset CurrentDriverAnimSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	TObjectPtr<UFortVehicleAnimSet> VehicleAnimSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	FVector ImpactDisplacement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	FVector WorldVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	FVector2D DriveStartPlayRateSpeedRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float DesiredSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float SlopePitchDegreeAngle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float SlopeRollDegreeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float SteeringAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float DriveStartPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float AimYawSmoothed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	float AimYawLastFrame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float ReversingSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float BrakingDeltaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float MovingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float MovingForwardThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float MovingFastThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float SteeringLeftThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float SteeringRightThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float StartAimYawLerpingDeltaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float StopAimYawLerpingDeltaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimYawSmoothSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleOccupant")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsFemale : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsBackLeftPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsBackRightPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsBoosting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsReversing : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsBraking : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsMoving : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsMovingForward : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsMovingFast : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsSteeringRight : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsSteeringLeft : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bIsSmoothingAimYaw : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bAimFWD : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bAimBWD : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bAimLFT : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="VehicleOccupant")
	uint8 bAimRGT : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortVehicleOccupantAnimInstance")
	uint8 bEnableLocomotionAdditives : 1;

};

