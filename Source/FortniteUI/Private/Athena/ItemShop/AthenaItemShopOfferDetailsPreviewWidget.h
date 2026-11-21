// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "Engine/DataTable.h"
#include "Athena/ItemShop/AthenaItemShopOfferDetailsWidgetBase.h"
#include "Context/FortFrontEndContext.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaItemShopOfferDetailsPreviewWidget.generated.h"

class UAthenaCosmeticUnlockingInfo;
class UAthenaItemShopOfferInspectionNavigator;
class UAthenaItemShopSection;
class UFortAccountItemDefinition;
class UFortAthenaReward;
class UFortCTAButton;
class UFortItem;
class UFortItemBaseWidget;
class UFortItemPreviewScreen;
class UFortStoreSkinDetailsPopup;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopOfferDetailsPreviewWidget : public UAthenaItemShopOfferDetailsWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetupNavigationForSection(UAthenaItemShopSection* SectionToNavigate);

protected:
	UFUNCTION(BlueprintCallable, Category="Focusing")
	void FocusOnWidget(UWidget* WidgetToFocus);

	UFUNCTION(BlueprintPure)
	bool GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const;

	UFUNCTION(BlueprintCallable, Category="AthenaItemShopOfferDetails")
	FUnlockableVariantPreviewInfo GetVariantPreviewInfo();

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void HandleBackAction();

	UFUNCTION(BlueprintCallable, Category="Currency")
	void HandleGetVBucksClicked();

	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType InputType);

	UFUNCTION()
	void HandleItemShown(const UFortAccountItemDefinition* AccountItemDef);

	UFUNCTION(BlueprintPure)
	bool IsMultiplePriceRealMoneyOffer() const;

	UFUNCTION(BlueprintPure)
	bool IsSingleItemEquipped() const;

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void OnUpdateItemRestrictionCallout(bool bShouldShow, const FText& RestrictionText);

	UFUNCTION(BlueprintImplementableEvent, Category="AthenaItemShopOfferDetails")
	void OnVariantPreviewInfoUpdated();

	UFUNCTION(BlueprintCallable)
	void RefreshFocus();

	UFUNCTION(BlueprintCallable)
	void RegisterItemRewardInteraction(UFortAthenaReward* InItemReward);

	UFUNCTION(BlueprintCallable)
	void SetIsPurchasing(bool bInIsPurchasing);

	UFUNCTION(BlueprintCallable)
	void SetItemToRepresent(const UFortItem* InItemToRepresent);

	UFUNCTION(BlueprintPure, Category="AthenaItemShopOfferDetails")
	bool ShouldDisplayOfferPurchasedOverlay() const;

	UFUNCTION(BlueprintCallable)
	void ShowItemFromItemReward(UFortAthenaReward* InItemReward);

	UFUNCTION(BlueprintCallable)
	void TriggerPurchaseChoiceRequest();

	UFUNCTION(BlueprintCallable)
	void TryDismiss();

	UFUNCTION(BlueprintCallable)
	void UpdatePreviewFromOffer();

	UFUNCTION(BlueprintCallable)
	void UpdateSwipeButtonsVisibility();

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferDetailsPreviewWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaItemShopOfferDetailsPreviewWidget")
	int32 VariantIndex;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferDetailsPreviewWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortItemPreviewScreen> ItemPreview_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferDetailsPreviewWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortItemBaseWidget> Item_InfoHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaCosmeticUnlockingInfo> UnlockingInfo;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferDetailsPreviewWidget")
	float TimeBetweenVariantsRestart;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopOfferDetailsPreviewWidget")
	float TimeBetweenVariants;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(Transient)
	TArray<FFortCosmeticVariantPreview> CachedVariantPreviews;

	UPROPERTY(Transient)
	FUnlockableVariantPreviewInfo VariantPreviewInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferDetailsPreviewWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopOfferInspectionNavigator> OfferNavigator_ArrowNavigation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortStoreSkinDetailsPopup> StorePopup_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopOfferDetailsPreviewWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_Gift;

};

