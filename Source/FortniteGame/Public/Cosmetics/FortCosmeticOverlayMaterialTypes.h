// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCosmeticOverlayMaterialTypes.generated.h"

class UMaterialInterface;

USTRUCT()
struct FFortCosmeticOverlayMaterialData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPart", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<UMaterialInterface> LowQualityMaterial;

	UPROPERTY(EditAnywhere, Category="CharacterPart", meta=(AssetBundles="EquippedCosmetic"))
	TSoftObjectPtr<UMaterialInterface> HighQualityMaterial;

	bool IsEmpty() const
	{
		return LowQualityMaterial.IsNull() && HighQualityMaterial.IsNull();
	}
};

