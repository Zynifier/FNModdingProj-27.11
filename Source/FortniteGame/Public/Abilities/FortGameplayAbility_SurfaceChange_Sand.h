// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_SurfaceChange_Sand.generated.h"

class UGameplayEffect;

UCLASS()
class UFortGameplayAbility_SurfaceChange_Sand : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddSnareStack();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void StartSnareMonitor();

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FActiveGameplayEffectHandle SnareGEHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	TSubclassOf<UGameplayEffect> SnareGameplayEffectClass;

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayAbility_SurfaceChange_Sand")
	bool bIsPawnOnGround;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FScalableFloat RequiresSandEnabled;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FGameplayTag SandEnabledTag;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FGameplayTagContainer TagsThatBlockSnare;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FScalableFloat MinAccelerationToPreventSnareStack;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayAbility_SurfaceChange_Sand")
	FScalableFloat MaxWaterDepthToApplySnare;

};

