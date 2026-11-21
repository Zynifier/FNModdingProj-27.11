// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortVoiceSettingsDisplay.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortGameSettingRegistry;
class UFortOptionsMenu;
class UFortSettingsListView;
class UHorizontalBox;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortVoiceSettingsDisplay : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void HandleSettingsButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowVoiceSettingsButton();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortVoiceSettingsDisplay")
	TSoftClassPtr<UFortOptionsMenu> SettingsClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameSettingRegistry> Registry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_PTTOnOff;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_InputDeviceName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_OutputDeviceName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_VoiceEnabledView;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VoiceEnabledView;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VoiceDisabledView;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> ParentalControlsNotification_VisOff;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ParentalText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_PTTKeybind;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_OpenSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EnableVoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingsListView> ListView_VoiceSettings;

};

