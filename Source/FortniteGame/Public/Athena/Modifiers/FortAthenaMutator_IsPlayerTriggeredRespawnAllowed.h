// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_IsPlayerTriggeredRespawnAllowed.generated.h"

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_IsPlayerTriggeredRespawnAllowed : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="IsPlayerTriggeredRespawnAllowed")
	bool bIsPlayerTriggeredRespawnAllowed;

};

