// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_KillsFeedback.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_KillsFeedback : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	uint8 bShouldDisplayKillFeed : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	uint8 bShouldDisplayKillsInSocialMenu : 1;

};

