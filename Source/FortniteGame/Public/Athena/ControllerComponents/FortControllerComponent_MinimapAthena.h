// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent_Minimap.h"
#include "FortControllerComponent_MinimapAthena.generated.h"

class UFortVolumeObjectTrackingComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MinimapAthena : public UFortControllerComponent_Minimap
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnHeatmapChanged(UFortVolumeObjectTrackingComponent* InVolumeObjectTrackingComponent);

};

