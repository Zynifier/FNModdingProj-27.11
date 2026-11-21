// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_TurnInQuest.generated.h"

USTRUCT(meta=(DisplayName="Turn In Quest"))
struct FFortObjectiveFilter_TurnInQuest : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_TurnInQuest")
	FObjectiveSubjectTags_Progressible NPC;

};

UCLASS()
class UFortObjectiveProcessor_TurnInQuest : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

