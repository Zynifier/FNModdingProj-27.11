// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "FortCosmeticFloatSliderVariant.generated.h"

class UFXSystemAsset;
class UFortChallengeBundleItemDefinition;
class UMaterialInterface;

UCLASS(MinimalAPI)
class UFortCosmeticFloatSliderVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	float DefaultStartingValue;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	float MinParamValue;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	float MaxParamValue;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> UnlockChallengeBundle;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	FName MaterialParamName;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	FName ParticleParamName;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	TArray<TSoftObjectPtr<UFXSystemAsset>> ParticleSystemsToAlter;

};

