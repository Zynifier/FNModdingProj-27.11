// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Misc/DateTime.h"
#include "McpSharedTypes.h"
#include "FortDailyRewardScheduleData.generated.h"

class UDataTable;
class UFortDailyRewardScheduleTokenDefinition;

USTRUCT()
struct FFortDailyLoginRewardStat_ScheduleClaimed
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 RewardsClaimed;

	UPROPERTY()
	bool ClaimedToday;

};

USTRUCT()
struct FFortDailyLoginRewardStat
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 NextDefaultReward;

	UPROPERTY()
	int32 TotalDaysLoggedIn;

	UPROPERTY()
	FDateTime LastClaimDate;

	UPROPERTY()
	TMap<FName, FFortDailyLoginRewardStat_ScheduleClaimed> AdditionalSchedules;

};

USTRUCT()
struct FFortDailyRewardScheduleDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDisplayData")
	FText Title;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDisplayData")
	FText Description;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDisplayData")
	FText ItemDescription;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDisplayData")
	FText EpicItemDescription;

};

USTRUCT()
struct FFortDailyRewardScheduleDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinition")
	FName ScheduleName;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinition")
	TSoftObjectPtr<UFortDailyRewardScheduleTokenDefinition> EnablingToken;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinition")
	TObjectPtr<UDataTable> Rewards;

	UPROPERTY(EditAnywhere, Category="Display")
	FFortDailyRewardScheduleDisplayData DisplayData;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinition")
	FDateTime BeginDate;

	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinition")
	FDateTime EndDate;

};

USTRUCT()
struct FFortDailyRewardsNotification
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 DaysLoggedIn;

	UPROPERTY()
	TArray<FMcpLootEntry> Items;

};

UCLASS(MinimalAPI)
class UFortDailyRewardScheduleDefinitions : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortDailyRewardScheduleDefinitions")
	TArray<FFortDailyRewardScheduleDefinition> Schedules;

};

