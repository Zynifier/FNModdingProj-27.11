// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "GameplayEffectCalculations/ModifierCalculations/FortGameplayModMagnitudeCalculation.h"
#include "FortScoutDroneCooldownMagnitudeCalculation.generated.h"

UCLASS(HideCategories=("Attributes", "ExternalDependencies"))
class UFortScoutDroneCooldownMagnitudeCalculation : public UFortGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Drone Cooldown Settings")
	FScalableFloat MinDroneCooldown;

};

