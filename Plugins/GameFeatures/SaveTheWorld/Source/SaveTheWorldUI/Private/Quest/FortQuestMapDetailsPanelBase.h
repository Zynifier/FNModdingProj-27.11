// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "FortQuestMapDetailsPanelBase.generated.h"

class AFortClientAnnouncement_Conversation;
class UFortQuestItemDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortQuestMapDetailsPanelBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetQuestToDisplay(UFortQuestItemDefinition* QuestDef);

	UFUNCTION(BlueprintCallable)
	void SetScrollWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Details Panel")
	TSubclassOf<AFortClientAnnouncement_Conversation> QuestConversationClass;

private:
	UFUNCTION()
	void HandleQuestsUpdatedInternal();

	UPROPERTY(EditAnywhere, Category="FortQuestMapDetailsPanelBase")
	float QuestUpdateDelayTime;

	UPROPERTY()
	FTimerHandle QuestUpdateTimerHandle;

};

