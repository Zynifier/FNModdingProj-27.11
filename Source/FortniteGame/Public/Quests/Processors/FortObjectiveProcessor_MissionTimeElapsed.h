// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_MissionTimeElapsed.generated.h"

USTRUCT(meta=(DisplayName="MissionTimeElapsed"))
struct FFortObjectiveFilter_MissionTimeElapsed : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MissionTimeElapsed")
	FObjectiveSubjectTags MissionTags;

};

UCLASS()
class FORTNITEGAME_API UFortObjectiveProcessor_MissionTimeElapsed : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

