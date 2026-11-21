// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GiveItemsAtGamePhaseStep.generated.h"

class UFortWorldItemDefinition;

USTRUCT()
struct FItemsToGive
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemsToGive")
	TObjectPtr<UFortWorldItemDefinition> ItemToDrop;

	UPROPERTY(EditAnywhere, Category="ItemsToGive")
	FScalableFloat NumberToGive;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GiveItemsAtGamePhaseStep : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UPROPERTY(EditDefaultsOnly, Category="Item Giver")
	EAthenaGamePhaseStep PhaseToGiveItems;

	UPROPERTY(EditDefaultsOnly, Category="Item Giver")
	TArray<FItemsToGive> ItemsToGive;

};

