// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CrowdSpawner.generated.h"

class UPlayspaceComponent_SpatialActorTracker;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCrowdSpawner : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RefreshTrackedActors(UPlayspaceComponent_SpatialActorTracker* InPlaySpaceComponent_SpatialActorTracker);

	UFUNCTION(BlueprintCallable)
	void SpawnCrowd(int32 Width, int32 Depth, int32 Height, int32 Precision, int32 CharacterScaleRandomness, int32 CharacterAngleRandomness, int32 Density);

};

