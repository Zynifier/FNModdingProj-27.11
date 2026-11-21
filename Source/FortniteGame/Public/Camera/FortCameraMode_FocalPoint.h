// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_FocalPoint.generated.h"

UCLASS(Abstract, MinimalAPI)
class UFortCameraMode_FocalPoint : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float InterpolatedFOV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraSettings")
	float FOVInterpSpeed;

};

