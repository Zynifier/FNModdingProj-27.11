// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "Items/FortPersistentTypes.h"
#include "STW/UI/FortScoreStylingData.h"
#include "FortUIScoreReport.generated.h"

class AFortPlayerPawn;
class AFortPlayerState;
class UFortItem;
class UFortLocalPlayer;

USTRUCT(BlueprintType)
struct FFortUIXpInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortUIXpInfo")
	int32 InitialLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortUIXpInfo")
	int32 InitialDisplayXp;

	UPROPERTY(BlueprintReadOnly, Category="FortUIXpInfo")
	FFortExperienceDelta ChangeInXp;

};

UCLASS(BlueprintType)
class UFortUIScoreReport : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Badges")
	int32 GetBadgeScore(UFortItem* BadgeItem) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	AFortPlayerPawn* GetCurrentPlayerPawn(int32 ScoreReportIndex) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	AFortPlayerState* GetCurrentPlayerState(int32 ScoreReportIndex) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	float GetDifficultBonusMultiplier() const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	int32 GetDifficultBonusScore() const;

	UFUNCTION(BlueprintPure, Category="XP")
	float GetLevelProgress(int32 Level, int32 DisplayXp) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	int32 GetPlayerCount() const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	void GetPlayerIDFromScoreReportIndex(int32 ScoreReportIndex, FUniqueNetIdRepl& OutUniqueNetIdRepl) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	FText GetPlayerName(int32 ScoreReportIndex) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	FString GetPlayerPlatform(int32 ScoreReportIndex) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	int32 GetPlayerScore(int32 ScoreReportIndex, EFortUIScoreType::Type ScoreType) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	int32 GetScoreReportIndex(const FUniqueNetIdRepl& PlayerId) const;

	UFUNCTION(BlueprintPure, Category="FortUIScoreReport")
	void GetScoreReportIndicesByPlayerID(TArray<int32>& SortedScoreReportIndices) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	int32 GetTeamScore(EFortUIScoreType::Type ScoreType) const;

	UFUNCTION(BlueprintPure, Category="XP")
	bool GetXpInfo(int32 ScoreReportIndex, FFortUIXpInfo& OutXpInfo) const;

	UFUNCTION(BlueprintPure, Category="XP")
	int32 GetXpToCompleteLevel(int32 Level) const;

	UFUNCTION(BlueprintPure, Category="Scoring")
	bool IsLocalPlayer(int32 ScoreReportIndex) const;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> LocalPlayer;

};

