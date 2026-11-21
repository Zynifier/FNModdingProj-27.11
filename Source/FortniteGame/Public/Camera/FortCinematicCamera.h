// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/FortCameraMode.h"
#include "FortCinematicCamera.generated.h"

class AFortPlayerControllerSpectating;

UCLASS(MinimalAPI)
class UFortCinematicCamera : public UFortCameraMode
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerControllerSpectating> SpectatorPC;

};

