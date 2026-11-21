// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortMatchmakingKnobsModal.h"
#include "FortPlaylistUserOptions.h"
#include "FortCreativeMessageKnobsDialog.generated.h"

class UAthenaConfirmationWindow;
class UBackgroundBlur;
class UCanvasPanel;
class UCommonActionWidget;
class UCommonTextBlock;
class UFortCTAButton;
class UFortCreativeDeviceBrowser;
class UFortCreativePropertyEditorDialogBase;
class UFortItemListOptionProxy;
class UObject;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFilterListCompleted, int32, NumberOfItemsInFilter);

USTRUCT()
struct FFortItemListOptionBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 ItemIndex;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemListOptionProxy>> ItemOptionData;

};

USTRUCT()
struct FFortWeightedObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> Object;

	UPROPERTY()
	int32 Weight;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMessageKnobsDialog : public UFortMatchmakingKnobsModal
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_DialogConfirmed();

	UFUNCTION(BlueprintCallable)
	bool CheckDestructiveSettings();

	UFUNCTION(BlueprintCallable)
	void DisableFilters();

	UFUNCTION(BlueprintCallable)
	void FilterEntriesByIsModified(bool bShowUnmodifiedEntries, bool UpdateSelection = true);

	UFUNCTION(BlueprintCallable)
	void FilterEntriesByString(const FString& FilterString, bool UpdateSelection = true);

	UFUNCTION(BlueprintCallable)
	void FilterEntriesByTag(FGameplayTagContainer Tags, bool UpdateSelection = true);

	UFUNCTION(BlueprintCallable)
	void GenerateFilteredEntries(bool bUpdateSelectionForGamepad = true, bool bUpdateSelectionForMouse = false);

	UFUNCTION(BlueprintPure)
	ESlateVisibility GetDesiredAdditionalActionButtonsVisiblity(const ESlateVisibility RequestedVisibility) const;

	UFUNCTION(BlueprintPure)
	bool IsAnyFilterActive();

	UFUNCTION(BlueprintCallable)
	void RefreshTagFilterForGrantedContextTags(bool bRefreshOnlyWhenChanged = true, bool bUpdateSelectionForGamepad = true, bool bUpdateSelectForMouse = false);

	UFUNCTION()
	virtual void RefreshUIOnDeviceButtonClicked();

	UFUNCTION(BlueprintCallable)
	void RemoveIsModifiedFilter(bool UpdateSelection = true);

	UFUNCTION(BlueprintCallable)
	void RemoveStringFilter(bool UpdateSelection = true);

	UFUNCTION(BlueprintCallable)
	void RemoveTagFilter(bool UpdateSelection = true);

	UFUNCTION(BlueprintPure)
	bool ShouldShowAdditonalActionButtons() const;

protected:
	UFUNCTION(BlueprintCallable)
	void CloseDialog(const bool bSetFocusToOptionsList = true);

	UFUNCTION(BlueprintPure)
	virtual bool ContainsItem() const;

	UFUNCTION(BlueprintPure)
	virtual FText GetClearItemsConfirmationText() const;

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	UAthenaConfirmationWindow* GetConfirmationDialogWidget();

	UFUNCTION(BlueprintPure)
	virtual int32 GetItemCount() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	float GetOptionsListScrollSpeed() const;

	UFUNCTION(BlueprintCallable)
	virtual void HandleClearItemsClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMainMenuInput();

	UFUNCTION(BlueprintPure)
	virtual bool HasClearItemsConfirmation() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void NativeHandleOnRenameInput() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnConfirmationDialogWidgetCreated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDialogOpenStateChanged(const bool bIsOpen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEntryAdditionalActionChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowLoadingSpinnerChanged(const bool bShowLoadingSpinner);

	UFUNCTION(BlueprintCallable)
	void SetFocusToItem(UObject* Item);

	UFUNCTION(BlueprintImplementableEvent)
	void SetOptionsButtonsEnabled(const bool bInButtonsEnabled);

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMessageKnobsDialog", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle MainMenuInputRowHandle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCreativePropertyEditorDialogBase> CurrentDialog;

	UPROPERTY(Transient)
	TObjectPtr<UObject> CachedSelectedPreFilterOption;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMessageKnobsDialog")
	TSubclassOf<UUserWidget> LegacyEntryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMessageKnobsDialog")
	TSubclassOf<UUserWidget> AdvancedEntryWidgetClass;

	UPROPERTY(Transient)
	TArray<FFortItemListOptionBucket> ItemListBuckets;

	UPROPERTY(BlueprintAssignable)
	FOnFilterListCompleted OnFilterListCompleted;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_OptionsDialog;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMessageKnobsDialog", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBackgroundBlur> BackgroundBlur_ConfirmDialog;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeMessageKnobsDialog")
	FText ItemName;

private:
	UFUNCTION(BlueprintCallable)
	void HandleDeviceBrowserButtonPressed();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMessageKnobsDialog", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActionWidget> Action_SelectedItemAdditionalAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMessageKnobsDialog", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SelectedItemAdditionalAction;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMessageKnobsDialog")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationDialogClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaConfirmationWindow> CachedConfirmationDialogWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMessageKnobsDialog", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_EventBrowser;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMessageKnobsDialog")
	TSoftClassPtr<UFortCreativeDeviceBrowser> SoftDeviceBrowserClass;

};

UCLASS()
class UFortItemListOptionProxy : public UFortUserOptionProxy
{
	GENERATED_BODY()

};

