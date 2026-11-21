// Copyright Epic Games, Inc. All Rights Reserved.

#include "Announcement/FortClientAnnouncement_Conversation.h"
#include "Net/UnrealNetwork.h"

void AFortClientAnnouncement_Conversation::AssetLoadTimeout()
{
}

void AFortClientAnnouncement_Conversation::CurrentSentenceAudioFinished()
{
}

void AFortClientAnnouncement_Conversation::CurrentSentenceAudioTimeout()
{
}

void AFortClientAnnouncement_Conversation::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortClientAnnouncement_Conversation, ConversationData);
}
