// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortRarityData.h"
#include "FortItemSeriesDefinition.generated.h"

class UMaterialInterface;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType)
class UFortItemSeriesDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Display")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FFortColorPalette Colors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> BackgroundTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UMaterialInterface> ItemCardMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	TSoftObjectPtr<UMaterialInterface> BackgroundMaterial;

};

