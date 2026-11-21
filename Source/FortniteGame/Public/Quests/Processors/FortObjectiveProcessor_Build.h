// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Build.generated.h"

USTRUCT(meta=(DisplayName="Build"))
struct FFortObjectiveFilter_Build : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Build")
	FObjectiveSubjectTags Building;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Build", meta=(InlineEditConditionToggle))
	uint8 bUseResourcesSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Build", meta=(DisplayPriority="-1"))
	uint8 bIncrementByResourcesSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Build", meta=(EditCondition="bUseResourcesSpent", UIMin="0"))
	FInt32Range ResourcesSpent;

};

UCLASS()
class UFortObjectiveProcessor_Build : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

