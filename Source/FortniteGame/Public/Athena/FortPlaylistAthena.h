// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGamePhaseEnum.h"
#include "FortItemAndCount.h"
#include "FortLeaderboardMetricEnum.h"
#include "FortPlaylist.h"
#include "FortServerTickRateEnum.h"
#include "FortUIExtension.h"
#include "FortPlaylistAthena.generated.h"

class AActor;
class AFortInGameMapManager;
class AInfo;
class UAnimationSharingSetup;
class UAthenaAISettings;
class UAthenaCharacterItemDefinition;
class UCurveTable;
class UDataTable;
class UFortAthenaExitCraftInfo;
class UFortAthenaHUDInfoDataAsset;
class UFortCurieSettings;
class UFortItemDefinition;
class UFortMissionGenerator;
class UFortPlaylistAthena;
class UFortPlaylistUIInfo;
class UFortSpawnActorInfo;
class UFortSupplyDropInfo;
class UObject;
class USoundMix;
class UTexture2D;
class UUserWidget;

UENUM(BlueprintType)
enum class EAirCraftBehavior : uint8
{
	// Default game behavior.  One aircraft coming from a random direction.

	Default = 0,
	// An Aircraft is created for each team coming from opposing directions.

	OpposingAirCraftForEachTeam = 1,
	// One aircraft is flying over the first circle center

	FlyTowardFirstCircleCenter = 2,
	// In this mode, there are no buses. Spawned in some other way 

	NoAircraft = 3,
};

UENUM(BlueprintType)
enum class EAthenaRespawnLocation : uint8
{
	LastDeath = 0,
	CreativePlayerStart = 1,
};

UENUM(BlueprintType)
enum class EAthenaRespawnType : uint8
{
	None = 0,
	InfiniteRespawn = 1,
	InfiniteRespawnExceptStorm = 2,
};

UENUM(BlueprintType)
enum class EAthenaScoringEvent : uint8
{
	/** No event set */
	None = 0,
	/** Killed an enemy */
	Elimination = 1,
	/** Opened a chest */
	ChestOpened = 2,
	/** Opened an ammo can */
	AmmoCanOpened = 3,
	/** Opened a supply drop */
	SupplyDropOpened = 4,
	/** Opened a supply llama */
	SupplyLlamaOpened = 5,
	/** Consumed a foraged item (apple, mushroom, etc.) */
	ForagedItemConsumed = 6,
	/** Survived an amount of minutes */
	SurvivalInMinutes = 7,
	/** Collected a bronze coin */
	CollectedCoinBronze = 8,
	/** Collected a silver coin */
	CollectedCoinSilver = 9,
	/** Collected a gold coin */
	CollectedCoinGold = 10,
	/** Killed an AI enemy */
	AIKilled = 11,
};

UENUM(BlueprintType)
enum class EAthenaWinCondition : uint8
{
	// normal last man standing

	LastManStanding = 0,
	// last man standing but includes allies with friendly fire

	LastManStandingIncludingAllies = 1,
	// team with most players wins after a timer expires that is set when the last storm circle begins (ties allowed)

	TimedTeamFinalFight = 2,
	// first player to reach the goal score wins

	FirstToGoalScore = 3,
	// altered last man/men standing where everyone alive after a set amount of time wins

	TimedLastMenStanding = 4,
	// used when a mutator is going to take control of the win condition

	MutatorControlled = 5,
	// used when a mutator is going to take control of the win condition but is using the scoring mechanism already present in the win condition logic

	MutatorControlledGoalScore = 6,
	// used when a mutator is going to take control of the win condition, but we still want China specific rules to get applied

	MutatorControlledChinaSupported = 7,
};

UENUM()
enum class ECustomGameVoiceChannel : uint8
{
	Squad = 0,
	FullTeam = 1,
};

UENUM(BlueprintType)
enum class EForceKickAfterDeathMode : uint8
{
	// Do not kick players after team death

	Disabled = 0,
	// Kick players after team death in all match types

	KickAll = 1,
	// Kick players after team death only in private match types

	KickPrivate = 2,
};

UENUM(BlueprintType)
enum class ERewardPlacementBonusType : uint8
{
	// based on placement when in a game where the player is solo

	Solo = 0,
	// based on placement when in a game where the player is in a game with one other person

	Duo = 1,
	// based on placement when in a game where the player is part of a squad (usually 4)

	Squad = 2,
	// based on placement when in a game where the player is part of a large team

	LargeTeam = 3,
	// no placement used

	None = 4,
	// based on placement when in a game where there are exactly two teams

	TwoTeam = 5,
	// based on placement when in a game where the player is part of a medium sized team

	MediumTeam = 6,
	// based on placement when in a game where the player is solo (short length game)

	QuickSolo = 7,
	// based on placement when in a game where the player is in a game with one other person (short length game)

	QuickDuo = 8,
	// based on placement when in a game where the player is part of a squad (usually 4) (short length game)

	QuickSquad = 9,
	// based on placement when in a game where the player is part of a large team (short length game)

	QuickLargeTeam = 10,
	// based on placement when in a game where there are exactly two teams (short length game)

	QuickTwoTeam = 11,
	// based on placement when in a game where the player is part of a medium sized team (short length game)

	QuickMediumTeam = 12,
	// game where only first place receives a bonus (used for game modes where there is a single event that will determine a winner such as Heist)

	SinglePlacement = 13,
};

UENUM(BlueprintType)
enum class ERewardTimePlayedType : uint8
{
	// normal handling of XP per minute

	Default = 0,
	// no reward for time played

	NoReward = 1,
	// a flat value given for just playing

	FlatValue = 2,
};

UENUM(BlueprintType)
enum class ESafeZoneStartUp : uint8
{
	UseDefaultGameBehavior = 0,
	StartsWithWarmUp = 1,
	StartsWithAirCraft = 2,
	StartsWithNoAirCraft = 3,
};

UENUM(BlueprintType)
enum class EWeaponSelectionPreservationType : uint8
{
	KeepSelectionWhenRespawning = 0,
	NeverKeepSelection = 1,
};

USTRUCT(BlueprintType)
struct FAthenaScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	EAthenaScoringEvent ScoringEvent;

	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	FText ScoreNameText;

	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	FGameplayTagContainer EventInclusionTags;

	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	int32 NumOccurrencesForScore;

	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	int32 NumOccurrencesPermitted;

	UPROPERTY(EditDefaultsOnly, Category="AthenaScoreData")
	FScalableFloat ScoreAwarded;

};

USTRUCT(BlueprintType)
struct FBracketDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BracketDefinition")
	int32 MaxScore;

	UPROPERTY(EditDefaultsOnly, Category="BracketDefinition")
	float MaxPriority;

};

USTRUCT(BlueprintType)
struct FCharacterFallbackPreloadBlock
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterFallbackPreloadBlock")
	bool bShouldGoInNPCBudget;

	UPROPERTY(EditAnywhere, Category="CharacterFallbackPreloadBlock")
	FGameplayTag FallbackTag;

};

USTRUCT(BlueprintType)
struct FCharacterPreloadBlock
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CharacterPreloadBlock")
	bool bShouldGoInNPCBudget;

	UPROPERTY(EditAnywhere, Category="CharacterPreloadBlock")
	TSoftObjectPtr<UAthenaCharacterItemDefinition> CID;

};

USTRUCT(BlueprintType)
struct FFillRateTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FillRateTable")
	int32 MinMmr;

	UPROPERTY(EditDefaultsOnly, Category="FillRateTable")
	int32 MaxMmr;

	UPROPERTY(EditDefaultsOnly, Category="FillRateTable")
	float MinFillPct;

	UPROPERTY(EditDefaultsOnly, Category="FillRateTable")
	float MaxFillPct;

	UPROPERTY(EditDefaultsOnly, Category="FillRateTable")
	float MaxPriority;

};

USTRUCT()
struct FQueryName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="NamedWeight")
	FName QueryName;

};

USTRUCT()
struct FNamedWeightTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="NamedWeight", meta=(ShowOnlyInnerProperties))
	FQueryName QueryName;

	UPROPERTY(EditDefaultsOnly, Category="NamedWeight")
	float Weight;

};

USTRUCT(BlueprintType)
struct FPlayerRatingBrackets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlayerRatingBrackets")
	int32 MinMmr;

	UPROPERTY(EditDefaultsOnly, Category="PlayerRatingBrackets")
	int32 MaxMmr;

};

USTRUCT(BlueprintType)
struct FRatingExpansion
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="RatingExpansion")
	int32 Priority;

	UPROPERTY(EditDefaultsOnly, Category="RatingExpansion")
	int32 RatingDelta;

};

USTRUCT(BlueprintType)
struct FSupplyDropSubPhaseModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDropSubPhaseModifier")
	EAthenaGamePhase GamePhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDropSubPhaseModifier")
	int32 SubPhaseIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDropSubPhaseModifier")
	float SpawnInPreviousZonePercentChance;

};

USTRUCT(BlueprintType)
struct FSupplyDropModifierData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDropModifierData")
	FName SupplyDropID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDropModifierData")
	TArray<FSupplyDropSubPhaseModifier> ModifierList;

};

USTRUCT(BlueprintType)
struct FWinConditionScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WinConditionScoreData")
	FScalableFloat GoalScore;

	UPROPERTY(EditDefaultsOnly, Category="WinConditionScoreData")
	FScalableFloat BigScoreThreshold;

	UPROPERTY(EditDefaultsOnly, Category="WinConditionScoreData")
	TArray<FAthenaScoreData> ScoreDataList;

};

UCLASS(MinimalAPI, BlueprintType, meta=(Patchable="KeyProperty=PlaylistName"))
class UFortPlaylistAthena : public UFortPlaylist
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="Event", meta=(CallInEditor="true"))
	void CreateCalendarPayload_Enabling();

	UFUNCTION(Exec, Category="Event", meta=(CallInEditor="true"))
	void CreateCalendarPayload_RegionalOverride();

	UFUNCTION(BlueprintPure, Category="Playlist")
	static int32 GetLastTeamNumber(const UObject* InWorldContext, const UFortPlaylistAthena* InPlaylist = nullptr);

	UFUNCTION(BlueprintPure, Category="Playlist")
	static int32 GetMaxNumberOfTeams(const UObject* InWorldContext, const UFortPlaylistAthena* InPlaylist = nullptr);

	UFUNCTION(BlueprintPure, Category="Playlist")
	static int32 GetMaxPlayerCount(const UObject* InWorldContext, const UFortPlaylistAthena* InPlaylist = nullptr);

	UFUNCTION(BlueprintPure, Category="Playlist")
	static int32 GetMaxTeamSize(const UObject* InWorldContext, const UFortPlaylistAthena* InPlaylist = nullptr);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Rewards", meta=(Patchable))
	bool bRewardsTrackPlacement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Rewards", meta=(Patchable))
	bool bRewardsAllowXPProgression;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Rewards", meta=(Patchable))
	bool bRewardForRevivingTeammates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Rewards", meta=(Patchable))
	ERewardPlacementBonusType RewardPlacementBonusType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Rewards", meta=(Patchable))
	int32 RewardsPlacementThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards", meta=(Patchable))
	ERewardTimePlayedType RewardTimePlayedType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards", meta=(Patchable))
	int32 RewardTimePlayedXPPerMinute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards", meta=(Patchable))
	int32 RewardTimePlayedXPFlatValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
	FScalableFloat InMatchXPRewardScalar;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> QuestEventXPTableOverride;

	UPROPERTY(EditAnywhere, Category="Rewards")
	TArray<TSoftObjectPtr<UFortItemDefinition>> FirstWinRewards;

	UPROPERTY(EditAnywhere, Category="Rewards", meta=(Patchable))
	TArray<FString> CalendarEventsForEndOfMatchUpdate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bAllowSinglePartyMatches;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bRequeueAfterFailedSessionAssignment;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Matchmaking", meta=(Patchable))
	bool bIsTournament;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsTournament", Patchable))
	bool bUseMultidivisionQueues;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Matchmaking", meta=(EditCondition="bIsTournament", Patchable))
	int32 CompetitivePointClamp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FString Strategy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FName BotVersionPlaylistName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Matchmaking", meta=(Patchable))
	int32 MaxBucketCapacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Matchmaking", meta=(Patchable))
	int32 MaxPendingMatches;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	TArray<FRatingExpansion> PriorityRatingExpansion;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Matchmaking", meta=(EditCondition="bIsTournament", Patchable))
	TArray<FBracketDefinition> BracketDefinitions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	TArray<FFillRateTable> FillRateTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 BotFillMMRCutoff;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	TArray<FPlayerRatingBrackets> PlayerRatingBrackets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 MinBracketSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 MaxBracketSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FString BracketBalanceMergeInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FString BracketBalanceSplitInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FString OutlierBracketBalanceMergeInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	float MinBracketPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	float MaxBracketPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	float MaxOutlierBracketPriority;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 MaxOutlierBracketMergeMmrGap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 MmrThresholdForPrioritySession;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bAllowBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bAllowBackfill", Patchable))
	int32 MinBackfillMatchPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bAllowBackfill", Patchable))
	int32 MaxTeamScoreAllowedForBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 MinPlayersForPrivateServer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bAllowBackfill", Patchable))
	float MaxTeamScoreDiscrepancyPercent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bUsePlayerRating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondtion="bEnableRatingUpdate", Patchable))
	bool bEnableRatingUpdate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bIsRankedMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float RankLossMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float RankLossFloorMod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float KillerRankShare;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	bool bUseRankScaling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float RankScalingMinDelta;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float RankScalingMaxDelta;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float RankScalingStandardDeviation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float DamageTakenMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float PlacementLossMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	float PlacementGainMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bIsRankedMode", Patchable))
	int32 SeasonNumber;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bUsePlayerRating", Patchable))
	bool bEnableDynamicBotBackfill;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Matchmaking", meta=(EditCondition="bUsePlayerRating", Patchable))
	FString RatingType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Matchmaking", meta=(Patchable))
	bool bRequireCrossplayEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bLimitedPoolMatchmakingEnabled;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking", meta=(DisplayName="Allow Splitscreen", Patchable))
	bool bAllowedInLeto;

	UPROPERTY(EditDefaultsOnly, Config, Category="Matchmaking", meta=(Patchable))
	int32 LastQueuedPlaylistPriority;

	UPROPERTY(EditDefaultsOnly, Category="Matchmaking", meta=(Patchable))
	bool bAllowInGameMatchMaking;

	UPROPERTY(EditDefaultsOnly, Category="Matchmaking", meta=(EditCondition="bAllowInGameMatchMaking", Patchable))
	bool bAllowReturnToMatchmakingOriginOnMatchEnd;

	UPROPERTY(EditDefaultsOnly, Category="Matchmaking", meta=(Patchable))
	bool bAllowBotsInHumanTeams;

	UPROPERTY(EditDefaultsOnly, Category="Matchmaking", meta=(Patchable))
	bool bForceNewPlayerStateOnReconnect;

	UPROPERTY(EditDefaultsOnly, Category="Matchmaking", meta=(Patchable))
	bool bShouldErrorOnAdditionalContentFailure;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bRemoveFromSquadOnLogout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	int32 DADTestValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	FString RequiredEntitlementToken;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	float DelayForPreServerTransitionAnimation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(Patchable))
	bool bUseKeepTogetherId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking", meta=(EditCondition="bUseKeepTogetherId", Patchable))
	int32 KeepTogetherIdExpirationInSeconds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition", meta=(Patchable))
	EAthenaWinCondition WinConditionType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition")
	FScalableFloat TimedWinConditionTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition")
	FScalableFloat FinalWinConditionTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition")
	FWinConditionScoreData ScoringData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition", meta=(Patchable))
	int32 WinConditionPlayersRemaining;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="WinCondition")
	FScalableFloat NumWinningTeamsCN;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Gameplay", meta=(Patchable))
	bool bIsLargeTeamGame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	bool bShouldSpreadTeams;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	bool bIgnoreDefaultQuests;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bDisallowMultipleWeaponsOfType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bAllowEditingEnemyWalls;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	int32 LootDropRounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	float ForceKickAfterDeathTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	EForceKickAfterDeathMode ForceKickAfterDeathMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	EWeaponSelectionPreservationType QuickbarSelectionPreservationMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	FGameplayTagContainer AlwaysAllowedNativeActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	FScalableFloat PawnForcedCullDistance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	FScalableFloat TransientMatchStartBonusCurrency;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TArray<FItemAndCount> InventoryItemsToGrant;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bIgnoreGameModeStartingInventory;

	UPROPERTY(EditDefaultsOnly, Category="Gameplay")
	FGameplayTagContainer MatchingQuestTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	float DestructedBuildingInGridTimeout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bTeamFilterDestructedBuildingsInGrid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bOwnerFilterDestructedBuildingsInGrid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bEnableBuildingCreatedEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	float MaximumAspectRatio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bVehiclesDestroyAllBuildingSMActorsOnContact;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay")
	TSubclassOf<AActor> VehicleBoundsXYSplineClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay", meta=(Patchable))
	bool bAutoAcquireSpawnChip;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay")
	TObjectPtr<USoundMix> SoundMix;

	UPROPERTY(EditDefaultsOnly, Config, Category="Gameplay", meta=(Patchable))
	bool bAllowHardcoreModifiers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn", meta=(Patchable))
	bool bForceCameraFadeOnRespawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn", meta=(Patchable))
	float MinTimeBeforeRespawnCameraFade;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Respawn", meta=(Patchable))
	EAthenaRespawnType RespawnType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RespawnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn", meta=(EditCondition="bUseMaxRespawnHeight"))
	FScalableFloat MaxRespawnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn", meta=(InlineEditConditionToggle))
	bool bUseMaxRespawnHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn", meta=(Patchable))
	bool bRespawnInAir;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	FScalableFloat RespawnLevelStreamDistanceToForceScreenFade;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Respawn")
	bool bForceRespawnLocationInsideOfVolume;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GamePhase", meta=(Patchable))
	bool bSkipWarmup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GamePhase", meta=(Patchable))
	bool bSkipAircraft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Warmup", meta=(Patchable))
	bool bAllowWarmupPlayerStartInSetupPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Warmup", meta=(Patchable))
	float WarmupEarlyRequiredPlayerPercent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(Patchable))
	EAirCraftBehavior AirCraftBehavior;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(Patchable))
	bool bUseCustomAircraftPathSelection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(Patchable))
	bool bUseSameDirectionForOpposingAircraft;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(Patchable))
	bool bAircraftDropOnlyWithinSafeZone;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft")
	FScalableFloat AircraftSafetyMarginPct;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float AircraftPathOffsetFromMapCenterMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float AircraftPathOffsetFromMapCenterMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float AircraftPathMidpointSelectionRadiusMin;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float AircraftPathMidpointSelectionRadiusMax;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float LastStepPushAircraftCenterLine_Magnitude;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Aircraft", meta=(ClampMin="0.0", EditCondition="bUseCustomAircraftPathSelection", Patchable, UIMin="0.0"))
	float LastStepPushAircraftCenterLine_Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Audio", meta=(Patchable))
	bool bDisableAudioShapes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Significance", meta=(ClampMax="1.0", ClampMin="0.0", Patchable, UIMax="1.0", UIMin="0.0"))
	float NonRenderedCharacterAnimationScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen", meta=(Patchable))
	TSubclassOf<UFortMissionGenerator> PlaylistMissionGen;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen", meta=(Patchable))
	bool bForceLTMLoadingScreenBackground;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LoadingScreen")
	TSoftClassPtr<UUserWidget> LoadingScreenWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI")
	TArray<FUIExtension> UIExtensions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="UI", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortPlaylistUIInfo> PlaylistUIData;

	UPROPERTY(EditDefaultsOnly, Category="UI", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<UFortAthenaHUDInfoDataAsset> HUDInfoDataAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	TObjectPtr<UTexture2D> MissionIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI", meta=(Patchable))
	FText UIDisplaySubName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="UI", meta=(Patchable))
	bool bLimitedTimeMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="UI", meta=(Patchable))
	bool bDisable_ReportAPlayerReason_TeamingUpWithEnemies_WhileInGame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="UI", meta=(Patchable))
	bool bDisplayScoreInHUD;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(Patchable))
	bool bDisplayRespawnWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI", meta=(Patchable))
	bool bDisableMatchStatsDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	FDataTableRowHandle SpecialActorInputActionDataTableRow;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI", meta=(Patchable))
	bool bEnforceFullSquadInUI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI|Elimination", meta=(Patchable))
	bool bShowEliminationIndicatorForSelf;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI|Elimination", meta=(Patchable))
	bool bShowEliminationIndicatorForSquadmates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI|Elimination", meta=(Patchable))
	bool bShowEliminationIndicatorForTeammates;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI|Elimination", meta=(Patchable))
	bool bShowEliminationIndicatorForEnemies;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI|Elimination")
	FScalableFloat EliminationIndicatorMaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="UI|Leaderboards", meta=(Patchable))
	bool bLeaderboardDisplaysIndividuals;

	UPROPERTY(EditDefaultsOnly, Category="UI|Leaderboards", meta=(Patchable))
	bool bUsePointLeaderAsTeamLeaderInLeaderboard;

	UPROPERTY(EditDefaultsOnly, Category="UI|Leaderboards", meta=(Patchable))
	EFortLeaderboardMetric TypeOfLeaderboard;

	UPROPERTY(EditDefaultsOnly, Category="Replay")
	FScalableFloat OnlyRespectsGlobalSettingForReplayRecording;

	UPROPERTY(EditDefaultsOnly, Category="Replay", meta=(DisplayName="Disable Client Replays"))
	FScalableFloat DisableReplays;

	UPROPERTY(EditDefaultsOnly, Category="Replay")
	FScalableFloat EnableServerReplays;

	UPROPERTY(EditDefaultsOnly, Category="Replay", meta=(Patchable))
	float ReplayChunkTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Voice")
	FScalableFloat ShouldUseCustomGameChannel;

	UPROPERTY(EditDefaultsOnly, Category="Voice")
	FScalableFloat ShouldRejectDefaultGameChat;

	UPROPERTY(EditDefaultsOnly, Category="Voice", meta=(Patchable))
	ECustomGameVoiceChannel CustomGameChannel;

	UPROPERTY(EditDefaultsOnly, Category="Voice")
	FScalableFloat ShouldRecommendCustomGameChannel;

	UPROPERTY(EditDefaultsOnly, Category="Voice")
	bool bForceGameChannel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map")
	FSlateBrush MapImageOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map", meta=(Patchable))
	float MapScaleOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map", meta=(Patchable))
	bool bDrawCreativeDynamicIslands;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Map", meta=(AssetBundles="Equipped"))
	TSoftClassPtr<AFortInGameMapManager> MapManagerClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Physics", meta=(Patchable))
	bool bUseAsyncPhysics;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	EFortServerTickRate ServerMaxTickRate;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	bool bOverrideServerPerClientMaxAI;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(EditCondition="bOverrideServerPerClientMaxAI", Patchable))
	int32 ServerPerClientMaxAI;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm", meta=(Patchable))
	ESafeZoneStartUp SafeZoneStartUp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Storm", meta=(Patchable))
	bool bWarmUpInStorm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Storm", meta=(Patchable))
	float StormEffectDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Storm", meta=(Patchable))
	bool bDisplayFinalStormPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm", meta=(Patchable))
	bool bDrawLineToStormCircleIfOutside;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm", meta=(Patchable))
	int32 LastSafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UCurveTable> SafeZoneLocationBlacklist;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> CreativeItemListSource;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> UpgradeBenchData;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> AILootOnDeathData;

	UPROPERTY(EditDefaultsOnly, Category="DataOverrides", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UDataTable> HeroStats;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDrops", meta=(Patchable))
	bool bUseDefaultSupplyDrops;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDrops")
	TArray<FSupplyDropModifierData> SupplyDropModifierList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SupplyDrops", meta=(AssetBundles="Equipped"))
	TArray<TSoftObjectPtr<UFortSupplyDropInfo>> SupplyDropInfoList;

	UPROPERTY(EditDefaultsOnly, Category="NamedWeights")
	TArray<TSoftObjectPtr<UDataTable>> QueryNameToLootChanceScaleTables;

	UPROPERTY(EditDefaultsOnly, Category="NamedWeights")
	TArray<TSoftObjectPtr<UDataTable>> QueryNameToLootCountScaleTables;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Exit Craft", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UFortAthenaExitCraftInfo> ExitCraftInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character Parts", meta=(Patchable))
	bool bPlaylistUsesCustomCharacterParts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Character Parts")
	TArray<FCharacterPreloadBlock> CharactersToPreload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Character Parts")
	TArray<FCharacterFallbackPreloadBlock> CharacterFallbackTagsToPreload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AIPawn Customizations")
	TArray<FGameplayTag> AIPawnCustomizationFallbackTagsToPreload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SpawnActors", meta=(AssetBundles="Equipped"))
	TArray<TSoftObjectPtr<UFortSpawnActorInfo>> SpawnActorInfoList;

	UPROPERTY(EditDefaultsOnly, Category="Performance", meta=(Patchable))
	int32 NetActorDiscoveryBudgetInKBytesPerSec;

	UPROPERTY(EditDefaultsOnly, Category="Performance")
	int32 NetDormancyNumFramesUntilObsolete;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bEnableCreativeMode : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bEnableSpawningStartup : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bAllowTeamSwitching : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bShowTeamSelectButton : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bAllowLayoutRequirementsFeature : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bUseCreativeStarterIsland : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(Patchable))
	uint8 bForceCustomMinigame : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Level", meta=(Patchable))
	uint8 bPreloadAthenaMapsForMatchmaking : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AnimationSharing", meta=(Patchable))
	bool bUsesAnimationSharing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AnimationSharing", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UAnimationSharingSetup> AnimationSharingSetup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowBroadcasting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Playlist", meta=(Patchable))
	bool bAllowSpectateAPartyMember;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Curie", meta=(Patchable))
	bool bActivateCurie;

	UPROPERTY(EditDefaultsOnly, Category="Curie", meta=(EditCondition="bActivateCurie"))
	TObjectPtr<UFortCurieSettings> CurieSettings;

	UPROPERTY(EditDefaultsOnly, Config, Category="Curie", meta=(Patchable))
	TArray<FName> CurieManagerConfigOverrides;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Gameplay", meta=(Patchable))
	bool bRequirePickaxeInStartingInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="Stats", meta=(Patchable))
	int32 PlaylistStatId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="Stats", meta=(Patchable))
	bool bAccumulateToProfileStats;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="Stats", meta=(Patchable))
	bool bSaveToRecentGameList;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, AssetRegistrySearchable, Category="Stats", meta=(Patchable))
	bool bEnableStatsV2Stats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI", meta=(AssetBundles="Equipped"))
	TSoftObjectPtr<UAthenaAISettings> AISettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Creative", meta=(MustImplement="/Script/FortniteGame.FortTimeOfDayManagerInterface"))
	TSoftClassPtr<AInfo> DefaultCreativeTOD;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FScalableFloat MaxVehiclesCanSpawnWithTireMod;

	UPROPERTY(EditDefaultsOnly, Category="Vehicles")
	FScalableFloat PercentChanceSpawnWithTireMod;

	UPROPERTY(EditAnywhere, Category="Matchmaking", meta=(Patchable))
	float WaitForServerInitializationTimeoutSecondsOverride;

};

