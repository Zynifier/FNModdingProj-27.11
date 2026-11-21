// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortUIMessageManager.generated.h"

class APlayerController;
class UFortUIMessageItemWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMessageAvailable);

UCLASS(BlueprintType)
class UFortUIMessageManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MessageManager")
	UFortUIMessageItemWidget* AddMessageItem(TSubclassOf<UFortUIMessageItemWidget> MessageItemClass, APlayerController* OwningPlayer, FName MessageID, int32 StackCount = 1);

	UFUNCTION(BlueprintCallable, Category="MessageManager")
	UFortUIMessageItemWidget* GetNextMessageInQueue();

	UFUNCTION(BlueprintPure, Category="MessageManager")
	int32 GetNumDisplayedItems() const;

	UPROPERTY(BlueprintAssignable, Category="MessageManager")
	FOnMessageAvailable OnMessageAvailable;

private:
	UFUNCTION()
	void HandleMessageDisplayed(UFortUIMessageItemWidget* MessageItem);

	UFUNCTION()
	void HandleMessageRemoved(UFortUIMessageItemWidget* MessageItem);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortUIMessageItemWidget>> MessageQueue;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortUIMessageItemWidget>> CurrentlyDisplayedMessages;

};

