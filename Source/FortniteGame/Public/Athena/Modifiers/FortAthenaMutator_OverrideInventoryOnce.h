// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_InventoryOverride.h"
#include "FortAthenaMutator_OverrideInventoryOnce.generated.h"

class AFortPlayerState;

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OverrideInventoryOnce : public AFortAthenaMutator_InventoryOverride
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void MarkPlayerInventoryImmune(AFortPlayerState* ImmunePlayer);

protected:
	UPROPERTY()
	TSet<TObjectPtr<AFortPlayerState>> AlreadyProcessedPlayerStates;

};

