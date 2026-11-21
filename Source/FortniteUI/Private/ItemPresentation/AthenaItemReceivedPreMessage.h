// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaItemReceivedPreMessage.generated.h"

class UFortGiftBoxItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaItemReceivedPreMessageBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGiftBoxItem>> GiftBoxItems;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaUpgradedPreMessage : public UAthenaItemReceivedPreMessageBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void OnPresentationFinished();

};

