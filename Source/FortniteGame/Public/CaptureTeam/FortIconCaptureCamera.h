// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FortIconCaptureCamera.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Hidden", "Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortIconCaptureCamera : public ACameraActor
{
	GENERATED_BODY()

};

