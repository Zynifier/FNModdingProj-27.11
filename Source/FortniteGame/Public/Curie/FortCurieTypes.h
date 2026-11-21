// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortCurieTypes.generated.h"

USTRUCT(BlueprintType)
struct FFortCurieExecutionParams
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(Categories="Curie.Element"))
	FGameplayTag ElementIdentifier;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	FScalableFloat Magnitude;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	FScalableFloat LandscapeEffectRadius;

	UPROPERTY(EditDefaultsOnly, Category="Curie|Fire")
	FScalableFloat PropagationFuelOverride;

};

