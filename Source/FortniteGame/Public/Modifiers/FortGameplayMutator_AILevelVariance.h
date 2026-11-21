// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modifiers/FortGameplayMutator.h"
#include "FortGameplayMutator_AILevelVariance.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameplayMutator_AILevelVariance : public AFortGameplayMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator")
	float MinVariance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mutator")
	float MaxVariance;

};

