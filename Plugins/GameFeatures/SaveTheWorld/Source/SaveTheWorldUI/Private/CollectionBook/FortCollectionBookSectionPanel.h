// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortDialogTypes.h"
#include "STW/CollectionBook/FortCollectionBookSlotData.h"
#include "FortCollectionBookSectionPanel.generated.h"

class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookPicker;
class UFortCollectionBookSection;
class UFortCollectionBookSectionCompletionRewardWidget;
class UFortCollectionBookSlotButton;
class UFortCollectionBookSlotConfirmationModal;
class UFortCollectionBookSlotView;
class UFortItem;
class UTextBlock;
class UWidget;
enum class EFortCollectionBookPopupButtonType : uint8;

UENUM()
enum class ECollectionBookSectionNavTarget : uint8
{
	SlotSelect = 0,
	SlotPicker = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPreviewXPChange, int32, XPChange);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSectionCloseRequest);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookSectionPanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAction, UFortItem*, SelectedItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnItemInspectAction, UFortItem*, SelectedItem, bool, EnableItemActions, bool, IsPlaceholderItem);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResearchItemAction, UFortItem*, SelectedItem, const FFortCollectionBookSlotData, SlotData);

public:
	UPROPERTY(BlueprintAssignable, Category="CollectionBook")
	FOnSectionCloseRequest OnSectionCloseRequest;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnPreviewXPChange OnPreviewXPChangeEvent;

protected:
	UFUNCTION()
	void OnBackActionExecuted(bool& bPassThrough);

	UFUNCTION()
	void OnInspectActionExecuted(bool& bPassThrough);

	UFUNCTION()
	void OnLogAllowedItemsActionExecuted(bool& bPassThrough);

	UFUNCTION()
	void OnOpenPickerActionExecuted(bool& bPassThrough);

	UFUNCTION()
	void OnPurchaseItemActionExecuted(bool& bPassThrough);

	UFUNCTION(BlueprintNativeEvent)
	void OnSectionChanged(const UFortCollectionBookSection* Section);

	UFUNCTION()
	void OnSlotButtonContextAction(EFortCollectionBookPopupButtonType ContextAction);

	UFUNCTION()
	void OnSlotButtonHovered(int32 ButtonIx);

	UFUNCTION()
	void OnSlotButtonSelected(const UFortCollectionBookSlotButton* SlotButton);

	UFUNCTION()
	void OnSlotItemActionExecuted(bool& bPassThrough);

	UFUNCTION()
	void OnUnslotItemActionExecuted(bool& bPassThrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnslotItemComplete(const UFortItem* UnslottedItem, FName SlotId);

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> SectionNameTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookSlotView> SlotViewWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookPicker> SlotItemPicker;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> ContextOverlayWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UTextBlock> ContextTextWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookSectionCompletionRewardWidget> SectionRewardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> ItemAcquisitionSourceContainerWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> ItemAcquisitionSourceDescWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> ItemAcquisitionSourceDesc2Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UWidget> ResearchRecruitUnslotContainerWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> PersonRecruitUnavailableMessageWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> ItemResearchUnavailableMessageWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> UnslotUnavailableMessageWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CloseActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SlotItemActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectItemActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectCollectionBookItemActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectPreviewItemActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle OpenPickerActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle LogAllowedItemsActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ResearchItemActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle RecruitActionRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Collection Book", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle UnslotItemActionRowHandle;

	UPROPERTY(Transient)
	ECollectionBookSectionNavTarget CurrentNavTarget;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookSection> AssociatedSection;

	UPROPERTY(Transient)
	bool bHasSummonedPanel;

	UPROPERTY(Transient)
	FFortDialogExternalLatentActionHandle SlotConfirmationDialogLatentHandle;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnItemAction OnShowItemDetailEvent;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnItemAction OnSlotItemConfirmEvent;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnResearchItemAction OnResearchItemConfirmEvent;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnItemAction OnUnslotItemConfirmEvent;

	UPROPERTY(BlueprintAssignable, Category="Collection Book")
	FOnItemInspectAction OnInspectItemEvent;

private:
	UFUNCTION()
	void OnResearchItemOperationComplete(const UFortAccountItem* NewItem, const FString& TemplateId);

	UFUNCTION()
	void OnSlottedItemOperationComplete(const UFortAccountItem* SlottedItem, FName SlotId);

	UFUNCTION()
	void OnUnslotItemOperationComplete(const UFortAccountItem* UnslottedItem, const UFortAccountItem* OldSlottedItem, FName SlotId);

	UPROPERTY(EditDefaultsOnly, Category="FortCollectionBookSectionPanel")
	TSubclassOf<UFortCollectionBookSlotConfirmationModal> SlotConfirmationModalClass;

};

