// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_PlayerEliminationBase.h"
#include "FortObjectiveProcessor_ScoredPlayerElimination.generated.h"

USTRUCT(meta=(DisplayName="(Deprecated) Scored Player Elimination"))
struct FFortObjectiveFilter_ScoredPlayerElimination : public FFortObjectiveFilter_PlayerEliminationBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ScoredPlayerElimination", meta=(DisplayAfter="KilledFortPawn"))
	FObjectiveSubjectTags KillerTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ScoredPlayerElimination", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FFloatRange Distance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ScoredPlayerElimination", meta=(InlineEditConditionToggle))
	bool bUseDistance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ScoredPlayerElimination", meta=(DisplayPriority="-1"))
	bool bIncrementByDistance;

};

UCLASS()
class UFortObjectiveProcessor_ScoredPlayerElimination : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

