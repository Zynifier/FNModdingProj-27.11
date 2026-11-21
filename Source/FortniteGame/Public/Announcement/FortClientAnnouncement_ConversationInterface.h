// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversation.h"
#include "FortClientAnnouncement_ConversationInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UFortClientAnnouncement_ConversationInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortClientAnnouncement_ConversationInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement|Conversation")
	void OnConversationFinished(FFortConversationSentence FinishingSentence, int32 FinishingSentenceSentenceIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement|Conversation")
	void OnConversationStarted(FFortConversationSentence StartingSentence, int32 StartingSentenceIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement|Conversation")
	void OnSentenceFinished(const FFortConversationSentence& Sentence, int32 SentenceIndex);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Announcement|Conversation")
	void OnSentenceStarted(const FFortConversationSentence& Sentence, int32 SentenceIndex);

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="Announcement|Conversation")
	bool ShouldPlaySentence(const FFortConversationSentence& NewSentence) const;

};

