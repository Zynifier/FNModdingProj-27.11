// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonButtonLegacy.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "SquadManagement/FortSquadManagement.h"
#include "FortSquadSlotsView.generated.h"

class IFortItemViewContextInterface;
class UCommonButtonLegacy;
class UFortCommittableButtonGroup;
class UFortDisableAutoSlottingPromptAction;
class UFortSquadSlotSelectorButton;
class UFortSquadSlotWidget;
class UMenuAnchor;
class UUserWidget;
class UWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestSquadSlotAction, int32, SquadSlotIndex);

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSquadSlotSelectorButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool GetInPreviewMode() const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool IsSquadSlotLockedBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void OpenSquadSlot();

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

	UFUNCTION(BlueprintNativeEvent, Category="Squad Slot Management")
	void SquadSlotWidgetUpdated();

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void ViewInAll();

	UPROPERTY(BlueprintAssignable, Category="Squad Slot Management")
	FOnRequestSquadSlotAction OnRequestOpenSquadSlotEvent;

	UPROPERTY(BlueprintAssignable, Category="Squad Slot Management")
	FOnRequestSquadSlotAction OnRequestViewInAllEvent;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandlePostDifferentSquadSlotSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandlePreDifferentSquadSlotSetBP();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadSlotSelectorButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotWidget> SquadSlotWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSquadSlotSelectorButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> PopupMenuAnchor;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

private:
	UFUNCTION()
	UUserWidget* GetPopupMenu();

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadSlotsView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDifferentSquadSlotSelected, int32, SquadSlotIndex);

public:
	UFUNCTION(BlueprintPure, Category="Squad Management")
	FName GetIdOfSquadToManageBP() const;

	UFUNCTION(BlueprintPure, Category="Squad Slots View")
	int32 GetIndexOfSelectedSquadSlot() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slots View")
	void SelectSlot(int32 SquadSlotIndex);

	UFUNCTION(BlueprintCallable, Category="Squad Management")
	void SetIdOfSquadToManageBP(const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="Squad Slots View")
	void SetInPreviewMode(const bool bPreview);

	UFUNCTION(BlueprintCallable, Category="Squad Slots View")
	void SetIsSelectionLocked(const bool ShouldSelectionBeLocked);

	UFUNCTION(BlueprintCallable, Category="Squad Slots View")
	bool TryGetSelectedSquadSlotSortTypes(FSquadSlotSortTypes& OutSlotSortTypes);

	UFUNCTION(BlueprintPure, Category="Squad Management")
	bool TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const;

	UPROPERTY(BlueprintAssignable, Category="Squad Slots View")
	FOnDifferentSquadSlotSelected OnDifferentSquadSlotSelectedEvent;

	UPROPERTY(BlueprintAssignable, Category="Squad Slots View")
	FOnRequestSquadSlotAction OnRequestOpenSquadSlotEvent;

	UPROPERTY(BlueprintAssignable, Category="Squad Slots View")
	FOnRequestSquadSlotAction OnRequestViewInAllEvent;

	UPROPERTY(BlueprintReadWrite, Category="Squad Slot Management")
	bool bReadOnlyModeWIFE;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slots View")
	UFortSquadSlotSelectorButton* CreateAndAddSquadSlotButton(const int32 SquadSlotIndex, const FHomebaseSquadSlot& SquadSlotDefinition, UWidget*& OutSquadSlotButtonHost);

	UPROPERTY(BlueprintReadOnly, Category="FortSquadSlotsView")
	int32 IndexOfSelectedSquadSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Slots View")
	bool bSlotButtonsRequireSelection;

	UPROPERTY(Transient)
	bool bInPreviewMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Slots View")
	TMap<ESquadSlotType, FSquadSlotSortTypes> SquadSlotSortTypesMap;

	UPROPERTY(EditAnywhere, Category="Squad Slots View")
	TSubclassOf<UFortDisableAutoSlottingPromptAction> DisableAutoSlottingToOpenSquadSlotPromptAction;

private:
	UFUNCTION()
	void HandleButtonClicked(UCommonButtonLegacy* CommittedButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleButtonDoubleClicked(UCommonButtonLegacy* CommittedButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleHoveredButtonChanged(UCommonButtonLegacy* HoveredButton, int32 ButtonIndex);

	UFUNCTION()
	void HandleRequestOpenSquadSlot(int32 SquadSlotIndex);

	UFUNCTION()
	void HandleRequestViewInAll(int32 SquadSlotIndex);

	UFUNCTION()
	void HandleSelectedButtonChanged(UCommonButtonLegacy* SelectedButton, int32 ButtonIndex);

	UPROPERTY()
	TObjectPtr<UFortCommittableButtonGroup> SquadSlotButtonGroup;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

