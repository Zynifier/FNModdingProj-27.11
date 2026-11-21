// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Item/FortItemDetailsHostPanel.h"
#include "FortItemManagementModeDetailsPanel.generated.h"

class IFortItemManagementMulchPanel;
class UCommonWidgetSwitcherLegacy;
class UFortAmmoItemDefinition;
class UFortInventoryContext;
class UFortItem;
class UFortItemDetailsActivatablePanel;
class UFortItemManagementScreen;
class UFortItemQuantityListBase;
enum class EFortItemManagementMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemManagementItemDetailsPanel : public UFortItemDetailsHostPanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	static TArray<UFortAmmoItemDefinition*> GetAmmoTypeItemDefinitions();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleHasItemMarkedForMulchingChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleHostSet();

	UPROPERTY(BlueprintReadOnly, Category="Item Management|Details")
	bool HasItemMarkedForMulching;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementItemDetailsPanel")
	TWeakObjectPtr<UFortItemManagementScreen> HostItemManagementScreen;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementModeDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Item Management|Item Tile")
	EFortItemManagementMode GetItemManagementMode() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mode", meta=(DisplayName="Handle Different Item Management Mode Set"))
	void HandleDifferentItemManagementModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleHostSet();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> ModeWidgetSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsActivatablePanel> DetailsModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsActivatablePanel> ComparisonModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemDetailsActivatablePanel> MulchModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel")
	TWeakObjectPtr<UFortItemManagementScreen> HostItemManagementScreen;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementMulchDetailsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Item Management|Mulch Details")
	void CommitMulch();

	UFUNCTION(BlueprintPure, Category="Item Management|Mulch Details")
	TArray<int32> GetItemCountsToMulch() const;

	UFUNCTION(BlueprintPure, Category="Item Management|Mulch Details")
	TArray<UFortItem*> GetItemsToMulch() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleHostSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mulch Details", meta=(DisplayName="Handle Set Of Items To Mulch Changed"))
	void HandleSetOfItemsToMulchChangedBP();

	UFUNCTION(BlueprintPure, Category="Item Management|Mulch Details")
	bool IsSpaceAvailableForMulch() const;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Management|Details", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemQuantityListBase> ResourceList;

	UPROPERTY(BlueprintReadOnly, Category="FortItemManagementMulchDetailsPanel")
	TScriptInterface<IFortItemManagementMulchPanel> HostItemManagementMulchPanel;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortInventoryContext> InventoryContext;

};

