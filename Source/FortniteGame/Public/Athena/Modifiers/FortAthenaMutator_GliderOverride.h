// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GliderOverride.generated.h"

class AFortPawn;
class UAthenaGliderItemDefinition;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GliderOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void PawnRespawned(AFortPawn* RespawnedPawn);

private:
	UPROPERTY(EditAnywhere, Category="Cosmetics")
	TObjectPtr<UAthenaGliderItemDefinition> GliderOverride;

};

