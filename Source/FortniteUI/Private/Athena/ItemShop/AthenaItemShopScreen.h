// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Layout/Margin.h"
#include "Online/FortMcpTypes.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "AthenaItemShopScreen.generated.h"

class ADynamicBackgroundDirector;
class UAthenaItemShopDisplayAssetOfferDetails;
class UAthenaItemShopOfferDetailsPreviewWidget;
class UAthenaItemShopRefreshTimerButton;
class UAthenaItemShopSectionNavigator;
class UAthenaScrollBox;
class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UDynamicEntryBox;
class UFortActivatableMovieWidget;
class UFortAffilateModal;
class UFortMtxStoreSelectionPopup;
class UImage;
class UInvalidationBox;
class UOverlay;
class UVerticalBox;
class UWidget;
class UWidgetAnimation;
enum class EItemShopNavigationAction : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaItemShopScreen : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NavigateToOffer(const FString& OfferId, EItemShopNavigationAction NavigationAction);

protected:
	UFUNCTION(BlueprintCallable)
	void EnableShopNavigation(bool bIsNavigationEnabled);

	UFUNCTION()
	void HandleUserMouseUp(float ScrollAmount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEstablishingSections();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNoOfferVideo();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSectionsEstablished(bool bEmpty);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpecialOfferVideoFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpecialOfferVideoSkipped();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpecialOfferVideoStarted();

	UFUNCTION(BlueprintCallable)
	void PlayIntroAnimation(UWidgetAnimation* IntroAnimation);

private:
	UFUNCTION()
	void HandlePurchaseOfferComplete(bool bSuccess, const TArray<FPurchasedItemInfo>& PurchasedItems);

	UPROPERTY(EditInstanceOnly, Category="AthenaItemShopScreen")
	bool bShowAvailableMTXBalance;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	FString AffiliateSourceName;

	UPROPERTY(EditAnywhere, Category="Primary Content Settings")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	FMargin SectionsPadding;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextCategoryInputAction;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PrevCategoryInputAction;

	UPROPERTY(EditAnywhere, Category="Item Inspection")
	TSoftClassPtr<UAthenaItemShopOfferDetailsPreviewWidget> ItemShopOfferDetailsScreenClass;

	UPROPERTY(EditAnywhere, Category="Item Inspection")
	TSoftClassPtr<UAthenaItemShopDisplayAssetOfferDetails> ItemShopDisplayAssetOfferDetailsClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	TSubclassOf<UFortAffilateModal> AffiliateModalClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	TSubclassOf<UFortMtxStoreSelectionPopup> StoreSelectionPopupClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	float ScrollThreshold;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAffilateModal> AffiliateModal;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMtxStoreSelectionPopup> StoreSelectionPopup;

	UPROPERTY(Transient)
	TObjectPtr<UWidgetAnimation> LastPlayedIntroAnimation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_NavigationControl;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaScrollBox> ScrollBox_Sections;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Sections;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UInvalidationBox> InvalidationBox_ItemShop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_AvailableAmount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopSectionNavigator> Navigator_ShopSections;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SectionsPips;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopScreen", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SupportACreator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ScrollToTop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_InGameScrollToTop;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackToGame;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemShopRefreshTimerButton> Button_RefreshTimerInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopScreen", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_RefreshTimerButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DefaultBackground;

	UPROPERTY(EditAnywhere, Category="AthenaItemShopScreen")
	TSubclassOf<UFortActivatableMovieWidget> SpecialOfferVideoPlayerClass;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_SectionsPips;

	UPROPERTY(BlueprintReadWrite, Category="AthenaItemShopScreen", meta=(AllowPrivateAccess="true"))
	TWeakObjectPtr<ADynamicBackgroundDirector> ItemShopBackgroundDirector;

	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopScreen")
	TSoftClassPtr<UCommonActivatableWidget> RefreshTimerInfoModalClass;

};

