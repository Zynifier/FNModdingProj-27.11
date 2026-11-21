// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ItemShop/ReloadMtx/AthenaMtxOfferButtonBaseLegacy.h"
#include "AthenaStaticMtxOfferButtonLegacy.generated.h"

class UCommonTextBlock;
class UHorizontalBox;
class USizeBox;

UCLASS(Abstract)
class UAthenaStaticMtxOfferButtonLegacy : public UAthenaMtxOfferButtonBaseLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BonusMtxAmount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BonusPercent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HB_BonusMtxArea;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SB_BonusPercentArea;

};

