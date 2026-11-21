// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticVariantApplyWrap.generated.h"

UCLASS(MinimalAPI)
class UFortCosmeticVariantApplyWrap : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(ShowOnlyInnerProperties, TitleProperty="VariantName"))
	FApplyWrapVariantDef WrapVariant;

};

