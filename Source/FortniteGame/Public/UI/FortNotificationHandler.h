// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortNotificationHandler.generated.h"

class APlayerController;
class UUserWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortNotificationClearedDelegate);

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortNotificationHandler : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintCosmetic, Category="Notification Navigation")
	FORTNITEGAME_API void ClearNotification();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, BlueprintCosmetic, Category="Notification Navigation")
	FORTNITEGAME_API UUserWidget* CreateWidget(APlayerController* OwningPlayer);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintCosmetic, Category="Notification Navigation")
	FORTNITEGAME_API void NotificationShown();

	UPROPERTY(BlueprintAssignable, Category="Notification Navigation")
	FFortNotificationClearedDelegate OnNotificationCleared;

protected:
	UPROPERTY(BlueprintReadWrite, Category="Notification Navigation")
	bool bNotificationCleared;

};

