// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Item/FortItemDetailsHostPanel.h"
#include "FortItemManagementModeDetailsPanel_STW.generated.h"

class IFortItemManagementMulchPanel;
class UCommonWidgetSwitcherLegacy;
class UFortAmmoItemDefinition;
class UFortInventoryContext;
class UFortItem;
class UFortItemDetailsActivatablePanel_STW;
class UFortItemManagementScreen_STW;
class UFortItemQuantityListBase;
enum class EFortItemManagementMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemManagementItemDetailsPanel_STW : public UFortItemDetailsHostPanel
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

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementItemDetailsPanel_STW")
	TWeakObjectPtr<UFortItemManagementScreen_STW> HostItemManagementScreen;

private:
	UPROPERTY(Transient)
	UFortInventoryContext* InventoryContext;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementModeDetailsPanel_STW : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="Item Management|Item Tile")
	EFortItemManagementMode GetItemManagementMode() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Mode", meta=(DisplayName="Handle Different Item Management Mode Set"))
	void HandleDifferentItemManagementModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	void HandleHostSet();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel_STW", meta=(BindWidget, EditInline="true"))
	UCommonWidgetSwitcherLegacy* ModeWidgetSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemDetailsActivatablePanel_STW* DetailsModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemDetailsActivatablePanel_STW* ComparisonModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel_STW", meta=(BindWidget, EditInline="true"))
	UFortItemDetailsActivatablePanel_STW* MulchModeItemDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemManagementModeDetailsPanel_STW")
	TWeakObjectPtr<UFortItemManagementScreen_STW> HostItemManagementScreen;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortItemManagementMulchDetailsPanel_STW : public UCommonUserWidget
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
	UFortItemQuantityListBase* ResourceList;

	UPROPERTY(BlueprintReadOnly, Category="FortItemManagementMulchDetailsPanel_STW")
	TScriptInterface<IFortItemManagementMulchPanel> HostItemManagementMulchPanel;

private:
	UPROPERTY(Transient)
	UFortInventoryContext* InventoryContext;

};

