// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "UObject/NoExportTypes.h"
#include "ContentBrowserFiltersPanel.generated.h"

class UContentBrowserFilterEntry;
class UObject;
class UScrollBox;
class USearchPanel;
class UUserWidget;
class UVerticalBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFilterChangedDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFocusChangedDelegate, bool, bIsFocused);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UContentBrowserFiltersPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetFilterCount() const;

	UPROPERTY(BlueprintAssignable)
	FFilterChangedDelegate OnFilterChanged;

	UPROPERTY(BlueprintAssignable)
	FFocusChangedDelegate OnFocusChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FilterEntry")
	TSubclassOf<UUserWidget> FilterEntryWidgetClass;

private:
	UFUNCTION()
	void HandleFilterEnabled(bool bIsFilterEnabled, UObject* ListItemObject);

	UFUNCTION()
	void HandleFilterSelected(bool bIsFilterEnabled, UContentBrowserFilterEntry* Entry);

	UFUNCTION()
	void HandleSearchTextChanged(const FText& Text);

	UFUNCTION()
	void HandleShowAll(bool bShowAllItems, UObject* ListItemObject);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> Box_Filters;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_FilterScroll;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UContentBrowserFilterEntry> Button_All;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USearchPanel> SearchPanel;

};

UCLASS(BlueprintType)
class UContentBrowserTag : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ContentBrowserTag")
	FName TagID;

	UPROPERTY(BlueprintReadOnly, Category="ContentBrowserTag")
	FText TagName;

};

