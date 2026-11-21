// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Replay/FortSpectatorCameraComponent.h"
#include "FortHoverDroneCameraComponent.generated.h"

UCLASS(HideCategories=("CameraSettings", "Mobility", "Rendering", "LOD", "Trigger", "PhysicsVolume"), HideFunctions=("SetFieldOfView", "SetAspectRatio"))
class UFortHoverDroneCameraComponent : public UFortSpectatorCameraComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDrone")
	float DroneTiltInterpSpeed_Accel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDrone")
	float DroneTiltInterpSpeed_Decel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="HoverDrone")
	FVector TiltUpVector;

};

