// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_ConvertNPC.generated.h"

USTRUCT(meta=(DisplayName="ConvertNPC"))
struct FFortObjectiveFilter_ConvertNPC : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ConvertNPC")
	FObjectiveSubjectTags ConvertedNPC;

};

UCLASS()
class UFortObjectiveProcessor_ConvertNPC : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

