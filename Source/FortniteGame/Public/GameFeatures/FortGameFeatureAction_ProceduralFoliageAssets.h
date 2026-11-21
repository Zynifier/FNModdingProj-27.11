// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_ProceduralFoliageAssets.generated.h"

class AActor;
class UMaterialInterface;

UCLASS(MinimalAPI, meta=(DisplayName="Procedural Foliage Assets"))
class UFortGameFeatureAction_ProceduralFoliageAssets : public UGameFeatureAction
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_ProceduralFoliageAssets")
	TArray<UMaterialInterface*> FoliageMaterials;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_ProceduralFoliageAssets")
	TArray<TSubclassOf<AActor>> FoliageActorClasses;
#endif

};

