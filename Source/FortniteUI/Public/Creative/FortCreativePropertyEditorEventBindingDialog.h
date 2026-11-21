// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Creative/Components/PlayspaceComponent_DeviceTracking.h"
#include "Creative/FortCreativePropertyEditorDialogBase.h"
#include "FortCreativePropertyEditorEventBindingDialog.generated.h"

class UCommonListView;
class UEditableTextBox;
class UFortCreativePropertyEditorEventBindingDialogListItemProxy;
class UObject;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativePropertyEditorEventBindingDialog : public UFortCreativePropertyEditorDialogBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, meta=(BlueprintProtected="TRUE"))
	static bool IsSearchEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchInput();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnfilteredListItemsSet();

private:
	UFUNCTION()
	void HandleSearchTextChanged(const FText& SearchText);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorEventBindingDialog", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonListView> ListView_Entries;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditorEventBindingDialog", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditableText_Search;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditorEventBindingDialog", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputRowHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativePropertyEditorEventBindingDialog", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SearchInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="Search Hint Text", meta=(DisplayName="Devices"))
	FText SearchHintTextDevices;

	UPROPERTY(EditDefaultsOnly, Category="Search Hint Text", meta=(DisplayName="Events"))
	FText SearchHintTextEvents;

	UPROPERTY(EditDefaultsOnly, Category="Search Hint Text", meta=(DisplayName="Functions"))
	FText SearchHintTextFunctions;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UObject>> UnfilteredListItems;

	UPROPERTY(Transient)
	TArray<FBasicDeviceTrackingInfo> FullTrackingInfoList;

	UPROPERTY(Transient)
	UFortCreativePropertyEditorEventBindingDialogListItemProxy* SelectedItemProxy;

};

