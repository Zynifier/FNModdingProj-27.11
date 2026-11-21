// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_OverrideSupplyDropRadius.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OverrideSupplyDropRadius : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_OverrideSupplyDropRadius")
	FScalableFloat SupplyDropRadius;

};

