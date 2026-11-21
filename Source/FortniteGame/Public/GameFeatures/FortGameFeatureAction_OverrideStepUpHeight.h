// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "FortGameFeatureAction_OverrideStepUpHeight.generated.h"

UCLASS(meta=(DisplayName="Override Step Up Height"))
class UFortGameFeatureAction_OverrideStepUpHeight : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Step Up")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, Category="Step Up", meta=(ClampMin="0.000000", ForceUnits="cm", UIMin="0.000000"))
	float OverrideMaxStepUpHeight;

	UPROPERTY(EditDefaultsOnly, Category="Step Up")
	int32 Priority;

};

