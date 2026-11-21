// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "RotateAimedObjectToCameraRayUpdateFunction.generated.h"

UCLASS(BlueprintType)
class URotateAimedObjectToCameraRayUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RotateAimedObjectToCameraRayUpdateFunction")
	FRotator RotationRatios;

};

