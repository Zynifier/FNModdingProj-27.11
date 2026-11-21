// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_HealingBase.h"
#include "FortObjectiveProcessor_HealingReceived.generated.h"

USTRUCT(meta=(DisplayName="Healing Received"))
struct FFortObjectiveFilter_HealingReceived : public FFortObjectiveFilter_HealingBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingReceived")
	uint8 bRequireHealingReceivedFromTeammate : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingReceived")
	FObjectiveSubjectTags HealSource;

};

UCLASS()
class UFortObjectiveProcessor_HealingReceived : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

