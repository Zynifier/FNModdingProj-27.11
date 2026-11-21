// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GiveItemsAtGamePhase.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FItemsToGiveAtPhase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemsToGiveAtPhase")
	TObjectPtr<UFortWorldItemDefinition> ItemToDrop;

	UPROPERTY(EditAnywhere, Category="ItemsToGiveAtPhase")
	FScalableFloat NumberToGive;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GiveItemsAtGamePhase : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Item Giver")
	EAthenaGamePhase PhaseToGiveItems;

	UPROPERTY(EditDefaultsOnly, Category="Item Giver")
	TArray<FItemsToGiveAtPhase> ItemsToGive;

};

