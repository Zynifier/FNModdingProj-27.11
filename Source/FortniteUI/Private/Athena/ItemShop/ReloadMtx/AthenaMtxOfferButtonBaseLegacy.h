// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Online/FortMcpTypes.h"
#include "AthenaMtxOfferButtonBaseLegacy.generated.h"

class UCommonLoadGuard;
class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UFortStoreFrontOfferInfo;
class UImage;

UCLASS(Abstract)
class UAthenaMtxOfferButtonBaseLegacy : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OfferData;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MtxAmount;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RealMoneyPrice;

private:
	UFUNCTION()
	void HandleMtxPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> OptionalSwitcher_CurrencyIcons;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> OptionalIMG_StarterKit;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> LoadGuardCurrencySpinner;

};

