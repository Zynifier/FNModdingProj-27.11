// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/Player/FortPlayerStatePvE.h"
#include "FortPlayerStateDeployableBase.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortPlayerStateDeployableBase : public AFortPlayerStatePvE
{
	GENERATED_BODY()

};

