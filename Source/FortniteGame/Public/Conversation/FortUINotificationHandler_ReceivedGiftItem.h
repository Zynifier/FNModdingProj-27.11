// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortGiftUINotifications.h"
#include "FortUINotificationHandler_ReceivedGiftItem.generated.h"

UCLASS(meta=(DisplayName="UI Notification Handler: Received Item"))
class UFortUINotificationHandler_ReceivedGiftItem : public UGiftUINotificationHandler
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameters")
	bool bCanGenerateMultipleNotifications;

};

