// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortParentalControlsSubScreens.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UEditableText;
class UFortCabinEmailManagementWidget;
class UFortSettingRegistry;
class UFortSettingsPanel;

UENUM(BlueprintType)
enum class EParentalControlsViewState : uint8
{
	Invalid = 0,
	EnterPin = 1,
	AskToEnableControls = 2,
	VerifyEmail = 3,
	SetupEmail = 4,
	SetupPin = 5,
	DisplaySettings = 6,
	DisableParentalControls = 7,
	AskToReEnable = 8,
	ReEnabling = 9,
	CabinModeEmailChange = 10,
};

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortParentalControlsSubScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_AskToEnableControls : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AskToEnableControls;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_AskToReEnable : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AskToReEnable;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_CabinModeEmailSubScreen : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortParentalControls_CabinModeEmailSubScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCabinEmailManagementWidget> CabinEmailManagementWidget;

};

UCLASS(Abstract)
class UFortParentalControls_SettingModifyingSubScreen : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_DisableParentalControls : public UFortParentalControls_SettingModifyingSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_DisableParentalControlsConfirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_DisableParentalControlsCancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisablingParentalControlsStatus;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_DisplaySettings : public UFortParentalControls_SettingModifyingSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SaveFail;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SaveSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MoreSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_DisableParentalControls;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingsPanel> Panel_Settings;

	UPROPERTY(Transient)
	TObjectPtr<UFortSettingRegistry> Registry;

};

UCLASS(Abstract)
class UFortParentalControls_PinSubScreen : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleEnterPinTextChanged(const FText& InText);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SubmitPin;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Pin_FailReason;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_Pin_Entry;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_Pin_SecondEntry;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_EnterPin : public UFortParentalControls_PinSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ForgotPin;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_Renabling : public UFortParentalControls_SettingModifyingSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ReEnableFail;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_SetupEmail : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SetupEmail_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SetupEmail;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_SetupPin : public UFortParentalControls_PinSubScreen
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortParentalControls_VerifyEmail : public UFortParentalControlsSubScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_VerifyEmail_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ChangeEmail;

};

