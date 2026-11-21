// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaCustomizationPickerSortAndFilterBlade.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UFortDynamicEntryBox;
class UUserWidget;
class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCustomizationPickerSortAndFilterBlade : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseBlade();

	UFUNCTION(BlueprintPure)
	UCommonButtonBase* GetFilterButtonAtIndex(const int32 DesiredIndex) const;

	UFUNCTION(BlueprintPure)
	int32 GetNumFilters() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumSorts() const;

	UFUNCTION(BlueprintPure)
	UCommonButtonBase* GetSortButtonAtIndex(const int32 DesiredIndex) const;

	UFUNCTION(BlueprintPure)
	bool IsBladeOpen() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Highlight Sort Or Filter Button"))
	void BP_HighlightSortOrFilterButton(UCommonButtonBase* SortOrFilterButton, bool bHighlight);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Archive Filtering Mode Set"))
	void BP_OnArchiveFilteringSet(bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Blade Close"))
	void BP_OnBladeClose();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Blade Open"))
	void BP_OnBladeOpen();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Set Sort Or Filter Button Display Name"))
	void BP_SetSortOrFilterButtonDisplayName(UCommonButtonBase* SortOrFilterButton, const FText& DisplayName);

	UFUNCTION(BlueprintCallable)
	TArray<UUserWidget*> GetAllSortAndFilterButtons();

	UFUNCTION(BlueprintCallable)
	void HandleCloseAnimationFinished();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Sorts;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Filters;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> DynamicEntryBox_SortButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> DynamicEntryBox_FilterButtons;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_Sorts;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_Filters;

};

