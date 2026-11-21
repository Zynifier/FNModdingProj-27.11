// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SpectateBeforeRespawn.generated.h"

class AFortPlayerControllerZone;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpectateBeforeRespawn : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnClientStartedRespawn(AFortPlayerControllerZone* PlayerController);

	UPROPERTY(EditDefaultsOnly, Category="Spectate")
	FScalableFloat SpectateToRespawnTransitionTime;

};

