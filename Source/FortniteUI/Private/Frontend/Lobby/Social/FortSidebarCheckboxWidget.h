// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortSidebarCheckboxWidget.generated.h"

class UButton;
class UWidgetSwitcher;

UCLASS(meta=(DisableNativeTick))
class UFortSidebarCheckboxWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Toggle Checkbox"))
	void BP_ToggleCheckbox();

	UFUNCTION(BlueprintCallable)
	void HandleCheckboxClicked();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarCheckboxWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UButton> CheckButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarCheckboxWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_CheckBox;

};

