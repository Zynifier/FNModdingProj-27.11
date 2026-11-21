// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "HurdleType.h"
#include "HurdleCameraMode.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UHurdleCameraMode : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector StartCameraOriginInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector ApexCameraOriginInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector EndCameraOriginInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle", meta=(ClampMin="0.010000", UIMin="0.010000"))
	float ConstantSpeedCameraTrackInterpolationExponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	float CameraOriginVerticalThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float FallingVerticalInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle", meta=(ForceUnits="cm/s"))
	float FallSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle")
	float NonSprintFOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hurdle")
	bool bOverrideSpectatorCamera;

private:
	UPROPERTY(Transient)
	FHurdleTargetingData HurdleTargetingData;

};

