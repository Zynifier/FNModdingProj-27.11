// Copyright Epic Games, Inc. All Rights Reserved.

#include "Announcement/FortClientAnnouncement_ConversationCodeInterface.h"

bool IFortClientAnnouncement_ConversationCodeInterface::IsPlayingConversation(bool bCheckAudioComponent) const
{
	return false;
}

bool IFortClientAnnouncement_ConversationCodeInterface::IsPlayingSentence(const FFortConversationSentence& Sentence) const
{
	return false;
}

bool IFortClientAnnouncement_ConversationCodeInterface::IsPlayingSentenceIndex(int32 SentenceIndex) const
{
	return false;
}

bool IFortClientAnnouncement_ConversationCodeInterface::PlayConversation()
{
	return false;
}

bool IFortClientAnnouncement_ConversationCodeInterface::PlayConversationFromSentence(const FFortConversationSentence& StartingSentence)
{
	return false;
}

bool IFortClientAnnouncement_ConversationCodeInterface::PlayConversationFromSentenceIndex(int32 StartingSentenceIndex)
{
	return false;
}

void IFortClientAnnouncement_ConversationCodeInterface::StopConversation()
{
}
