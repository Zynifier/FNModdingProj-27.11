// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/Fort3PCameraMode.h"
#include "FortScoutDroneCameraMode.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortScoutDroneCameraMode : public UFort3PCameraMode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Interpolation")
	bool bShouldInterpolateLocation;

	UPROPERTY(EditDefaultsOnly, Category="Interpolation")
	bool bShouldInterpolateRotation;

};

