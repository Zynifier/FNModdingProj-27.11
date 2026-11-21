// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "Rewards/FortRewardNotificationSubWidget.h"
#include "FortRewardExpeditionWidget.generated.h"

class UFortExpeditionItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExpeditionMcpErrorDelegate);

UCLASS(BlueprintType, Blueprintable)
class UFortRewardExpeditionWidget : public UFortRewardNotificationSubWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Expedition")
	void CollectExpedition(UFortExpeditionItem* Expedition);

	UPROPERTY(BlueprintAssignable, Category="Rewards")
	FOnExpeditionMcpErrorDelegate OnMcpError;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCollectExpeditionCompleted(const UFortExpeditionItem* Expedition, bool bSucceeded, const TArray<FFortItemInstanceQuantityPair>& Rewards);

};

