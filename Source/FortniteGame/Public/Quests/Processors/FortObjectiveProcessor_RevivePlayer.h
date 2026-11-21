// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_RevivePlayer.generated.h"

USTRUCT(meta=(DisplayName="Revive Player"))
struct FFortObjectiveFilter_RevivePlayer : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevivePlayer")
	uint8 bAllowSelfRevives : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevivePlayer")
	uint8 bRequireSquadMemberRevived : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevivePlayer")
	FObjectiveSubjectTags_Progressible RevivedPlayer;

};

UCLASS()
class UFortObjectiveProcessor_RevivePlayer : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

