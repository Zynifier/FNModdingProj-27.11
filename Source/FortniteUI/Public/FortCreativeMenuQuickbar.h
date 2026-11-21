// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeContentBrowserTypes.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeMenuQuickbar.generated.h"

class UAthenaQuickbarEditorBase;
class UFortItemDefinition;
class UWidgetSwitcher;
enum class EFortContentBrowserQuickbarState : uint8;
enum class EFortQuickBars : uint8;

UENUM(BlueprintType)
enum class EFortContentBrowserQuickbarState : uint8
{
	Disabled = 0,
	Creative = 1,
	Primary = 2,
	Trap = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeMenuQuickbarStateChangedDelegate, const EFortContentBrowserQuickbarState, State);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquipSelectionDelegate, const FFortItemEntry&, ItemEntry);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMenuQuickbar : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQuickbarHighlight();

	UFUNCTION(BlueprintCallable)
	void ShowQuickbar(EFortContentBrowserQuickbarState InQuickbarState);

	UPROPERTY(BlueprintAssignable)
	FOnFocusChangedDelegate OnFocusChanged;

	UPROPERTY(BlueprintAssignable)
	FOnEquipSelectionDelegate OnEquipItem;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeMenuQuickbarStateChangedDelegate OnQuickbarStateChanged;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleAddItemToQuickbarAction(EFortQuickBars QuickbarType, const int32 SlotNum, const UFortItemDefinition* ItemDefinition);

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMenuQuickbar")
	TObjectPtr<UFortItemDefinition> CurrentItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMenuQuickbar")
	EFortCreativeItemType CurrentType;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_QuickBars;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMenuQuickbar", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> AthenaQuickbar_Creative;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMenuQuickbar", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> AthenaQuickbar_Trap;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuickbarEditorBase> AthenaQuickbar_Primary;

};

