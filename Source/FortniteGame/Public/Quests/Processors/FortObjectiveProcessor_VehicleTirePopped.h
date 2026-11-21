// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_VehicleBase.h"
#include "FortObjectiveProcessor_VehicleTirePopped.generated.h"

USTRUCT(meta=(DisplayName="Vehicle Tire Popped"))
struct FFortObjectiveFilter_VehicleTirePopped : public FFortObjectiveFilter_VehicleBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_VehicleTirePopped")
	uint8 bRequireAllTiresPopped : 1;

};

UCLASS()
class UFortObjectiveProcessor_VehicleTirePopped : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

