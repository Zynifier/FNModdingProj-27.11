// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortGameStateAthena.h"
#include "FortHUDElementWidget.h"
#include "DiscoWidgetBase.generated.h"

class AAthenaCapturePoint;
class AFortPlayerStateZone;
enum class EDiscoScoreProgressTypes : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDiscoCaptureIconState : uint8
{
	None = 0,
	Hidden = 1,
	Neutral = 2,
	AllyCaptured = 3,
	EnemyCaptured = 4,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDiscoCaptureProgressState : uint8
{
	None = 0,
	AllyProgress = 1,
	EnemyProgress = 2,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDiscoScoreProgressTypes : uint8
{
	None = 0,
	ProgressSoundMild = 1,
	ProgressSoundMedium = 2,
	ProgressSoundStrong = 3,
	CountdownSoundNormal = 4,
	CountdownSoundStrong = 5,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDiscoCaptureIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureIconData")
	EDiscoCaptureIconState CurrIconState;

	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureIconData")
	EDiscoCaptureProgressState CurrProgressState;

	UPROPERTY(BlueprintReadOnly, Category="DiscoCaptureIconData")
	float CurrCapturePercent;

	UPROPERTY()
	TObjectPtr<AAthenaCapturePoint> CapturePoint;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FDiscoTeamScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DiscoTeamScoreData")
	FText CurrScoreText;

	UPROPERTY(BlueprintReadOnly, Category="DiscoTeamScoreData")
	float CurrScorePercent;

	UPROPERTY(Transient)
	int32 CurrScore;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UDiscoWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnCountdownTimerUpdate();

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION()
	void OnMutatorObjectUpdated(const FGameplayMutatorObjectDataArray& MutatorArray);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayScoreProgressSound(EDiscoScoreProgressTypes ScoreProgressType, bool bIsLocalTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateCapturePoint(int32 IconIndex, const FDiscoCaptureIconData& IconData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTeamScore(int32 TeamIndex, const FDiscoTeamScoreData& ScoreData);

	UFUNCTION()
	void UpdateAllUI();

	UPROPERTY(Transient)
	TArray<FDiscoCaptureIconData> CapturePointIconList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	TArray<float> PlayScoreProgressSoundPercentagesMild;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	TArray<float> PlayScoreProgressSoundPercentagesMedium;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	TArray<float> PlayScoreProgressSoundPercentagesStrong;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	float PercentageScoreToPlayCountdown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	float PercentageScoreToPlayFinalCountdown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DiscoWidgetBase")
	float ScoreCountdownSoundFrequency;

	UPROPERTY(Transient)
	bool bLocalTeamIsScoring;

	UPROPERTY(Transient)
	bool bEnemyTeamIsScoring;

	UPROPERTY(Transient)
	uint8 LastViewedTeam;

};

