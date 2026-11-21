// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Creative/FortCreativePropertyEditorDialogBase.h"
#include "FortCreativePropertyEditorColorPickerDialog.generated.h"

class UCommonTileView;
class UEditableTextBox;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditorColorPickerDialog : public UFortCreativePropertyEditorDialogBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchInput();

protected:
	UFUNCTION(BlueprintPure, Category="Option Picker")
	int32 GetItemIndexFromUnfilteredItemList(UObject* Item);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorColorPickerDialog", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView_Swatches;

private:
	UFUNCTION()
	void HandleSearchTextChanged(const FText& SearchText);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorColorPickerDialog", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditableText_Search;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativePropertyEditorColorPickerDialog", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SearchInputRowHandle;

	UPROPERTY(Transient)
	TArray<UObject*> UnfilteredListItems;

};

