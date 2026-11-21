// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Verbs/FortVerbMessage_AugmentsRerolled.h"
#include "FortObjectiveProcessor_AugmentsRerolled.generated.h"

USTRUCT(meta=(DisplayName="Augments Re-Rolled"))
struct FFortObjectiveFilter_AugmentsRerolled : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_AugmentsRerolled")
	EAugmentReRollType ReRollType;

};

UCLASS()
class UFortObjectiveProcessor_AugmentsRerolled : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

