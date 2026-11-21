// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "FortWeaponCameraAnimation.generated.h"

class AFortWeaponRanged;
class UCurveFloat;
class UPrimaryDataAsset;

UCLASS(BlueprintType, Blueprintable)
class UFortWeaponCameraAnimation : public UCameraModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	void GetInputParams(float& OutStartTime, float& OutPreviousDeltaFOV, float& OutIntensityTimer, float& OutTimeBetweenShots) const;

	UFUNCTION(BlueprintImplementableEvent)
	void SetInputParams(float StartTime, float PreviousDeltaFOV, float IntensityTimer, float TimeBetweenShots);

	UFUNCTION(BlueprintImplementableEvent)
	void SetShakeDataParam(TSubclassOf<UPrimaryDataAsset> ShakeDataClass);

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortWeaponCameraAnimation")
	TWeakObjectPtr<AFortWeaponRanged> LastWeaponFired;

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	bool GetCameraShakeData(UCurveFloat*& RollCurve, UCurveFloat*& FOVCurve, UCurveFloat*& RollNoiseCurve, UCurveFloat*& ContinuousFireIntensityCurve, float& RollNoiseTimescale) const;

	UFUNCTION(BlueprintPure)
	bool UseNativeImplementation() const;

};

