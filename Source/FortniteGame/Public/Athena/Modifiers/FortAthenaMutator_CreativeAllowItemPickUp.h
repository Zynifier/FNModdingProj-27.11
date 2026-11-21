// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_AllowItemPickUp.h"
#include "FortAthenaMutator_CreativeAllowItemPickUp.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeAllowItemPickUp : public AFortAthenaMutator_AllowItemPickUp
{
	GENERATED_BODY()

};

