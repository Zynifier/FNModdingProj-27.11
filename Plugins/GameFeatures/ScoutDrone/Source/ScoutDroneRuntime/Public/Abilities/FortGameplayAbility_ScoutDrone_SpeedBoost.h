// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility_ScoutDrone_TargetingBase.h"
#include "FortGameplayAbility_ScoutDrone_SpeedBoost.generated.h"

class UFortBuildingWallDoorComponent;
class UGameplayEffect;

UCLASS(Abstract)
class UFortGameplayAbility_ScoutDrone_SpeedBoost : public UFortGameplayAbility_ScoutDrone_TargetingBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Damaging")
	void OnBoostedIntoActor(const FHitResult& HitResult);

	UFUNCTION(BlueprintImplementableEvent, Category="Door Bash")
	void OnDoorBashed(const FHitResult& HitResult, UFortBuildingWallDoorComponent* BashedDoor);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Door Bash", meta=(Categories="GameplayCue"))
	FGameplayTag DoorBashCueTag;

private:
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	TSubclassOf<UGameplayEffect> DamageGameplayEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	FGameplayTag DoorBashPawnLaunchGameplayCueTag;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	FScalableFloat DoorBashEnabledHotfix;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	FScalableFloat DoorBashSphereRadiusForPawnLaunch;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	FScalableFloat DoorBashScalarForPawnLaunch;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	TArray<TEnumAsByte<EObjectTypeQuery>> DoorBashCollisionTypesForPawn;

	UPROPERTY(EditDefaultsOnly, Category="Damaging")
	FScalableFloat DoorBashEnabled;

	UPROPERTY(EditDefaultsOnly, Category="Door Bash")
	FScalableFloat DamageOnBoostEnabled;

};

