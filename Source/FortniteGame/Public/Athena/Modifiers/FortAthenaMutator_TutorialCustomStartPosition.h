// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TutorialCustomStartPosition.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TutorialCustomStartPosition : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_TutorialCustomStartPosition")
	FGameplayTag TutorialStartTag;

};

