// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/DeadZone/FortCameraDeadZone.h"
#include "FortCameraDeadZoneAxial.generated.h"

UCLASS(BlueprintType)
class UFortCameraDeadZoneAxial : public UFortCameraDeadZone
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Parameters", meta=(ExposeOnSpawn))
	FVector DeadZoneDimensions;

};

