// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_InteractionDistance.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InteractionDistance : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_InteractionDistance")
	float InteractionDistanceOverride;

};

