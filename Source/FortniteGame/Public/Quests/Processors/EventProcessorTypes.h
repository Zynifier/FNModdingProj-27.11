// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EventProcessorTypes.generated.h"

USTRUCT()
struct FEventMessageContext
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FObjectiveSubjectTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ObjectiveSubjectTags")
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FObjectiveSubjectTags_Progressible : public FObjectiveSubjectTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveSubjectTags_Progressible")
	bool bCanGainProgressForThisObjective;

};

USTRUCT(BlueprintType, meta=(Hidden))
struct FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ObjectiveFilter", meta=(DisplayPriority="10"))
	FObjectiveSubjectTags_Progressible Author;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ObjectiveFilter", meta=(DisplayPriority="100"))
	FObjectiveSubjectTags Context;

};

