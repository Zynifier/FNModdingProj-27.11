// Copyright Epic Games, Inc. All Rights Reserved.

#include "Frontend/Settings/FortOptionsMenu.h"

void UFortOptionsMenu::AddTabs(TSubclassOf<UFortOptionsTab> WidgetClass, const FText& DisplayName, FName NameId, const FSlateBrush& Icon, ESettingTab TabType)
{
}

void UFortOptionsMenu::ApplySettingss()
{
}

void UFortOptionsMenu::CenterOnActiveTab()
{
}

void UFortOptionsMenu::ClearCachedEula()
{
}

void UFortOptionsMenu::ExitIfTabSaved()
{
}

void UFortOptionsMenu::HandleActiveWidgetChanged(UWidget* ActiveWidget, int32 ActiveWidgetIndex)
{
}

void UFortOptionsMenu::HandleApply()
{
}

void UFortOptionsMenu::HandleReset()
{
}

void UFortOptionsMenu::HandleResetAvailableActionHandlerStates()
{
}

void UFortOptionsMenu::HandleTabSelected(FName TabId)
{
}

void UFortOptionsMenu::MenuInitialize()
{
}

bool UFortOptionsMenu::NeedsLanguageChangeConfirmation()
{
	return false;
}

bool UFortOptionsMenu::NeedsVideoChangeConfirmation()
{
	return false;
}

void UFortOptionsMenu::NotifyTabsOfActivationState(UFortOptionsTab* ActivatedTab)
{
}

void UFortOptionsMenu::OnApplyAndTest(bool& PassThrough)
{
}

void UFortOptionsMenu::OnApplySettingsInternal(bool& PassThrough)
{
}

void UFortOptionsMenu::OnBackInternal(bool& PassThrough)
{
}

void UFortOptionsMenu::OnInputResetToDefaultInternal(bool& PassThrough)
{
}

void UFortOptionsMenu::OnReset()
{
}

void UFortOptionsMenu::OnResetToDefaultInternal(bool& PassThrough)
{
}

void UFortOptionsMenu::OnResetToDefaults(int32 PresetToSet)
{
}

void UFortOptionsMenu::OnRestoreToInitial()
{
}

void UFortOptionsMenu::OnTabSettingChanged()
{
}

void UFortOptionsMenu::OnTest(bool& PassThrough)
{
}

void UFortOptionsMenu::OnToggleModeInternal(bool& PassThrough)
{
}

void UFortOptionsMenu::OnVideoAccept()
{
}

void UFortOptionsMenu::OnVideoCancel()
{
}

bool UFortOptionsMenu::RequestTab(FName TabId, const FString& SettingDevName)
{
	return false;
}

void UFortOptionsMenu::ResetActionHandlerStates(bool bIsBackButtonDisabled)
{
}

void UFortOptionsMenu::ResetClientHUDSettings()
{
}

void UFortOptionsMenu::ResetGameOptionsToDefault(UFortOptionsTab* OptionsTab)
{
}

void UFortOptionsMenu::SetApplyOrTest(bool bShowApply)
{
}

void UFortOptionsMenu::SetBackground()
{
}

void UFortOptionsMenu::SetOverrideResetToDefaultModal(const bool bOverride)
{
}

bool UFortOptionsMenu::ShouldUseNewControllerSettings() const
{
	return false;
}

bool UFortOptionsMenu::ShowAccountOptions()
{
	return false;
}

bool UFortOptionsMenu::ShowControllerOptions()
{
	return false;
}

bool UFortOptionsMenu::ShowInputOptions()
{
	return false;
}

bool UFortOptionsMenu::ShowNewControllerSenseOptions()
{
	return false;
}

bool UFortOptionsMenu::ShowTouchAndMotionOptions()
{
	return false;
}

bool UFortOptionsMenu::ShowTouchWeaponOptions()
{
	return false;
}

void UFortOptionsMenu::ShowUnsavedConfirmation()
{
}

bool UFortOptionsMenu::ShowVideoOptions()
{
	return false;
}

void UFortOptionsMenu::UpdateAllOptionTabs()
{
}

void UFortOptionsMenu::UpdateBasedOnActiveWidget(UWidget* ActiveWidget, bool bShouldCenterOnTab)
{
}

void UFortOptionsMenu::UpdateHeaderTextByTabId(FName TabId)
{
}
