// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/DateTime.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortMinigameScoring.generated.h"

class AActor;
class AFortMinigameScoreRegistry;
class AFortPlayerState;
class UDataTable;
class UFortPlaysetItemDefinition;

UENUM(BlueprintType)
enum class EMinigameScoreType : uint8
{
	Time = 0,
	PointTotal = 1,
};

USTRUCT(BlueprintType)
struct FMinigameScoreEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl UniqueId;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigameScoreEntry")
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigameScoreEntry")
	float Score;

	UPROPERTY()
	FDateTime TimeRecorded;

	UPROPERTY(NotReplicated)
	uint8 bHasScore : 1;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMinigameScoreDelegate, UFortPlaysetItemDefinition*, Playset, FMinigameScoreEntry, ScoreEntry);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameScoresUpdatedDelegate, AFortMinigameScoreRegistry*, ScoreRegistry);

USTRUCT()
struct FMinigameHighScoreEntryRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MinigameHighScoreEntryRow")
	FString PlayerName;

	UPROPERTY(EditDefaultsOnly, Category="MinigameHighScoreEntryRow")
	float Score;

};

USTRUCT()
struct FMinigameHighScoreRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MinigameHighScoreRow")
	TObjectPtr<UDataTable> HighScoresTable;

};

USTRUCT()
struct FMinigameScoreArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, Category="MinigameScoreArray")
	TArray<FMinigameScoreEntry> Scores;

	UPROPERTY(VisibleAnywhere, Transient, NotReplicated, Category="MinigameScoreArray")
	TArray<FMinigameScoreEntry> HighScores;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AActor> Owner;

};

USTRUCT(BlueprintType)
struct FMinigameScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="MinigameScoreData")
	float Score;

};

USTRUCT(BlueprintType)
struct FMinigameScoreTemplate
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinigameScoreTemplate")
	EMinigameScoreType ScoreType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinigameScoreTemplate")
	int32 NumHighScores;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinigameScoreTemplate")
	bool bAscending;

};

USTRUCT(BlueprintType)
struct FMinigameSoloScoreData : public FMinigameScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="MinigameSoloScoreData")
	TObjectPtr<AFortPlayerState> PlayerState;

};

USTRUCT(BlueprintType)
struct FMinigameTeamScoreData : public FMinigameScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="MinigameTeamScoreData")
	uint8 Team;

};

USTRUCT(BlueprintType)
struct FMinigameScoreTracker
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="MinigameScoreTracker")
	FMinigameScoreData GroupScore;

	UPROPERTY(VisibleAnywhere, Category="MinigameScoreTracker")
	TArray<FMinigameTeamScoreData> TeamScores;

	UPROPERTY(VisibleAnywhere, Category="MinigameScoreTracker")
	TArray<FMinigameSoloScoreData> SoloScores;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortMinigameScoreRegistry : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Minigame|Scoring")
	bool GetHighScores(TArray<FMinigameScoreEntry>& HighScores) const;

	UFUNCTION(BlueprintPure, Category="Minigame|Scoring")
	bool GetScores(AFortPlayerState* PlayerState, TArray<FMinigameScoreEntry>& ScoreEnties) const;

	UFUNCTION(BlueprintPure, Category="Minigame|Format")
	static FText PointsToText(float Points);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame|Scoring")
	bool RecordScore(AFortPlayerState* PlayerState, float Score);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame|Scoring")
	bool RemoveAllScores(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Minigame|Scoring")
	FText ScoreToText(float Score) const;

	UFUNCTION(BlueprintPure, Category="Minigame|Format")
	static FText TimeToText(float Time);

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_Playset, Category="Minigame|Scoring")
	TObjectPtr<UFortPlaysetItemDefinition> Playset;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Replicated, Category="Minigame|Scoring")
	FMinigameScoreTemplate ScoreTemplate;

	UPROPERTY(EditAnywhere, Category="Minigame|Scoring")
	bool bPostToKillFeed;

	UPROPERTY(BlueprintAssignable)
	FMinigameScoreDelegate OnScoreRecorded;

	UPROPERTY(BlueprintAssignable)
	FMinigameScoresUpdatedDelegate OnScoreRankingsUpdated;

protected:
	UFUNCTION()
	void OnRep_Playset();

	UFUNCTION()
	void OnRep_Scores();

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_Scores, Category="Minigame|Scoring")
	FMinigameScoreArray Scores;

};

