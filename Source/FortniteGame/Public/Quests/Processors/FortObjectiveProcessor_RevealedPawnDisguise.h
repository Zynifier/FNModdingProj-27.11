// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_RevealedPawnDisguise.generated.h"

USTRUCT(meta=(DisplayName="RevealedPawnDisguise"))
struct FFortObjectiveFilter_RevealedPawnDisguise : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevealedPawnDisguise")
	FObjectiveSubjectTags_Progressible RevealedPawn;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevealedPawnDisguise", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevealedPawnDisguise", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange Distance;

};

UCLASS()
class UFortObjectiveProcessor_RevealedPawnDisguise : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

