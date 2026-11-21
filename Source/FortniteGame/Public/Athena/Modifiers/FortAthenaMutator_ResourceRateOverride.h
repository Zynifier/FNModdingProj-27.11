// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ResourceRateOverride.generated.h"

class UCurveTable;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ResourceRateOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ResourceRateOverride")
	int32 ResourceRateOverrideIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ResourceRateOverride")
	TArray<TObjectPtr<UCurveTable>> ResourceRateOverrides;

};

