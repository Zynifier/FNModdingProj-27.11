// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortCreativeItemDetailsSidePanel.generated.h"

class UCommonVisibilitySwitcher;
class UCreativeContentBrowserItemInfo;
class UFortItemDetailsHostPanel;
class UImage;

UCLASS(MinimalAPI)
class UFortCreativeItemDetailsSidePanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeItemDetailsSidePanel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSpecialItemTagVisibility(const FString& SpecialItemTag);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Special Item")
	TArray<FString> SpecialItemTags;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SelectedItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCreativeContentBrowserItemInfo> ContentBrowserItemInfo_ItemDetails;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsHostPanel> ItemInspectionMainItemDetails_LegacyDetailsPanel;

};

