// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_MatchStarted.generated.h"

USTRUCT(meta=(DisplayName="Match Started"))
struct FFortObjectiveFilter_MatchStarted : public FObjectiveFilter
{
	GENERATED_BODY()

};

UCLASS()
class UFortObjectiveProcessor_MatchStarted : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

