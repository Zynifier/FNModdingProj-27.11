// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Settings/FortOptionsTab.h"
#include "FortTabGamepadOptions.generated.h"

class UCommonButtonLegacy;
class UCommonListView;
class UCommonTextBlock;
class UObject;
class UUserWidget;
class UWidget;

UCLASS(Abstract)
class UFortTabGamepadOptions : public UFortOptionsTab
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ResetSettingsToDefault();

protected:
	UFUNCTION(BlueprintCallable, Category="FortInputOptions")
	UWidget* GetListWidget(UObject* Item);

	UFUNCTION(BlueprintPure, Category="FortInputOptions")
	bool IsAdvancedSettingsEnabled();

	UFUNCTION(BlueprintCallable, Category="FortInputOptions")
	void ToggleAdvancedSettingsDisplay(bool bShowAdvancedSettings);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInputOptions", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonListView> InputCommonListView;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortInputOptions", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> TooltipDisplay;

	UPROPERTY(EditAnywhere, Category="FortInputOptions")
	TSubclassOf<UUserWidget> InputCategoryWidgetClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTabGamepadOptions", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AdvancedSettingsToggle;

};

