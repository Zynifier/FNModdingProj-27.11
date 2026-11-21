// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotify_PlayNiagaraEffect.h"
#include "FortAnimNotify_PlayNiagaraVariantEffect.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Object"), meta=(DisplayName="Variant Aware Burst Niagara Effect"))
class UFortAnimNotify_PlayNiagaraEffectVariant : public UAnimNotify_PlayNiagaraEffect
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="NiagaraSystem")
	TObjectPtr<UAthenaCosmeticItemDefinition> CosmeticDefContainingVariants;

	UPROPERTY(EditAnywhere, Category="FortAnimNotify_PlayNiagaraEffectVariant")
	bool bAddToPawnHighlightSet;

};

