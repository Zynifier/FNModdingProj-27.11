// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortGameModeAthena.h"
#include "FortGameModeBR.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeBR : public AFortGameModeAthena
{
	GENERATED_BODY()

};

