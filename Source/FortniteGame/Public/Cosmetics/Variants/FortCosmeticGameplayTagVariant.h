// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticGameplayTagVariant.generated.h"

USTRUCT()
struct FGameplayTagVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Variant Def")
	FCosmeticMetaTagContainer MetaTags;

};

UCLASS(MinimalAPI)
class UFortCosmeticGameplayTagVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(TitleProperty="VariantName"))
	TArray<FGameplayTagVariantDef> GenericTagOptions;

};

