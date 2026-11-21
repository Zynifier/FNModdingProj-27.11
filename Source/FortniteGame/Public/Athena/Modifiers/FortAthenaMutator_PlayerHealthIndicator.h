// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortAthenaMutator_PlayerHealthIndicator.generated.h"

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerHealthIndicator : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_DisplayMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_DisplayMode, Category="UI")
	EPlayerIndicatorDisplayMode DisplayMode;

};

