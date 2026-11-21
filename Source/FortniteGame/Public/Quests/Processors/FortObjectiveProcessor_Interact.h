// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Interact.generated.h"

USTRUCT(meta=(DisplayName="Interact"))
struct FFortObjectiveFilter_Interact : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Interact")
	FObjectiveSubjectTags Target;

};

UCLASS()
class UFortObjectiveProcessor_Interact : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

