// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_VehicleBase.h"
#include "FortObjectiveProcessor_VehicleMod.generated.h"

USTRUCT(meta=(DisplayName="Vehicle Mod"))
struct FFortObjectiveFilter_VehicleMod : public FFortObjectiveFilter_VehicleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleMod")
	FObjectiveSubjectTags VehicleMod;

};

UCLASS()
class UFortObjectiveProcessor_VehicleMod : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

