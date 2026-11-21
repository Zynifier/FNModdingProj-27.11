// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "AthenaInventoryScreenContainer.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UFortTabListWidgetBase;
class UInputComponent;
class UScaleBox;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, Config=Game, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UAthenaInventoryScreenContainer : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetCreated(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryScreenContainer")
	TSubclassOf<UCommonButtonBase> TabButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryScreenContainer", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryScreenContainer", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryScreenContainer")
	TArray<FName> BlockedInputActions;

	UPROPERTY(Config)
	TArray<FName> AdditionalBlockedInputActions;

	UPROPERTY(EditDefaultsOnly, Category="AthenaInventoryScreenContainer")
	TArray<FName> BlockedInputAxes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_Leto;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryScreenContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase> TabList_Inventory;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryScreenContainer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_InventoryTabs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InventoryScreenInputComponent;

};

