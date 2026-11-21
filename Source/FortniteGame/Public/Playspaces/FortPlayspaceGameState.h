// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortGameStateAthena.h"
#include "FortPlayspaceGameState.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayspaceGameState : public AFortGameStateAthena
{
	GENERATED_BODY()

};

