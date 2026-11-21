// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortDialogNotificationHandler.h"
#include "FortQuestNotificationHandler.generated.h"

class UFortQuestItem;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UFortQuestNotificationHandler : public UFortDialogNotificationHandler
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Quest Notification")
	TObjectPtr<UFortQuestItem> Quest;

};

