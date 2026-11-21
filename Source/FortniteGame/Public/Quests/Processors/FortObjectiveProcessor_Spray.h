// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Spray.generated.h"

USTRUCT(meta=(DisplayName="Spray"))
struct FFortObjectiveFilter_Spray : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Spray")
	FObjectiveSubjectTags Spray;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Spray")
	FObjectiveSubjectTags Target;

};

UCLASS()
class UFortObjectiveProcessor_Spray : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

