// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_SpentBarsOnNPCService.generated.h"

USTRUCT(meta=(DisplayName="Spent Bars On NPC Service"))
struct FFortObjectiveFilter_SpentBarsOnNPCService : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SpentBarsOnNPCService", meta=(DisplayPriority="-1"))
	uint8 bProgressObjectiveByBarsSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SpentBarsOnNPCService", meta=(InlineEditConditionToggle))
	uint8 bUseBarsSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SpentBarsOnNPCService")
	FObjectiveSubjectTags_Progressible NPC;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SpentBarsOnNPCService")
	FObjectiveSubjectTags ServiceType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SpentBarsOnNPCService", meta=(EditCondition="bUseBarsSpent", UIMin="0"))
	FInt32Range BarsSpent;

};

UCLASS()
class UFortObjectiveProcessor_SpentBarsOnNPCService : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

