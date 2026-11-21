// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "RockBouncyChassis.h"
#include "RockVehicleAnimInstance.generated.h"

USTRUCT()
struct FRockVehicleWheelAnimInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RockVehicleWheelAnimInfo")
	float SpringToWheelOffsetZ;

	UPROPERTY(EditAnywhere, Category="RockVehicleWheelAnimInfo")
	FFloatInterval SpringTravelRange;

	UPROPERTY(EditAnywhere, Category="RockVehicleWheelAnimInfo")
	float WheelRadius;

};

UCLASS(HideCategories=("AnimInstance"))
class ROCKVEHICLERUNTIME_API URockVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RockVehicleAnimInstance")
	FBouncyChassisState BouncyChassis;

	UPROPERTY(EditAnywhere, Category="RockVehicleAnimInstance")
	FRockVehicleWheelAnimInfo WheelInfoFR;

	UPROPERTY(EditAnywhere, Category="RockVehicleAnimInstance")
	FRockVehicleWheelAnimInfo WheelInfoFL;

	UPROPERTY(EditAnywhere, Category="RockVehicleAnimInstance")
	FRockVehicleWheelAnimInfo WheelInfoBR;

	UPROPERTY(EditAnywhere, Category="RockVehicleAnimInstance")
	FRockVehicleWheelAnimInfo WheelInfoBL;

	UPROPERTY(EditAnywhere, Category="RockVehicleAnimInstance")
	float WheelLerpSpeed;

};

