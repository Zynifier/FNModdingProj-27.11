// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIManager/FortUIManagerWidget_NUI.h"

EFortUIState UFortUIManagerWidget_NUI::_BPGetCurrentUIState() const
{
	return EFortUIState();
}

UFortUINotification* UFortUIManagerWidget_NUI::CreateNotification(TSubclassOf<UFortUINotification> UINotificationClass)
{
	return nullptr;
}

UFortUIManagerWidget_NUI* UFortUIManagerWidget_NUI::GetUIManagerWidget(const UObject* WorldContextObject)
{
	return nullptr;
}

UFortUINotificationQueue* UFortUIManagerWidget_NUI::GetUINotificationQueue(UObject* WorldContextObject, EFortNotificationQueueType QueueType)
{
	return nullptr;
}

void UFortUIManagerWidget_NUI::HandleConfirmationWindowDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel)
{
}

void UFortUIManagerWidget_NUI::HandleDeactivatedModal(UCommonActivatablePanelLegacy* DeactivatedPanel)
{
}

void UFortUIManagerWidget_NUI::HandleErrorWindowDeactivated(UCommonActivatablePanelLegacy* RemovedPanel)
{
}

bool UFortUIManagerWidget_NUI::IsStateContentChildShowing() const
{
	return false;
}

void UFortUIManagerWidget_NUI::KillConfirmationDialog(UObject* WorldContextObject)
{
}

void UFortUIManagerWidget_NUI::NativeClearLayers()
{
}

void UFortUIManagerWidget_NUI::RequestClearConfirmationLayer()
{
}
