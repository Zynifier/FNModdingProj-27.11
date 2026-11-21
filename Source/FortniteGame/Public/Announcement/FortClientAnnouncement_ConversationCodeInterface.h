// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversation.h"
#include "FortClientAnnouncement_ConversationCodeInterface.generated.h"

UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UFortClientAnnouncement_ConversationCodeInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortClientAnnouncement_ConversationCodeInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool IsPlayingConversation(bool bCheckAudioComponent = true) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool IsPlayingSentence(const FFortConversationSentence& Sentence) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool IsPlayingSentenceIndex(int32 SentenceIndex) const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool PlayConversation();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool PlayConversationFromSentence(const FFortConversationSentence& StartingSentence);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual bool PlayConversationFromSentenceIndex(int32 StartingSentenceIndex);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Announcement|Conversation")
	virtual void StopConversation();

};

