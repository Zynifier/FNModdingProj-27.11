// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "ScalableFloat.h"
#include "FortCameraModifier_Grinding.generated.h"

class UCurveFloat;

UCLASS(BlueprintType, Blueprintable)
class UFortCameraModifier_Grinding : public UCameraModifier
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Config")
	FScalableFloat bUseNativeCalculation;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	UCurveFloat* BlendInCurve;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	UCurveFloat* BlendOutCurve;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	FScalableFloat SnapToGrindingLocation;

	UPROPERTY(EditDefaultsOnly, Category="Config")
	FScalableFloat ADSAlphaInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat CurrentForwardInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxRightSpeedOldRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxRightSpeedNewRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MinForwardSpeedOldRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxForwardSpeedOldRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MinForwardSpeedNewRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxForwardSpeedNewRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MinUpSpeedOldRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxUpSpeedOldRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MinUpSpeedNewRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat MaxUpSpeedNewRangeForForward;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat BaseForwardMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat SpeedUpBoosterForwardMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Forward")
	FScalableFloat SprintingForwardMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat RightSpeedOldRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat RightSpeedNewRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MaxUpSpeedOldRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MaxUpSpeedNewRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MinForwardSpeedOldRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MaxForwardSpeedOldRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MinForwardSpeedNewRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat MaxForwardSpeedNewRangeForRight;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat BaseRightMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat SpeedUpBoostRightMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat SprintingRightMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Right")
	FScalableFloat CurrentRightInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat UpSpeedOldRangeForUp;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat UpSpeedNewRangeForUp;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat CurrentUpInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat BaseUpMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat SpeedUpBoostUpMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Up")
	FScalableFloat SprintingUpMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat MinForwardSpeedOldRangeForLean;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat MaxForwardSpeedOldRangeForLean;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat MinForwardSpeedNewRangeForLean;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat MaxForwardSpeedNewRangeForLean;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat MultiplierForMaxNewLeanRange;

	UPROPERTY(EditDefaultsOnly, Category="Config | Lean")
	FScalableFloat CurrentLeanInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat MaxSpeedOldRangeForFOV;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat MaxSpeedNewRangeForFOV;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat BaseFOV;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat SpeedUpBoosterFOV;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat SprintingFOV;

	UPROPERTY(EditDefaultsOnly, Category="Config | FOV")
	FScalableFloat CurrentFOVInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat DeltaDecreaseInZForOffset;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat CurrentOffsetInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat StraightnessMultiplierForOffset;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat FinalOffsetForwardDelta;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat FinalOffsetUpDelta;

	UPROPERTY(EditDefaultsOnly, Category="Config | Offset")
	FScalableFloat FinalOffsetRightDelta;

	UPROPERTY(BlueprintReadOnly, Category="FortCameraModifier_Grinding")
	bool bCachedUseNativeCalculation;

};

