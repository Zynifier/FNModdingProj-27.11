// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataTable.h"
#include "STW/FortHomebase/FortHomebaseManager.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortSquadManagementScreenBase.generated.h"

class UFortDisableAutoSlottingPromptAction;
class UFortItem;
class UFortItemViewContext_SquadSlotItemPicker;
class UFortItemViewContext_SquadSlotsView;
class UFortSquadSlotDetailsPanel;
class UFortSquadSlotItemPicker;
class UFortSquadSlotsView;
class UFortSquadStatsWidgetBase;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadManagementScreenBase : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	void ClearSquad();

	UFUNCTION(BlueprintPure, Category="Squad Management")
	FName GetIdOfSquadToManageBP() const;

	UFUNCTION(BlueprintPure, Category="Squad Management Screen")
	int32 GetNumUnlockedSquads() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void HandleNextSquadInputAction();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void HandlePreviousSquadInputAction();

	UFUNCTION(BlueprintPure, Category="Squad Management")
	bool IsScreenWIFE() const;

	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	void NavigateToSquadSlot(int32 SquadSlotIndex);

	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	void SelectNextSquad();

	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	void SelectPreviousSquad();

	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	void SelectSquadWithOffset(int32 Offset);

	UFUNCTION(BlueprintCallable, Category="Squad Management")
	void SetIdOfSquadToManageBP(const FName& SquadId);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Squad Management")
	void ShowWarningReadOnlyWIFE(bool Force);

	UFUNCTION(BlueprintPure, Category="Squad Management Screen")
	bool TryGetAttributeValueFromSquad(float& OutValue, const FGameplayAttribute& Attribute) const;

	UFUNCTION(BlueprintPure, Category="Squad Management Screen")
	bool TryGetSquadMainAttribute(FGameplayAttribute& OutGameplayAttribute) const;

	UFUNCTION(BlueprintPure, Category="Squad Management Screen")
	bool TryGetSquadTeamAttribute(FGameplayAttribute& OutGameplayAttribute) const;

	UFUNCTION(BlueprintPure, Category="Squad Management")
	bool TryGetStaticSquadDataBP(FHomebaseSquad& OutSquadData) const;

	UPROPERTY(BlueprintReadWrite, Category="Squad Management Screen|Mode")
	bool bReadOnlyModeWIFE;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleBackInputAction();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void HandleDifferentSquadSetBP();

	UFUNCTION()
	virtual void HandleDifferentSquadSlotSelected(const int32 SquadSlotIndex);

	UFUNCTION()
	void HandleManageInputAction();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void HandleSquadSlotPickerHidden();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management Screen")
	void HandleSquadSlotPickerShown();

	UFUNCTION(BlueprintImplementableEvent, Category="Squad Management")
	void HandleSquadStateChanged();

	UFUNCTION(BlueprintCallable, Category="Squad Management Screen")
	virtual void SetupInputHandlers();

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSquadStatsWidgetBase> SquadStatsWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotsView> SquadSlotsView;

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotDetailsPanel> SelectedSlotDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="Squad Management Screen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSquadSlotItemPicker> SelectedSlotItemPicker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ManageInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InventoryInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InventoryCloseInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClosePickerInputActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SelectPickerSlotActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CyclePickerSortActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousSquadActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextSquadActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClearAllActionRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Management Screen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HelpScreenActionRowHandle;

	UPROPERTY(EditAnywhere, Category="Squad Slots View")
	TSubclassOf<UFortDisableAutoSlottingPromptAction> DisableAutoSlottingToClearSquadPromptAction;

private:
	UFUNCTION()
	void HandleClosePickerInputAction();

	UFUNCTION()
	void HandleCyclePickerSortInputAction();

	UFUNCTION()
	void HandleInspectInputAction();

	UFUNCTION()
	void HandleInventoryInputAction();

	UFUNCTION()
	void HandleOpenSquadSlot(const int32 SquadSlotIndex);

	UFUNCTION()
	void HandlePickerSelectionChanged(UFortItem* SelectedItem);

	UFUNCTION()
	void HandlePickerSelectionCommitted(UFortItem* CommittedItem);

	UFUNCTION()
	void HandleSelectPickerSlotInputAction();

	UFUNCTION()
	void HandleShouldAutoSlotSurvivorSquadsChanged();

	UFUNCTION()
	void HandleViewInAll(const int32 SquadSlotIndex);

	UPROPERTY(Instanced)
	TObjectPtr<UFortItemViewContext_SquadSlotsView> ItemViewContext_SquadSlotsView;

	UPROPERTY(Instanced)
	TObjectPtr<UFortItemViewContext_SquadSlotItemPicker> ItemViewContext_SquadSlotItemPicker;

};

