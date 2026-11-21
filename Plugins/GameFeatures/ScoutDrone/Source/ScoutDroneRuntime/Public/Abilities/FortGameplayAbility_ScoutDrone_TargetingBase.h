// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "ScalableFloat.h"
#include "Types/TargetingSystemTypes.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_ScoutDrone_TargetingBase.generated.h"

class UTargetingPreset;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortGameplayAbility_ScoutDrone_TargetingBase : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnTargetsFound"))
	void BP_OnTargetsFound(const FTargetingRequestHandle& TargetingHandle);

	UFUNCTION(BlueprintCallable)
	void StartTargeting();

	UFUNCTION(BlueprintCallable)
	void StopTargeting();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Targeting")
	TObjectPtr<UTargetingPreset> TargetingPreset;

private:
	UPROPERTY(Transient)
	FTargetingRequestHandle AsyncTargetingHandle;

	UPROPERTY(Transient)
	FTimerHandle TargetingTimerHandle;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	FScalableFloat TargetingInterval;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	bool bUseControllerAsInstigator;

};

