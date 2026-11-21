// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Announcement/FortClientAnnouncement.h"
#include "Announcement/FortClientAnnouncement_ConversationCodeInterface.h"
#include "Announcement/FortClientAnnouncement_ConversationInterface.h"
#include "FortClientAnnouncement_Conversation.generated.h"

class UAudioComponent;
class UFortConversation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnnouncementConversationDelegate);

USTRUCT(BlueprintType)
struct FFortClientAnnouncementData_Conversation : public FFortClientAnnouncementData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Conversation")
	TObjectPtr<UFortConversation> Conversation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Conversation")
	EFortAnnouncementDisplayPreference ConversationDisplayPreference;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_Conversation : public AFortClientAnnouncement, public IFortClientAnnouncement_ConversationInterface, public IFortClientAnnouncement_ConversationCodeInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Announcement|Conversation", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_Conversation ConversationData;

	UPROPERTY(BlueprintAssignable, Category="Announcement")
	FAnnouncementConversationDelegate OnConversationStarted;

	UPROPERTY(BlueprintAssignable, Category="Announcement")
	FAnnouncementConversationDelegate OnConversationStopped;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> SpeechComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Announcement|Conversation")
	bool bAutoPlayConversation;

	UPROPERTY()
	bool bCurrentlyPlaying;

	UPROPERTY()
	int32 CurrentSentenceIndex;

private:
	UFUNCTION()
	void AssetLoadTimeout();

	UFUNCTION()
	void CurrentSentenceAudioFinished();

	UFUNCTION()
	void CurrentSentenceAudioTimeout();

};

