// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ScoutDrone_Dive.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct FFortScoutDroneDiveTransitionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dive")
	TObjectPtr<UCurveFloat> Curve;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat TransitionDuration;

};

UCLASS()
class UFortGameplayAbility_ScoutDrone_Dive : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Dive")
	void BP_OnDroneStartedDiving();

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Dive")
	void BP_OnDroneStoppedDiving();

private:
	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FFortScoutDroneDiveTransitionData EaseInData;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FFortScoutDroneDiveTransitionData EaseOutData;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat DiveUpdateInterval;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat DiveSpeedIncrease;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat MinSpeedToDive;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat MinDistToGround;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat TargetPitchToDive;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat DivingGravityScale;

	UPROPERTY(EditDefaultsOnly, Category="Dive")
	FScalableFloat MaxSpeedDivingGravityScale;

};

