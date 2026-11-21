// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "Abilities/FortGameplayAbility_ScoutDrone_TargetingBase.h"
#include "ScoutDroneTypes.h"
#include "FortGameplayAbility_ScoutDrone_PickUp.generated.h"

class UGameplayEffect;
class UScoutDronePickUpTargetsPayload;

UCLASS()
class UFortGameplayAbility_ScoutDrone_PickUp : public UFortGameplayAbility_ScoutDrone_TargetingBase
{
	GENERATED_BODY()

private:
	UFUNCTION(Server, Reliable)
	void ServerConfirmTargets();

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	FScalableFloat MaxNumberOfItemsToGrab;

	UPROPERTY(Transient)
	TObjectPtr<UScoutDronePickUpTargetsPayload> PayloadCache;

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	FScalableFloat PickupToggleCooldownDuration;

	UPROPERTY(EditDefaultsOnly, Category="Pickup")
	TSubclassOf<UGameplayEffect> AttachedPawnGEClass;

};

UCLASS(BlueprintType)
class SCOUTDRONERUNTIME_API UScoutDronePickUpTargetsPayload : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ScoutDronePickUpTargetsPayload")
	FScoutDronePickupTargets PickUpTargets;

};

