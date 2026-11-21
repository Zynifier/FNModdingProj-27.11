// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "ScoutDroneTypes.h"
#include "FortGameplayAbility_ScoutDrone_Tether.generated.h"

UCLASS(Abstract)
class UFortGameplayAbility_ScoutDrone_Tether : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void StartCheckingDistances();

	UFUNCTION(BlueprintCallable)
	void StopCheckingDistances();

private:
	UFUNCTION()
	void OnRep_bIsInSignalLossRange();

	UFUNCTION()
	void OnRep_bIsInWarningRange();

	UPROPERTY(EditDefaultsOnly, Category="Tether Settings")
	FScalableFloat WarningRange;

	UPROPERTY(EditDefaultsOnly, Category="Tether Settings")
	FScalableFloat SignalLossRange;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsInWarningRange)
	bool bIsInWarningRange;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bIsInSignalLossRange)
	bool bIsInSignalLossRange;

	UPROPERTY(Transient)
	FTimerHandle TetheringTimerHandle;

	UPROPERTY(Transient)
	FTimerHandle TetheringReportTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_ScoutDrone_Tether")
	FScoutDroneDeferredDestructionData DismissDelayData;

};

