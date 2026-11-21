// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraMode.h"
#include "FortDeathCameraMode.generated.h"

UCLASS()
class UFortDeathCameraMode : public UFortCameraMode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraModeData")
	float FOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraModeData")
	float TimeToTrackTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraModeData")
	float TrackToTargetSpeed;

};

