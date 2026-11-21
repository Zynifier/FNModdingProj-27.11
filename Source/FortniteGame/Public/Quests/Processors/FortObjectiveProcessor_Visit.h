// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Visit.generated.h"

USTRUCT(meta=(DisplayName="Visit"))
struct FFortObjectiveFilter_Visit : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Visit")
	FObjectiveSubjectTags Location;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Visit", meta=(DisplayPriority="-1"))
	bool bIncrementProgressByEveryMatchingLocationTag;

};

UCLASS()
class FORTNITEGAME_API UFortObjectiveProcessor_Visit : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

