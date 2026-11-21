// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/DeadZone/FortCameraDeadZone.h"
#include "FortCameraDeadZoneRadial.generated.h"

UCLASS(BlueprintType)
class UFortCameraDeadZoneRadial : public UFortCameraDeadZone
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters", meta=(ExposeOnSpawn))
	float DeadZoneDiameter;

};

