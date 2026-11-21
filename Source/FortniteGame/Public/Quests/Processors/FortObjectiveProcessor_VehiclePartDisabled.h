// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_VehicleBase.h"
#include "FortObjectiveProcessor_VehiclePartDisabled.generated.h"

USTRUCT(meta=(DisplayName="Vehicle Part Disabled"))
struct FFortObjectiveFilter_VehiclePartDisabled : public FFortObjectiveFilter_VehicleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehiclePartDisabled", meta=(Categories="Vehicle.Part"))
	FObjectiveSubjectTags VehiclePart;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehiclePartDisabled")
	uint8 bRequireCriticalHit : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehiclePartDisabled", meta=(InlineEditConditionToggle))
	uint8 bUseDamageDone : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehiclePartDisabled", meta=(EditCondition="bUseDamageDone", UIMin="0"))
	FFloatRange DamageDone;

};

UCLASS()
class UFortObjectiveProcessor_VehiclePartDisabled : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

