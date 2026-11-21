// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "FortAthenaMutator_Leave.generated.h"

class UMaterialInterface;
class UUserWidget;

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Leave : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSoftClassPtr<UUserWidget> CustomDBNOWidget;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSoftObjectPtr<UMaterialInterface> CustomReviveIndicator;

};

