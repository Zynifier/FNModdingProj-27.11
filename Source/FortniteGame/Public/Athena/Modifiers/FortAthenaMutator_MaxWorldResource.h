// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_MaxWorldResource.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MaxWorldResource : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="MaxWorldResource")
	int32 MaxWorldResources;

};

