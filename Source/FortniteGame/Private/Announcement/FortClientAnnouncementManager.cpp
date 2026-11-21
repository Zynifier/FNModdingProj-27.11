// Copyright Epic Games, Inc. All Rights Reserved.

#include "Announcement/FortClientAnnouncementManager.h"
#include "Net/UnrealNetwork.h"

void AFortClientAnnouncementManager::OnRep_CancelledAnnouncements()
{
}

void AFortClientAnnouncementManager::OnRep_ClientAnnouncements(TArray<TWeakObjectPtr<AFortClientAnnouncement>>& PreviousClientAnnouncements)
{
}

void AFortClientAnnouncementManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortClientAnnouncementManager, ClientAnnouncements);
	DOREPLIFETIME(AFortClientAnnouncementManager, CancelledAnnouncements);
}
