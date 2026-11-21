// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "FortControllerEffectApplyGameplayEffect.generated.h"

class UGameplayEffect;

UCLASS(Abstract, AutoCollapseCategories=("Parameters"))
class UFortControllerEffect_ApplyGameplayEffectBase : public UFortControllerEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float EffectLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parameters")
	bool bSetMagnitudeFromParameter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Parameters", meta=(Categories="SetByCaller", EditCondition="bSetMagnitudeFromParameter"))
	FGameplayTag ParameterName;

};

UCLASS(AutoCollapseCategories=("Parameters", "Parameters"), meta=(DisplayName="Effect: Apply Gameplay Effect"))
class UFortControllerEffect_ApplyGameplayEffect : public UFortControllerEffect_ApplyGameplayEffectBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameters", meta=(EditCondition="bSetMagnitudeFromParameter"))
	FScalableFloat ParameterQuantity;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(EditCondition="bSetMagnitudeFromParameter"))
	FString AnalyticsEventAttributeName;

};

UCLASS(AutoCollapseCategories=("Parameters", "Parameters"), meta=(DisplayName="Effect: Heal Player"))
class UFortControllerEffect_HealPlayer : public UFortControllerEffect_ApplyGameplayEffectBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameters", meta=(EditCondition="bSetMagnitudeFromParameter"))
	FScalableFloat HealthRestoreQuantity;

};

UCLASS(AutoCollapseCategories=("Parameters", "Parameters"), meta=(DisplayName="Effect: Shield Player"))
class UFortControllerEffect_ShieldPlayer : public UFortControllerEffect_ApplyGameplayEffectBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameters", meta=(EditCondition="bSetMagnitudeFromParameter"))
	FScalableFloat ShieldRestoreQuantity;

};

