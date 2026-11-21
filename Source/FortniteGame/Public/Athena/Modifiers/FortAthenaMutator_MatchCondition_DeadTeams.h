// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_MatchCondition.h"
#include "FortAthenaMutator_MatchCondition_DeadTeams.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Actor", "Cooking", "FortAthenaMutator", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MatchCondition_DeadTeams : public AFortAthenaMutator_MatchCondition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_MatchCondition_DeadTeams")
	FScalableFloat NumTeamsToDie;

};

