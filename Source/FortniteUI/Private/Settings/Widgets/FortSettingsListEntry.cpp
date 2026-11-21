// Copyright Epic Games, Inc. All Rights Reserved.

#include "Settings/Widgets/FortSettingsListEntry.h"

UUserWidget* UFortSettingsListEntrySetting_ControllerButton::GetPopupMenu()
{
	return nullptr;
}

void UFortSettingsListEntrySetting_ControllerButton::HandleActionButtonClicked()
{
}

void UFortSettingsListEntrySetting_Scalar::HandleSliderCaptureEnded()
{
}

void UFortSettingsListEntrySetting_Scalar::HandleSliderValueChanged(float Value)
{
}

UListEntrySettingButton::UListEntrySettingButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UListEntrySettingButton::NotifySettingSelected()
{
}
