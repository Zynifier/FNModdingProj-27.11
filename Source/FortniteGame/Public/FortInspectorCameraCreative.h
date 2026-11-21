// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "FortInspectorCameraCreative.generated.h"

class UFortCreativeVolumeLinkComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortInspectorCameraCreative : public ACameraActor
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortCreativeVolumeLinkComponent* CreativeLinkComponent;

};

