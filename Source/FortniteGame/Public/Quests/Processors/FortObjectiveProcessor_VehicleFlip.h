// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_VehicleBase.h"
#include "FortObjectiveProcessor_VehicleFlip.generated.h"

USTRUCT(meta=(DisplayName="Vehicle Flip"))
struct FFortObjectiveFilter_VehicleFlip : public FFortObjectiveFilter_VehicleBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortObjectiveProcessor_VehicleFlip : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

