// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortKeybindWidget.h"

bool UFortKeybindWidget::GetBrushForKey(EFortBrushSize::Type InBrushSize, FSlateBrush& Brush) const
{
	return false;
}

EFortBrushSize::Type UFortKeybindWidget::GetBrushSize() const
{
	return EFortBrushSize::Type();
}

bool UFortKeybindWidget::IsBoundKeyValid() const
{
	return false;
}

bool UFortKeybindWidget::IsHoldKeybind() const
{
	return false;
}

void UFortKeybindWidget::SetAxisScale(const float NewValue)
{
}

void UFortKeybindWidget::SetBoundAction(FName NewBoundAction)
{
}

void UFortKeybindWidget::SetBoundInputAction(UInputAction* NewAction)
{
}

void UFortKeybindWidget::SetBoundKey(FKey NewBoundAction)
{
}

void UFortKeybindWidget::SetBrushSize(EFortBrushSize::Type InBrushSize)
{
}

void UFortKeybindWidget::SetForcedHoldKeybind(bool InForcedHoldKeybind)
{
}

void UFortKeybindWidget::SetForcedHoldKeybindStatus(EFortKeybindForcedHoldStatus InForcedHoldKeybindStatus)
{
}

void UFortKeybindWidget::SetInputContextOverride(UInputMappingContext* NewContextOverride)
{
}

void UFortKeybindWidget::SetPresetNameOverride(const FName NewValue)
{
}

void UFortKeybindWidget::SetShowProgressCountDown(bool bShow)
{
}

void UFortKeybindWidget::StartHoldProgress(FName HoldActionName, float HoldDuration)
{
}

void UFortKeybindWidget::StopHoldProgress(FName HoldActionName, bool bCompletedSuccessfully)
{
}

void UFortKeybindWidget::UpdateKeybindWidget()
{
}
