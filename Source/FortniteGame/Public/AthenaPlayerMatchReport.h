// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "JsonObjectWrapper.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "Items/FortAccoladeTypes.h"
#include "McpSharedTypes.h"
#include "Online/AthenaLevelInfo.h"
#include "AthenaPlayerMatchReport.generated.h"

class UAthenaSeasonItemDefinition;
class UAthenaStatsSet;

UENUM()
enum class EAthenaMatchXpMultiplierSource : uint8
{
	Invalid = 0,
	BattlePassSelf = 1,
	BattlePassFriends = 2,
	CosmeticSet = 3,
	AntiAddictionPenalty = 4,
	BonusXpEvent = 5,
	MAX_COUNT = 6,
};

UENUM(BlueprintType)
enum class EAthenaTravelEventType : uint8
{
	/**  */
	GroundMove = 0,
	/**  */
	AirMove = 1,
	/**  */
	BattleBusJump = 2,
	/**  */
	LaunchJump = 3,
	/**  */
	Landed = 4,
	/**  */
	OpenChest = 5,
	/**  */
	OpenAmmo = 6,
	/**  */
	GotAssist = 7,
	/**  */
	GotKnockdown = 8,
	/**  */
	GotKill = 9,
	/**  */
	PlayerDowned = 10,
	/**  */
	PlayerDied = 11,
	/**  */
	Won = 12,
	/**  */
	DealtDamage = 13,
	/**  */
	HealthChange = 14,
	/**  */
	GotItem = 15,
	/**  */
	DroppedItem = 16,
	/**  */
	ShieldChange = 17,
	/**  */
	WeaponExecuted = 18,
	/**  */
	EnteredVehicle = 19,
	/**  */
	ExitedVehicle = 20,
	/**  */
	TrapBuilt = 21,
	/**  */
	UsedItem = 22,
	/**  */
	ZoneUpdate = 23,
	/**  */
	PlacedBuilding = 24,
	/**  */
	EmoteUsed = 25,
	/**  */
	UpgradedBuilding = 26,
	/**  */
	EditedBuilding = 27,
	/**  */
	Count = 28,
};

UENUM(BlueprintType)
enum class EAthenaTravelLogPlayerType : uint8
{
	/**  */
	Self = 0,
	/**  */
	Ally = 1,
	/**  */
	Enemy = 2,
	/**  */
	Invalid = 3,
};

UENUM()
enum class ERewardSource : uint8
{
	Invalid = 0,
	MinutesPlayed = 1,
	FirstKill = 2,
	TeamKills = 3,
	FirstRevive = 4,
	AdditionalRevives = 5,
	Placement = 6,
	Medals = 7,
	FirstWin = 8,
	SeasonLevelUp = 9,
	BookLevelUp = 10,
	MatchXP = 11,
	MAX_COUNT = 12,
};

USTRUCT(BlueprintType)
struct FAthenaTravelLogEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	float Time;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FRotator Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	EAthenaTravelEventType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FName InstigatorName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FUniqueNetIdRepl InstigatorId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	EAthenaTravelLogPlayerType InstigatorPlayerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FName ReceiverName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FUniqueNetIdRepl ReceiverId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	EAthenaTravelLogPlayerType ReceiverPlayerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FJsonObjectWrapper Meta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelLogEntry")
	FGameplayTagContainer LocationPOITags;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTravelLogUpdated, const FAthenaTravelLogEntry&, NewEntry);

USTRUCT()
struct FAthenaAwardGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ERewardSource RewardSource;

	UPROPERTY()
	TArray<FMcpLootEntry> Items;

	UPROPERTY()
	int32 Score;

	UPROPERTY()
	float SeasonXp;

	UPROPERTY()
	int32 BookXp;

};

USTRUCT(BlueprintType)
struct FAthenaMatchLootReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchLootReward")
	FString TemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchLootReward")
	int32 Amount;

};

USTRUCT(BlueprintType)
struct FAthenaWeaponStats
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString WeaponId;

	UPROPERTY()
	int32 Stats[27];

};

USTRUCT(BlueprintType)
struct FAthenaXPStats
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FName Stat;

	UPROPERTY()
	int32 Count;

	UPROPERTY()
	int32 GainedXP;

	UPROPERTY()
	EFortAccoladeSubtype Subtype;

};

USTRUCT(BlueprintType)
struct FAthenaMatchStats
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FString StatBucket;

	UPROPERTY()
	FString MatchId;

	UPROPERTY()
	FString MatchEndTime;

	UPROPERTY()
	FString MatchPlatform;

	UPROPERTY()
	int32 Stats[20];

	UPROPERTY()
	TArray<FAthenaWeaponStats> WeaponStats;

	UPROPERTY()
	TArray<FAthenaXPStats> XPStats;

	UPROPERTY()
	FDynamicXpProfileStats DynamicXp;

	UPROPERTY()
	bool bIsValid;

	UPROPERTY()
	FString FactionTag;

};

USTRUCT(BlueprintType)
struct FAthenaMatchTeamStats
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchTeamStats")
	int32 Place;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchTeamStats")
	int32 TotalPlayers;

};

USTRUCT()
struct FAthenaMatchXpMultiplierGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EAthenaMatchXpMultiplierSource Source;

	UPROPERTY()
	int32 Amount;

};

USTRUCT(BlueprintType)
struct FAthenaMatchXpReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXpReward")
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaMatchXpReward")
	int32 Amount;

};

USTRUCT()
struct FAthenaRewardResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 LevelsGained;

	UPROPERTY()
	int32 BookLevelsGained;

	UPROPERTY()
	int32 TotalSeasonXpGained;

	UPROPERTY()
	int32 TotalBookXpGained;

	UPROPERTY()
	int32 PrePenaltySeasonXpGained;

	UPROPERTY()
	TArray<FAthenaMatchXpMultiplierGroup> XpMultipliers;

	UPROPERTY()
	TArray<FAthenaAwardGroup> Rewards;

	UPROPERTY()
	float AntiAddictionMultiplier;

};

USTRUCT(BlueprintType)
struct FAthenaTravelRecord
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaTravelRecord")
	TArray<FAthenaTravelLogEntry> Log;

};

UCLASS(BlueprintType)
class UAthenaPlayerMatchReport : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDataAvailableEvent);

public:
	UFUNCTION(BlueprintCallable)
	void GetLootRewards(TArray<FAthenaMatchLootReward>& LootRewards);

	UFUNCTION(BlueprintPure)
	int32 GetTotalBookXpEarned() const;

	UFUNCTION(BlueprintPure)
	int32 GetTotalScoreEarned() const;

	UFUNCTION(BlueprintPure)
	int32 GetTotalSeasonalXpEarned() const;

	UFUNCTION(BlueprintCallable)
	void GetXpRewards(TArray<FAthenaMatchXpReward>& XpRewards);

	UPROPERTY(BlueprintAssignable)
	FDataAvailableEvent OnRewardsAvailable;

	UPROPERTY(BlueprintAssignable)
	FDataAvailableEvent OnStatsAvailable;

	UPROPERTY(BlueprintAssignable)
	FDataAvailableEvent OnTeamStatsAvailable;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	FAthenaLevelInfo InitialLevelInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	bool bHasMatchStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	FAthenaMatchStats MatchStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	bool bHasTeamStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	FAthenaMatchTeamStats TeamStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	bool bHasRewards;

	UPROPERTY()
	FAthenaRewardResult EndOfMatchResults;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerMatchReport")
	FAthenaTravelRecord TravelRecord;

	UPROPERTY(BlueprintAssignable)
	FOnTravelLogUpdated TravelLogUpdated;

};

UCLASS(BlueprintType)
class UAthenaSeasonStats : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UAthenaSeasonItemDefinition* GetSeasonDefintion();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSeasonStats")
	TObjectPtr<UAthenaStatsSet> CumulativeStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSeasonStats")
	TMap<FName, TObjectPtr<UAthenaStatsSet>> Buckets;

	UPROPERTY(Transient)
	TObjectPtr<UAthenaSeasonItemDefinition> SeasonDefinition;

};

UCLASS(BlueprintType)
class UAthenaStatsSet : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FAthenaMatchStats CumulativeStats;

	UPROPERTY()
	TArray<FAthenaMatchStats> BestMatches;

};

