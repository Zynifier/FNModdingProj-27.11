// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "FirstPersonHeadMotionUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UFirstPersonHeadMotionUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FirstPersonHeadMotionUpdateFunction")
	FVector TranslationInheritRatios;

	UPROPERTY(EditAnywhere, Category="FirstPersonHeadMotionUpdateFunction")
	FRotator RotationInheritRatios;

};

