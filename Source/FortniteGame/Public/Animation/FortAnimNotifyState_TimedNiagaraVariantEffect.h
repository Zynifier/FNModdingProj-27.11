// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotifyState_TimedNiagaraEffect.h"
#include "FortAnimNotifyState_TimedNiagaraVariantEffect.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object"), meta=(DisplayName="Variant Aware Timed Niagara Effect"))
class UFortAnimNotifyState_TimedNiagaraEffectVariant : public UAnimNotifyState_TimedNiagaraEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="NiagaraSystem")
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticDefContainingVariants;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_TimedNiagaraEffectVariant")
	bool bAddToPawnHightlightSet;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object"), meta=(DisplayName="Advanced Variant Aware Timed Niagara Effect"))
class UFortAnimNotifyState_TimedNiagaraEffectVariantAdvanced : public UAnimNotifyState_TimedNiagaraEffectAdvanced
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="NiagaraSystem")
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticDefContainingVariants;

	UPROPERTY(EditAnywhere, Category="FortAnimNotifyState_TimedNiagaraEffectVariantAdvanced")
	bool bAddToPawnHightlightSet;

};

