// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortAbilityTargetSelection.h"
#include "FortGameplayEffectContainerSpec.generated.h"

USTRUCT(BlueprintType)
struct FFortGameplayEffectContainerSpec
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayEffectContainer")
	FFortAbilityTargetSelectionList TargetSelection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayEffectContainer")
	TArray<FGameplayEffectSpecHandle> TargetGameplayEffectSpecs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayEffectContainer")
	TArray<FGameplayEffectSpecHandle> OwnerGameplayEffectSpecs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayEffectContainer", meta=(Categories="GameplayCue"))
	FGameplayTagContainer ActivationCues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameplayEffectContainer", meta=(Categories="GameplayCue"))
	FGameplayTagContainer ImpactCues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float ImpactNoiseRange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AI", meta=(ClampMin="0", UIMin="0"))
	float FlyByNoiseRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer")
	bool bOverrideChargeMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameplayEffectContainer", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="bOverrideChargeMagnitude"))
	float ChargeMagnitudeOverrideValue;

};

