// Copyright Epic Games, Inc. All Rights Reserved.

#include "Announcement/FortClientAnnouncement.h"
#include "Net/UnrealNetwork.h"

void AFortClientAnnouncement::CancelClientAnnouncement()
{
}

int32 AFortClientAnnouncement::GetPriority()
{
	return int32();
}

void AFortClientAnnouncement::StopClientAnnouncement()
{
}

void AFortClientAnnouncement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortClientAnnouncement, AnnouncementID);
	DOREPLIFETIME(AFortClientAnnouncement, Priority);
	DOREPLIFETIME(AFortClientAnnouncement, bInterrupt);
	DOREPLIFETIME(AFortClientAnnouncement, RecipientControllers);
}

void AFortClientAnnouncement_Basic::OnRep_BasicData(const FFortClientAnnouncementData_Basic& PreviousBasicData)
{
}

void AFortClientAnnouncement_Basic::SetDetailText(FText DetailText)
{
}

void AFortClientAnnouncement_Basic::SetDisplayTime(float DisplayTime)
{
}

void AFortClientAnnouncement_Basic::SetIcon(FSlateBrush& Icon)
{
}

void AFortClientAnnouncement_Basic::SetTitleText(FText TitleText)
{
}

void AFortClientAnnouncement_Basic::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortClientAnnouncement_Basic, BasicData);
}
