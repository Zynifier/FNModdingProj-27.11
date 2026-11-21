// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortEmporiumUtilities.h"
#include "EmporiumBrowserFiltersPanel.generated.h"

class UCommonButtonBase;
class UEmporiumBrowserFilterEntry;
class UFortEmporiumFilterCategoryHeader;
class UObject;
class UScrollBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumCategoryActivatedDelegate, FName, CategoryID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumCategoryFocusedDelegate, FName, CategoryID);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEmporiumFilterChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEmporiumFocusChangedDelegate, bool, bIsFocused);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEmporiumSortChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEmporiumSubFilterToggled);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEmporiumBrowserFiltersPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ExcludeItemDetailTag(const FName& TagID);

	UFUNCTION(BlueprintPure)
	int32 GetFilterCount() const;

	UFUNCTION(BlueprintCallable)
	void IncludeItemDetailTag(const FName& TagID);

	UFUNCTION(BlueprintCallable)
	void SetItemDetailTags(const TArray<FName>& TagIDs);

	UPROPERTY(BlueprintAssignable)
	FEmporiumFilterChangedDelegate OnFilterChanged;

	UPROPERTY(BlueprintReadOnly, Category="EmporiumBrowserFiltersPanel")
	FEmporiumSortChangedDelegate OnSortChanged;

	UPROPERTY(BlueprintReadOnly, Category="EmporiumBrowserFiltersPanel")
	FEmporiumSubFilterToggled OnSubFilterToggled;

	UPROPERTY(BlueprintAssignable)
	FEmporiumFocusChangedDelegate OnFocusChanged;

	UPROPERTY(BlueprintAssignable)
	FEmporiumCategoryActivatedDelegate OnCategoryActivated;

	UPROPERTY(BlueprintAssignable)
	FEmporiumCategoryFocusedDelegate OnCategoryFocused;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSearchFocused();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSearchText(const FText& NewSearchText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetSearchVisible(bool bVisible);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FilterEntry")
	TSubclassOf<UFortEmporiumFilterCategoryHeader> FilterSectionHeaderWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FilterEntry")
	TSubclassOf<UFortEmporiumFilterCategoryHeader> FilterCategoryHeaderWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FilterEntry")
	TSubclassOf<UFortEmporiumFilterCategoryHeader> FilterHomeHeaderWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FilterEntry")
	TSubclassOf<UEmporiumBrowserFilterEntry> FilterEntryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="EmporiumBrowserFiltersPanel")
	TArray<FFortEmporiumSortEntry> SortEntries;

	UPROPERTY(EditDefaultsOnly, Category="EmporiumBrowserFiltersPanel")
	TArray<FFortEmporiumFilterEntry> FilterEntries;

	UPROPERTY(EditDefaultsOnly, Category="EmporiumBrowserFiltersPanel")
	TArray<FFortEmporiumPriceFilterEntry> PriceFilterEntries;

	UPROPERTY(EditDefaultsOnly, Category="EmporiumBrowserFiltersPanel")
	TArray<FName> LicenseFilterEntries;

	UPROPERTY(EditDefaultsOnly, Category="EmporiumBrowserFiltersPanel")
	FName DefaultCategoryFilter;

private:
	UFUNCTION()
	void HandleCategoryActivated(bool bIsExpanded, UObject* ListItemObject);

	UFUNCTION()
	void HandleCategoryWidgetDestroyed(UObject* ListItemObject);

	UFUNCTION()
	void HandleFilterEnabled(bool bIsFilterEnabled, UObject* ListItemObject);

	UFUNCTION()
	void HandleFilterSelected(bool bIsFilterEnabled, UEmporiumBrowserFilterEntry* Entry);

	UFUNCTION(BlueprintCallable)
	void HandleSearchTextChanged(const FText& Text);

	UFUNCTION()
	void HandleShowAllEnabled(bool bShowAllItems, UObject* ListItemObject);

	UFUNCTION()
	void HandleSortAndFilterClicked();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_FilterScroll;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UEmporiumBrowserFilterEntry> Button_All;

	UPROPERTY(BlueprintReadOnly, Export, Category="EmporiumBrowserFiltersPanel", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SortAndFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EmporiumBrowserFiltersPanel", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle FocusSearchInputActionRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EmporiumBrowserFiltersPanel", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClearSearchInputActionRow;

};

UCLASS(BlueprintType)
class UEmporiumBrowserTag : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EmporiumBrowserTag")
	FName TagID;

};

