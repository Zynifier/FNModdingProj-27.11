// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "UIManager/FortHUDShutdownTimerInterface.h"
#include "AthenaGiftingScreen.generated.h"

class UAthenaGiftingConfirmationScreen;
class UAthenaGiftingPriceWidget;
class UAthenaLockerItemInfo;
class UCommonActionWidget;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortGiftingSocialUserListView;
class UFortGiftingUserSearchWidget;
class UFortItemDefinition;
class UFortStoreFrontOfferInfo;
class UOverlay;
class UTileView;
enum class EFilterType : uint8;
enum class EGiftingScreenPresentationMode : uint8;

UENUM(BlueprintType)
enum class EFilterType : uint8
{
	All = 0,
	Party = 1,
};

UENUM(BlueprintType)
enum class EGiftingScreenPresentationMode : uint8
{
	ItemList = 0,
	NoContent = 1,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaGiftingScreen : public UFortItemPreviewScreen, public IFortHUDShutdownTimerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BlockScreenContent(const bool bBlockScreen, const FText& ContentBlockedText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFilterChanged(EFilterType FilterType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendSelectionChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartyListUpdated(bool bEmpty);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPresentationModeChanged(EGiftingScreenPresentationMode Mode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupFilterTabButton(UCommonButtonBase* Button, EFilterType FilterType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShownItemChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowSearchWarningText(bool bShow);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortGiftingUserSearchWidget> SearchWidget_SocialSearchWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortGiftingSocialUserListView> ListView_Recipients;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Items;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GiftingPolicy;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGiftingScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CameraControl;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OfferName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VBucksOffCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ShownItemIndex;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_NoContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_OfferItemOwnedCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Container_VBucksOffViolator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_GiftCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingPriceWidget> Widget_Price;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaLockerItemInfo> Widget_ItemInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="CommonButtonBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_FilterTabs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_FilterTabsPrevious;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_FilterTabsNext;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGiftingConfirmationScreen> ActivatableWidget_GiftingConfirmation;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGiftingScreen")
	float ItemCyclingInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaGiftingScreen", meta=(AllowPrivateAccess, RowType="/Script/CommonUIBase.CommonInputActionData"))
	FDataTableRowHandle FilterTabsPreviousAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaGiftingScreen", meta=(AllowPrivateAccess, RowType="/Script/CommonUIBase.CommonInputActionData"))
	FDataTableRowHandle FilterTabsNextAction;

	UPROPERTY(EditAnywhere, Category="AthenaGiftingScreen", meta=(MultiLine="TRUE"))
	FText RegularGiftingPolicy;

	UPROPERTY(EditAnywhere, Category="AthenaGiftingScreen", meta=(MultiLine="TRUE"))
	FText BattlePassGiftingPolicy;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UCommonButtonBase>, EFilterType> FilterMap;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> FilterGroup;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> ItemDefinitions;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> PresentedItemDefinition;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> GiftableOfferInfo;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> OptionalTokenOfferInfo;

};

