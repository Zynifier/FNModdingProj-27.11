// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_AllowSpectateOtherTeams.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class FORTNITEGAME_API AFortAthenaMutator_AllowSpectateOtherTeams : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="AllowSpectateOtherTeams")
	bool bAllowSpectateOtherTeams;

};

