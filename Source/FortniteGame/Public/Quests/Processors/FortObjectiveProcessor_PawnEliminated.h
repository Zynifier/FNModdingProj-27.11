// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_PawnEliminated.generated.h"

class UFortObjectiveProcessor_KillContribution;

UENUM()
enum class EEliminationKillType : uint8
{
	Player = 0,
	NPC = 1,
	Wildlife = 2,
};

USTRUCT(meta=(DisplayName="Pawn Eliminated"))
struct FFortObjectiveFilter_PawnEliminated : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	FObjectiveSubjectTags EliminatedPawn;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	FObjectiveSubjectTags Killer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	FObjectiveSubjectTags EliminationSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	TArray<EEliminationKillType> AllowedKilledPawnTypes;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	TArray<EEliminationKillType> ProhibitedKilledPawnTypes;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated")
	uint8 bRequirePawnWasEliminatedByConvertedPawn : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated", meta=(DisplayPriority="-1"))
	uint8 bIncrementByDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PawnEliminated", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FFloatRange Distance;

};

UCLASS()
class UFortObjectiveProcessor_PawnEliminated : public UFortObjectiveProcessor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UFortObjectiveProcessor_KillContribution* ContributionProcessor;

};

