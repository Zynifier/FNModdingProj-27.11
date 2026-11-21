// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_StormPhaseChanged.generated.h"

USTRUCT(meta=(DisplayName="Storm Phase Changed"))
struct FFortObjectiveFilter_StormPhaseChanged : public FObjectiveFilter
{
	GENERATED_BODY()

};

UCLASS()
class UFortObjectiveProcessor_StormPhaseChanged : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

