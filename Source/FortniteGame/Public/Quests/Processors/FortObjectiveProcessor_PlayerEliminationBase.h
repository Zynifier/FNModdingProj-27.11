// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "FortObjectiveProcessor_PlayerEliminationBase.generated.h"

USTRUCT(meta=(Hidden))
struct FFortObjectiveFilter_PlayerEliminationBase : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerEliminationBase", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags_Progressible KilledFortPawn;

};

