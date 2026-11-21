// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "DynamicUI/DynamicUIDirectorBase.h"
#include "ScoutDroneUIDirector.generated.h"

UCLASS(Abstract, HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"))
class AScoutDroneUIDirector : public ADynamicUIDirectorBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Drone Events", meta=(DisplayName="OnScoutDroneDeployed"))
	void BP_OnScoutDroneDeployed();

	UFUNCTION(BlueprintImplementableEvent, Category="Drone Events", meta=(DisplayName="OnScoutDroneDismissed"))
	void BP_OnScoutDroneDismissed();

private:
	UPROPERTY(EditDefaultsOnly, Category="Drone UI Settings")
	FGameplayTagContainer HUDTagsToHide;

};

