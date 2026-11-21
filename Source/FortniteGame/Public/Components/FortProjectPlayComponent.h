// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureStateChangeObserver.h"
#include "Math/MathFwd.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "FortProjectPlayComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortProjectPlayComponent : public UFortPlayspaceComponent, public IGameFeatureStateChangeObserver
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_BoundsScale();

	UPROPERTY(EditAnywhere, Category="FortProjectPlayComponent")
	bool bScaleVolumeBounds;

	UPROPERTY(EditDefaultsOnly, Category="FortProjectPlayComponent")
	bool bEnableIslandLoadingOnCreated;

	UPROPERTY(ReplicatedUsing=OnRep_BoundsScale)
	FVector BoundsScale;

	UPROPERTY(Transient, Replicated)
	FBox EstimatedGameplayBounds;

	UPROPERTY(Transient)
	FBox AllActorsBounds;

	UPROPERTY(Transient)
	FBox LevelBoundsActorBounds;

};

