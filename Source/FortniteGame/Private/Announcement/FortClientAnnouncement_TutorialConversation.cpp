// Copyright Epic Games, Inc. All Rights Reserved.

#include "Announcement/FortClientAnnouncement_TutorialConversation.h"
#include "Net/UnrealNetwork.h"

void AFortClientAnnouncement_TutorialConversation::OnRep_TutorialData(const FFortClientAnnouncementData_Tutorial& PreviousTutorialData)
{
}

void AFortClientAnnouncement_TutorialConversation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortClientAnnouncement_TutorialConversation, TutorialData);
}
