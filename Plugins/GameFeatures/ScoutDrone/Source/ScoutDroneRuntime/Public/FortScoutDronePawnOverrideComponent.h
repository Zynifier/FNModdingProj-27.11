// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnOverrideComponent.h"
#include "FortScoutDronePawnOverrideComponent.generated.h"

class UFortCameraMode;

UCLASS(Abstract, HideCategories=("Trigger", "PhysicsVolume"))
class UFortScoutDronePawnOverrideComponent : public UFortPawnOverrideComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Camera")
	TSubclassOf<UFortCameraMode> DroneSpectateCameraMode;

};

