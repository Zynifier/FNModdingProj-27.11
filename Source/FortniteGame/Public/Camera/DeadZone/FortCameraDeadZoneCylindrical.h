// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/DeadZone/FortCameraDeadZoneRadial.h"
#include "FortCameraDeadZoneCylindrical.generated.h"

UCLASS(BlueprintType)
class UFortCameraDeadZoneCylindrical : public UFortCameraDeadZoneRadial
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters", meta=(ExposeOnSpawn))
	float DeadZoneHeight;

};

