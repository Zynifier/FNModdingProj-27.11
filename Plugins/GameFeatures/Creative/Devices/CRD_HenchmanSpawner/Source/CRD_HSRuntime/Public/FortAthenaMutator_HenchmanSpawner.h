// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortInitializationInterface.h"
#include "FortAthenaMutator_HenchmanSpawner.generated.h"

UCLASS(BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class CRD_HSRUNTIME_API AFortAthenaMutator_HenchmanSpawner : public AFortAthenaMutator_GameModeBase, public IFortInitializationInterface
{
	GENERATED_BODY()

};

