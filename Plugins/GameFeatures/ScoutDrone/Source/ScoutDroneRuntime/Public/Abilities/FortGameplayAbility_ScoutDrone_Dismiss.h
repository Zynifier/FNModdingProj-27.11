// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "ScoutDroneTypes.h"
#include "FortGameplayAbility_ScoutDrone_Dismiss.generated.h"

class AFortScoutDrone;

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayAbility_ScoutDrone_Dismiss : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	AFortScoutDrone* GetControlledDrone();

private:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_ScoutDrone_Dismiss")
	FScoutDroneDeferredDestructionData DismissDelayData;

};

