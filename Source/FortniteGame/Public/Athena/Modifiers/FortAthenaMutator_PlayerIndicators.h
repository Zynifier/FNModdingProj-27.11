// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PlayerIndicators.generated.h"

UCLASS(BlueprintType, HideCategories=("Actor", "Cooking", "Events", "FortAthenaMutator", "Mutator", "Physics", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerIndicators : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PlayerIndicators")
	FGameplayTag BlockAllPlayerIndicatorsTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PlayerIndicators")
	FGameplayTag BlockSinglePlayerIndicatorTag;

};

