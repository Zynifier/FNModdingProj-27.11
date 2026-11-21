// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "Pawns/FortPawnMovementOverridesSubsystem.h"
#include "FortGameFeatureAction_OverrideDirectionalSpeedMultiplier.generated.h"

UCLASS(meta=(DisplayName="Override Directional Speed Multiplier"))
class UFortGameFeatureAction_OverrideDirectionalSpeedMultiplier : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Movement")
	FDirectionalSpeedMultiplierOverrideData DirectionalSpeedMultiplierCurves;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	int32 Priority;

};

