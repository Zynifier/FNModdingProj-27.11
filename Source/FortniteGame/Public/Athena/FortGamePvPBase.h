// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameModeZone.h"
#include "FortGamePvPBase.generated.h"

UCLASS(Abstract, HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGamePvPBase : public AFortGameModeZone
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="PvP")
	uint8 NumTeams;

};

