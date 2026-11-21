// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_UsedNPCService.generated.h"

USTRUCT(meta=(DisplayName="Used NPC Service"))
struct FFortObjectiveFilter_UsedNPCService : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_UsedNPCService")
	FObjectiveSubjectTags_Progressible NPC;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_UsedNPCService")
	FObjectiveSubjectTags ServiceType;

};

UCLASS()
class UFortObjectiveProcessor_UsedNPCService : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

