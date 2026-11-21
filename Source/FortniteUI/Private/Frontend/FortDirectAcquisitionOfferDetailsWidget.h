// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Store/FortStoreFrontOfferDetailsWidgetBase.h"
#include "FortDirectAcquisitionOfferDetailsWidget.generated.h"

class UAthenaItemShopOfferInspectionNavigator;
class UCommonButtonLegacy;
class UFortCommunityVotingAvailableVotesWidget;
class UFortCommunityVotingFeedback;
class UFortCommunityVotingThanksPopup;
class UFortCommunityVotingVoteCounter;
class UFortItemBaseWidget;
class UFortStoreSkinDetailsPopup;
class UOverlay;
class UWidget;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDirectAcquisitionOfferDetailsWidget : public UFortStoreFrontOfferDetailsWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="DirectAcquisitionOfferDetailsWidget")
	void Dismiss();

	UFUNCTION(BlueprintCallable, Category="Focusing")
	void FocusOnWidget(UWidget* WidgetToFocus);

	UFUNCTION(BlueprintPure)
	bool GetSalePriceFromLastAppStore(const int32 PriceIndex, FText& SalePrice, const int32 ItemQuantity) const;

	UFUNCTION(BlueprintCallable, Category="Currency")
	void HandleGetVBucksClicked();

	UFUNCTION(BlueprintPure)
	bool IsMultiplePriceRealMoneyOffer() const;

	UFUNCTION(BlueprintCallable)
	void TriggerPurchaseChoiceRequest();

	UFUNCTION(BlueprintCallable, Category="DirectAcquisitionOfferDetailsWidget")
	void UpdateSwipeButtonsVisibility();

	UFUNCTION(BlueprintCallable, Category="VotingOfferDetails")
	void UpdateVoteCounter();

	UPROPERTY(EditAnywhere, Category="FortDirectAcquisitionOfferDetailsWidget")
	TSubclassOf<UFortCommunityVotingFeedback> VoteFeedbackClass;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortDirectAcquisitionOfferDetailsWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortItemBaseWidget> Item_InfoHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CastVote;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingVoteCounter> FlameCounter;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingAvailableVotesWidget> AvailableSparksWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> ComVoteFeedbackContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDirectAcquisitionOfferDetailsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SendGift;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_MtxAndVote;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingThanksPopup> Com_ThanksForVotingMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDirectAcquisitionOfferDetailsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopOfferInspectionNavigator> OfferNavigator_ArrowNavigation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortStoreSkinDetailsPopup> StorePopup_Details;

};

