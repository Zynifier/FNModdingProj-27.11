// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Crucible.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerPawn;
enum class EFortCrucibleControlType : uint8;
enum class EFortCrucibleLeaderboardId : uint8;
enum class EFortCrucibleLeaderboardState : uint8;
enum class EFortCrucibleStatId : uint8;
enum class EFortCrucibleStatType : uint8;

UENUM(BlueprintType)
enum class EFortCrucibleControlType : uint8
{
	Gamepad = 0,
	KBM = 1,
	Touch = 2,
	Count = 3,
};

UENUM(BlueprintType)
enum class EFortCrucibleLeaderboardId : uint8
{
	GlobalGamepad = 0,
	GlobalKBM = 1,
	GlobalTouch = 2,
	GlobalAll = 3,
	FriendsGamepad = 4,
	FriendsKBM = 5,
	FriendsTouch = 6,
	FriendsAll = 7,
	Count = 8,
};

UENUM(BlueprintType)
enum class EFortCrucibleLeaderboardState : uint8
{
	Disabled = 0,
	ReadyForQuery = 1,
	WaitingForQueryResults = 2,
	NeedsUserInfoQueried = 3,
	Complete = 4,
};

UENUM()
enum class EFortCrucibleStatId : uint8
{
	Gamepad_CourseOverall = 0,
	Gamepad_CourseSegment1 = 1,
	Gamepad_CourseSegment2 = 2,
	Gamepad_CourseSegment3 = 3,
	Gamepad_CourseSegment4 = 4,
	Gamepad_CourseSegment5 = 5,
	KBM_CourseOverall = 6,
	KBM_CourseSegment1 = 7,
	KBM_CourseSegment2 = 8,
	KBM_CourseSegment3 = 9,
	KBM_CourseSegment4 = 10,
	KBM_CourseSegment5 = 11,
	Touch_CourseOverall = 12,
	Touch_CourseSegment1 = 13,
	Touch_CourseSegment2 = 14,
	Touch_CourseSegment3 = 15,
	Touch_CourseSegment4 = 16,
	Touch_CourseSegment5 = 17,
	Count = 18,
};

UENUM()
enum class EFortCrucibleStatSource : uint8
{
	None = 0,
	Backend = 1,
	CurrentSession = 2,
};

UENUM(BlueprintType)
enum class EFortCrucibleStatType : uint8
{
	CourseOverall = 0,
	CourseSegment1 = 1,
	CourseSegment2 = 2,
	CourseSegment3 = 3,
	CourseSegment4 = 4,
	CourseSegment5 = 5,
	Count = 6,
};

UENUM(BlueprintType)
enum class EFortCrucibleWorkType : uint8
{
	Invalid = 0,
	SetupPlayer = 1,
	GetFriendsList = 2,
	GetFriendsStats = 3,
	GetGlobalLeaderboard = 4,
	GetDisplayNames = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCrucibleLatestCourseResultsUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCrucibleLeaderboardUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCrucibleParticipantBestTimesUpdated);

USTRUCT(BlueprintType)
struct FCrucibleSegmentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bRegistered;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentData")
	int32 NumAI;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentData")
	int32 NumTargets;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentData")
	float MissedTargetPenalty;

	UPROPERTY()
	EFortCrucibleStatType BackendStatType;

};

USTRUCT(BlueprintType)
struct FCrucibleCourseData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseData")
	TArray<FCrucibleSegmentData> SegmentsData;

};

USTRUCT(BlueprintType)
struct FCrucibleSegmentResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	int32 SegmentId;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	float CalculatedScore;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	float CalculatedPenalty;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	int32 CalculatedMissedTargets;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	float FinishTime;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	float CancelTime;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	int32 NumAIElims;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleSegmentResults")
	int32 NumTargetElims;

};

USTRUCT(BlueprintType)
struct FCrucibleCourseResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	float CalculatedScore;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	float CalculatedTotalPenalty;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	int32 CalculatedMissedTargets;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	int32 CalculatedSpawnedTargets;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	TArray<FCrucibleSegmentResults> SegmentResults;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	float FinishTime;

	UPROPERTY(BlueprintReadOnly, Category="CrucibleCourseResults")
	float CancelTime;

	UPROPERTY()
	bool bInputMethodWasKBMAtAnyPoint;

};

USTRUCT(BlueprintType)
struct FCrucibleLeaderboardEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CrucibleLeaderboardEntry")
	FString DisplayName;

	UPROPERTY(BlueprintReadWrite, Category="CrucibleLeaderboardEntry")
	int32 Rank;

	UPROPERTY(BlueprintReadWrite, Category="CrucibleLeaderboardEntry")
	int32 Value;

	UPROPERTY(BlueprintReadWrite, Category="CrucibleLeaderboardEntry")
	bool bIsLocalPlayer;

	UPROPERTY(BlueprintReadWrite, Category="CrucibleLeaderboardEntry")
	FUniqueNetIdRepl UserNetId;

};

USTRUCT(BlueprintType)
struct FCrucibleLeaderboardData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortCrucibleLeaderboardId LeaderboardId;

	UPROPERTY()
	EFortCrucibleLeaderboardState CurrentState;

	UPROPERTY()
	FString LeaderboardName;

	UPROPERTY()
	TArray<FCrucibleLeaderboardEntry> CurrentCompiledResults;

	UPROPERTY()
	bool bHasBeenRequestedByUser;

	UPROPERTY()
	bool bHasHadWorkQueued;

	UPROPERTY()
	int32 NumQueries;

};

USTRUCT(BlueprintType)
struct FCrucibleParticipantData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPlayerControllerAthena> AthenaPC;

	UPROPERTY(BlueprintReadOnly, Category="Crucible")
	TMap<FString, int64> LatestRetrievedRawStats;

};

USTRUCT(BlueprintType)
struct FCrucibleStatValue
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Crucible")
	float BestTime;

	UPROPERTY(BlueprintReadOnly, Category="Crucible")
	int64 RawBestTime;

	UPROPERTY(BlueprintReadOnly, Category="Crucible")
	EFortCrucibleStatSource Source;

	UPROPERTY(BlueprintReadOnly, Category="Crucible")
	FString BackendStatName;

};

USTRUCT()
struct FCrucibleWorkManager
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Crucible : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Crucible")
	const FCrucibleCourseData& GetCourseData() const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool GetCourseSegmentData(int32 SegmentId, FCrucibleSegmentData& OutSegmentData) const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	EFortCrucibleControlType GetCurrentControlState() const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	const FCrucibleCourseResults& GetLatestCourseResults(bool& OutIsInProgress, bool& OutHasBeenCanceled) const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool GetLatestSegmentResults(int32 SegmentId, FCrucibleSegmentResults& OutSegmentResults, bool& OutIsInProgress, bool& OutHasBeenCanceled) const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	float GetLatestServerTime() const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	float GetLatestServerTimeReceivedOnClientTime() const;

	UFUNCTION(BlueprintCallable, Category="Crucible")
	TArray<FCrucibleLeaderboardEntry> GetLeaderboardEntries(EFortCrucibleLeaderboardId LeaderboardId);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	EFortCrucibleLeaderboardState GetLeaderboardState(EFortCrucibleLeaderboardId LeaderboardId);

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool GetParticipantBestTime(EFortCrucibleStatId StatId, FCrucibleStatValue& OutStatValue) const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool GetParticipantBestTimeCurrentControlState(EFortCrucibleStatType StatType, FCrucibleStatValue& OutStatValue) const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	float GetServerTimeContinuous() const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool HasRegisteredPlayerController() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Crucible")
	void InitializePlayerAmmo(AFortPlayerPawn* PlayerPawn) const;

	UFUNCTION(BlueprintCallable, Category="Crucible")
	static void InsertLocalScoreIntoLeaderboard(FCrucibleLeaderboardEntry LocalTopScore, UPARAM(ref) TArray<FCrucibleLeaderboardEntry>& LeaderboardToUpdate);

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool IsLeaderboardFilterTextDisabled() const;

	UFUNCTION(BlueprintPure, Category="Crucible")
	bool IsLeaderboardSwitchingDisabled() const;

	UFUNCTION()
	void OnInputMethodChanged(ECommonInputType CurrentInputType);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void RegisterCourseSegment(int32 SegmentId, int32 NumAI, int32 NumTargets);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void RegisterParticipant(AFortPlayerControllerAthena* AthenaPC);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void ReportCrucibleStatsRaw(AFortPlayerControllerAthena* AthenaPC, const TMap<FString, int64>& InStats);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void RetrieveCrucibleStatsRaw(AFortPlayerControllerAthena* AthenaPC, const TArray<FString>& InStatNames);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseCancel(AFortPlayerControllerAthena* AthenaPC);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseFinish(AFortPlayerControllerAthena* AthenaPC);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseSegmentAIElim(int32 SegmentId);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseSegmentFinish(AFortPlayerControllerAthena* AthenaPC, int32 SegmentId);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseSegmentStart(AFortPlayerControllerAthena* AthenaPC, int32 SegmentId);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseSegmentTargetElim(int32 SegmentId);

	UFUNCTION(BlueprintCallable, Category="Crucible")
	void TriggerCourseStart(AFortPlayerControllerAthena* AthenaPC);

	UPROPERTY(BlueprintAssignable, Category="Crucible")
	FCrucibleLeaderboardUpdated OnCrucibleLeaderboardUpdated;

	UPROPERTY(BlueprintAssignable, Category="Crucible")
	FCrucibleParticipantBestTimesUpdated OnCrucibleParticipantBestTimesUpdated;

	UPROPERTY(BlueprintAssignable, Category="Crucible")
	FCrucibleLatestCourseResultsUpdated OnCrucibleLatestCourseResultsUpdated;

protected:
	UFUNCTION()
	void OnRep_CurrentControlType();

	UFUNCTION()
	void OnRep_LatestCourseResults();

	UFUNCTION()
	void OnRep_LatestServerTime();

	UFUNCTION()
	void OnRep_ParticipantBestTimes();

	UPROPERTY(Replicated)
	FCrucibleCourseData CourseData;

	UPROPERTY(ReplicatedUsing=OnRep_ParticipantBestTimes)
	TArray<FCrucibleStatValue> ParticipantBestTimes;

	UPROPERTY(ReplicatedUsing=OnRep_CurrentControlType)
	EFortCrucibleControlType CurrentControlType;

	UPROPERTY(ReplicatedUsing=OnRep_LatestCourseResults)
	FCrucibleCourseResults LatestCourseResults;

	UPROPERTY(ReplicatedUsing=OnRep_LatestServerTime)
	float LatestServerTime;

};

