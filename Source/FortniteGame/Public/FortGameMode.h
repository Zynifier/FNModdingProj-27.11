// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortGameModeBase.h"
#include "FortGameplayStateEnum.h"
#include "Items/FortQuickBars.h"
#include "FortGameMode.generated.h"

class AFortGameSession;
class AFortMissionGenerationManager;
class AFortMissionManager;
class AFortPlayerControllerGameplay;
class AFortTeamInfo;
class APawn;
class UBuildingFlushManager;
class UFortGameDeathPenalty;
class UFortSharedMissionLists;
class UMatchHeartbeatManager;

UENUM()
enum class EFortInputFilterLevel : uint8
{
	None = 0,
	Touch = 1,
	Gamepad = 2,
	Mouse = 3,
};

UENUM()
enum class EProfileCaptureType : uint8
{
	FramePro = 0,
	Insights = 1,
	Network = 2,
	Count = 3,
};

USTRUCT()
struct FAccountIdAndScore
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	int32 TotalScore;

	UPROPERTY()
	int32 IndividualContribution;

	UPROPERTY()
	bool bCriticalMatchBonus;

	UPROPERTY()
	bool bIsLeecherExempt;

};

USTRUCT()
struct FContestedBuildingRequest
{
	GENERATED_BODY()

};

USTRUCT()
struct FCumulativeFrameTimeWithoutSleepLimits
{
	GENERATED_BODY()

public:
	UPROPERTY()
	double FrameTimeWithoutSleep;

	UPROPERTY()
	double MaxCumulativeFrameTimeAboveThreshold;

	UPROPERTY()
	double MaxNumberOfFramesAboveThreshold;

};

USTRUCT(BlueprintType)
struct FFortMatchmakingSessionAssignedEvent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFrameTimeSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	double EndTimeSeconds;

	UPROPERTY()
	double FrameTimeAverageMS;

	UPROPERTY()
	int32 NumFrames;

	UPROPERTY()
	int32 PlayersLeft;

};

UCLASS(MinimalAPI, HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameMode : public AFortGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	virtual void DumpReservations() const;

	UFUNCTION()
	virtual void OnEndOfDay();

	UPROPERTY(Transient)
	uint8 bDisableCloudStorage : 1;

	UPROPERTY(Transient)
	uint8 bTravelInitiated : 1;

	UPROPERTY(Transient)
	FString CurrentWUID;

	UPROPERTY(Transient)
	FString CurrentBucketId;

	UPROPERTY(Transient)
	int32 CurrentPlaylistId;

	UPROPERTY(Transient)
	FName CurrentPlaylistName;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TMap<FString, FString> DeveloperPlaylistOptions;
#endif

	UPROPERTY(Transient)
	FString MatchmakingRegionId;

	UPROPERTY(Transient)
	FString CurrentZoneInstanceId;

	UPROPERTY(Transient)
	int32 ZoneIndex;

	UPROPERTY(Transient)
	uint8 bPlayersInvincible : 1;

	UPROPERTY(Config)
	bool bKickIdlers;

	UPROPERTY(Config)
	float MaxIdleTime;

	UPROPERTY(Config)
	float NoScoreKickTime;

	UPROPERTY(Config)
	bool bEnableNotifications;

	UPROPERTY(Config)
	bool bEnableReplicationGraph;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Death Penalty")
	TObjectPtr<UFortGameDeathPenalty> DeathPenaltyDataOverride;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameSession> FortGameSession;

	UPROPERTY()
	FString GameModeSessionString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameMode")
	uint8 bIsAutomatedTest : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GameMode")
	TSoftClassPtr<APawn> DefaultPawnClassStringRef;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Missions")
	TSubclassOf<AFortMissionManager> MissionManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	FGameplayTagContainer GameModeGameplayTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	bool bContainersForceTossLoot;

	UPROPERTY(EditAnywhere, Category="QuickBar")
	bool bOverrideQuickBars;

	UPROPERTY(EditAnywhere, Category="QuickBar", meta=(ArraySizeEnum="/Script/FortniteGame.EFortQuickBars"))
	FQuickBarData QuickBarDefinitions[3];

protected:
	UPROPERTY()
	bool bOverrideRotationOnRestartPlayer;

	UPROPERTY()
	TEnumAsByte<EFortGameplayState::Type> PendingTimerState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="DBNO")
	bool bDBNOEnabled;

	UPROPERTY(Transient)
	uint8 bWorldIsReady : 1;

	UPROPERTY(Transient)
	uint8 bTheaterDataIsReady : 1;

	UPROPERTY(Transient)
	int32 TheaterSlot;

	UPROPERTY(Config)
	float GameplayServerHitchThreshold;

	UPROPERTY(Config)
	float MovementTimeDiscrepancyHitchCooldown;

	UPROPERTY(Config)
	float AbilityRefireHitchCooldown;

	UPROPERTY(Config)
	bool bCheckWeaponTracesForPlayerBuiltWalls;

	UPROPERTY()
	TObjectPtr<UMatchHeartbeatManager> MatchHeartbeatManager;

	UPROPERTY(Transient)
	FGameplayTagContainer GameContextTags;

	UPROPERTY()
	TObjectPtr<UFortSharedMissionLists> SharedMissionLists;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Teams")
	TSubclassOf<AFortTeamInfo> TeamInfoClass;

	UPROPERTY(Config)
	TArray<double> FrameTimeWithoutSleepHistogramBucketsMs;

	UPROPERTY(Config)
	TArray<FCumulativeFrameTimeWithoutSleepLimits> CumulativeFrameTimeWithoutSleepLimits;

	UPROPERTY(Config)
	TArray<double> GameNetDriverTickFlushCostPerClientBucketsMicroSec;

	UPROPERTY(Config)
	TArray<double> DemoNetDriverTickFlushTimeHistogramBucketsMs;

	UPROPERTY(Config)
	TArray<double> CPUTimeBuckets;

	UPROPERTY(Config)
	TArray<double> CPUPercentPerCoreBuckets;

	UPROPERTY(Config)
	TArray<double> ActorsStarvedByClassTimeHistogramBuckets;

	UPROPERTY(Config)
	TArray<FString> StarvedActorClassList;

	UPROPERTY(Transient)
	TObjectPtr<AFortMissionGenerationManager> MissionGenerationManager;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingFlushManager> FlushManager;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerGameplay>> ConnectedPlayerControllers;

private:
	UPROPERTY(Transient)
	FString MatchmakingLinkCode;

	UPROPERTY(Transient)
	FString MatchmakingLinkType;

	UPROPERTY(Transient)
	TSoftObjectPtr<UFortGameDeathPenalty> DefaultDeathPenaltyData;

	UPROPERTY(EditAnywhere, Category="Death Penalty")
	TObjectPtr<UFortGameDeathPenalty> DeathPenaltyData;

	UPROPERTY(Config)
	bool bAlwaysFlushMMREndZoneEvents;

};

