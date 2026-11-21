// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "Online/FortMcpTypes.h"
#include "Store/FortStoreFrontOfferDetailsWidgetBase.h"
#include "FortRealMoneyOfferDetails.generated.h"

class UCommonButtonBase;
class UFortCTAButton;
class UFortStoreFrontOfferDetailsWidgetBase;
class UScrollBox;
class UWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortRealMoneyOfferDetails : public UFortStoreFrontOfferDetailsWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UFortCTAButton* GetPurchaseButtonCurrent() const;

	UFUNCTION(BlueprintPure)
	bool GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const;

	UFUNCTION(BlueprintPure)
	bool IsGiftable() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSendGiftComplete(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetPurchaseButtonText();

	UFUNCTION(BlueprintCallable)
	void SendGift();

	UFUNCTION(BlueprintImplementableEvent)
	void SetMtxButtonVisible(const bool bVisible);

	UFUNCTION(BlueprintCallable)
	void ShowLegalTextInPopup(const FText& ItemName, const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPurchaseConfirmation();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPurchasedOverlay(int32 QuantityPurchased, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePurchaseBlocked(bool bIsBlocked, const FText& PurchaseNotAllowedReason);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortRealMoneyOfferDetails", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchaseFocusWidget;

private:
	UFUNCTION(BlueprintCallable)
	void ClearActionOnPurchaseButton();

	UFUNCTION(BlueprintCallable)
	void DeclineMtxPurchase();

	UFUNCTION()
	void HandleBackAction(bool& bPassthrough);

	UFUNCTION()
	void HandleItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandleMtxPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandleOnInputMethodChanged(ECommonInputType CommonInput);

	UFUNCTION(BlueprintCallable)
	void RequestMtxPurchase();

	UFUNCTION(BlueprintCallable)
	void SetCanPurchase(bool bInCanPurchase);

	UFUNCTION(BlueprintCallable)
	void SetPurchaseActionOnPurchaseButton();

	UFUNCTION(BlueprintCallable)
	void SetVBuckActionOnPurchaseButton();

	UPROPERTY(EditAnywhere, Category="FortRealMoneyOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(EditAnywhere, Category="FortRealMoneyOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PurchaseAction;

	UPROPERTY(EditAnywhere, Category="FortRealMoneyOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle VBuckAction;

	UPROPERTY(EditAnywhere, Category="FortRealMoneyOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ReloadMtxAction;

	UPROPERTY(EditAnywhere, Category="FortRealMoneyOfferDetails")
	TSubclassOf<UFortStoreFrontOfferDetailsWidgetBase> ItemInspectScreenClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRealMoneyOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRealMoneyOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Purchase_STW;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SendGift;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Inspect;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MTX;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> Container_SimpleMTXDisplay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRealMoneyOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Details;

};

