// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_StormAlteration.generated.h"

class UMaterialInterface;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_StormAlteration : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Alterations")
	FScalableFloat DisableStormAlterations;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Alterations")
	TArray<TObjectPtr<UMaterialInterface>> MaterialOverrides;

};

