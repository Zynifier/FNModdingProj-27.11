// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/FortPlayspace.h"
#include "PapayaPlayspaceHub.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class APapayaPlayspaceHub : public AFortPlayspace
{
	GENERATED_BODY()

};

