// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortUINotificationQueue.generated.h"

class UFortUINotification;
enum class EFortNotificationPriority : uint8;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnFortNotificationAvailable);

UCLASS(Config=Game, BlueprintType)
class FORTNITEUI_API UFortUINotificationQueue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortUINotificationManager|Basic")
	bool CanNotificationBeQueued(EFortNotificationPriority Priority) const;

	UFUNCTION(BlueprintCallable, Category="FortUINotificationManager|Basic")
	UFortUINotification* GetNextNotification();

	UFUNCTION(BlueprintCallable, Category="FortUINotificationManager|Basic")
	void QueueNotification(UFortUINotification* Notification, bool bShowImmediately = true);

	UFUNCTION(BlueprintCallable, Category="FortUINotificationManager|Basic")
	void RegisterToReceiveNotifications(const FOnFortNotificationAvailable& NotificationDelegate);

	UFUNCTION(BlueprintCallable, Category="FortUINotificationManager|Basic")
	void RemoveNotification(const UFortUINotification* InNotificationDescription);

	UFUNCTION(BlueprintCallable, Category="FortUINotificationManager|Basic")
	void UnregisterToReceiveNotifications();

protected:
	UPROPERTY(BlueprintReadOnly, Config, Category="FortUINotificationManager|Basic")
	int32 MaxNotificationsInQueue;

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortUINotification>> NotificationQueue;

};

