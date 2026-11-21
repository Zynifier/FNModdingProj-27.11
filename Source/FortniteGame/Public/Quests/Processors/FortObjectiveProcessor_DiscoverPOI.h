// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_DiscoverPOI.generated.h"

USTRUCT(meta=(DisplayName="DiscoverPOI"))
struct FFortObjectiveFilter_DiscoverPOI : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DiscoverPOI")
	FObjectiveSubjectTags POITags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DiscoverPOI", meta=(DisplayPriority="-1"))
	bool bIncrementProgressByEveryNewPOITag;

};

UCLASS()
class FORTNITEGAME_API UFortObjectiveProcessor_DiscoverPOI : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

