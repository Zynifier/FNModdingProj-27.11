// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonInputManagerLegacy.h"

bool UCommonInputManagerLegacy::GetAvailableInputActions(TArray<FCommonInputActionHandlerData>& AvailableInputActions)
{
	return false;
}

int32 UCommonInputManagerLegacy::GetGlobalInputHandlerPriorityFilter() const
{
	return int32();
}

UCommonActivatablePanelLegacy* UCommonInputManagerLegacy::GetTopPanel() const
{
	return nullptr;
}

bool UCommonInputManagerLegacy::IsInputSuspended() const
{
	return false;
}

bool UCommonInputManagerLegacy::IsPanelOnStack(const UCommonActivatablePanelLegacy* InPanel) const
{
	return false;
}

void UCommonInputManagerLegacy::PopActivatablePanel(UCommonActivatablePanelLegacy* ActivatablePanel)
{
}

void UCommonInputManagerLegacy::PushActivatablePanel(UCommonActivatablePanelLegacy* ActivatablePanel, bool bIntroPanel, bool bOutroPanelBelow)
{
}

void UCommonInputManagerLegacy::ResumeStartingOperationProcessing()
{
}

void UCommonInputManagerLegacy::SetGlobalInputHandlerPriorityFilter(int32 InFilterPriority)
{
}

bool UCommonInputManagerLegacy::StartListeningForExistingHeldAction(const FDataTableRowHandle& InputActionDataRow, const FCommonActionCompleteSingle& CompleteEvent, const FCommonActionProgressSingle& ProgressEvent)
{
	return false;
}

bool UCommonInputManagerLegacy::StopListeningForExistingHeldAction(const FDataTableRowHandle& InputActionDataRow, const FCommonActionCompleteSingle& CompleteEvent, const FCommonActionProgressSingle& ProgressEvent)
{
	return false;
}

void UCommonInputManagerLegacy::SuspendStartingOperationProcessing()
{
}
