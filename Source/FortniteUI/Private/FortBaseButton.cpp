// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortBaseButton.h"

void UFortBaseButton::ForceClick()
{
}

const FMargin UFortBaseButton::GetCurrentButtonPadding() const
{
	return FMargin();
}

const FMargin UFortBaseButton::GetCurrentCustomPadding() const
{
	return FMargin();
}

const FSlateFontInfo UFortBaseButton::GetCurrentFont() const
{
	return FSlateFontInfo();
}

const FFortStateStyle UFortBaseButton::GetCurrentStateStyle() const
{
	return FFortStateStyle();
}

bool UFortBaseButton::GetSelected() const
{
	return false;
}

int32 UFortBaseButton::GetSelectionGroupIndex()
{
	return int32();
}

UFortButtonStyle* UFortBaseButton::GetStyle() const
{
	return nullptr;
}

void UFortBaseButton::OnButtonClicked()
{
}

void UFortBaseButton::SetBangVisibility(bool bVisible)
{
}

void UFortBaseButton::SetBrushSize(EFortBrushSize::Type InSize)
{
}

void UFortBaseButton::SetClickable(bool InClickable)
{
}

void UFortBaseButton::SetClickMethod(EButtonClickMethod::Type InClickMethod)
{
}

void UFortBaseButton::SetHovered(bool InHovered)
{
}

void UFortBaseButton::SetSelected(bool InSelected)
{
}

void UFortBaseButton::SetSelectionGroup(FName InSelectionGroup)
{
}

void UFortBaseButton::SetStyle(TSubclassOf<UFortButtonStyle> InStyle)
{
}

const FSlateBrush UFortButtonStyle::GetBrushBySizeFromMultiSizeBrush(const FFortMultiSizeBrush& MultiSizeBrush, EFortBrushSize::Type Size)
{
	return FSlateBrush();
}

const FMargin UFortButtonStyle::GetButtonPaddingBySize(EFortBrushSize::Type Size) const
{
	return FMargin();
}

const FMargin UFortButtonStyle::GetCustomPaddingBySize(EFortBrushSize::Type Size) const
{
	return FMargin();
}

const FSlateFontInfo UFortButtonStyle::GetFontBySize(EFortBrushSize::Type Size) const
{
	return FSlateFontInfo();
}

const FSlateFontInfo UFortButtonStyle::GetFontBySizeFromMultiSizeFont(const FFortMultiSizeFont& MultiSizeFont, EFortBrushSize::Type Size)
{
	return FSlateFontInfo();
}

const FMargin UFortButtonStyle::GetMarginBySizeFromMultiSizeMargin(const FFortMultiSizeMargin& MultiSizeMargin, EFortBrushSize::Type Size)
{
	return FMargin();
}
