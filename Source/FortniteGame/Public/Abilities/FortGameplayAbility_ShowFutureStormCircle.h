// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ShowFutureStormCircle.generated.h"

UCLASS()
class UFortGameplayAbility_ShowFutureStormCircle : public UFortGameplayAbility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_ShowFutureStormCircle")
	FScalableFloat NumCirclesToShowBeforeEnding;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_ShowFutureStormCircle")
	FScalableFloat TrackShownCirclesDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_ShowFutureStormCircle")
	FScalableFloat MaximumDuration;

};

