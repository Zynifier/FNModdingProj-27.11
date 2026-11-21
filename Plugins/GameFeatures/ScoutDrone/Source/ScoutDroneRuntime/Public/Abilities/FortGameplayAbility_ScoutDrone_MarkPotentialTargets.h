// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility_ScoutDrone_TargetingBase.h"
#include "Components/FortControllerComponent_IndicatedActorManagement.h"
#include "FortGameplayAbility_ScoutDrone_MarkPotentialTargets.generated.h"

class AActor;

UCLASS()
class UFortGameplayAbility_ScoutDrone_MarkPotentialTargets : public UFortGameplayAbility_ScoutDrone_TargetingBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Targeting")
	void OnStartHighlightingTarget(AActor* Target);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Targeting")
	void OnStoppedHighlightingTarget(AActor* Target);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Drone Indicators")
	FIndicatedActorData IndicatedActorData;

private:
	UPROPERTY(EditDefaultsOnly, Category="Potential Target Marking")
	FScalableFloat MaxNumberOfPotentialTargets;

};

