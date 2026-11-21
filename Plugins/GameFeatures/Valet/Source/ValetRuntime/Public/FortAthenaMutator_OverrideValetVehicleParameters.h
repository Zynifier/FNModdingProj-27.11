// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_OverrideValetVehicleParameters.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "HLOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OverrideValetVehicleParameters : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTags);

protected:
	UPROPERTY(EditDefaultsOnly, Category="OverrideVehicleParamters")
	FScalableFloat MinInitialVehicleFuelPercent;

	UPROPERTY(EditDefaultsOnly, Category="OverrideVehicleParamters")
	FScalableFloat MaxInitialVehicleFuelPercent;

};

