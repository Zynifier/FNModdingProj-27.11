// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_RevivedFromDBNO.generated.h"

USTRUCT(meta=(DisplayName="Revived From DBNO"))
struct FFortObjectiveFilter_RevivedFromDBNO : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_RevivedFromDBNO")
	FObjectiveSubjectTags_Progressible RevivingPlayer;

};

UCLASS()
class UFortObjectiveProcessor_RevivedFromDBNO : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

