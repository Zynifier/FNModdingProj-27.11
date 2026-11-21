// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/FortControllerComponent_MinigameActivity.h"
#include "AthenaMinigameActivityWidget.generated.h"

class UCommonTextBlock;

UENUM()
enum class EMinigameActivityWidgetStatFormat : uint8
{
	Score = 0,
	Time = 1,
	AddTime = 2,
	Distance = 3,
	Laps = 4,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMinigameActivityWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Best Lap Time Changed"))
	void BP_OnHandleMinigameBestLapTimeChanged(const float BestLapTime);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Distance Changed"))
	void BP_OnHandleMinigameDistanceChanged(float Distance);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Ended"))
	void BP_OnHandleMinigameEnded(const FMinigameActivityEndedData& EndData);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Laps Changed"))
	void BP_OnHandleMinigameLapsChanged(const int32 CurrentLap, const int32 MaxLaps);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Rank Changed"))
	void BP_OnHandleMinigameRankChanged(int32 Rank);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Score Changed"))
	void BP_OnHandleMinigameScoreChanged(int32 CurrentScore, int32 TotalScore);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Started"))
	void BP_OnHandleMinigameStarted(const FMinigameActivityStartedData& StartData);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Time Changed"))
	void BP_OnHandleMinigameTimeChanged(float Time, float Delta);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame UI Enabled Changed"))
	void BP_OnHandleMinigameUIEnabledChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Best Lap Time UI Enabled Changed"))
	void BP_OnMinigameBestLapTimeUIEnabledChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Progress UI Enabled Changed"))
	void BP_OnMinigameProgressUIEnabledChanged(const bool bEnabled);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Timer UI Enabled Changed"))
	void BP_OnMinigameTimerUIEnabledChanged(const bool bEnabled);

private:
	UPROPERTY(EditAnywhere, Category="Text")
	TMap<EMinigameActivityWidgetStatFormat, FText> StatFormats;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Stat;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AddTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Score;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Lap;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BestLapTime;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMinigameActivityWidget", meta=(AllowPrivateAccess))
	bool bMinigameActive;

};

