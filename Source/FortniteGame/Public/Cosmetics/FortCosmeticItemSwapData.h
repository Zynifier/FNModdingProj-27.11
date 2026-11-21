// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Cosmetics/Extensibility/FortCosmeticItemAdditionalData.h"
#include "Cosmetics/Variants/FortAppliedSwapItemAndVariantStateEnum.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticItemSwapData.generated.h"

USTRUCT()
struct FFortCosmeticPresetSwapData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCosmeticPresetSwapData")
	TArray<FFortSwapItemAndVariantData> Swaps;

	UPROPERTY(EditAnywhere, Category="FortCosmeticPresetSwapData")
	FGuid SwapId;

	UPROPERTY(EditAnywhere, Category="FortCosmeticPresetSwapData")
	EFortAppliedSwapItemAndVariantState SwapState;

};

UCLASS(MinimalAPI)
class UFortCosmeticItemSwapData : public UFortCosmeticItemAdditionalData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCosmeticItemSwapData")
	TArray<FFortCosmeticPresetSwapData> SwapPresets;

};

