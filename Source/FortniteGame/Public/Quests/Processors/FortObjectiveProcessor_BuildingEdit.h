// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_BuildingEdit.generated.h"

USTRUCT(meta=(DisplayName="Building Edit"))
struct FFortObjectiveFilter_BuildingEdit : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingEdit")
	FObjectiveSubjectTags Building;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingEdit", meta=(InlineEditConditionToggle))
	uint8 bUseBuildingLevel : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingEdit", meta=(DisplayPriority="-1"))
	uint8 bIncrementByCurrentBuildingLevel : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingEdit", meta=(EditCondition="bUseBuildingLevel", UIMin="0"))
	FInt32Range CurrentBuildingLevel;

};

UCLASS()
class UFortObjectiveProcessor_BuildingEdit : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

