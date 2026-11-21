// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortCameraMode_AthenaVehicle.h"
#include "FortCameraMode_Hoagie.generated.h"

UCLASS(Config=Game, BlueprintType, Blueprintable)
class UFortCameraMode_Hoagie : public UFortCameraMode_AthenaVehicle
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	float CurrentRollMultiplier;

	UPROPERTY(Transient)
	float CurrentPitchMultiplier;

	UPROPERTY(Transient)
	FVector LastOrigin;

	UPROPERTY(Transient)
	FVector CurrentInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	FVector BoostInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BaseRollMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BasePitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BoostRollMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BoostPitchMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BoostRollDampFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BoostRollRecoveryDampFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Helicopter")
	float BoostRecoveryInterpSpeed;

};

