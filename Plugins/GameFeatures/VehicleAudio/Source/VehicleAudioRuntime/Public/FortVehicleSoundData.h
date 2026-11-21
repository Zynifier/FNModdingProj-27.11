// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortVehicleSoundData.generated.h"

class UFortVehicleSoundComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortVehicleSoundData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Components")
	TArray<UFortVehicleSoundComponent*> SoundComponents;

	UPROPERTY(EditAnywhere, Category="Config", meta=(ClampMin="0.000000"))
	float MaxListenerDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config|MotorModel")
	bool bUpdateDataFromController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(EditCondition="!bUpdateDataFromController"))
	float MaxBrakeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(EditCondition="!bUpdateDataFromController"))
	float ThrottleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(ClampMin="0.000000", EditCondition="!bUpdateDataFromController"))
	float SurfaceFrictionModifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(ClampMin="0.000000", EditCondition="!bUpdateDataFromController"))
	float MotorFrictionModifier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(ClampMin="0.000000", EditCondition="!bUpdateDataFromController"))
	FVector2D FrictionJitter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config|MotorModel", meta=(EditCondition="!bUpdateDataFromController"))
	bool bCanShiftOverride;

};

