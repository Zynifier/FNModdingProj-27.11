// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "Athena/Spectator/Minigame/MinigameHUD_SpectatorLeaderboardEntry.h"
#include "MinigameHUD_SpectatorLeaderboard.generated.h"

class UFortDynamicEntryBox;
class UFortMinigameStatFilter;
class UMinigameHUD_SpectatorLeaderboardEntry;

UCLASS(Abstract)
class UMinigameHUD_SpectatorLeaderboard : public UMinigameWidgetBase
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, DisplayName="Score Multiplier"))
	int32 DesignTime_Multiplier;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="1", DisplayName="End Score"))
	int32 DesignTime_EndScore;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMin="0", DisplayName="Time (Minutes)"))
	int32 DesignTime_MinutesTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMax="59", ClampMin="0", DisplayName="Time (Seconds)"))
	int32 DesignTime_SecondsTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, ClampMax="99", ClampMin="0", DisplayName="Time (cs)"))
	int32 DesignTime_CsTime;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, DisplayName="Show Coin"))
	bool DesignTime_ShowCoin;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time Only", meta=(AllowPrivateAccess, DisplayName="Entry Type"))
	ESpectatorLeaderboardEntryType DesignTime_EntryType;
#endif

	UPROPERTY(EditDefaultsOnly, Category="MinigameHUD_SpectatorLeaderboard")
	TSubclassOf<UFortMinigameStatFilter> ScoreStat;

	UPROPERTY(EditDefaultsOnly, Category="MinigameHUD_SpectatorLeaderboard")
	TSubclassOf<UFortMinigameStatFilter> ItemCollectStat;

	UPROPERTY(EditDefaultsOnly, Category="MinigameHUD_SpectatorLeaderboard")
	TSubclassOf<UFortMinigameStatFilter> LapTimeStat;

	UPROPERTY(EditDefaultsOnly, Category="MinigameHUD_SpectatorLeaderboard")
	TSubclassOf<UFortMinigameStatFilter> TimeAliveStat;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="MinigameHUD_SpectatorLeaderboard", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_LeaderboardEntries;

	UPROPERTY(EditAnywhere, Category="MinigameHUD_SpectatorLeaderboard")
	TSubclassOf<UMinigameHUD_SpectatorLeaderboardEntry> OutsideTopThreeEntryClass;

};

