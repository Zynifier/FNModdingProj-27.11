// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_AthenaLoadouts.generated.h"

class UFortAthenaInventoryLoadout;
class UUserWidget;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_AthenaLoadouts : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UUserWidget> LoadoutUserWidget;

	UPROPERTY(EditAnywhere, Category="Loadouts")
	TArray<TObjectPtr<UFortAthenaInventoryLoadout>> Loadouts;

};

