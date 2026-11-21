// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticDynamicVariant.generated.h"

UCLASS(MinimalAPI)
class UFortCosmeticDynamicVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(TitleProperty="VariantName"))
	TArray<FDynamicVariantDef> DynamicOptions;

};

