// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayAbility_PlayAnim.h"
#include "FortGameplayAbility_PlayAnimAndApplyEffect.generated.h"

class UGameplayEffect;
class UTargetingPreset;

UCLASS(HideCategories=("GameplayEffects", "Damage", "Advanced", "Accuracy", "Behavior", "Mod", "ActorTracking", "AI", "Animation", "AbilityWeapon"))
class UFortGameplayAbility_PlayAnimAndApplyEffect : public UFortGameplayAbility_PlayAnim
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Animation Info")
	bool bWaitForAnimNotify;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay Effect")
	TSubclassOf<UGameplayEffect> EffectToApply;

	UPROPERTY(EditDefaultsOnly, Category="Targeting")
	TObjectPtr<UTargetingPreset> TargetingPreset;

};

