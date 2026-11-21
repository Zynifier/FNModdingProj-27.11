// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Commandlets/IslandProcessing/FortCreativeIslandProcessingTask.h"
#include "FortIslandTextRemovalTaskFullSpawnPatcher.generated.h"

class UWorld;

UCLASS()
class UFortIslandTextRemovalTaskFullSpawnPatcher : public UFortCreativeIslandProcessingTaskBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	UWorld* CurrentWorld;

};

