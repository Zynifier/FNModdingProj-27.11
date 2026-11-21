// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PropManipulationNativeComponent.generated.h"

class ABuildingSMActor;
class UPlayspaceComponent_SpatialActorTracker;

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class PROPMANIPULATION_API UPropManipulationNativeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void RefreshTrackedActors(UPlayspaceComponent_SpatialActorTracker* InPlaySpaceComponent_SpatialActorTracker);

	UFUNCTION(BlueprintCallable)
	void SetControlledObjectsVisibilityAndCollision(TArray<ABuildingSMActor*> InObjectsOfControl, const bool InNewVisibility);

};

