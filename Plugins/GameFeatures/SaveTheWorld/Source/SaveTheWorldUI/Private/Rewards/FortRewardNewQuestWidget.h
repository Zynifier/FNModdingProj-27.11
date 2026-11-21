// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversation.h"
#include "Rewards/FortRewardNotificationSubWidget.h"
#include "FortRewardNewQuestWidget.generated.h"

class UFortConversation;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class UFortRewardNewQuestWidget : public UFortRewardNotificationSubWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	void GetDataFromSentence(const FFortConversationSentence& Sentence, FText& Text, UTexture2D*& TalkingHeadTexture);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	bool IsValidConversation(const UFortConversation* Conversation);

};

