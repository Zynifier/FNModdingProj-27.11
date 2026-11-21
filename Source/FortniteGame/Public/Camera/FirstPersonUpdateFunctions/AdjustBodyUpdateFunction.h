// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "AdjustBodyUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UAdjustBodyUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Full Weight Parameters")
	FName BoneName;

	UPROPERTY(EditAnywhere, Category="Full Weight Parameters")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category="Full Weight Parameters")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, Category="Transition In/Out Parameters")
	FVector TransitionOffset;

	UPROPERTY(EditAnywhere, Category="Transition In/Out Parameters")
	float TransitionMinDistanceThreshold;

	UPROPERTY(EditAnywhere, Category="Transition In/Out Parameters")
	float TransitionMaxDistanceThreshold;

};

