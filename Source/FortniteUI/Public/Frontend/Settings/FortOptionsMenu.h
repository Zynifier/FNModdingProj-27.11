// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Styling/SlateBrush.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortTabListWidgetBase.h"
#include "UIManager/AthenaHUDPrimaryContentInterface.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortOptionsMenu.generated.h"

class UCommonBorder;
class UCommonBorderStyle;
class UCommonButtonBase;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortOptionsTab;
class UFortProgressModal;
class UFortTabListWidgetBase_Legacy;
class UNamedSlot;
class UWidget;
enum class ESettingTab : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOptionsApplied);

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortOptionsMenu : public UCommonActivatablePanelLegacy, public IAthenaHUDPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool RequestTab(FName TabId, const FString& SettingDevName);

protected:
	UFUNCTION(BlueprintCallable)
	void AddTabs(TSubclassOf<UFortOptionsTab> WidgetClass, const FText& DisplayName, FName NameId, const FSlateBrush& Icon, ESettingTab TabType);

	UFUNCTION(BlueprintCallable)
	void CenterOnActiveTab();

	UFUNCTION()
	void HandleActiveWidgetChanged(UWidget* ActiveWidget, int32 ActiveWidgetIndex);

	UFUNCTION(BlueprintCallable)
	void HandleApply();

	UFUNCTION(BlueprintCallable)
	void HandleReset();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HandleTabGamepadConfigActionHandlerStates();

	UFUNCTION()
	void HandleTabSelected(FName TabId);

	UFUNCTION(BlueprintCallable)
	void MenuInitialize();

	UFUNCTION(BlueprintCallable)
	void NotifyTabsOfActivationState(UFortOptionsTab* ActivatedTab);

	UFUNCTION(BlueprintImplementableEvent, Category="FortOptionsMenu")
	void OnBack();

	UFUNCTION(BlueprintImplementableEvent, Category="FortOptionsMenu")
	void OnInputsResetToDefault();

	UFUNCTION(BlueprintImplementableEvent, Category="FortOptionsMenu")
	void OnSettingsTabListPopulated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowResetToDefaultModal();

	UFUNCTION(BlueprintImplementableEvent, Category="FortOptionsMenu")
	void OnSplitscreenUpdateSizing();

	UFUNCTION(BlueprintCallable)
	void ResetGameOptionsToDefault(UFortOptionsTab* OptionsTab);

	UFUNCTION(BlueprintCallable)
	void SetBackground();

	UFUNCTION(BlueprintCallable)
	void SetOverrideResetToDefaultModal(const bool bOverride);

	UFUNCTION(BlueprintPure)
	bool ShouldUseNewControllerSettings() const;

	UFUNCTION(BlueprintCallable)
	void UpdateAllOptionTabs();

	UFUNCTION(BlueprintCallable)
	void UpdateHeaderTextByTabId(FName TabId);

	UPROPERTY(EditAnywhere, Category="Primary Content Interface")
	FPrimaryContentSetup PrimaryContentSetup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ApplyInputAction;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ApplyAndTestInputAction;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle TestInputAction;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleModeInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ResetToDefaultInputAction;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InputsResetToDefaulInputAction;

	UPROPERTY(EditAnywhere, Category="FortOptionsMenu", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> VideoTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> TabVideoOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> GameplayTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> HUDTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> TouchOptionsClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> TouchWeaponOptionsClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> KeyboardMouseClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> ControllerSensitivityTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> ControllerSettingsOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> AudioOptionsClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> InputTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> TabInputOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> GamepadTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> GamepadTabClassV2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> TabGamepadOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> TabGamepadOptionsV2;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TabClasses")
	TSubclassOf<UFortOptionsTab> AccountTabClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabClasses")
	TSoftClassPtr<UFortOptionsTab> TabAccountOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortOptionsMenu")
	TSubclassOf<UCommonBorderStyle> BorderBackgroundStyle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortOptionsMenu")
	TSubclassOf<UFortProgressModal> ProgressModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortOptionsMenu")
	TSubclassOf<UCommonButtonBase> IconTabButtonClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortOptionsMenu", meta=(EditInline="true"))
	TObjectPtr<UFortProgressModal> SavingModalInstance;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	TArray<FName> TabIds;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	TArray<FFortTabButtonLabelInfo> TabLabels;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortOptionsMenu", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortOptionsTab>> TabWidgets;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	FTimerHandle ResetVideoOptionsTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush VideoBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush GameplayBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush GameUIBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush TouchOptionsBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush TouchWeaponOptionsBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush KeyboardMouseBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush ControllerSensitivityBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush AudioBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush InputBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush GamepadOptionsBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TabBrushes")
	FSlateBrush AccountPrivacyBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortOptionsMenu")
	FGameplayTagContainer HUDHideOnMenuTags;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	bool bVideoTabSelected;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	bool bApplyVisible;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	bool bIsLanguageConfirmationVisible;

	UPROPERTY(BlueprintReadWrite, Category="FortOptionsMenu")
	bool bIsLeavingOptionsMenu;

private:
	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void ApplySettingss();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void ClearCachedEula();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void ExitIfTabSaved();

	UFUNCTION(BlueprintCallable)
	void HandleResetAvailableActionHandlerStates();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool NeedsLanguageChangeConfirmation();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool NeedsVideoChangeConfirmation();

	UFUNCTION()
	void OnApplyAndTest(bool& PassThrough);

	UFUNCTION()
	void OnApplySettingsInternal(bool& PassThrough);

	UFUNCTION()
	void OnBackInternal(bool& PassThrough);

	UFUNCTION()
	void OnInputResetToDefaultInternal(bool& PassThrough);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void OnReset();

	UFUNCTION()
	void OnResetToDefaultInternal(bool& PassThrough);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void OnResetToDefaults(int32 PresetToSet);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void OnRestoreToInitial();

	UFUNCTION(BlueprintCallable)
	void OnTabSettingChanged();

	UFUNCTION()
	void OnTest(bool& PassThrough);

	UFUNCTION()
	void OnToggleModeInternal(bool& PassThrough);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void OnVideoAccept();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void OnVideoCancel();

	UFUNCTION(BlueprintCallable, Category="FortGameOptions")
	void ResetActionHandlerStates(bool bIsBackButtonDisabled);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void ResetClientHUDSettings();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	void SetApplyOrTest(bool bShowApply);

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowAccountOptions();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowControllerOptions();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowInputOptions();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowNewControllerSenseOptions();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowTouchAndMotionOptions();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowTouchWeaponOptions();

	UFUNCTION(BlueprintCallable)
	void ShowUnsavedConfirmation();

	UFUNCTION(BlueprintCallable, Category="FortOptionsMenu")
	bool ShowVideoOptions();

	UFUNCTION(BlueprintCallable)
	void UpdateBasedOnActiveWidget(UWidget* ActiveWidget, bool bShouldCenterOnTab);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> TabList_Categories;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> SettingTabSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UNamedSlot> SavingLayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonBorder> Message;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonBase> VideoSettingsAccept;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonButtonBase> VideoSettingsCancel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsMenu", meta=(AllowPrivateAccess, BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Background;

};

