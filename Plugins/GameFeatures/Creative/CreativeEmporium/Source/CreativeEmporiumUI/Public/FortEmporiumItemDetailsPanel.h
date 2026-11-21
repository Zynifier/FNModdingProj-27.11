// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "FortEmporiumItemDetailsPanel.generated.h"

class UCommonVisibilitySwitcher;
class UFortEmporiumItemInfo;
class UFortItem;
class UFortItemDefinition;
class UFortItemDetailsHostPanel;

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortEmporiumItemDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool HasLegacyItemDetailsPanel() const;

	UFUNCTION(BlueprintImplementableEvent)
	void SetActiveItemDetailTags(const TArray<FName>& ActiveTags);

	UFUNCTION(BlueprintCallable)
	void SetItemToDetail(const UFortItem* InItemToDetail, const bool bUseLargeThumbnail, const bool bAllowInteractiveTags);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSpecialItemTagVisibility(const FName& SpecialItemTag);

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleItemDetailsPanel();

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Get Special Item Tags"))
	TArray<FName> BP_GetSpecialItemTags() const;

	UFUNCTION(BlueprintCallable)
	void HandleItemTagSelected(FName TagID, bool bSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void HideAdditionalButtons();

	UFUNCTION(BlueprintImplementableEvent)
	void HideExtendedDataPanel();

	UFUNCTION(BlueprintNativeEvent)
	bool IsShowingAdditionalButtons();

	UFUNCTION(BlueprintNativeEvent)
	bool IsShowingExtendedDataPanel() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetItemDetails(const UFortItem* FortItem, const bool bUseLargeThumbnail, const bool bAllowInteractiveTags);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowExtendedDataPanel();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateItemDetailsDisplay(bool bShowItemDetails);

	UPROPERTY(EditAnywhere, Category="FortEmporiumItemDetailsPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemDetailTagsInputRowHandle;

	UPROPERTY(BlueprintReadOnly, Category="FortEmporiumItemDetailsPanel")
	TObjectPtr<UFortItemDefinition> CachedItemDefinition;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEmporiumItemDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEmporiumItemInfo> ItemDetails;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> LegacyItemDetails;

};

