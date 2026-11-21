// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "FortQuestTypes.generated.h"

class UFortAccoladeItemDefinition;
class UFortMissionInfo;

UENUM()
enum class EAthenaRebootEligiblityStatus : uint8
{
	None = 0,
	// User is neither eligible themselves or in an eligible party

	User = 1,
	// User themselves are eligible

	Squad = 2,
};

UENUM(BlueprintType, meta=(Category="Fortnite UI"))
enum class EFortChallengeBundleInfoLockedReasonCode : uint8
{
	/// Indicates that the bundle is not locked

	Unlocked = 0,
	/// Indicates that there is no known method of unlocking the bundle

	NoKnownUnlockMethod = 1,
	/// Indicates that the bundle requires purchase of a battle pass

	PurchaseTheBattlePass = 2,
	/// Indicates that the bundle requires reaching a specific tier

	ReachSpecificTier = 3,
	/// Indicates that the bundle is time-locked and will unlock automatically later

	TimeLeftBeforeUnlock = 4,
};

UENUM()
enum class EFortQuestAnalyticState : uint8
{
	None = 0,
	/** Quest was granted */
	Granted = 1,
	/** Quest was claimed */
	Claimed = 2,
};

UENUM(BlueprintType)
enum class EFortQuestState : uint8
{
	/** Quest suspended - progress on objectives is ignored */
	Inactive = 0,
	/** Quest acquired and progress can be made on the quest */
	Active = 1,
	/** All the quest objectives fulfilled, but rewards not yet claimed */
	Completed = 2,
	/** Quest completed and rewards claimed */
	Claimed = 3,
};

USTRUCT(BlueprintType)
struct FAthenaAccolades
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaAccolades")
	TObjectPtr<UFortAccoladeItemDefinition> AccoladeDef;

	UPROPERTY()
	FString TemplateId;

	UPROPERTY(BlueprintReadOnly, Category="AthenaAccolades")
	int32 Count;

};

USTRUCT()
struct FAttributePair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Field;

	UPROPERTY()
	FString Value;

};

USTRUCT(BlueprintType, meta=(Category="Fortnite UI"))
struct FFortChallengeBundleInfoLockedReason
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortChallengeBundleInfoLockedReasonCode ReasonCode;

	UPROPERTY()
	FString EventName;

	UPROPERTY()
	int32 RequiredTier;

	UPROPERTY()
	FTimespan UnlockTimespanAfterStart;

};

USTRUCT()
struct FFortCreateItemDetail
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	int32 Quantity;

	UPROPERTY()
	TArray<FAttributePair> Attributes;

};

USTRUCT()
struct FFortQuestAnalyticEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	EFortQuestAnalyticState State;

};

USTRUCT()
struct FFortQuestDataToExport
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortQuestDelete
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString McpId;

	UPROPERTY()
	bool bSendAnalytics;

};

USTRUCT()
struct FFortQuestEarnedBadgeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	int32 Count;

};

USTRUCT()
struct FFortQuestPoolStats_PerPool
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString PoolName;

	UPROPERTY()
	FDateTime NextRefresh;

	UPROPERTY()
	int32 RerollsRemaining;

};

USTRUCT()
struct FFortQuestPoolStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortQuestPoolStats_PerPool> PoolStats;

};

USTRUCT()
struct FFortQuestManagerAttributes
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime DailyLoginInterval;

	UPROPERTY()
	int32 DailyQuestRerolls;

	UPROPERTY()
	FFortQuestPoolStats QuestPoolStats;

};

USTRUCT(BlueprintType)
struct FFortQuestMissionCreationContext
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMissionCreationContext")
	TSoftObjectPtr<UFortMissionInfo> MissionInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMissionCreationContext")
	TArray<FGameplayTagContainer> MissionCreationContextTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMissionCreationContext")
	bool bSetQuestOwnerAsMissionOwner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMissionCreationContext")
	int32 MaxNumberToSpawnInWorld;

};

USTRUCT()
struct FFortQuestObjectiveCompletion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StatName;

	UPROPERTY()
	int32 Count;

	UPROPERTY()
	int32 TimestampOffset;

};

USTRUCT()
struct FFortTransientQuestGrant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TemplateId;

	UPROPERTY()
	TArray<FFortQuestObjectiveCompletion> Objectives;

	UPROPERTY()
	FString ExpirationTime;

	UPROPERTY()
	FString CreationTime;

};

USTRUCT(BlueprintType)
struct FQuestVisibilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestVisibilityData")
	bool bIsVisibleWhenClaimed;

	UPROPERTY(EditAnywhere, Category="QuestVisibilityData")
	bool bIsVisibleWhenCompleted;

	UPROPERTY(EditAnywhere, Category="QuestVisibilityData")
	bool bIsVisibleWhenExpired;

};

USTRUCT()
struct FSecondaryXpGained
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Type;

	UPROPERTY()
	int32 secondaryXp;

};

