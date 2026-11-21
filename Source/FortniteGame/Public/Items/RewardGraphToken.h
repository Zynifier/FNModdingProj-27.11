// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Items/FortTokenType.h"
#include "RewardGraphToken.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("FrontendPreview", "FortItemDefinition", "Functionality", "InventoryLimit", "Series", "Rating"))
class URewardGraphToken : public UFortTokenType
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CosmeticPreview")
	TSoftObjectPtr<UAthenaCosmeticItemDefinition> PrimaryCosmeticItem;

	UPROPERTY(EditAnywhere, Category="CosmeticPreview|Variants")
	TArray<FFortCosmeticVariantPreview> ItemVariantPreviews;

};

