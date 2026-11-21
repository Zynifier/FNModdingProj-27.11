// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortUINotification.h"

void UFortUINotification::ClearNotification_Implementation()
{
}

const FText& UFortUINotification::GetDescription() const
{
	static FText Dummy;
	return Dummy;
}

const TSoftObjectPtr<UObject>& UFortUINotification::GetDisplayAsset() const
{
	static TSoftObjectPtr<UObject> Dummy;
	return Dummy;
}

float UFortUINotification::GetDisplayTimeOverride() const
{
	return float();
}

const FUniqueNetIdRepl& UFortUINotification::GetIdToRepresent() const
{
	static FUniqueNetIdRepl Dummy;
	return Dummy;
}

EFortNotificationType UFortUINotification::GetNotificationType() const
{
	return EFortNotificationType();
}

EFortNotificationPriority UFortUINotification::GetPriority() const
{
	return EFortNotificationPriority();
}

const FText& UFortUINotification::GetTitle() const
{
	static FText Dummy;
	return Dummy;
}

bool UFortUINotification::HasAction() const
{
	return false;
}

bool UFortUINotification::IsLongNotification() const
{
	return false;
}

void UFortUINotification::NotificationShown_Implementation()
{
}

void UFortUINotification::SetDescription(const FText& InDescription)
{
}

void UFortUINotification::SetDisplayAsset(const TSoftObjectPtr<UObject>& InDisplayAsset)
{
}

void UFortUINotification::SetDisplayTimeOverride(const float InDisplayTimeOverride)
{
}

void UFortUINotification::SetHasAction(const bool bInHasAction)
{
}

void UFortUINotification::SetIdToRepresent(const FUniqueNetIdRepl& InIdToRepresent)
{
}

void UFortUINotification::SetIsLongNotification(const bool bInIsLongNotification)
{
}

void UFortUINotification::SetNotificationType(const EFortNotificationType InNotificationType)
{
}

void UFortUINotification::SetPriority(const EFortNotificationPriority InPriority)
{
}

void UFortUINotification::SetTitle(const FText& InTitle)
{
}

bool UFortUINotification::ShouldShowNotification() const
{
	return false;
}

void UFortUINotification::TakeAction()
{
}
