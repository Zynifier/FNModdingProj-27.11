// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Commandlets/IslandProcessing/FortCreativeIslandProcessingTask.h"
#include "FortIslandTextRemovalTaskDirectPatcher.generated.h"

class UFortCreativeDevicesTemplatesManager;

UCLASS()
class UFortIslandTextRemovalTaskDirectPatcher : public UFortCreativeIslandProcessingTaskBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UFortCreativeDevicesTemplatesManager* CreativeDevicesTemplatesManager;

};

