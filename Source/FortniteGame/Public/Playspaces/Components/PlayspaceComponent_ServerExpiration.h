// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_ServerExpiration.generated.h"

class AGameStateBase;
class UFortUINotification;
class UObject;

USTRUCT(BlueprintType)
struct FServerExpirationAlertData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ServerExpirationAlertData")
	int32 SecondsRemainingStart;

	UPROPERTY(EditDefaultsOnly, Category="ServerExpirationAlertData")
	int32 SecondsVisible;

	UPROPERTY(EditDefaultsOnly, Category="ServerExpirationAlertData")
	bool ShowCountdown;

	UPROPERTY(Transient)
	TObjectPtr<UFortUINotification> Notification;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_ServerExpiration : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyCountdownTimerUpdated, int32, SecondsRemaining);

protected:
	UFUNCTION()
	void OnGameStateReady(AGameStateBase* GameState);

private:
	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_ServerExpiration")
	TArray<FServerExpirationAlertData> AlertDataList;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_ServerExpiration")
	int32 ServerShutdownTimeInSeconds;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_ServerExpiration")
	int32 PostShutdownForceRestartTimeInSeconds;

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_ServerExpiration")
	TSoftObjectPtr<UObject> UINotificationIcon;

};

