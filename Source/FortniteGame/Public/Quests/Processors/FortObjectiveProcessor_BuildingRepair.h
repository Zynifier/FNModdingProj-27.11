// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_BuildingRepair.generated.h"

USTRUCT(meta=(DisplayName="Building Repair"))
struct FFortObjectiveFilter_BuildingRepair : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingRepair")
	FObjectiveSubjectTags Building;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingRepair", meta=(InlineEditConditionToggle))
	uint8 bUseResourcesSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingRepair", meta=(DisplayPriority="-1"))
	uint8 bIncrementByResourcesSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_BuildingRepair", meta=(EditCondition="bUseResourcesSpent", UIMin="0"))
	FInt32Range ResourcesSpent;

};

UCLASS()
class UFortObjectiveProcessor_BuildingRepair : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

