// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/Commandlets/IslandProcessing/FortCreativeIslandProcessingTask.h"
#include "FortIslandTextRemovalTaskTestLSRComparer.generated.h"

class UFortCreativeDevicesTemplatesManager;
class ULevelSaveRecord;

UCLASS()
class UFortIslandTextRemovalTaskTestLSRComparer : public UFortCreativeIslandProcessingTaskBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UFortCreativeDevicesTemplatesManager* CreativeDevicesTemplatesManager;

	UPROPERTY()
	TMap<FString, ULevelSaveRecord*> OutputLSRToCompareByID;

};

