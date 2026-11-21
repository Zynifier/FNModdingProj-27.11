// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Math/MathFwd.h"
#include "FortVehicleDynAnimInstance.generated.h"

class AFortAthenaAntelopeVehicle;
class AFortAthenaSKVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleDynAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaSKVehicle> Vehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaAntelopeVehicle> Quad;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance")
	FRotator CurrentDriveJiggle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance")
	float SpeedABS;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleDynAnimInstance")
	bool bIsBoosting;

};

