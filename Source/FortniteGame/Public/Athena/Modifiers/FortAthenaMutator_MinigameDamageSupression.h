// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_MinigameDamageSupression.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MinigameDamageSupression : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_MinigameDamageSupression")
	uint8 bPreventPreGameDamage : 1;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_MinigameDamageSupression")
	uint8 bPreventPostGameDamage : 1;

};

