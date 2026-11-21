// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FirstPersonUpdateFunction.h"
#include "AlignOpticEntranceToCameraRayUpdateFunction.generated.h"

UCLASS(BlueprintType)
class UAlignOpticEntranceToCameraRayUpdateFunction : public UFirstPersonUpdateFunction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AlignOpticEntranceToCameraRayUpdateFunction")
	float CorrectionRatio;

};

