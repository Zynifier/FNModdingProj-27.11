// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortVehicleAnimInstance.generated.h"

class AFortAthenaSKVehicle;

UENUM(BlueprintType)
enum class EFortValetVehicleType : uint8
{
	Default = 0,
	Sport = 1,
	BasicTruck = 2,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<AFortAthenaSKVehicle> Vehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector AxlePositionF;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector AxlePositionB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator AxleRotationF;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator AxleRotationB;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector WheelPositionFR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector WheelPositionFL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector WheelPositionBR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FVector WheelPositionBL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelSpinFR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelSpinFL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelSpinBR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelSpinBL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator DriveShaftSpin;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelRotationFR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelRotationFL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelRotationBR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator WheelRotationBL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	FRotator SteeringRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortVehicleAnimInstance")
	EFortValetVehicleType VehicleType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleAnimInstance")
	bool bHasDriver;

};

