// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_BotsWinCondition.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_BotsWinCondition : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bOnlyBotRemaining : 1;

};

