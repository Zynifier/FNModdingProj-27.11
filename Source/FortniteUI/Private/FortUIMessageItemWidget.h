// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUIMessageItemWidget.generated.h"

class UFortUIMessageItemWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageItemDisplayStateChange, UFortUIMessageItemWidget*, MessageItem);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUIMessageItemWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="MessageItemWidget")
	FOnMessageItemDisplayStateChange OnMessageDisplayed;

	UPROPERTY(BlueprintAssignable, Category="MessageItemWidget")
	FOnMessageItemDisplayStateChange OnMessageRemoved;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MessageItemWidget")
	FName MessageID;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MessageItemWidget")
	int32 StackSize;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="MessageItemWidget")
	void OnBeginRemove();

	UFUNCTION(BlueprintImplementableEvent, Category="MessageItemWidget")
	void OnReturnedToPool();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="MessageItemWidget")
	void OnStackSizeChanged(int32 OldStackSize);

	UPROPERTY(EditDefaultsOnly, Category="MessageItemWidget")
	float DisplayDuration;

	UPROPERTY(EditDefaultsOnly, Category="MessageItemWidget")
	float RemoveDuration;

};

