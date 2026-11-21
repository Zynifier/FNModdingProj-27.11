// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/FortSpatialGameplayInterface.h"
#include "Building/SpatialGameplay/SpatialGameplayTypes.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_CreativeLoadingStateProxy.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_CreativeLoadingStateProxy : public UFortPlayspaceComponent, public IFortSpatialGameplayInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_CurrentLockedLoadingState();

	UFUNCTION()
	void OnRep_SpatialLoadingState();

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_SpatialLoadingState, Category="Volume")
	ESpatialLoadingState SpatialLoadingState;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentLockedLoadingState)
	ESpatialLoadingState CurrentLockedLoadingState;

	UPROPERTY(Replicated)
	bool bNeverAllowSaving;

	UPROPERTY()
	TArray<ESpatialLoadingState> LockedLoadingStates;

};

