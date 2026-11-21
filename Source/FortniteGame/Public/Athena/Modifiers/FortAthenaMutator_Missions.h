// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Missions.generated.h"

class UFortMissionInfo;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Missions : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Missions")
	TArray<TObjectPtr<UFortMissionInfo>> Missions;

};

