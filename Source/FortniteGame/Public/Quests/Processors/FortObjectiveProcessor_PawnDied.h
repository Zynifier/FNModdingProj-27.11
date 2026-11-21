// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDeathCauseEnum.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_PawnDied.generated.h"

USTRUCT(meta=(DisplayName="Pawn Died"))
struct FFortObjectiveFilter_PawnDied : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied", meta=(DisplayPriority="-1"))
	uint8 bIncrementByDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied")
	FObjectiveSubjectTags_Progressible Killer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied")
	FObjectiveSubjectTags_Progressible Downer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied")
	TArray<EDeathCause> RequiredCausesOfDeath;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied")
	TArray<EDeathCause> ProhibitedCausesOfDeath;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied")
	FObjectiveSubjectTags DeathTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnDied", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange Distance;

};

UCLASS()
class UFortObjectiveProcessor_PawnDied : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

