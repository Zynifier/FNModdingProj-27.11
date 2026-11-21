// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_Mash.h"
#include "FortTypes.h"
#include "FortAthenaMutator_Bagel.generated.h"

class AActor;
class ABuildingActor;
class ABuildingRift;
class AController;
class AFortAIPawn;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerStart;
class AFortPlayerStateAthena;
class UFortAIEncounterInfo;
class UFortDifficultyEncounterSettings;
class UMaterialInterface;
class UPrimitiveComponent;

UENUM()
enum class EBagelDifficulty : uint8
{
	Easy = 0,
	Medium = 1,
	Hard = 2,
};

UENUM(BlueprintType)
namespace EBagelPhase
{
	enum Type
	{
		NotStarted = 0,
		Preparation = 1,
		Survival = 2,
		AfterMath = 3,
		Moving = 4,
		FinalPhase = 5,
		FinalPhaseFullStorm = 6,
		MAX = 7,
	};
}

UENUM(BlueprintType)
namespace EBagelScoreEvent
{
	enum Type
	{
		FiendKill = 0,
		BruteKill = 1,
		RangedKill = 2,
		ExplodingKill = 3,
		ChillKill = 4,
		PoisonKill = 5,
		GoldKill = 6,
		RiftDestroyed = 7,
		ScoreMultiplierUsed = 8,
		HeadshotKill = 9,
		RespawnPenalty = 10,
		AmmoBoxOpened = 11,
		ChestOpened = 12,
		FinalBossKill = 13,
		MAX = 14,
	};
}

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBagelPhaseChanged, int32, NewPhase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBagelPlayerDataChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBagelVictory);

USTRUCT(BlueprintType)
struct FBagelAreaSpecialActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelAreaSpecialActorData")
	bool bShouldDrawCompassIcon;

};

USTRUCT(BlueprintType)
struct FBagelDifficultySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelDifficultySettings")
	FScalableFloat SpawnCountPlayerCountMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelDifficultySettings")
	FScalableFloat SpawnCountDifficultyMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelDifficultySettings")
	FScalableFloat AIEffectPlayerCountMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelDifficultySettings")
	FScalableFloat AIEffectDifficultyMultiplier;

	UPROPERTY(Transient)
	float SpawnCountMultiplier;

	UPROPERTY(Transient)
	float AIEffectMultiplier;

};

USTRUCT(BlueprintType)
struct FBagelLeaderboardEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	int32 Value;

	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	int32 Rank;

	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	FUniqueNetIdRepl UserNetId;

	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	bool bIsSpecialEntry;

	UPROPERTY(BlueprintReadOnly, Category="BagelLeaderboardEntry")
	bool bIsLocalPlayer;

};

USTRUCT(BlueprintType)
struct FBagelFriendsLeaderboard
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BagelFriendsLeaderboard")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="BagelFriendsLeaderboard")
	TArray<FBagelLeaderboardEntry> LeaderBoard;

};

USTRUCT()
struct FBagelLeaderboardQuery
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl RequestingId;

};

USTRUCT(BlueprintType)
struct FBagelLootTierOverrideAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelLootTierOverrideAssetData")
	int32 SafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelLootTierOverrideAssetData")
	FName TieredGroup;

};

USTRUCT()
struct FBagelScoreMultiplierInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> Actor;

	UPROPERTY(Transient)
	FName SpecialActorID;

};

USTRUCT()
struct FBagelObjectiveAreaInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	TObjectPtr<AActor> AreaActor;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY(Transient)
	TArray<FBagelScoreMultiplierInstanceData> ScoreMultipliers;

};

USTRUCT(BlueprintType)
struct FBagelPlayerDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="BagelPlayerDataEntry")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EBagelScoreEvent"))
	int32 Scores[14];

	UPROPERTY(BlueprintReadOnly, Transient, Category="BagelPlayerDataEntry")
	int32 TotalScore;

	UPROPERTY(Transient)
	uint8 StreakScoreLevel;

	UPROPERTY(Transient)
	uint8 StreakMultiplierCurrentKillCount;

	UPROPERTY(Transient, NotReplicated)
	float LastAIKillTime;

	UPROPERTY(Transient, NotReplicated)
	TArray<float> AIKillTimes;

	UPROPERTY(Transient, NotReplicated)
	FTimerHandle ResetStreakScoreMultiplierTimerHandle;

	UPROPERTY(Transient, NotReplicated)
	int32 TotalAIKillCount;

};

USTRUCT(BlueprintType)
struct FBagelPlayerDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BagelPlayerDataArray")
	TArray<FBagelPlayerDataEntry> Entries;

};

USTRUCT(BlueprintType)
struct FBagelScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreData")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreData")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreData")
	FGameplayTagContainer ExclusionTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreData")
	FScalableFloat ScoreValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreData")
	FText ScoreText;

};

USTRUCT(BlueprintType)
struct FBagelScoreMultiplierSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FScalableFloat ScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FScalableFloat SpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FScalableFloat MinSpawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FScalableFloat MaxSpawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	TSubclassOf<ABuildingActor> ObjectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BagelScoreMultiplierSpawnData")
	bool bShouldDrawCompassIcon;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Bagel : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Leaderboard")
	bool GetPlayerBestScore(AFortPlayerControllerAthena* AthenaPC, int32& OutStatValue) const;

	UFUNCTION(BlueprintPure, Category="Score")
	bool GetPlayerScore(AFortPlayerControllerAthena* AthenaPC, int32& OutScore) const;

	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void RetrievePlayerFriendsLeaderBoard(AFortPlayerControllerAthena* AthenaPC);

	UPROPERTY(BlueprintAssignable)
	FOnTeamScoreMultiplierChanged OnTeamScoreMultiplierChanged;

	UPROPERTY(BlueprintAssignable)
	FOnBagelPlayerDataChanged OnPlayerDataChanged;

	UPROPERTY(BlueprintAssignable)
	FOnBagelPhaseChanged OnPhaseChanged;

	UPROPERTY(BlueprintAssignable)
	FOnBagelVictory OnBagelVictory;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerFriendLeaderboardUpdated OnPlayerFriendLeaderboardUpdated;

protected:
	UFUNCTION()
	void HandleAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleFinalPhaseAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleFinalPhaseAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleRiftDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleRiftDying(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift, AController* Controller, AActor* DamageActor);

	UFUNCTION()
	void HandleRiftSpawned(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift);

	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UFUNCTION()
	void OnRep_CurrentPhase();

	UFUNCTION()
	void OnRep_PlayerData();

	UFUNCTION()
	void OnRep_TeamScoreMultiplier();

	UFUNCTION()
	void OnSafeZoneUpdated(const FFortSafeZonePhaseUpdatedEvent& Event);

	UFUNCTION()
	void OnScoreMultiplierInteractionCompleted(ABuildingActor* SelfActor, AFortPawn* InteractingPawn);

	UFUNCTION()
	void OverrideStormMaterial(const FFortSafeZoneIndicatorUpdatedEvent& Event);

	UFUNCTION()
	void ResetStreakScoreMultiplier(AFortPlayerStateAthena* PlayerState);

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	bool bOverrideReplicationSettingsDebug;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	FScalableFloat MaxAIPerClient;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	FScalableFloat ReplicateGameplayCues;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	EBagelDifficulty CurrentDifficulty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Storm")
	TArray<TObjectPtr<UMaterialInterface>> StormMaterialOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Areas")
	TSubclassOf<AActor> ObjectiveObjectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Areas")
	TSubclassOf<AActor> FinalPhaseObjectiveObjectClass;

	UPROPERTY(EditDefaultsOnly, Category="Areas")
	FGameplayTag StartingAreaTag;

	UPROPERTY(EditDefaultsOnly, Category="Areas")
	FGameplayTag ObjectiveAreaTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat IsPreparationPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat IsSurvivePhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat IsMovingPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat IsAftermathPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat IsFinalPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat RefillPlayerHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat RefillPlayerShield;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat OnlyRespawnAtNewPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Phases")
	FScalableFloat ShouldRespawnDeadPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	float SpawnScoreMultiplierTraceStartHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	float SpawnSscoreMultiplierTraceEndHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	FBagelAreaSpecialActorData AreaSpecialActorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	FBagelScoreMultiplierSpawnData ScoreMutliplierSpawnData;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettingsStatic;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettingsDynamic;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettingsFinalPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelMessages")
	FScalableFloat DisplayIntroGameMsg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelMessages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelMessages")
	FScalableFloat DisplayOnTeamMultiplierIncreasedGameMsg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BagelMessages")
	FAthenaGameMessageData GameMsg_OnTeamMultiplierIncreased;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	FBagelDifficultySettings DifficultySettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	bool bUseLootTierOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	TArray<FBagelLootTierOverrideAssetData> LootTierOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Score")
	FGameplayTag HeadshotGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Score", meta=(ArraySizeEnum="/Script/FortniteGame.EBagelScoreEvent"))
	FBagelScoreData ScoreEventList[14];

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat ObjectiveAreaCompletedScoreMultiplierBonus;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat RiftDestroyedScoreMultiplierBonus;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierUseSpecialMechanicToActivate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierResetTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierKillThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierTimeThresholdToActivate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierMaxLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat StreakScoreMultiplierValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leaderboard")
	TArray<FString> PlayerStatsNames;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	int32 FriendsLeaderboardDisplayedNumber;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	float TimeSecRetreiveLeaderboardTimeOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Bagel")
	bool bIsGameOver;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_Bagel")
	bool bIsRespawningAllowed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Bagel")
	uint8 CurrentObjectiveAreaIndex;

	UPROPERTY(Transient, Replicated)
	uint8 TotalObjectiveAreaCount;

	UPROPERTY(Transient)
	TArray<FBagelObjectiveAreaInstanceData> ObjectiveAreas;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> CurrentEncounter;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> FinalPhaseEncounter;

	UPROPERTY(Transient)
	FName CurrentLootTierGroupOverride;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TeamScoreMultiplier, Category="FortAthenaMutator_Bagel")
	uint8 TeamScoreMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerData, Category="FortAthenaMutator_Bagel")
	FBagelPlayerDataArray PlayerDataArray;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentPhase, Category="FortAthenaMutator_Bagel")
	TEnumAsByte<EBagelPhase::Type> CurrentPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Bagel")
	TObjectPtr<AFortPlayerStart> RespawnLocationActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Bagel")
	TArray<FRiftDamagerInfo> RiftDamagerInfo;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_Bagel")
	TObjectPtr<AFortAIPawn> FinalBoss;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Bagel")
	FBagelFriendsLeaderboard LocalPlayerFriendsLeaderboard;

	UPROPERTY(Transient)
	FBagelLeaderboardQuery LocalPlayerFriendsLeaderboardQuery;

};

