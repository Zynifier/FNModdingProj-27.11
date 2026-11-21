// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_AugmentSelected.generated.h"

USTRUCT(meta=(DisplayName="Augment Selected"))
struct FFortObjectiveFilter_AugmentSelected : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AugmentSelected")
	FObjectiveSubjectTags Augment;

};

UCLASS()
class UFortObjectiveProcessor_AugmentSelected : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

