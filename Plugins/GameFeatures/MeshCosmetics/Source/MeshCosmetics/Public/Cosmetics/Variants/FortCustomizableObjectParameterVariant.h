// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "Cosmetics/Variants/FortCustomizableObjectVariantTypes.h"
#include "FortCustomizableObjectParameterVariant.generated.h"

class AActor;

UCLASS(MinimalAPI)
class UFortCustomizableObjectParameterVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant", meta=(TitleProperty="VariantName"))
	TArray<FCustomizableObjectParamsVariantDef> ParameterOptions;

private:
	UFUNCTION(BlueprintCallable, Category="MeshCosmetics")
	static void ApplyVariants(AActor* Actor, const FFortAthenaLoadout& Loadout);

};

