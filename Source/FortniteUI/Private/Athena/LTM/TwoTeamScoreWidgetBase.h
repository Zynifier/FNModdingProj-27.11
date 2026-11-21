// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "TwoTeamScoreWidgetBase.generated.h"

class AFortPlayerStateZone;
enum class ETDMScoreProgressTypes : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ETDMScoreProgressTypes : uint8
{
	None = 0,
	ProgressSoundMild = 1,
	ProgressSoundMedium = 2,
	ProgressSoundStrong = 3,
	CountdownSoundNormal = 4,
	CountdownSoundStrong = 5,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FTDMTeamScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="TDMTeamScoreData")
	FText CurrScoreText;

	UPROPERTY(BlueprintReadOnly, Category="TDMTeamScoreData")
	float CurrScorePercent;

	UPROPERTY(Transient)
	int32 CurrScore;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTwoTeamScoreWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCountdownTimerUpdate();

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayScoreProgressSound(ETDMScoreProgressTypes ScoreProgressType, bool bIsLocalTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTeamScore(int32 TeamIndex, const FTDMTeamScoreData& ScoreData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTotalScore(const FText& TotalScoreText, int32 Score);

	UFUNCTION()
	void UpdateAllUI();

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TArray<float> PlayScoreProgressSoundPercentagesMild;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TArray<float> PlayScoreProgressSoundPercentagesMedium;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TArray<float> PlayScoreProgressSoundPercentagesStrong;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float PercentageScoreToPlayCountdown;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float PercentageScoreToPlayFinalCountdown;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	float ScoreCountdownSoundFrequency;

	UPROPERTY(Transient)
	uint8 LastViewedTeam;

};

