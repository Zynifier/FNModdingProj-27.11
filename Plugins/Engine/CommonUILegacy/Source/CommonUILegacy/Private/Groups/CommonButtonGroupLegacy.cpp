// Copyright Epic Games, Inc. All Rights Reserved.

#include "Groups/CommonButtonGroupLegacy.h"

UCommonButtonGroupLegacy* UCommonButtonGroupLegacy::CreateButtonGroup(UObject* ContextObject, bool bInSelectionRequired)
{
	return nullptr;
}

UCommonButtonLegacy* UCommonButtonGroupLegacy::GetButtonAtIndex(int32 Index) const
{
	return nullptr;
}

UCommonButtonLegacy* UCommonButtonGroupLegacy::GetSelectedButton() const
{
	return nullptr;
}

void UCommonButtonGroupLegacy::HandleNativeOnButtonClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleNativeOnButtonDoubleClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleNativeOnHoveredButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleNativeOnSelectedButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleOnButtonClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleOnButtonDoubleClicked(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleOnHoveredButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::HandleOnSelectedButtonChanged(UCommonButtonBase* BaseButton, int32 InSelectedButtonIndex)
{
}

void UCommonButtonGroupLegacy::OnButtonHovered(UCommonButtonLegacy* BaseButton)
{
}

void UCommonButtonGroupLegacy::OnButtonUnhovered(UCommonButtonLegacy* BaseButton)
{
}

void UCommonButtonGroupLegacy::OnHandleButtonClicked(UCommonButtonLegacy* BaseButton)
{
}

void UCommonButtonGroupLegacy::OnHandleButtonDoubleClicked(UCommonButtonLegacy* BaseButton)
{
}

void UCommonButtonGroupLegacy::OnSelectionStateChanged(UCommonButtonLegacy* BaseButton, bool bIsSelected)
{
}
