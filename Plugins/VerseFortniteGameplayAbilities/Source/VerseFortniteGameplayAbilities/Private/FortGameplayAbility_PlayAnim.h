// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_PlayAnim.generated.h"

class UAnimMontage;

UCLASS(HideCategories=("GameplayEffects", "Damage", "Advanced", "Accuracy", "Behavior", "Mod", "ActorTracking", "AI", "Animation", "AbilityWeapon"))
class UFortGameplayAbility_PlayAnim : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Animation Info")
	TObjectPtr<UAnimMontage> MontageToPlay;

	UPROPERTY(EditDefaultsOnly, Category="Animation Info")
	float PlayRate;

private:
	UFUNCTION()
	void OnBlendOut();

	UFUNCTION()
	void OnCancelled();

	UFUNCTION()
	void OnCompleted();

	UFUNCTION()
	void OnInterrupted();

};

