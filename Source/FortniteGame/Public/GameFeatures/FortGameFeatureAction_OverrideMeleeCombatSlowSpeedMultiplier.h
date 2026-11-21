// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "FortGameFeatureAction_OverrideMeleeCombatSlowSpeedMultiplier.generated.h"

UCLASS(meta=(DisplayName="Override Melee Combat Slow Speed Multiplier"))
class UFortGameFeatureAction_OverrideMeleeCombatSlowSpeedMultiplier : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Melee Multiplier")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Melee Multiplier", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float OverrideMeleeCombatSlowSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Melee Multiplier")
	int32 Priority;

};

