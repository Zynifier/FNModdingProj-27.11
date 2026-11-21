// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_KillCredit.generated.h"

USTRUCT(meta=(DisplayName="(Deprecated) Kill Credit"))
struct FFortObjectiveFilter_KillCredit : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_KillCredit", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags_Progressible KilledActor;

};

UCLASS()
class UFortObjectiveProcessor_KillCredit : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

