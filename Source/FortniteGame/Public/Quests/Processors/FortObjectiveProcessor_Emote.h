// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "FortObjectiveProcessor_Emote.generated.h"

USTRUCT(meta=(DisplayName="Emote"))
struct FFortObjectiveFilter_Emote : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Emote")
	FObjectiveSubjectTags Emote;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Emote")
	FObjectiveSubjectTags Target;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Emote")
	FFortObjectiveFilterType_NearbyPlayers NearbyPlayersFilter;

};

UCLASS()
class UFortObjectiveProcessor_Emote : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

