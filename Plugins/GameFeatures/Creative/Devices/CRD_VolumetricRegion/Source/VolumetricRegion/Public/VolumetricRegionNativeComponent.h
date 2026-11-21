// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VolumetricRegionNativeComponent.generated.h"

class UPlayspaceComponent_SpatialActorTracker;

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class VOLUMETRICREGION_API UVolumetricRegionNativeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void RefreshTrackedActors(UPlayspaceComponent_SpatialActorTracker* InPlaySpaceComponent_SpatialActorTracker);

};

