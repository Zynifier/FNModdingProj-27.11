// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortHoverboardCameraMode.generated.h"

class UCurveFloat;

UCLASS(BlueprintType, Blueprintable)
class UFortHoverboardCameraMode : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Movement", meta=(DisplayName="Velocity Based FOV Increase"))
	TObjectPtr<UCurveFloat> VelocityBasedFOVIncreaseCurve;

};

