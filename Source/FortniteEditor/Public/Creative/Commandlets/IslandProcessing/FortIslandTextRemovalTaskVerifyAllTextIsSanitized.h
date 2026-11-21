// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Commandlets/IslandProcessing/FortCreativeIslandProcessingTask.h"
#include "FortIslandTextRemovalTaskVerifyAllTextIsSanitized.generated.h"

class UFortCreativeDevicesTemplatesManager;
class UWorld;

UCLASS()
class UFortIslandTextRemovalTaskVerifyAllTextIsSanitized : public UFortCreativeIslandProcessingTaskBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UWorld* CurrentWorld;

	UPROPERTY()
	UFortCreativeDevicesTemplatesManager* CreativeDevicesTemplatesManager;

};

