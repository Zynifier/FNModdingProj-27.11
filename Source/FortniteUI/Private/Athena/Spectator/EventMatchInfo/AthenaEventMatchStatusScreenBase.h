// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Spectator/EventMatchInfo/AthenaEventScreenBase.h"
#include "AthenaEventMatchStatusScreenBase.generated.h"

class UAthenaRemotePlayerViewData;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaEventMatchStatusScreenBase : public UAthenaEventScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlayerDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDead);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Player Dead State Changed"))
	void OnPlayerDeadStateChanged_BP(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDead);

	UFUNCTION()
	void OnPlayerKillScoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InKillScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateChestsLootedText(const FText& ChestsLootedText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateCircleRadiusText(const FText& CircleRadiusText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateDamageHealedText(const FText& DamageHealedText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateDamageInflictedText(const FText& DamageInflictedText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateDamageTakenText(const FText& DamageTakenText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateFastestKillText(const FText& FastestKillText, const FText& FastestKillTime);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateGamePhaseText(const FText& GamePhaseText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateGamePhaseTimeText(const FText& GamePhaseTimeText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateGamePhaseTimeTitleText(const FText& GamePhaseTimeTitleText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateLongestEliminationScore(const FText& LongestEliminationScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateLongestEliminationText(const FText& LongestEliminationText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMatchTimeText(const FText& MatchTimeText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMostKillsScore(const FText& MostKillsScore);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateMostKillsText(const FText& MostKillsText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdatePiecesBuiltText(const FText& PiecesBuiltText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdatePiecesDestroyedText(const FText& PiecesDestroyedText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdatePlayersRemainingText(const FText& PlayersRemainingText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateShotsFiredText(const FText& ShotsFiredText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateSupplyDropsLootedText(const FText& SupplyDropsLootedText);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateTimeSinceLastKillText(const FText& TimeSinceLastKillText);

};

