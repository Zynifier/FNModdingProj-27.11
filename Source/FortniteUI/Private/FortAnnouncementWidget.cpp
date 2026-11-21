// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAnnouncementWidget.h"

void UFortAnnouncementWidget::BindUpdateEvents(AFortClientAnnouncement* Announcement)
{
}

FName UFortAnnouncementWidget::FindFirstUnboundAction(FText AnnouncementBody)
{
	return FName();
}

FText UFortAnnouncementWidget::GetTextForAction(const FName& ActionName) const
{
	return FText();
}
