// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemPicker.generated.h"

class IFortItemListViewInterface;
class IFortItemViewContextInterface;
class UFortItem;
class UFortItemTileView;
class UListView;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemPickerBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSelectionScriptDelegate, UFortItem*, SelectedItem);

public:
	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API bool CanItemBeComitted(const UFortItem* ItemToCommit);

	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API void CenterSelectedItemTileWidget();

	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API void ClearSelection();

	UFUNCTION(BlueprintPure, Category="Item Picker")
	FORTNITEUI_API int32 GetIndexForItem(UFortItem* Item) const;

	UFUNCTION(BlueprintPure, Category="Item Picker")
	FORTNITEUI_API UFortItem* GetSelectedItem() const;

	UFUNCTION(BlueprintPure, Category="Item Picker")
	FORTNITEUI_API bool IsNullItemExplicitlySelected() const;

	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API bool SetSelectedIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API void SetSelectedItem(const UFortItem* ItemToSelect);

	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API bool TryCommitSelectedItem();

	UPROPERTY(BlueprintAssignable, Category="Item Picker")
	FOnItemSelectionScriptDelegate OnSelectionChangedEvent;

	UPROPERTY(BlueprintAssignable, Category="Item Picker")
	FOnItemSelectionScriptDelegate OnSelectionCommittedEvent;

	UPROPERTY(BlueprintAssignable, Category="Item Picker")
	FOnItemSelectionScriptDelegate OnItemHoveredEvent;

	UPROPERTY(BlueprintAssignable, Category="Item Picker")
	FOnItemSelectionScriptDelegate OnItemUnhovered;

protected:
	UFUNCTION(BlueprintCallable, Category="Item Picker")
	FORTNITEUI_API TScriptInterface<IFortItemListViewInterface> GetListViewInterface();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPickerBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemTileView> PickerTileView;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPickerBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UListView> ItemListViewWidget;

	UPROPERTY(EditAnywhere, Category="FortItemPickerBase")
	bool bConfirmSelectionIfAlreadySelectedAfterOneClick;

private:
	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

