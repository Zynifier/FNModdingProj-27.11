// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_PlayerDowned.generated.h"

USTRUCT(meta=(DisplayName="Player Downed"))
struct FFortObjectiveFilter_PlayerDowned : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned")
	FObjectiveSubjectTags_Progressible DownedPlayer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned")
	FObjectiveSubjectTags Downer;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned")
	uint8 bIsHeadShot : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned")
	uint8 bIsSaviorDBNO : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned")
	uint8 bIsAvengerDBNO : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned", meta=(InlineEditConditionToggle))
	uint8 bUseDownedDistance : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerDowned", meta=(EditCondition="bUseDownedDistance", ForceUnits="meters"))
	FFloatRange DownedDistance;

};

UCLASS()
class UFortObjectiveProcessor_PlayerDowned : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

