// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaSprayItemDefinition.generated.h"

class UMaterialInterface;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaSprayItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Spray")
	TSoftObjectPtr<UMaterialInterface> GetDecalMaterial() const;

	UFUNCTION(BlueprintPure, Category="Spray")
	TSoftObjectPtr<UTexture2D> GetDecalTexture() const;

	UFUNCTION(BlueprintPure, Category="Spray")
	bool ShouldUseBannerAsTexture() const;

protected:
	UPROPERTY(EditAnywhere, Category="Spray")
	TSoftObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditAnywhere, Category="Spray")
	FName ProgressiveCosmeticStatName;

	UPROPERTY(EditAnywhere, Category="Spray")
	bool bUseBannerAsTexture;

	UPROPERTY(EditAnywhere, Category="Spray", meta=(EditCondition="!bUseBannerAsTexture"))
	TSoftObjectPtr<UTexture2D> DecalTexture;

};

