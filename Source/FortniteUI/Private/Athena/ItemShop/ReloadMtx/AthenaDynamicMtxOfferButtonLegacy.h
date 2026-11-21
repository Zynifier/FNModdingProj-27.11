// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ItemShop/ReloadMtx/AthenaMtxOfferButtonBaseLegacy.h"
#include "AthenaDynamicMtxOfferButtonLegacy.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UAthenaDynamicMtxOfferButtonLegacy : public UAthenaMtxOfferButtonBaseLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DynamicMtxAmount;

};

