// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Online/FortMcpContext.h"
#include "Online/FortMcpTypes.h"
#include "Store/PurchaseChoiceRequestInterface.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "AthenaItemShopOfferDetailsWidgetBase.generated.h"

class UAthenaItemShopPurchaseOverlayModal;
class UCommonTextBlock;
class UFortCTAButton;
class UFortItemShopOfferVM;
class UFortStoreFrontOfferInfo;
class ULockerConfirmationModal;
class UWidget;

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaItemShopOfferDetailsWidgetBase : public UCommonActivatableWidget, public IFortHUDShutdownTimerInterface, public IPurchaseChoiceRequesterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AthenaItemShopOfferDetails")
	UFortStoreFrontOfferInfo* GetOfferInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void PurchaseAmountLeft();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void PurchaseAmountRight();

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void RefreshUndoState(UFortStoreFrontOfferInfo* OfferPurchased);

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void SetOffer(UFortStoreFrontOfferInfo* InOfferData);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails", meta=(DisplayName="On Offer Set"))
	void BP_OnSetOffer();

	UFUNCTION(BlueprintPure)
	UWidget* GetNextFocusableButton(TArray<UWidget*> Buttons, int32 InitialIndex = 0, bool bForwardDirection = true) const;

	UFUNCTION(BlueprintPure, Category="AthenaItemShopOfferDetails")
	UFortStoreFrontOfferInfo* GetOfferInfoById(const FString& OfferId) const;

	UFUNCTION()
	void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void HandleUndoAction(const float HoldTime);

	UFUNCTION(BlueprintPure)
	bool IsFocusableButton(const UWidget* InButton) const;

	UFUNCTION(BlueprintCallable, Category="Experiment")
	bool IsReloadMtxEnabled();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void OnPurchasingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPaymentLegalText(const FText& LegalText);

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void OnUndoAction();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void OnUpdateStatus();

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void PurchaseOffer(const FOnPurchaseOfferComplete& Callback, int32 Quantity, const float HoldTime);

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void RefreshOfferInfo();

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void SendRealMoneyPurchase(int32 PriceIndex = 0, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="AthenaItemShopOfferDetails")
	void SendShopInteractionAnalytic(const FString& Interaction, const float HoldTime = 0.000000f) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void SetParentOffer(const UFortItemShopOfferVM* InParentOffer);

	UFUNCTION(BlueprintPure, Category="AthenaItemShopOfferDetails")
	bool ShouldHavePurchaseConfirmation() const;

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void ShowItemPresentationScreen(const TArray<FPurchasedItemInfo>& PurchasedItems);

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	void ShowPurchasedOverlayWidget(int32 QuantityPurchased, const TArray<FPurchasedItemInfo> PurchasedItems, bool bShowAsRefund, const FString OfferId);

	UFUNCTION(BlueprintCallable, Category="Currency")
	void ShowReloadMtx();

	UPROPERTY(BlueprintReadOnly, Category="AthenaItemShopOfferDetailsWidgetBase")
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> PagedItems;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OfferData;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaItemShopOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CosmeticWarning;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextUndoAvailability;

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaItemShopOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UndoBottomBarWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Undo;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferDetailsWidgetBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle UndoAction;

private:
	UFUNCTION()
	void HandleGiftingItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(EditAnywhere, Category="AthenaItemShopOfferDetailsWidgetBase")
	TSubclassOf<UAthenaItemShopPurchaseOverlayModal> PurchaseModalClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferDetailsWidgetBase")
	TSoftClassPtr<ULockerConfirmationModal> ConfirmPurchaseModalClass;

	UPROPERTY(Config)
	bool bShowRefundWarningWhileMatchmaking;

	UPROPERTY(Config)
	bool bShowRefundWarningWhileInZone;

	UPROPERTY(Transient)
	TArray<FPurchasedItemInfo> CachedRefundedItems;

};

