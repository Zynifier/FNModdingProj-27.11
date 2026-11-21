// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraBase.h"
#include "FortStormShieldCameraActor.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortStormShieldCameraActor : public AFortCameraBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortStormShieldCameraActor")
	float CameraTurnSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortStormShieldCameraActor")
	FRotator CameraRotationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortStormShieldCameraActor")
	float CameraOffsetForward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortStormShieldCameraActor")
	float CameraOffsetZ;

};

