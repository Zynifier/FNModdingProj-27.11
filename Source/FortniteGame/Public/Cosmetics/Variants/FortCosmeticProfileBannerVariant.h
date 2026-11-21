// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "FortCosmeticProfileBannerVariant.generated.h"

class UMaterialInterface;

UCLASS(HideCategories=("Cosmetic", "Variant"))
class UFortCosmeticProfileBannerVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Banner Variant")
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;

	UPROPERTY(EditAnywhere, Category="Banner Variant")
	FName BannerIconParamName;

	UPROPERTY(EditAnywhere, Category="Banner Variant")
	FName BannerPrimaryColorParamName;

	UPROPERTY(EditAnywhere, Category="Banner Variant")
	FName BannerSecondaryColorParamName;

	UPROPERTY(EditAnywhere, Category="Banner Variant")
	FName CC_PrimaryColorParamName;

};

