// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeRichTextEditorWidget.h"

bool UFortCreativeRichTextEditorWidget::CanShowStyleEditor() const
{
	return false;
}

void UFortCreativeRichTextEditorWidget::ClearSelectedWordButtons()
{
}

EButtonContext UFortCreativeRichTextEditorWidget::GetButtonContext()
{
	return EButtonContext();
}

FString UFortCreativeRichTextEditorWidget::GetTextInRange()
{
	return FString();
}

void UFortCreativeRichTextEditorWidget::HandleStyleButtonClicked(UCommonButtonBase* Button, int32 Index)
{
}

void UFortCreativeRichTextEditorWidget::HandleTabButtonSelected(UCommonButtonBase* AssociatedButton, const int32 ButtonIndex)
{
}

void UFortCreativeRichTextEditorWidget::HandleTextChanged(const FText& Text)
{
}

void UFortCreativeRichTextEditorWidget::HandleWordButtonClicked(UFortCreativeRichTextWordButton* Button)
{
}

void UFortCreativeRichTextEditorWidget::HandleWordButtonHovered(UFortCreativeRichTextWordButton* Button)
{
}

bool UFortCreativeRichTextEditorWidget::IsStyleEditorEnabled()
{
	return false;
}

void UFortCreativeRichTextEditorWidget::SetAllowLineBreaks(bool InAllowLineBreaks)
{
}

void UFortCreativeRichTextEditorWidget::SetAllowStyleEditing(bool InAllowStyleEditing)
{
}

void UFortCreativeRichTextEditorWidget::SetEntryCharLimit(int32 InCharLimit)
{
}

void UFortCreativeRichTextEditorWidget::SetRichStyleSetOverride(UDataTable* RichStyleSetOverride)
{
}

void UFortCreativeRichTextEditorWidget::ShowConfirmationDialog(EConfirmDialogType DialogType)
{
}
