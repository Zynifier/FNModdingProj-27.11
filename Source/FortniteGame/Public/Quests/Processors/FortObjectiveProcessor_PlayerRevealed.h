// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_PlayerRevealed.generated.h"

USTRUCT(meta=(DisplayName="Player Revealed"))
struct FFortObjectiveFilter_PlayerRevealed : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerRevealed")
	FObjectiveSubjectTags RevealedPlayer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerRevealed")
	FObjectiveSubjectTags TrackingTypeTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerRevealed", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerRevealed", meta=(EditCondition="bUseDistance"))
	FFloatRange DistanceToRevealedPlayer;

};

UCLASS()
class UFortObjectiveProcessor_PlayerRevealed : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

