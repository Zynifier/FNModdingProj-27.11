// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortAbilitiesPageTileBase.generated.h"

class UCommonWidgetSwitcherLegacy;
class UFortKeybindWidget;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAbilitiesPageTileBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateGamepadKeyBindingText();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AbilitiesPage", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> SwitcherAbilityBindingSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="AbilitiesPage", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindAbilityKeybind;

	UPROPERTY(BlueprintReadOnly, Export, Category="AbilitiesPage", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindAbilityKeybindCombo1;

	UPROPERTY(BlueprintReadOnly, Export, Category="AbilitiesPage", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindAbilityKeybindCombo2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAbilitiesPageTileBase")
	int32 QuickbarSlot;

};

