// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Announcement/FortClientAnnouncement_Conversation.h"
#include "Announcement/FortClientAnnouncement_Tutorial.h"
#include "Announcement/FortClientAnnouncement_TutorialInterface.h"
#include "FortClientAnnouncement_TutorialConversation.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation", "Input", "Actor", "Replication", "Rendering", "navigation"))
class AFortClientAnnouncement_TutorialConversation : public AFortClientAnnouncement_Conversation, public IFortClientAnnouncement_TutorialInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Announcement|Tutorial", meta=(ExposeOnSpawn="TRUE"))
	FFortClientAnnouncementData_Tutorial TutorialData;

protected:
	UFUNCTION()
	void OnRep_TutorialData(const FFortClientAnnouncementData_Tutorial& PreviousTutorialData);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Announcement|Tutorial")
	float AutoContinueDelay;

};

