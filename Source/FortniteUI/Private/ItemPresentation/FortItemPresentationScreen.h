// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Frontend/FortItemPreviewScreen.h"
#include "ItemReceived/FortItemReceivedTypes.h"
#include "Items/FortGiftBoxItemDefinition.h"
#include "Items/FortGiftBoxTypes.h"
#include "FortItemPresentationScreen.generated.h"

class UAthenaBattlePassTracker;
class UAthenaExclusiveRewardBanner;
class UCommonBorder;
class UCommonButtonBase;
class UCommonButtonGroupLegacy;
class UCommonListView;
class UCommonRichTextBlock;
class UDynamicEntryBox;
class UFortGiftBoxItem;
class UFortItem;
class UFortItemInfoPresentationWidget;
class UFortItemPresentationEntry;
class UFortItemReceivedHeaderBase;
class UImage;
class ULockerConfirmationModal;
class UNamedSlot;
class UTextBlock;
class UUserWidget;
class UWidget;
enum class EItemContextAction : uint8;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FCurrencyDataWithGiftBox
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CurrencyDataWithGiftBox")
	TArray<FCurrencyData> GiftBoxCurrencyData;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemPresentationScreen : public UFortItemPreviewScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ClearItemPreview();

	UFUNCTION(BlueprintCallable)
	void EnableUserControlOnPaidItems();

	UFUNCTION(BlueprintCallable)
	void FinishSwitchingToPaidItems();

	UFUNCTION(BlueprintCallable)
	void HandleBack();

	UFUNCTION()
	void HandleExitBattlePassPurchaseFlow();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseScreen();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCloseScreenWithoutAnimations();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayEquipButton(bool bCanEquip);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayItemsCollectedText(bool bCloseScreen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishDisplayingHotItems(bool bShowOtherRewards);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitialIconAnimation(bool bUsingListView);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeftsideContentUpdated(const UWidget* LeftSideWidget, const FCurrencyDataWithGiftBox& OutDataWithGiftBox);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwitchLeftsideContent(bool bInDefaultContent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwitchToPaidItems();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateHeaderInformation(const FFortItemHeaderInformation& HeaderInformation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemContextAction(const EItemContextAction ItemContextAction);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemEquipped();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateItemInformation(const UFortItem* FortItem);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateNextButtonText(bool bShowNext);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateOwnedItemText(bool bShowText);

	UFUNCTION(BlueprintCallable)
	void SetGiftBoxItem(UFortGiftBoxItem* GiftBoxItem);

	UPROPERTY(EditAnywhere, Category="FortItemPresentationScreen")
	TSubclassOf<UFortItemPresentationEntry> ItemCardClass;

	UPROPERTY(BlueprintReadOnly, Category="FortItemPresentationScreen")
	TArray<FFortReceivedItemLootInfo> ItemDefs;

	UPROPERTY(BlueprintReadOnly, Category="FortItemPresentationScreen")
	TArray<FFortReceivedItemLootInfo> PaidBattlePassItemDefs;

	UPROPERTY(Transient)
	TObjectPtr<UFortItem> CurrentItemSelected;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> EntryBoxButtonGroup;

	UPROPERTY(Transient)
	TArray<FText> BackgroundMessageTexts;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UUserWidget>> GiftboxCustomLeftsideContentWidgetClasses;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationScreen")
	int32 MaxItemsInView;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationScreen")
	float HotItemDisplayTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> FakeHackGradient;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPresentationScreen")
	FString SpecialCollectionTabID;

private:
	UFUNCTION()
	void HandleHoldToClose();

	UPROPERTY(EditDefaultsOnly, Category="FortItemPresentationScreen")
	FText MultipleItemPurchaseHeaderTitle;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPresentationScreen")
	FText SingleItemPurchaseHeaderTitle;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPresentationScreen")
	FText PurchaseHeaderBody;

	UPROPERTY(EditDefaultsOnly, Category="FortItemPresentationScreen")
	TSoftClassPtr<ULockerConfirmationModal> LockerConfirmationModalClass;

	UPROPERTY(BlueprintReadOnly, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE"))
	bool bShowingBattlePassItems;

	UPROPERTY(EditAnywhere, Category="FortItemPresentationScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HoldToCloseAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Equip;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Next;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BattlePassRewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BattlePassCustomization;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SpecialCollection;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_ItemsCollected;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortItemInfoPresentationWidget> ItemInfoPresentationWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortItemReceivedHeaderBase> ItemHeaderWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaBattlePassTracker> BattlePassTracker;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_UnownedBaseItemMessage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Lock;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Items;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Items;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_PaidItems;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPresentationScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_InputBlocker;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_LeftScrollArrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RightScrollArrow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaExclusiveRewardBanner> Banner_TokenDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> CustomContent;

};

