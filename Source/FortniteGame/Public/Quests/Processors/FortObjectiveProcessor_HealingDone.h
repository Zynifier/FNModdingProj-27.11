// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_HealingBase.h"
#include "FortObjectiveProcessor_HealingDone.generated.h"

USTRUCT(meta=(DisplayName="Healing Done"))
struct FFortObjectiveFilter_HealingDone : public FFortObjectiveFilter_HealingBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingDone")
	uint8 bRequireHealingDoneToTeammate : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_HealingDone")
	FObjectiveSubjectTags SubjectHealed;

};

UCLASS()
class UFortObjectiveProcessor_HealingDone : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

