// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "Online/FortMcpTypes.h"
#include "FortSeasonLevelConfirmationScreen.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class USizeBox;
class UWidget;

UCLASS(Abstract, MinimalAPI)
class UFortSeasonLevelConfirmationScreen : public UFortItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPurchaseFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetsRefreshed();

private:
	UFUNCTION(BlueprintPure)
	bool CanAffordTierBundlePurchase() const;

	UFUNCTION(BlueprintPure)
	bool CanAffordTierPurchase() const;

	UFUNCTION()
	void HandleCloseScreen(bool& bPassThrough);

	UFUNCTION()
	void HandlePurchaseComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems, const FString& OfferId);

	UPROPERTY(EditAnywhere, Category="FortSeasonLevelConfirmationScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseScreenRowHandle;

	UPROPERTY(Transient)
	FGameplayTag SpatialCamera;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_IncreasePurchaseTier;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_DecreasePurchaseTier;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TierBundleOffer_Header;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RewardCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PurchasePrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TierBundleOriginalPrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TierBundlePurchasePrice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RefundDisclaimer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="FortAthenaReward"))
	TObjectPtr<UDynamicEntryBox> EntryBox_RewardIcons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSeasonLevelConfirmationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Purchase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSeasonLevelConfirmationScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TierBundlePurchase;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SB_TierBundle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_TierBundleWarning;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonLevelConfirmationScreen")
	FText RefundDisclaimerSingleOffer;

	UPROPERTY(EditDefaultsOnly, Category="FortSeasonLevelConfirmationScreen")
	FText RefundDisclaimerMultipleOffer;

};

