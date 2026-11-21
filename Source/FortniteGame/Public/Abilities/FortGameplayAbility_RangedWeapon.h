// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_RangedWeapon.generated.h"

class AFortWeaponRanged;

UCLASS(MinimalAPI)
class UFortGameplayAbility_RangedWeapon : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float FiringNoiseRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float FlyByNoiseRange;

	UPROPERTY(BlueprintReadOnly, Category="Animation")
	TObjectPtr<AFortWeaponRanged> CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayCue", meta=(Categories="GameplayCue"))
	FGameplayTagContainer WeaponFireCue;

};

