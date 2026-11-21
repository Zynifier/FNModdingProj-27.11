// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortInteractionIndicatorWidget.h"

UFortInteractContextInfoWidget* UFortInteractionIndicatorWidget::ActivateContextOverride(const TSubclassOf<UFortInteractContextInfoWidget>& ContextOverrideWidget, const UFortInteractContextInfo* ContextInfo, bool bPrimary)
{
	return nullptr;
}

void UFortInteractionIndicatorWidget::HandleAddContextOverride(TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget, bool bPrimary)
{
}

void UFortInteractionIndicatorWidget::HandleImprovedDBNOStateChanged(bool bImprovedDBNOEnabled)
{
}

void UFortInteractionIndicatorWidget::HandleRemoveContextOverride(TSubclassOf<UFortInteractContextInfoWidget> ContextOverrideWidget, bool bPrimary)
{
}
