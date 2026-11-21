// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/ObjectiveProcessor.h"
#include "ObjectiveProcessor_Custom.generated.h"

USTRUCT()
struct FEventMessageContext_Custom : public FEventMessageContext
{
	GENERATED_BODY()

};

USTRUCT(meta=(DisplayName="Custom"))
struct FObjectiveFilter_Custom : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveFilter_Custom", meta=(Categories="CustomVerb", DisplayPriority="1"))
	FGameplayTag Verb;

	UPROPERTY(EditAnywhere, Category="ObjectiveFilter_Custom", meta=(DisplayAfter="Context"))
	TMap<FName, FObjectiveSubjectTags> Subjects;

	UPROPERTY(EditAnywhere, Category="ObjectiveFilter_Custom", meta=(DisplayAfter="Subjects"))
	TMap<FName, FDoubleRange> Values;

	UPROPERTY(EditAnywhere, Category="ObjectiveFilter_Custom", meta=(InlineEditConditionToggle))
	bool bIncrementByNamedValue;

	UPROPERTY(EditAnywhere, Category="ObjectiveFilter_Custom", meta=(EditCondition="bIncrementByNamedValue"))
	FName NameOfValueToIncrementBy;

};

UCLASS()
class UObjectiveProcessor_Custom : public UObjectiveProcessorBase
{
	GENERATED_BODY()

};

