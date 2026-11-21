// Copyright Epic Games, Inc. All Rights Reserved.

#include "Notifications/FortUINotificationQueue.h"

bool UFortUINotificationQueue::CanNotificationBeQueued(EFortNotificationPriority Priority) const
{
	return false;
}

UFortUINotification* UFortUINotificationQueue::GetNextNotification()
{
	return nullptr;
}

void UFortUINotificationQueue::QueueNotification(UFortUINotification* Notification, bool bShowImmediately)
{
}

void UFortUINotificationQueue::RegisterToReceiveNotifications(const FOnFortNotificationAvailable& NotificationDelegate)
{
}

void UFortUINotificationQueue::RemoveNotification(const UFortUINotification* InNotificationDescription)
{
}

void UFortUINotificationQueue::UnregisterToReceiveNotifications()
{
}
