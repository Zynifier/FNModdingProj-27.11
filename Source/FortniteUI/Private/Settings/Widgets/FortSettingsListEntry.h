// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "Blueprint/UserWidget.h"
#include "CommonUserWidget.h"
#include "FortSettingsListEntry.generated.h"

class UAnalogSlider;
class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortControllerActionsMenu;
class UFortInputSettingBase;
class UFortKeybindWidget;
class UFortSetting;
class UFortSettingAction;
class UFortSettingCollectionPage;
class UFortSettingControllerInput;
class UFortSettingValueDiscrete;
class UFortSettingValueScalar;
class UFortSettingsPressAnyKey;
class UFortSettingsPreviewActionUnbind;
class UFortSettingsRotator;
class UImage;
class UListEntrySettingButton;
class UMenuAnchor;
class UPanelWidget;
class UUserWidget;
class UWidget;

UCLASS(Abstract, NotBlueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntryBase : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetPrimaryGamepadFocusWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEditableStateChanged(const bool bIsEditable);

	UPROPERTY()
	TObjectPtr<UFortSetting> Setting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntryBase", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UUserWidget> Background;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntry_Setting : public UFortSettingsListEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntry_Setting", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SettingName;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_Action : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingAssigned(const FText& ActionText, bool bShowKeybindWidget);

	UPROPERTY()
	TObjectPtr<UFortSettingAction> ActionSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Action", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Action;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_ControllerButton : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	UUserWidget* GetPopupMenu();

	UFUNCTION(BlueprintCallable)
	void HandleActionButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingAssigned(const FText& ActionText);

	UPROPERTY(EditAnywhere, Category="FortSettingsListEntrySetting_ControllerButton")
	TSubclassOf<UFortControllerActionsMenu> BindingMenuClass;

	UPROPERTY()
	TObjectPtr<UFortSettingControllerInput> ControllerInputSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_ControllerButton", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Key_ControllerButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_ControllerButton", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UMenuAnchor> MenuAnchor_BindableActions;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_Discrete : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscrete> DiscreteSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Discrete", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Value;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Discrete", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortSettingsRotator> Rotator_SettingValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Discrete", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Decrease;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Discrete", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Increase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Discrete", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UImage> OptionsModifiedIndicator;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_DiscreteButtons : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingSet(const int32 NewSetting);

	UPROPERTY(EditDefaultsOnly, Category="FortSettingsListEntrySetting_DiscreteButtons")
	TSubclassOf<UListEntrySettingButton> SettingButtonClass;

	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscrete> DiscreteSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_DiscreteButtons", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true", EntryClass="ListEntrySettingButton"))
	TObjectPtr<UDynamicEntryBox> SettingButtonEntryBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_DiscreteButtons", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Decrease;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_DiscreteButtons", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Increase;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_DiscreteButtons", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AdditionalDescription;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_KeyboardInput : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateKeyText(const FText& PrimaryKeyText, const FText& SecondaryKeyText);

	UPROPERTY()
	TObjectPtr<UFortInputSettingBase> InputSetting;

	UPROPERTY(EditDefaultsOnly, Category="FortSettingsListEntrySetting_KeyboardInput")
	TSubclassOf<UFortSettingsPressAnyKey> PressAnyKeyPanelClass;

	UPROPERTY(EditDefaultsOnly, Category="FortSettingsListEntrySetting_KeyboardInput")
	TSubclassOf<UFortSettingsPreviewActionUnbind> PreviewActionUnbindClass;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_KeyboardInput", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PrimaryKey;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_KeyboardInput", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SecondaryKey;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_KeyboardInput", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Clear;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_Navigation : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingAssigned(const FText& ActionText);

	UPROPERTY()
	TObjectPtr<UFortSettingCollectionPage> CollectionSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Navigation", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Navigate;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsListEntrySetting_Scalar : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleSliderCaptureEnded();

	UFUNCTION()
	void HandleSliderValueChanged(float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDefaultValueChanged(float DefaultValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnValueChanged(float Value);

	UPROPERTY()
	TObjectPtr<UFortSettingValueScalar> ScalarSetting;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Scalar", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Value;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Scalar", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UAnalogSlider> Slider_SettingValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsListEntrySetting_Scalar", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SettingValue;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Settings", DisableNativeTick))
class UListEntrySettingButton : public UUserWidget
{
	GENERATED_BODY()

public:
	UListEntrySettingButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingSelectionChanged(int32 ButtonIndex, int32 SelectedSettingIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void SetOptionText(const FText& NewOptionText);

protected:
	UFUNCTION(BlueprintCallable)
	void NotifySettingSelected();

};

