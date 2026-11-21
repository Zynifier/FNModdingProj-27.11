// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Quests/FortQuestObjectiveType.h"
#include "FortAthenaMutator_CreativeCombineMinigameStats.generated.h"

class UFortMinigameStatFilter;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeCombineMinigameStats : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_CreativeCombineMinigameStats")
	TSubclassOf<UFortMinigameStatFilter> ChangingStat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_CreativeCombineMinigameStats")
	FStatEventFilter StatEventFilter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_CreativeCombineMinigameStats")
	float StatMultiplier;

};

