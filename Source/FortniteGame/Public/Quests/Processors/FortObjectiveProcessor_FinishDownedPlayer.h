// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_FinishDownedPlayer.generated.h"

USTRUCT(meta=(DisplayName="Finish Downed Player"))
struct FFortObjectiveFilter_FinishDownedPlayer : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_FinishDownedPlayer")
	FObjectiveSubjectTags_Progressible DownedPlayer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_FinishDownedPlayer")
	FObjectiveSubjectTags DamageSource;

};

UCLASS()
class UFortObjectiveProcessor_FinishDownedPlayer : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

