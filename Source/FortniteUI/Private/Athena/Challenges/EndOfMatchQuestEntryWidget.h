// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "EndOfMatchQuestEntryWidget.generated.h"

class UFortNotificationEntry_Quest;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UEndOfMatchQuestEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndOfMatchQuestCreateFinished);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndOfMatchQuestMoveDownFinished);

public:
	UPROPERTY(BlueprintCallable)
	FOnEndOfMatchQuestCreateFinished OnEndOfMatchQuestIntroFinishedDelegate;

	UPROPERTY(BlueprintCallable)
	FOnEndOfMatchQuestMoveDownFinished OnEndOfMatchQuestMoveDownFinishedDelegate;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleMoveDownFinished();

	UPROPERTY(EditAnywhere, Category="EndOfMatchQuestEntryWidget", meta=(ClampMin="0.1", DisplayName="Move Down Animation Duration"))
	float MoveDownDuration;

	UPROPERTY(BlueprintReadOnly, Export, Category="EndOfMatchQuestEntryWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortNotificationEntry_Quest> QuestNotification;

private:
	UFUNCTION()
	void HandleNotificationDisplayed();

};

