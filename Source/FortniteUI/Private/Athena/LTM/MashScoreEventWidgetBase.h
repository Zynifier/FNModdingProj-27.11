// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/Modifiers/FortAthenaMutator_Mash.h"
#include "MashScoreEventWidgetBase.generated.h"

class AFortAthenaMutator_Mash;
class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UMashScoreEventWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Mash Score Events")
	void OnScoreEvent(int32 ScoreValue, const FText& ScoreText, EMashScoreEvent::Type ScoreEventType);

	UFUNCTION(BlueprintImplementableEvent, Category="Mash Score Events")
	void OnStreakScoreMultiplierCountdownUpdated(float RemainingTimeBeforeReset);

	UFUNCTION(BlueprintImplementableEvent, Category="Mash Score Events")
	void OnStreakScoreMultiplierKillCountUpdated(int32 TotalStreakKillCount, float StreakLevelProgressRatio);

	UFUNCTION(BlueprintImplementableEvent, Category="Mash Score Events")
	void OnStreakScoreMultiplierUpdated(uint8 StreakScoreLevel, uint8 MaxStreakScoreLevel, float ScoreMultiplier);

protected:
	UFUNCTION()
	void OnPlayerDataChanged();

	UFUNCTION()
	void OnStreakScoreMultiplierExpires();

	UFUNCTION()
	void UpdateStreakScoreMultiplierCountdown();

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashScoreEventWidgetBase")
	TObjectPtr<AFortAthenaMutator_Mash> MashMutatorRef;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> CachedLocalPlayerState;

	UPROPERTY(Transient)
	FMashPlayerDataEntry CachedLocalPlayerEntry;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashScoreEventWidgetBase")
	float StreakScoreMultiplierRemainingTime;

};

