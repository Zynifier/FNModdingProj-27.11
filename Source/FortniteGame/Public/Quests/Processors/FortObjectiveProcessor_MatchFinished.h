// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_MatchFinished.generated.h"

USTRUCT(meta=(DisplayName="Match Finished"))
struct FFortObjectiveFilter_MatchFinished : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MatchFinished")
	FObjectiveSubjectTags MatchMetaData;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MatchFinished", meta=(InlineEditConditionToggle))
	uint8 bUseFinishingRankRange : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MatchFinished", meta=(InlineEditConditionToggle))
	uint8 bUsePlayersOutLived : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MatchFinished", meta=(EditCondition="bUseFinishingRankRange", UIMin="0"))
	FInt32Range FinishingRankRange;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_MatchFinished", meta=(EditCondition="bUsePlayersOutLived", UIMin="0"))
	FInt32Range PlayersOutLived;

};

UCLASS()
class UFortObjectiveProcessor_MatchFinished : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

