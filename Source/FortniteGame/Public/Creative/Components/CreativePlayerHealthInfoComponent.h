// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Player/FortPlayerHealthInfoComponent.h"
#include "CreativePlayerHealthInfoComponent.generated.h"

class AFortMinigame;
class AFortPlayerState;
class AFortPlayerStateAthena;
class UCreativePlayerHealthInfoComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossPlayerChanged, AFortPlayerStateAthena*, PlayerState, UCreativePlayerHealthInfoComponent*, HealthInfoComponent);

UCLASS(Config=Creative, MinimalAPI, ClassGroup=("Minigame"))
class UCreativePlayerHealthInfoComponent : public UFortPlayerHealthInfoComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnBossPlayerChanged OnBossPlayerChanged;

private:
	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigamePlayerChangedTeam(AFortPlayerState* PlayerState, uint8 TeamId, uint8 OldTeamId, bool bTeamChangedWithoutRespawn);

	UFUNCTION()
	void OnMinigamePlayerClassApplied(AFortPlayerState* PlayerState, uint8 ClassSlotIndex);

	UFUNCTION()
	void OnMinigamePlayerDeadStateChanged(AFortPlayerStateAthena* PlayerState, bool bIsDead);

	UFUNCTION()
	void OnMinigamePlayerJoinedMinigame(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnMinigamePlayerLeftMinigame(FUniqueNetIdRepl UniqueNetId, bool bIsLocalPlayer);

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnRep_BossPlayerState();

	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> ControllingMinigame;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BossPlayerState)
	TObjectPtr<AFortPlayerStateAthena> BossPlayerState;

};

