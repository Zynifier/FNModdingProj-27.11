// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Storm.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Storm : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mutator")
	void PauseStormDamage(bool bPause);

	UFUNCTION(BlueprintCallable, Category="Mutator")
	void PauseStormProgression(bool bPause);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Storm")
	FScalableFloat SafeZoneFinalDestinationX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Storm")
	FScalableFloat SafeZoneFinalDestinationY;

};

