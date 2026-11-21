// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortUINotificationManager.generated.h"

class UFortLocalPlayer;
class UFortUINotificationQueue;

UCLASS()
class UFortUINotificationManager : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBattlePassPageUnlockToast();

	UFUNCTION()
	void HandleProfileUpdated();

	UFUNCTION()
	void HandlePurchaseBattlePassOfferComplete(const bool bSuccess);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortUINotificationQueue>> UINotificationQueues;

	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

};

