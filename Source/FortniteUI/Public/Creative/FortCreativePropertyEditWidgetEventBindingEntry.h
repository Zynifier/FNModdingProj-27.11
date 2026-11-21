// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Creative/FortCreativePropertyListEntryBase.h"
#include "FortCreativePropertyEditWidgetEventBindingEntry.generated.h"

class UFortCreativePropertyEditWidgetEventBindingButton;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePropertyEditWidgetEventBindingEntry : public UFortCreativePropertyListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDeviceDisplayNameSet(const FText& DeviceDisplayName);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEntrySelectedStateChanged(const bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsParentItemSelectedChanged(const bool bIsParentItemSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOptionDisplayNameSet(const FText& OptionDisplayName);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditWidgetEventBindingEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativePropertyEditWidgetEventBindingButton> Button_SelectDevice;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePropertyEditWidgetEventBindingEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCreativePropertyEditWidgetEventBindingButton> Button_SelectOption;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditWidgetEventBindingEntry", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SelectDeviceAdditionalAction;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePropertyEditWidgetEventBindingEntry", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SelectOptionAdditionalAction;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> LastFocusedButton;

};

