// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortItemDetailsActivatablePanel.generated.h"

class UCommonLoadGuard;
class UCommonWidgetSwitcherLegacy;
class UFortItem;
class UFortItemManagementItemDetailsPanel;
class UFortItemManagementMulchDetailsPanel;
class UFortItemManagementScreen;
class UFortTooltipLoadingWrapper;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemDetailsActivatablePanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleConsumeItemProgressChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToCompareSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleDifferentItemToDetailSetBP();

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Details")
	TWeakObjectPtr<UFortItemManagementScreen> HostItemManagementScreen;

private:
	UFUNCTION()
	void HandleItemToDetailTooltipAssetsLoaded();

	UPROPERTY()
	TObjectPtr<UFortTooltipLoadingWrapper> ItemToDetailLoadingWrapper;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> ItemToDetailLoadGuard;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemCompareModeActivatablePanel : public UFortItemDetailsActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCompareModeActivatablePanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementItemDetailsPanel> ComparisonModeLeftItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemCompareModeActivatablePanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementItemDetailsPanel> ComparisonModeRightItemDetailsPanel;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemDetailsModeActivatablePanel : public UFortItemDetailsActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsModeActivatablePanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> DetailPanelWidgetSwitcher;

private:
	UFUNCTION()
	void HandleOnActiveWidgetChanged(UWidget* ActiveWidget, int32 ActiveWidgetIndex);

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemMulchModeActivatablePanel : public UFortItemDetailsActivatablePanel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemMulchModeActivatablePanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementItemDetailsPanel> MulchModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemMulchModeActivatablePanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemManagementMulchDetailsPanel> MulchDetailsPanel;

};

