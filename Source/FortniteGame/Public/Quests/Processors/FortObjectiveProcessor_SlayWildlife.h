// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_SlayWildlife.generated.h"

USTRUCT(meta=(DisplayName="(Deprecated) Slay Wildlife"))
struct FFortObjectiveFilter_SlayWildlife : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SlayWildlife", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags_Progressible SlainWildlife;

};

UCLASS()
class UFortObjectiveProcessor_SlayWildlife : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

