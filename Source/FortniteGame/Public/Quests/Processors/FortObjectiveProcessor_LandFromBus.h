// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessor_Land.h"
#include "FortObjectiveProcessor_LandFromBus.generated.h"

USTRUCT(meta=(DisplayName="LandFromBus"))
struct FFortObjectiveFilter_LandFromBus : public FFortObjectiveFilter_Land
{
	GENERATED_BODY()

};

UCLASS()
class UFortObjectiveProcessor_LandFromBus : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

