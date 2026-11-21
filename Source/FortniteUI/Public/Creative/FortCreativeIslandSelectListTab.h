// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeIslandSelectTab.h"
#include "FortCreativeIslandSelectListTab.generated.h"

class UCommonButtonBase;
class UFortCreativeIslandDetailsPanel;
class UFortGameActivityProvider;
class UImage;
class UListView;
class UObject;
class UOverlay;
class UTextBlock;
class UUserWidget;
class UWidgetSwitcher;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeIslandSelectListTab : public UFortCreativeIslandSelectTab
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleIslandSelectionChanged(UObject* Item);

	UFUNCTION()
	void HandleListScrolled(float ItemOffset, float DistanceRemaining);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeIslandSelectListTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UListView> ListView_Activities;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Select;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Remove;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Favorite;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_IslandsList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_IslandListContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_NoIslandsContent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_NoFavorites;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_NoIslands;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUserWidget> Widget_LaunchError;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LoadingIndicator;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCreativeIslandDetailsPanel> IslandDetailsPanel;

	UPROPERTY()
	TObjectPtr<UFortGameActivityProvider> ActivityProvider;

	UPROPERTY()
	TObjectPtr<UObject> LastItemToTriggerLoading;

};

