// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_OverrideDestructionEffectAssets.generated.h"

class UMaterialInterface;
class UNiagaraSystem;

UCLASS(meta=(DisplayName="Override Destruction Effect Assets"))
class UFortGameFeatureAction_OverrideDestructionEffectAssets : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UMaterialInterface> DynamicDestructionMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic Destruction", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UNiagaraSystem> DynamicDestructionNiagaraSystem;

};

