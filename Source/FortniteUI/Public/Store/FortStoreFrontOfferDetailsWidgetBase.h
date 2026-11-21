// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Athena/FortActivatablePanelWithItemPreview.h"
#include "FortItemQuantityPair.h"
#include "Online/FortMcpContext.h"
#include "Online/FortMcpTypes.h"
#include "Store/PurchaseChoiceRequestInterface.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "FortStoreFrontOfferDetailsWidgetBase.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortAthenaReward;
class UFortItem;
class UFortItemDefinition;
class UFortMtxStoreRootBase;
class UFortPurchaseOverlayModal;
class UFortStoreFrontOfferInfo;
class UFortVariantPicker;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBattlePassPurchaseComplete, bool, bSuccess);

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class FORTNITEUI_API UFortStoreFrontOfferDetailsWidgetBase : public UFortActivatablePanelWithItemPreview, public IFortHUDShutdownTimerInterface, public IPurchaseChoiceRequesterInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase", meta=(DisplayName="On Offer Set"))
	void BP_OnOfferSet();

	UFUNCTION(BlueprintCallable)
	static bool FindItemQuantityPair(UFortItemDefinition* ItemDefinition, UPARAM(ref) TArray<FFortItemQuantityPair>& InItemQuantityPairs, FFortItemQuantityPair& OutItemQuantity);

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferDetailsWidgetBase")
	UFortStoreFrontOfferInfo* GetOfferInfo() const;

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	UFortStoreFrontOfferInfo* GetOfferInfoById(const FString& OfferId);

	UFUNCTION(BlueprintCallable)
	void HandleBattlePassPurchaseComplete(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void HideUndoInBottomBar();

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void OnUpdateStatus();

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void PurchaseAmountLeft();

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void PurchaseAmountRight();

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void RefreshOfferInfo();

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void RefreshUndoState(UFortStoreFrontOfferInfo* OfferPurchased);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void RequestExternalPurchase(int32 PriceIndex = -1, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SendingToMainStore();

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SendRealMoneyStoreInteractionAnalytic(const FString& Interaction) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortDirectAcquisitionOfferWidgetBase")
	void SendReloadMtxPurchaseSKUAnalytic() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortDirectAcquisitionOfferWidgetBase")
	void SendSeasonPassInteractionAnalytic(const FString& Interaction) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SendShopInteractionAnalytic(const FString& Interaction, const float HoldTime = 0.000000f) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SendUndoMtxReturnedAnalytic(const FString& Interaction, const FString PurchaseID, const int32 MtxReturned) const;

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SetIsInItemViewMode(const bool Value);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SetPagedItems(const TArray<UFortStoreFrontOfferInfo*>& InPagedItems);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SetShouldAllowItemViewModeAction(const bool Value);

	UFUNCTION(BlueprintCallable)
	void SetStoreRoot(UFortMtxStoreRootBase* InStoreRoot);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SetupOffer(UFortStoreFrontOfferInfo* InOfferData);

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferDetailsWidgetBase")
	bool ShouldDisplayOfferPurchasedOverlay() const;

	UFUNCTION(BlueprintPure, Category="FortStoreFrontOfferDetailsWidgetBase")
	bool ShouldHavePurchaseConfirmation() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ShowUndoInBottomBar();

protected:
	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void ConfirmUndo();

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void DeactivateUndoButton();

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	int32 GetPriceIndexToShow();

	UFUNCTION()
	void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

	UFUNCTION()
	void HandleVaultItemsViewed(const TArray<UFortItem*>& ItemsShown);

	UFUNCTION(BlueprintCallable, Category="Experiment")
	bool IsReloadMtxEnabled();

	UFUNCTION()
	void OnEnterViewModeActionCommitted(bool& PassThrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchasingStarted();

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void OnUpdateItemRestrictionCallout(bool bShouldShow, const FText& RestrictionText);

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void OnVariantChanged(FGameplayTag VariantChannel, FGameplayTag VariantTag, const FString& VariantCustomData, bool IsOwned);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void PurchaseOffer(const FOnPurchaseOfferComplete& Callback, int32 Quantity, const float HoldTime);

	UFUNCTION(BlueprintCallable, Category="CyclingVariants")
	void RegisterItemRewardInteraction(UFortAthenaReward* InItemReward);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void SendRealMoneyPurchase(int32 PriceIndex = 0, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable)
	void SetItemRewardSecondaryItem(const UFortItemDefinition* ItemDef, TArray<FFortItemQuantityPair> AllItemQuantityPairs, UFortAthenaReward* RewardWidget);

	UFUNCTION(BlueprintCallable, Category="CyclingVariants")
	void SetSecondaryItem(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void ShowItemPresentationScreen(const TArray<FPurchasedItemInfo>& PurchasedItems);

	UFUNCTION(BlueprintCallable, Category="FortStoreFrontOfferDetailsWidgetBase")
	void ShowPurchasedOverlayWidget(int32 QuantityPurchased, const TArray<FPurchasedItemInfo> PurchasedItems, bool bShowAsRefund, const FString OfferId);

	UFUNCTION(BlueprintCallable, Category="Currency")
	void ShowReloadMtx();

	UFUNCTION(BlueprintCallable, Category="CyclingVariants")
	void ShowVaultItem(const UFortItem* InItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="CyclingVariants")
	void ShowVaultItemFromItemReward(UFortAthenaReward* InItemReward);

	UFUNCTION(BlueprintImplementableEvent, Category="FortStoreFrontOfferDetailsWidgetBase")
	void UpdateItemViewModeBP();

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle EnterViewModeInputActionRowHandle;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreFrontOfferDetailsWidgetBase")
	bool IsInItemViewMode;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreFrontOfferDetailsWidgetBase")
	bool ShouldAllowItemViewModeAction;

	UPROPERTY(BlueprintReadWrite, Category="FortStoreFrontOfferDetailsWidgetBase")
	bool bImmediatelyPurchased;

	UPROPERTY(BlueprintReadOnly, Category="FortStoreFrontOfferDetailsWidgetBase")
	TArray<TObjectPtr<UFortStoreFrontOfferInfo>> PagedItems;

	UPROPERTY()
	TObjectPtr<UFortStoreFrontOfferInfo> OfferData;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortStoreFrontOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortVariantPicker> Picker_VariantSelector;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextUndoAvailability;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortStoreFrontOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UndoBottomBarWarning;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Undo;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortStoreFrontOfferDetailsWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CosmeticWarning;

private:
	UFUNCTION()
	void HandleGiftingItemPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UFUNCTION()
	void HandleRealMoneyPurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(EditAnywhere, Category="FortStoreFrontOfferDetailsWidgetBase")
	TSubclassOf<UFortPurchaseOverlayModal> PurchaseModalClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> SecondaryItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="FortStoreFrontOfferDetailsWidgetBase")
	float TimeBetweenVariantsRestart;

	UPROPERTY(EditDefaultsOnly, Category="FortStoreFrontOfferDetailsWidgetBase")
	float TimeBetweenVariants;

	UPROPERTY(Config)
	bool bShowRefundWarningWhileMatchmaking;

	UPROPERTY(Config)
	bool bShowRefundWarningWhileInZone;

};

