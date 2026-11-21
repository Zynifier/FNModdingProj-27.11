// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"
#include "Online/FortMcpTypes.h"
#include "AthenaItemShopPurchaseOverlayModal.generated.h"

class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaItemShopPurchaseOverlayModal : public UAthenaItemShopOfferDetailsWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION(BlueprintPure)
	const TArray<FPurchasedItemInfo>& GetPurchasedItems() const;

	UFUNCTION(BlueprintPure)
	int32 GetQuantityPurchased() const;

	UFUNCTION(BlueprintPure)
	bool HasMultipleItems() const;

	UFUNCTION(BlueprintImplementableEvent)
	void InitBundleLayout();

	UFUNCTION(BlueprintPure)
	bool IsLastItem(int32 ItemIndex) const;

	UFUNCTION(BlueprintPure)
	bool ShouldShowAsRefund() const;

private:
	UPROPERTY(Transient)
	TArray<FPurchasedItemInfo> PurchasedItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_SuccessfullyPurchased;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_SuccessfullyRefunded;

};

