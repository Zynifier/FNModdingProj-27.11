// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_AllowItemDrop.h"
#include "FortAthenaMutator_CreativeAllowItemDrop.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeAllowItemDrop : public AFortAthenaMutator_AllowItemDrop
{
	GENERATED_BODY()

};

