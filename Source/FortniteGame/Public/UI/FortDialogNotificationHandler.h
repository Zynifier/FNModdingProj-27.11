// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDialogTypes.h"
#include "UI/FortNotificationHandler.h"
#include "FortDialogNotificationHandler.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAccepted);

UCLASS(MinimalAPI, BlueprintType)
class UFortDialogNotificationHandler : public UFortNotificationHandler
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActionComplete);

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="Dialog Notification")
	FORTNITEGAME_API void Accept();

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="Dialog Notification")
	FORTNITEGAME_API void Decline();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Dialog Notification")
	FORTNITEGAME_API void SetDialogDescription(FFortDialogDescription InDialogDescription);

	UFUNCTION(BlueprintNativeEvent, BlueprintCosmetic, Category="Dialog Notification")
	FORTNITEGAME_API void Timeout();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Dialog Notification")
	FOnActionComplete OnAccepted;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Dialog Notification")
	FOnActionComplete OnDeclined;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Dialog Notification")
	FOnActionComplete OnTimedOut;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Dialog Notification")
	FFortDialogDescription DialogDescription;

};

