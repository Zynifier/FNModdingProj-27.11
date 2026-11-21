// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "FortCameraMode_AthenaAircraft.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortCameraMode_AthenaAircraft : public UFortCameraMode_ThirdPerson
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CameraPivot")
	FVector CameraOriginInterpSpeedToPawn;

};

