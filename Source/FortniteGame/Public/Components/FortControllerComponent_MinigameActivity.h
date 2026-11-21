// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_MinigameActivity.generated.h"

class APawn;
class UFortControllerComponent_MinigameActivity;
enum class EMinigameActivityComponentValidityResult : uint8;
enum class EMinigameActivityStat : uint8;

UENUM(BlueprintType)
enum class EMinigameActivityComponentValidityResult : uint8
{
	Valid = 0,
	IsNotValid = 1,
};

UENUM()
enum class EMinigameActivityStat : uint8
{
	Score = 0,
	Time = 1,
	Distance = 2,
	RaceProgress = 3,
	CurrentLap = 4,
	MaxLaps = 5,
	BestLapTime = 6,
	COUNT = 7 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FMinigameActivityEndedData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	bool bSuccessfullyCompleted;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	EMinigameActivityStat Stat;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	float FinalStatValue;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	float FinalStatBestValue;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	int32 FinalScore;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	int32 TotalScore;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityEndedData")
	int32 Rank;

};

USTRUCT(BlueprintType)
struct FMinigameActivityStartedData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityStartedData")
	FText MinigameActivityName;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityStartedData")
	EMinigameActivityStat Stat;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityStartedData")
	float InitialStatValue;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityStartedData")
	int32 InitialScore;

	UPROPERTY(BlueprintReadWrite, Category="MinigameActivityStartedData")
	int32 TotalScore;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_MinigameActivity : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ForwardMinigameActivityEnded(const FMinigameActivityEndedData& EndData);

	UFUNCTION(BlueprintCallable)
	void ForwardMinigameActivityRankChanged(int32 Rank);

	UFUNCTION(BlueprintCallable)
	void ForwardMinigameActivityScoreChanged(int32 CurrentScore, int32 TotalScore);

	UFUNCTION(BlueprintCallable)
	void ForwardMinigameActivityStarted(const FMinigameActivityStartedData& StartData);

	UFUNCTION(BlueprintCallable)
	void ForwardMinigameActivityStatChanged(EMinigameActivityStat Stat, float Value);

	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutIsValid"))
	static UFortControllerComponent_MinigameActivity* GetMinigameActivityComponent(const APawn* Pawn, EMinigameActivityComponentValidityResult& OutIsValid);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetUIBestLapTimeEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetUIEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetUIProgressEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetUITimeEnabled(const bool bEnabled);

};

