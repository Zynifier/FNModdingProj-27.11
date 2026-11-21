// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_LoadPrimaryDataAssets.generated.h"

UCLASS(meta=(DisplayName="Load Primary Assets in Editor"))
class UFortGameFeatureAction_LoadPrimaryDataAssets : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Asset Manager")
	TArray<FName> AdditionalPrimaryAssetTypesToLoad;

};

