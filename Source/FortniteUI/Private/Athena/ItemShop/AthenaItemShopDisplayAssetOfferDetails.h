// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"
#include "Online/FortMcpTypes.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "AthenaItemShopDisplayAssetOfferDetails.generated.h"

class UAthenaItemShopOfferDetailsWidgetBase;
class UCommonButtonBase;
class UFortCTAButton;
class UScrollBox;
class UWidget;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UAthenaItemShopDisplayAssetOfferDetails : public UAthenaItemShopOfferDetailsWidgetBase, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePurchaseClicked();

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

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPurchaseConfirmation();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowPurchasedOverlay(int32 QuantityPurchased, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePurchaseBlocked(bool bIsBlocked, const FText& PurchaseNotAllowedReason);

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchaseFocusWidget;

private:
	UFUNCTION(BlueprintCallable)
	void AttemptPurchase();

	UFUNCTION(BlueprintCallable)
	void ClearActionOnPurchaseButton();

	UFUNCTION(BlueprintCallable)
	void DeclineMtxPurchase();

	UFUNCTION(BlueprintPure)
	UWidget* GetFirstFocusableButton() const;

	UFUNCTION()
	void HandleBackAction();

	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType CommonInput);

	UFUNCTION()
	void HandleItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandleLegalTextAction();

	UFUNCTION()
	void HandleMtxPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION(BlueprintCallable)
	void RequestMtxPurchase();

	UFUNCTION(BlueprintCallable)
	void SetCanPurchase(bool bInCanPurchase);

	UFUNCTION(BlueprintCallable)
	void SetPurchaseActionOnPurchaseButton();

	UFUNCTION(BlueprintCallable)
	void SetVBuckActionOnPurchaseButton();

	UFUNCTION(BlueprintCallable)
	void ShowLegalTextInPopup(const FText& ItemName, const FText& LegalText);

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PurchaseAction;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle VBuckAction;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ReloadMtxAction;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle LegalTextAction;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopDisplayAssetOfferDetails")
	TSubclassOf<UAthenaItemShopOfferDetailsWidgetBase> ItemInspectScreenClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_SendGift;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Inspect;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MTX;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> Container_SimpleMTXDisplay;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopDisplayAssetOfferDetails", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Details;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

};

