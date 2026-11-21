// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/TimerHandle.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortTypes.h"
#include "Pawns/FortAIPawn.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Mash.generated.h"

class AActor;
class ABuildingActor;
class ABuildingRift;
class AController;
class AFortAIPawn;
class AFortPawn;
class AFortPlayerControllerAthena;
class AFortPlayerStart;
class AFortPlayerStateAthena;
class UDataTable;
class UEnvQuery;
class UFortAIEncounterInfo;
class UFortDifficultyEncounterSettings;
class UGameplayEffect;
class UMaterialInterface;
class UPrimitiveComponent;
class USplineComponent;

UENUM()
enum class EMashAISpecialEncounterType : uint8
{
	/** This encounter will spawn a boss that will display a special boss health bar in the HUD.
	*	When a boss is spawned the current safezone phase will NOT end until the boss is killed, then the phase will end immediately.
	*	Bosses can also override the size of the safezone. */
	Boss = 0,
	/** A specific enemy is spawned, but this enemy is not treated as anything special. Killing the enemy does not end the phase early nor is killing this type of enemy required to end the phase. */
	UniqueAISpawn = 1,
};

UENUM()
enum class EMashDifficulty : uint8
{
	Easy = 0,
	Medium = 1,
	Hard = 2,
};

UENUM(BlueprintType)
namespace EMashPhase
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
namespace EMashScoreEvent
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
		BossKill = 13,
		FinalBossKill = 14,
		SafeDetonationDistanceKill = 15,
		SpecialEncounterKill = 16,
		MAX = 17,
	};
}

USTRUCT(BlueprintType)
struct FMashBossHealthShieldData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MashBossHealthShieldData")
	float TotalHealth;

	UPROPERTY(BlueprintReadOnly, Category="MashBossHealthShieldData")
	float CurrentHealth;

	UPROPERTY(BlueprintReadOnly, Category="MashBossHealthShieldData")
	float TotalShield;

	UPROPERTY(BlueprintReadOnly, Category="MashBossHealthShieldData")
	float CurrentShield;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMashBossHealthShieldChanged, const FMashBossHealthShieldData&, NewHealthShieldData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMashBossPawnChanged, AFortPawn*, NewBossPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMashInitialized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMashPhaseChanged, int32, NewPhase);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMashPlayerDataChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMashScoresFinalized);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMashVictory);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerFriendLeaderboardUpdated, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTeamScoreMultiplierChanged, uint8, Multiplier);

USTRUCT(BlueprintType)
struct FMashAIEncounterWeights
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MashAIEncounterWeights")
	FScalableFloat EnabledPercentChance;

	UPROPERTY(EditDefaultsOnly, Category="MashAIEncounterWeights")
	FScalableFloat SpawnDelay;

	UPROPERTY(EditDefaultsOnly, Category="MashAIEncounterWeights")
	TMap<FName, FScalableFloat> EncounterWeightsByNameMap;

};

USTRUCT(BlueprintType)
struct FMashAIPawnLootDropOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashAIPawnLootDropOverride")
	FGameplayTag Tag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashAIPawnLootDropOverride")
	FFortAIPawnLootDropData LootDropData;

};

USTRUCT(BlueprintType)
struct FMashAISpecialEncounterData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="MashAISpecialEncounterData")
	EMashAISpecialEncounterType EncounterType;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyEncounterSettings")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettings;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot Pawn", meta=(EditCondition="DifficultyEncounterSettings == nullptr"))
	FPrimaryAssetId AIBotSpawnerDataAssetId;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot Pawn", meta=(EditCondition="DifficultyEncounterSettings == nullptr"))
	TObjectPtr<UEnvQuery> AIBotSpawnLocationQuery;

	UPROPERTY(EditDefaultsOnly, Category="AI Bot Pawn", meta=(EditCondition="DifficultyEncounterSettings == nullptr"))
	FScalableFloat AIBotSkillValue;

	UPROPERTY(EditDefaultsOnly, Category="MashAISpecialEncounterData")
	TArray<TSubclassOf<UGameplayEffect>> InitialGameplayEffectByPlayerCount;

};

USTRUCT(BlueprintType)
struct FMashAreaSpecialActorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashAreaSpecialActorData")
	bool bShouldDrawCompassIcon;

};

USTRUCT(BlueprintType)
struct FMashDifficultySettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashDifficultySettings")
	FScalableFloat SpawnCountPlayerCountMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashDifficultySettings")
	FScalableFloat SpawnCountDifficultyMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashDifficultySettings")
	FScalableFloat AIEffectPlayerCountMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashDifficultySettings")
	FScalableFloat AIEffectDifficultyMultiplier;

	UPROPERTY(Transient)
	float SpawnCountMultiplier;

	UPROPERTY(Transient)
	float AIEffectMultiplier;

};

USTRUCT(BlueprintType)
struct FMashLeaderboardEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	int32 Value;

	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	int32 Rank;

	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	FUniqueNetIdRepl UserNetId;

	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	bool bIsSpecialEntry;

	UPROPERTY(BlueprintReadOnly, Category="MashLeaderboardEntry")
	bool bIsLocalPlayer;

};

USTRUCT(BlueprintType)
struct FMashFriendsLeaderboard
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MashFriendsLeaderboard")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="MashFriendsLeaderboard")
	TArray<FMashLeaderboardEntry> LeaderBoard;

};

USTRUCT()
struct FMashLeaderboardQuery
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl RequestingId;

};

USTRUCT(BlueprintType)
struct FMashLootTierOverrideAssetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashLootTierOverrideAssetData")
	int32 SafeZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashLootTierOverrideAssetData")
	FName TieredGroup;

};

USTRUCT()
struct FMashScoreMultiplierInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> Actor;

	UPROPERTY(Transient)
	FName SpecialActorID;

};

USTRUCT()
struct FMashObjectiveAreaInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	FRotator Rotation;

	UPROPERTY(Transient)
	TObjectPtr<AActor> AreaActor;

	UPROPERTY(Transient)
	FName SpecialActorID;

	UPROPERTY(Transient)
	TArray<FMashScoreMultiplierInstanceData> ScoreMultipliers;

};

USTRUCT(BlueprintType)
struct FMashScoreTrackingData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 Count;

	UPROPERTY(Transient)
	int32 Score;

};

USTRUCT(BlueprintType)
struct FMashPlayerDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MashPlayerDataEntry")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, NotReplicated, Category="MashPlayerDataEntry")
	FString PlayerName;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EMashScoreEvent"))
	FMashScoreTrackingData ScoreTracking[17];

	UPROPERTY(BlueprintReadOnly, Transient, Category="MashPlayerDataEntry")
	int32 TotalScore;

	UPROPERTY(Transient)
	uint8 StreakScoreLevel;

	UPROPERTY(Transient)
	uint8 StreakMultiplierKillCountCurrentForLevel;

	UPROPERTY(Transient, NotReplicated)
	uint32 StreakMultiplierKillCountCurrentTotal;

	UPROPERTY(Transient, NotReplicated)
	uint32 StreakMultiplierKillCountHighestThisSession;

	UPROPERTY(Transient, NotReplicated)
	float LastAIKillTime;

	UPROPERTY(Transient, NotReplicated)
	TArray<float> AIKillTimes;

	UPROPERTY(Transient, NotReplicated)
	FTimerHandle ResetStreakScoreMultiplierTimerHandle;

	UPROPERTY(Transient, NotReplicated)
	int32 TotalAIKillCount;

	UPROPERTY(Transient, NotReplicated)
	float TotalAIDamageDealt;

	UPROPERTY(Transient, NotReplicated)
	float TotalRiftDamageDealt;

	UPROPERTY(Transient, NotReplicated)
	float TotalRiftDamageDealtByPickaxe;

	UPROPERTY(Transient)
	uint32 LastReportedTeamScore;

};

USTRUCT(BlueprintType)
struct FMashPlayerDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MashPlayerDataArray")
	TArray<FMashPlayerDataEntry> Entries;

};

USTRUCT(BlueprintType)
struct FMashScoreData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FGameplayTagContainer ExclusionTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FScalableFloat ScoreValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FScalableFloat bUsesStreakScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FScalableFloat bUsesTeamScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreData")
	FText ScoreText;

};

USTRUCT(BlueprintType)
struct FMashScoreMultiplierSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FScalableFloat ScoreMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FScalableFloat SpawnCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FScalableFloat MinSpawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FScalableFloat MaxSpawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	TSubclassOf<ABuildingActor> ObjectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FGameplayTag SpecialActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashScoreMultiplierSpawnData")
	bool bShouldDrawCompassIcon;

};

USTRUCT(BlueprintType)
struct FMashTableRowPoiRoute : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashTableRowPoiRoute")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashTableRowPoiRoute")
	FScalableFloat Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashTableRowPoiRoute")
	TArray<FGameplayTag> PoiTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MashTableRowPoiRoute")
	TArray<FGameplayTag> MoveSplineTags;

};

USTRUCT(BlueprintType)
struct FRiftDamagerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="RiftDamagerInfo")
	TObjectPtr<ABuildingRift> Rift;

	UPROPERTY(BlueprintReadOnly, Transient, Category="RiftDamagerInfo")
	TArray<TObjectPtr<AController>> Damagers;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Mash : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Score")
	bool ArePlayerScoresFinal() const;

	UFUNCTION(BlueprintPure)
	virtual const FText& GetBossDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Boss AI")
	const FMashBossHealthShieldData& GetBossHealthShieldData() const;

	UFUNCTION(BlueprintPure, Category="Leaderboard")
	bool GetPlayerBestScore(AFortPlayerControllerAthena* AthenaPC, int32& OutStatValue) const;

	UFUNCTION(BlueprintPure, Category="Score")
	bool GetPlayerScore(const AFortPlayerControllerAthena* AthenaPlayerController, int32& OutScore) const;

	UFUNCTION(BlueprintPure, Category="Score")
	bool GetPlayerScoreFromPlayerState(const AFortPlayerStateAthena* AthenaPlayerState, int32& OutScore) const;

	UFUNCTION(BlueprintPure)
	float GetStreakScoreMultiplierResetTime() const;

	UFUNCTION(BlueprintPure, Category="Score")
	int32 GetTeamScore(const uint8 TeamId) const;

	UFUNCTION(BlueprintCallable, Category="Leaderboard")
	void RetrievePlayerFriendsLeaderBoard(AFortPlayerControllerAthena* AthenaPC);

	UPROPERTY(BlueprintAssignable)
	FOnTeamScoreMultiplierChanged OnTeamScoreMultiplierChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMashPlayerDataChanged OnPlayerDataChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMashScoresFinalized OnScoresFinalized;

	UPROPERTY(BlueprintAssignable)
	FOnMashPhaseChanged OnPhaseChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMashVictory OnMashVictory;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerFriendLeaderboardUpdated OnPlayerFriendLeaderboardUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnMashBossPawnChanged OnBossPawnChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMashBossHealthShieldChanged OnBossHealthShieldChanged;

	UPROPERTY(BlueprintAssignable)
	FOnMashInitialized OnMashInitialized;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Mash")
	UDataTable* PoiRoutesDataTable;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Mash")
	FName DebugPoiRouteName;

protected:
	UFUNCTION()
	void HandleAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleAISpecialEncounterAISpawned(UFortAIEncounterInfo* Encounter, AFortAIPawn* SpawnedEnemy);

	UFUNCTION()
	void HandleBossAIDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleBossPawnHealthShieldChanged();

	UFUNCTION()
	void HandleRiftDamaged(AActor* DamagedRiftActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleRiftDying(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift, AController* Controller, AActor* DamageActor);

	UFUNCTION()
	void HandleRiftSpawned(UFortAIEncounterInfo* Encounter, ABuildingRift* Rift);

	UFUNCTION()
	void MaybeSpawnAISpecialEncounterForSafeZone(const int32 InSafeZoneIndex);

	UFUNCTION()
	void OnRep_BossHealthShieldData();

	UFUNCTION()
	void OnRep_BossPawn();

	UFUNCTION()
	void OnRep_bScoresAreFinal();

	UFUNCTION()
	void OnRep_CurrentPhase();

	UFUNCTION()
	void OnRep_PlayerData();

	UFUNCTION()
	void OnRep_TeamScoreMultiplier();

	UFUNCTION()
	void OnScoreMultiplierInteractionCompleted(ABuildingActor* SelfActor, AFortPawn* InteractingPawn);

	UFUNCTION()
	void ResetStreakScoreMultiplier(AFortPlayerStateAthena* PlayerState);

	UFUNCTION()
	void ScheduleMarkPlayerScoresAsFinal();

	UFUNCTION()
	void SpawnObjectiveAreaObjects();

	UPROPERTY(EditDefaultsOnly, Category="Cheat")
	bool bCheatMakeFirstPhaseTheFinalPhase;

	UPROPERTY(EditDefaultsOnly, Category="Cheat")
	TArray<FString> DebugObjectiveActorNameOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	bool bOverrideReplicationSettingsDebug;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	FScalableFloat MaxAIPerClient;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	FScalableFloat ReplicateGameplayCues;

	UPROPERTY(EditDefaultsOnly, Category="Debug")
	EMashDifficulty CurrentDifficulty;

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

	UPROPERTY(EditDefaultsOnly, Category="Areas")
	FGameplayTag RouteActorTag;

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
	FMashAreaSpecialActorData AreaSpecialActorData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Objectives")
	FMashScoreMultiplierSpawnData ScoreMutliplierSpawnData;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettingsStatic;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	TObjectPtr<UFortDifficultyEncounterSettings> DifficultyEncounterSettingsDynamic;

	UPROPERTY(EditDefaultsOnly, Category="AI | Special AI Encounter")
	TMap<int32, FMashAIEncounterWeights> AISpecialEncountersBySafeZoneIndexMap;

	UPROPERTY(EditDefaultsOnly, Category="AI | Special AI Encounter")
	TMap<FName, FMashAISpecialEncounterData> AISpecialEncounterOptionsMap;

	UPROPERTY(EditDefaultsOnly, Category="AI | Special AI Encounter")
	FText BossEncounterDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="AI | Special AI Encounter")
	FText FinalBossEncounterDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="AI | Special AI Encounter")
	FScalableFloat OverrideBossPhaseSafeZoneRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashMessages")
	FScalableFloat DisplayIntroGameMsg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashMessages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashMessages")
	FScalableFloat DisplayOnTeamMultiplierIncreasedGameMsg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="MashMessages")
	FAthenaGameMessageData GameMsg_OnTeamMultiplierIncreased;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Difficulty")
	FMashDifficultySettings DifficultySettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	bool bUseLootTierOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	TArray<FMashLootTierOverrideAssetData> LootTierOverrides;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loot")
	TArray<FMashAIPawnLootDropOverride> PawnAILootDropOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Score")
	FGameplayTag HeadshotGameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="Score", meta=(ArraySizeEnum="/Script/FortniteGame.EMashScoreEvent"))
	FMashScoreData ScoreEventList[17];

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	TArray<TEnumAsByte<EMashScoreEvent::Type>> SafeDetonationScoreEventTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Score")
	FScalableFloat SafeDetonationKillDistance;

	UPROPERTY(EditDefaultsOnly, Category="Tournament")
	FString TeamScoreTournamentStatName;

	UPROPERTY(EditDefaultsOnly, Category="Quest", meta=(Categories="CustomVerb"))
	FGameplayTag ReportQS2TeamScoreTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest", meta=(Categories="CustomVerb"))
	FGameplayTag ReportQS2KillStreakMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FGameplayTag VictoryQuestTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FGameplayTag StreakMultiplierKillCountQuestTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	TMap<uint32, FGameplayTag> StreakMultiplierKillCountQuestTagMap;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FGameplayTag RiftDamageDealtByPickaxeQuestTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FScalableFloat ReportTeamScoreInterval;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FGameplayTag ReportTeamScoreTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest")
	FGameplayTag ReportTeamScoreChangesTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Leaderboard")
	TArray<FString> PlayerStatsNames;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	FScalableFloat FriendsLeaderboardDisplayedNumber;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	FScalableFloat MinNumberOfScoresToDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	float TimeSecRetreiveLeaderboardTimeOut;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	FScalableFloat MaxTotalNumFriendsForLeaderboardQuery;

	UPROPERTY(EditDefaultsOnly, Category="Leaderboard")
	FScalableFloat MaxNumFriendsForSingleLeaderboardQuery;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	bool bMashInitialized;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	bool bScoringAndIntroMessageInitialized;

	UPROPERTY(Transient)
	bool bInitRequirementAllAdditionalPlaylistLevelsVisible;

	UPROPERTY(Transient)
	bool bInitRequirementSafeZoneLocationsInitialized;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	bool bIsGameOver;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortAthenaMutator_Mash")
	bool bIsRespawningAllowed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	uint8 CurrentObjectiveAreaIndex;

	UPROPERTY(Transient, Replicated)
	uint8 TotalObjectiveAreaCount;

	UPROPERTY(Transient)
	TArray<FMashObjectiveAreaInstanceData> ObjectiveAreas;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USplineComponent>> RouteSplineComponents;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> CurrentEncounter;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> AISpecialEncounter;

	UPROPERTY(Transient)
	FName CurrentLootTierGroupOverride;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TeamScoreMultiplier, Category="FortAthenaMutator_Mash")
	uint8 TeamScoreMultiplier;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PlayerData, Category="FortAthenaMutator_Mash")
	FMashPlayerDataArray PlayerDataArray;

	UPROPERTY(ReplicatedUsing=OnRep_bScoresAreFinal)
	bool bScoresAreFinal;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentPhase, Category="FortAthenaMutator_Mash")
	TEnumAsByte<EMashPhase::Type> CurrentPhase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	TObjectPtr<AFortPlayerStart> RespawnLocationActor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	TArray<FRiftDamagerInfo> RiftDamagerInfo;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_BossPawn, Category="FortAthenaMutator_Mash")
	TObjectPtr<AFortPawn> BossPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	TObjectPtr<AFortPawn> SpecialEncounterPawn;

	UPROPERTY(Replicated)
	bool bFinalBossEncounterSpawned;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_BossHealthShieldData, Category="FortAthenaMutator_Mash")
	FMashBossHealthShieldData BossHealthShieldData;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAthenaMutator_Mash")
	FMashFriendsLeaderboard LocalPlayerFriendsLeaderboard;

	UPROPERTY(Transient)
	FMashLeaderboardQuery LocalPlayerFriendsLeaderboardQuery;

private:
	UFUNCTION()
	void BuildAndReportPlayersScores_PostMatch() const;

};

UCLASS()
class UFortCheatManager_Mash : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void MashFinalPhase(const FName BossEncounterName = NAME_None);

	UFUNCTION(Exec)
	void MashGetAISpecialEncounterNames();

	UFUNCTION(Exec)
	void MashSetFinalBoss(const FName BossEncounterName = NAME_None);

	UFUNCTION(Exec)
	void MashSetNextAISpecialEncounter(const FName EncounterName = NAME_None);

	UFUNCTION(Exec)
	void MashSpawnScoreMultiplier();

	UFUNCTION(Exec)
	void MashWin();

};

