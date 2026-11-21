// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_StreamDistanceOverride.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_StreamDistanceOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_StreamDistanceOverride")
	FScalableFloat StreamDistanceScale;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_StreamDistanceOverride")
	bool bApplyScalability;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_StreamDistanceOverride")
	bool bApplyAfterWarmup;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_StreamDistanceOverride")
	bool bForceOverride;

};

