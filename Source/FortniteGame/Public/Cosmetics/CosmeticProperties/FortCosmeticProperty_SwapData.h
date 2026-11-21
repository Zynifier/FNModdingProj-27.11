// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "CosmeticPropertyBase.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCosmeticProperty_SwapData.generated.h"

USTRUCT(BlueprintType)
struct FFortCosmeticProperty_SwapData : public FCosmeticPropertyBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCosmeticProperty_SwapData")
	TArray<FFortSwapItemAndVariantData> Swaps;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortCosmeticProperty_SwapData")
	FGuid SwapId;

};

