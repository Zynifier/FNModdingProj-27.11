// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonActivatablePanelLegacy.h"

void UCommonActivatablePanelLegacy::AddInputActionHandler(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent)
{
}

void UCommonActivatablePanelLegacy::AddInputActionHandlerWithPopup(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, UCommonPopupMenuLegacy* PopupMenu)
{
}

void UCommonActivatablePanelLegacy::AddInputActionHandlerWithProgress(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent)
{
}

void UCommonActivatablePanelLegacy::AddInputActionHandlerWithProgressPopup(UDataTable* DataTable, FName RowName, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent, UCommonPopupMenuLegacy* PopupMenu)
{
}

void UCommonActivatablePanelLegacy::AddInputActionNoHandler(UDataTable* DataTable, FName RowName)
{
}

void UCommonActivatablePanelLegacy::BeginIntro()
{
}

void UCommonActivatablePanelLegacy::BeginOutro()
{
}

void UCommonActivatablePanelLegacy::EndIntro()
{
}

void UCommonActivatablePanelLegacy::EndOutro()
{
}

bool UCommonActivatablePanelLegacy::GetInputActions(TArray<FCommonInputActionHandlerData>& InputActionDataRows) const
{
	return false;
}

bool UCommonActivatablePanelLegacy::HasInputActionHandler(FDataTableRowHandle InputActionRow) const
{
	return false;
}

bool UCommonActivatablePanelLegacy::IsInActivationStack() const
{
	return false;
}

bool UCommonActivatablePanelLegacy::IsIntroed() const
{
	return false;
}

void UCommonActivatablePanelLegacy::OnBeginIntro_Implementation()
{
}

void UCommonActivatablePanelLegacy::OnBeginOutro_Implementation()
{
}

void UCommonActivatablePanelLegacy::PopPanel()
{
}

void UCommonActivatablePanelLegacy::RemoveAllInputActionHandlers()
{
}

void UCommonActivatablePanelLegacy::RemoveInputActionHandler(FDataTableRowHandle InputActionRow)
{
}

void UCommonActivatablePanelLegacy::SetActionHandlerState(const UDataTable* DataTable, FName RowName, EInputActionState State)
{
}

void UCommonActivatablePanelLegacy::SetActionHandlerStateFromHandle(FDataTableRowHandle InputActionRow, EInputActionState State)
{
}

void UCommonActivatablePanelLegacy::SetActionHandlerStateFromHandleWithDisabledCommitEvent(FDataTableRowHandle InputActionRow, EInputActionState State, FCommonActionCommited DisabledCommitEvent)
{
}

void UCommonActivatablePanelLegacy::SetActionHandlerStateWithDisabledCommitEvent(UDataTable* DataTable, FName RowName, EInputActionState State, FCommonActionCommited DisabledCommitEvent)
{
}

void UCommonActivatablePanelLegacy::SetInputActionHandler(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent)
{
}

void UCommonActivatablePanelLegacy::SetInputActionHandlerWithPopupMenu(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, UCommonPopupMenuLegacy* PopupMenu)
{
}

void UCommonActivatablePanelLegacy::SetInputActionHandlerWithProgress(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent)
{
}

void UCommonActivatablePanelLegacy::SetInputActionHandlerWithProgressPopupMenu(FDataTableRowHandle InputActionRow, FCommonActionCommited CommitedEvent, FCommonActionProgressSingle ProgressEvent, UCommonPopupMenuLegacy* PopupMenu)
{
}

bool UCommonActivatablePanelLegacy::HandleHoldInput(int32 ControllerId, FKey KeyPressed, EInputEvent EventType, bool& bPassThrough)
{
	return false;
}

bool UCommonActivatablePanelLegacy::HandlePressInput(FKey KeyPressed, EInputEvent EventType, bool& bPassThrough)
{
	return false;
}

bool UCommonActivatablePanelLegacy::HandleTouchInput(uint32 TouchId, ETouchType::Type TouchType, const FVector2D& TouchLocation, bool& bPassThrough)
{
	return false;
}

void UCommonActivatablePanelLegacy::UpdateCurrentlyHeldAction(float InDeltaTime)
{
}

void UCommonActivatablePanelLegacy::TriggerFirstMatchingInputAction(int32 ControllerId, const FCommonInputActionDataBase& InInputActionData, bool bHoldAction)
{
}
