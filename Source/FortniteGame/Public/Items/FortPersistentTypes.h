// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/Guid.h"
#include "FortCompletionResult.h"
#include "FortTeamEnum.h"
#include "Items/FortItemEntry.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Items/FortRewardActivityType.h"
#include "McpSharedTypes.h"
#include "FortPersistentTypes.generated.h"

class AFortPlayerState;
class UFortMissionGenerator;
class UFortQuestItemDefinition;
class UFortZoneTheme;

UENUM(BlueprintType)
enum class EFortIsFinalXpUpdate : uint8
{
	Uninitialized = 0,
	NotFinal = 1,
	Final = 2,
};

UENUM()
namespace EFortRewardType
{
	enum Type
	{
		// Awards that were granted for success

		Default = 0,
		// Awards that were possible but were not granted

		Missed = 1,
		// Invalid type, not awarded at all

		Max_None = 2 UMETA(DisplayName="None"),
	};
}

USTRUCT()
struct FFortUpdatedObjectiveStat
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> Quest;

	UPROPERTY()
	FName BackendName;

	UPROPERTY()
	int32 StatValue;

	UPROPERTY()
	int32 ShadowStatValue;

	UPROPERTY()
	int32 StatDelta;

	UPROPERTY()
	int32 CurrentStage;

	UPROPERTY()
	bool bSharedQuestUpdate;

	UPROPERTY()
	bool bShowToast;

};

USTRUCT()
struct FFortDisplayQuestUpdateData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortUpdatedObjectiveStat ObjectiveUpdated;

	UPROPERTY()
	TObjectPtr<AFortPlayerState> QuestOwner;

	UPROPERTY()
	TObjectPtr<AFortPlayerState> AssistingPlayer;

};

USTRUCT(BlueprintType)
struct FFortExperienceDelta
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 Level;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 Xp;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 BaseXPEarned;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 BonusXPEarned;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 BoostXPEarned;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 BoostXPMissed;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 RestXPEarned;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	int32 GroupBoostXPEarned;

	UPROPERTY(BlueprintReadOnly, Category="FortExperienceDelta")
	EFortIsFinalXpUpdate IsFinalXpUpdate;

};

USTRUCT(BlueprintType)
struct FFortPlayerScoreReport
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	FUniqueNetIdRepl PlayerId;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	FString PlayerName;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	TEnumAsByte<EFortTeam::Type> PlayerTeam;

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	FReplicatedStatValues ReplicatedStats_Campaign[35];

	UPROPERTY(meta=(ArraySizeEnum="/Script/FortniteGame.EFortReplicatedStat"))
	FReplicatedStatValues ReplicatedStats_Zone[35];

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	int32 InitialLevel;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	int32 InitialExperienceAmount;

	UPROPERTY()
	FFortExperienceDelta ExperienceInfoDelta;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	int32 LastExperienceDeltaAmount;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerScoreReport")
	int32 LastScoreDeltaAmount;

};

USTRUCT(BlueprintType)
struct FFortPresenceBasicInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 HomeBaseRating;

};

USTRUCT()
struct FFortPresenceGameplayStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString State;

	UPROPERTY()
	FName Playlist;

	UPROPERTY()
	int32 NumKills;

	UPROPERTY()
	bool bFellToDeath;

};

USTRUCT()
struct FFortPresenceSocialStatus
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<int32> AttendingSocialEventIds;

};

USTRUCT()
struct FFortRewardActivity
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EFortRewardActivityType::Type> ActivityType;

	UPROPERTY()
	FGuid ActivityGuid;

	UPROPERTY()
	FText TitleText;

	UPROPERTY()
	FText DescriptionText;

	UPROPERTY()
	float RewardDisplayTime;

	UPROPERTY()
	TArray<FFortItemEntry> RewardItems;

	UPROPERTY()
	TArray<FFortItemEntry> MissedRewardItems;

	UPROPERTY()
	EFortCompletionResult ActivityCompletionResult;

	UPROPERTY()
	int32 AdditionalCompletionMissionPoints;

};

USTRUCT()
struct FFortSavedModeLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LoadoutName;

	UPROPERTY()
	TArray<FString> SelectedGadgets;

};

USTRUCT()
struct FFortZoneInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString WorldId;

	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	FString TheaterMissionId;

	UPROPERTY()
	FString TheaterMissionAlertId;

	UPROPERTY()
	TSoftClassPtr<UFortZoneTheme> ZoneThemeClass;

};

USTRUCT()
struct FFortZoneInstanceDetails : public FFortZoneInstanceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftClassPtr<UFortMissionGenerator> MissionGenerator;

	UPROPERTY()
	FDataTableRowHandle ZoneDifficultyInfo;

	UPROPERTY()
	FMcpLootResult MissionRewards;

	UPROPERTY()
	TArray<FMcpLootResult> DifficultyIncreaseMissionRewards;

	UPROPERTY()
	FMcpLootResult MissionAlertRewards;

	UPROPERTY()
	FMcpLootResult ZoneModifiers;

	UPROPERTY()
	FString MissionAlertCategoryName;

	UPROPERTY()
	int32 TileIndex;

};

