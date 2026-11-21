// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "Pawns/FortPawnMovementOverridesSubsystem.h"
#include "FortGameFeatureAction_OverrideMovementCurves.generated.h"

UCLASS(meta=(DisplayName="Override Movement Curves"))
class UFortGameFeatureAction_OverrideMovementCurves : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Curves")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Curves")
	FOverrideMovementCurveData CurveData;

	UPROPERTY(EditDefaultsOnly, Category="Curves")
	int32 Priority;

};

