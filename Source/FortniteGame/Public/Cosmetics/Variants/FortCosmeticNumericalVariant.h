// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "FortCosmeticNumericalVariant.generated.h"

class UMaterialInterface;

UCLASS(MinimalAPI)
class UFortCosmeticNumericalVariant : public UFortCosmeticVariant
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	int32 DefaultStartingNumeric;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	int32 MinNumericalValue;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	int32 MaxNumbericalValue;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	FName ZerosDigitParamName;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	FName TensDigitParamName;

	UPROPERTY(EditAnywhere, Category="Cosmetic Variant")
	TArray<TSoftObjectPtr<UMaterialInterface>> MaterialsToAlter;

};

