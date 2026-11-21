// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Athena/FortMutatorContext.h"
#include "Athena/FortPlayerControllerAthena.h"
#include "Building/FortVolumeAccessorInterface.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "Creative/FortCreativeIconOption.h"
#include "FortInitializationInterface.h"
#include "FortItemAndCount.h"
#include "FortUIExtension.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "Minigame/FortMinigameStats.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortMinigame.generated.h"

class AActor;
class AController;
class AFortMinigame;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class AFortPlayerStartCreative;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortPlayerStateZone;
class AGameplayVolume;
class APawn;
class APlayerState;
class UCreativePlayerHealthInfoComponent;
class UFortAIManagerMinigameComponent;
class UFortCreativeCreatureManagerComponent;
class UFortCreativeTeleporterManagerComponent;
class UFortMinigameLogicComponent;
class UFortMinigamePlayerStartComponent;
class UFortMinigameStatFilter;
class UFortWorldItemDefinition;
class UObject;
class USceneComponent;
class UUserWidget;
enum class ECreativeBossDisplayMode : uint8;
enum class EDeviceFireVolumeFireOption : uint8;
enum class EFortMinigameEnd : uint8;
enum class EFortMinigameExec : uint8;
enum class EFortMinigamePlayerSpawnLocationSetting : uint8;
enum class EFortMinigameState : uint8;
enum class EFortQuestObjectiveStatEvent : uint8;
enum class EMinigameFullscreenMapWidgetType : uint8;
enum class EMinigameScoreboardStates : uint8;
enum class EPlayerIndicatorDisplayMode : uint8;
enum class ERoundVictoryAnimation : uint8;

UENUM(BlueprintType)
enum class EDeviceFireVolumeFireOption : uint8
{
	None = 0 UMETA(DisplayName="None"),
	UseIslandSettings = 1 UMETA(DisplayName="UseIslandSettings"),
	Yes = 2 UMETA(DisplayName="Yes"),
	No = 3 UMETA(DisplayName="No"),
};

UENUM(BlueprintType)
enum class EFortMinigameEnd : uint8
{
	// Abrupt end with no UI, minimal cleanup

	Teardown = 0,
	// Abrupt end with no UI

	AbandonGame = 1,
	// Graceful end with UI

	EndGame = 2,
	// Graceful end with UI and start next round

	EndRound = 3,
};

UENUM(BlueprintType)
enum class EFortMinigameExec : uint8
{
	Yes = 0,
	No = 1,
};

UENUM(BlueprintType)
enum class EMinigameFullscreenMapWidgetType : uint8
{
	Last_Opened = 0 UMETA(DisplayName="Last Opened Tab"),
	Default_Map = 1 UMETA(DisplayName="Overview Map"),
	Creative_Scoreboard = 2 UMETA(DisplayName="Scoreboard"),
};

UENUM(BlueprintType)
enum class EMinigameGameEndCallout : uint8
{
	WinLose = 0 UMETA(DisplayName="You Win/Lose"),
	// Shows Victory / Defeat title

	Placement = 1 UMETA(DisplayName="Placement"),
	// Shows Victory / You Placed #...

	Cooperative = 2 UMETA(DisplayName="Cooperative"),
};

UENUM(BlueprintType)
enum class EMinigamePlayerPawnType : uint8
{
	FortniteCharacter = 0 UMETA(DisplayName="Fortnite Character"),
	BeanCharacter = 1 UMETA(DisplayName="Bean Character"),
};

UENUM(BlueprintType)
enum class EMinigamePlayerPersistence : uint8
{
	None = 0 UMETA(DisplayName="No player state is persisted"),
	PartyLeaderOnly = 1 UMETA(DisplayName="Only party leader state is persisted"),
	AllPlayers = 2 UMETA(DisplayName="All player state is persisted"),
};

UENUM(BlueprintType)
enum class EMinigameScoreboardStates : uint8
{
	RoundEndDisplayWinner = 0,
	GameEndDisplayWinner = 1,
	RoundEndDisplayScoreboard = 2,
	GameEndDisplayScoreboard = 3,
	Max = 4,
};

UENUM(BlueprintType)
enum class EMinigameTeamListType : uint8
{
	Blacklist = 0,
	Whitelist = 1,
};

UENUM(BlueprintType)
enum class EMinigameWinCondition : uint8
{
	MostRoundWins = 0 UMETA(DisplayName="Most Round Wins"),
	MostScoreWins = 1 UMETA(DisplayName="Most Score Wins"),
};

UENUM(BlueprintType)
enum class RankingType : uint8
{
	// Teams that tie are given the same higher ranking number and the a gap is after the tied teams. 
// E.g., Two tie for second place resulting in the following ranking: 1 2 2 4

	StandardCompetition = 0,
	// Teams that tie are given the same lower ranking number and the gap is before the tied teams.
// E.g., Two tie for second place resulting in the following ranking: 1 3 3 4

	ModifiedCompetition = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBossInfoChanged, ECreativeBossDisplayMode, DisplayMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrentRoundChanged, AFortMinigame*, Minigame, int32, CurrentRound);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthIndicatorChanged, EPlayerIndicatorDisplayMode, DisplayMode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnMinigameEndGame, AFortPlayerController*, InstigatorPC, EFortMinigameEnd, EndMethod, EFortMinigameState, NextState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigameHideHUD, bool, bHideHUD);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigamePlayerOrBotSpawned, AController*, SpawningPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMinigamePlayerSpawned, AFortPlayerController*, SpawningPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(FOnMinigameStatChanged, EFortQuestObjectiveStatEvent, Type, UObject*, TargetObject, AFortPlayerController*, PlayerController, const FGameplayTagContainer&, TargetTags, const FGameplayTagContainer&, SourceTags, const FGameplayTagContainer&, ContextTags, int32, Count);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnTeleportedEvent, AFortPlayerPawn*, PlayerPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayModeChanged, AFortMinigame*, Minigame, bool, bIsInPlayMode);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnPlayerChangedClass, AFortPlayerState*, PlayerState, uint8, ClassSlotIndex, uint8, OldClassSlotIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnPlayerChangedTeam, AFortPlayerState*, PlayerState, uint8, TeamId, uint8, OldTeamId, bool, bTeamChangedWithoutRespawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerChanged, FUniqueNetIdRepl, UniqueNetId, bool, bIsLocalPlayer);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerClassEvent, AFortPlayerState*, PlayerState, uint8, ClassSlotIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnPlayerHitPointsChanged, AFortPlayerState*, PlayerState, float, Health, float, HealthMax, float, Shield, float, ShieldMax);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerJoinInProgress, APawn*, Pawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPrePlayerJoinInProgress, const AFortPlayerState*, FortPlayerState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStateChanged, AFortMinigame*, Minigame, EFortMinigameState, MinigameState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUIExtensionsChanged, AFortMinigame*, Minigame);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerSpawnOverrideDevicesUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRefreshIndicatorPlayersCache);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleMinigameDelegate);

USTRUCT()
struct FCreativeMatchmakingRequest
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFireVolumesForMinigame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FireVolumesForMinigame")
	TObjectPtr<AGameplayVolume> FireVolume;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FireVolumesForMinigame")
	EDeviceFireVolumeFireOption FireOption;

};

USTRUCT()
struct FFortMinigameTimes
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float SetupTime;

	UPROPERTY()
	float WarmupTime;

	UPROPERTY()
	float StartTime;

	UPROPERTY()
	float EndTime;

	UPROPERTY()
	float ResetTime;

};

USTRUCT(BlueprintType)
struct FGameplayMessageMinigameStarted
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FMinigameClassSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameClassSlot")
	uint8 ClassSlotIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameClassSlot")
	FText ClassName;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameClassSlot")
	FText ClassDescription;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameClassSlot")
	bool bVisibleInUI;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameClassSlot")
	TArray<FItemAndCount> InventoryItems;

};

USTRUCT(BlueprintType)
struct FMinigameEndCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MinigameEndCondition")
	FFortMinigameStatQuery StatQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MinigameEndCondition")
	EMinigameTeamListType TeamListType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MinigameEndCondition")
	TArray<uint8> TeamList;

};

USTRUCT(BlueprintType)
struct FMinigamePlayerTeamClassSlotPair
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayerTeamClassSlotPair")
	uint8 TeamIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayerTeamClassSlotPair")
	uint8 ClassSlotIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayerTeamClassSlotPair")
	float StartTimeSeconds;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayerTeamClassSlotPair")
	float EndTimeSeconds;

};

USTRUCT(BlueprintType)
struct FMinigamePlayer : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	FUniqueNetIdRepl UniquePlayerId;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bHasValidResetData;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	uint8 ClassSlotIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	FName MinigameClassScope;

	UPROPERTY(NotReplicated)
	float LastClassSwitchTime;

	UPROPERTY(NotReplicated)
	float EnteredMinigameTime;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	uint8 TeamBeforeMinigameStarted;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	int32 RoundWinCount;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	FVector LocationBeforeMinigameStarted;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	FRotator RotationBeforeMinigameStarted;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bIsLocationBeforeGameStartedBlocked;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bWasSkydivingBeforeMinigameStarted;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bWasFlyingBeforeMinigameStarted;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bIsTeleportingOrRespawningForGameplay;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, NotReplicated, Category="MinigamePlayer")
	bool bIsLocalPlayer;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, NotReplicated, Category="MinigamePlayer")
	bool bPreparingForRespawn;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigamePlayer")
	bool bLeftMatchDuringPreGame;

	UPROPERTY(VisibleInstanceOnly, Category="MinigamePlayer")
	TObjectPtr<AFortPlayerStartCreative> ClaimedPlayerStart;

	UPROPERTY(Transient, NotReplicated)
	bool bIsWaitingForPersistence;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, NotReplicated, Category="MinigamePlayer")
	TArray<FMinigamePlayerTeamClassSlotPair> TeamAndClassSlotHistory;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="MinigamePlayer")
	FString PlayerName;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="MinigamePlayer")
	uint8 LastPlayerTeam;

};

USTRUCT()
struct FMinigamePlayerBucket
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamIdAtGameStart;

	UPROPERTY()
	uint8 TeamIdAtRoundStart;

	UPROPERTY()
	float DesiredTeamSizePercent;

private:
	UPROPERTY()
	TArray<FUniqueNetIdRepl> PlayerIds;

};

USTRUCT()
struct FMinigamePlayerPersistentStartPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	FQuat Rotation;

	UPROPERTY(Transient)
	FUniqueNetIdRepl UniqueId;

	UPROPERTY(Transient)
	bool bConsumed;

};

USTRUCT()
struct FMinigamePlayers : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="MinigamePlayers")
	TArray<FMinigamePlayer> Players;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AFortMinigame> Owner;

};

USTRUCT(BlueprintType)
struct FMinigameStatRow
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="MinigameStatRow")
	FText PlayerName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MinigameStatRow")
	int32 TeamColorIndex;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MinigameStatRow")
	TArray<FText> PlayerStats;

	UPROPERTY(BlueprintReadWrite, Transient, Category="MinigameStatRow")
	TArray<FText> CumulativePlayerStats;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MinigameStatRow")
	bool bIsTeamRow;

};

USTRUCT(BlueprintType)
struct FMinigameTeam
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	uint8 TeamIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	FText TeamName;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	FText TeamDescription;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	int32 TeamColorIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="MinigameTeam")
	int32 MaxInitTeamSize;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="MinigameTeam")
	int32 InitTeamSizeWeight;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	bool bHasBucketAvailable;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	uint8 EliminatedCount;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	uint8 TeamSize;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	FCreativeIconOption TeamIcon;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="MinigameTeam")
	bool bUseTeamScore;

};

USTRUCT()
struct FMinigameUIExtensionsChangedContext
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> Minigame;

};

USTRUCT(BlueprintType)
struct FPlayerStartCompatibilityInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="PlayerStartCompatibilityInfo")
	bool bIsCompatible;

	UPROPERTY(BlueprintReadWrite, Category="PlayerStartCompatibilityInfo")
	bool bDoesAllowAnyTeam;

	UPROPERTY(BlueprintReadWrite, Category="PlayerStartCompatibilityInfo")
	bool bIsMatchingTeam;

	UPROPERTY(BlueprintReadWrite, Category="PlayerStartCompatibilityInfo")
	bool bDoesAllowAnyClass;

	UPROPERTY(BlueprintReadWrite, Category="PlayerStartCompatibilityInfo")
	bool bIsMatchingClass;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortMinigame : public AInfo, public IFortMutatorOwner, public IFortInitializationInterface, public IFortVolumeAccessor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnyLocalPlayerChangedClass);

public:
	UFUNCTION()
	void AccumulateTimeAliveForAlivePlayer(FMinigamePlayer& PlayerEntry);

	UFUNCTION(BlueprintCallable)
	void AddExtensionWidget(const FUIExtension& NewExtension);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void AddMinigameActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void AddMinigameComponent(UFortMinigameLogicComponent* MinigameComponent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void AddMinigamePlayer(AFortPlayerState* PlayerState, bool bForceSpawn = false);

	UFUNCTION(BlueprintCallable)
	void AddPersistenceRequirement();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AddPlayerSpawnOverrideDevice(AActor* InOverrideDevice);

	UFUNCTION(BlueprintCallable)
	void AddToFireVolumesForMinigame(const AGameplayVolume* FireVolume, const EDeviceFireVolumeFireOption FireOption);

	UFUNCTION()
	void AdvanceState();

	UFUNCTION()
	bool AreEnoughPlayersLeftToContinueMatch();

	UFUNCTION(BlueprintPure, Category="Minigame | Teams")
	bool AreTeamsAsymmetrical() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void CancelPendingClassSlotChange(AFortPlayerState* PlayerState, uint8 PendingClassSlot);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool CanPlayerRespawn(const AFortPlayerState* InPlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool CanStartMinigame() const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	AActor* ChoosePlayerStart(AController* Player, bool bCheckEnemy = false, bool bNearTeammates = false);

	UFUNCTION(BlueprintCallable)
	void ClearFireVolumesForMinigame();

	UFUNCTION(BlueprintCallable, Category="Minigame | Round Rules")
	void DeclareWinnerImmediately(int32 WinningBucket);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Minigame")
	bool DetermineSpawnLocation(AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround);

	UFUNCTION(BlueprintCallable, Category="UI")
	void DisableCustomScoreboard();

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool DoAllPlayersHaveSpawnLocation(EFortMinigamePlayerSpawnLocationSetting SpawnLocation) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool DoesTimerCountDown() const;

	UFUNCTION(BlueprintCallable, Category="UI")
	void EnableCustomScoreboard(const float InDisplayTime);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void EndGame(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool EvaluateStatQuery(const FMinigameEndCondition& InEndCondition, const int32 PlayerBucketIndex) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	bool ForceRespawn(AFortPlayerState* PlayerState, UPARAM(ref) FGameplayTagContainer& RespawnReasons);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	static FText FormatStat(UFortMinigameStatFilter* InStat, int32 InValue);

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool GetAirSpawnLocation(FVector& OutLocation, FRotator& OutRotation, AFortPlayerStateAthena* PlayerState);

	UFUNCTION(BlueprintPure, Category="Minigame")
	int32 GetBucketForPlayerId(const FUniqueNetIdRepl& PlayerId, bool bMatchCurrentTeam = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	int32 GetBucketForPlayerState(const APlayerState* PlayerState, bool bMatchCurrentTeam = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	int32 GetBucketForTeamIndex(int32 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats", meta=(DisplayName="Get Round Wins For Bucket Index"))
	bool GetBucketWinCount(int32& WinCount, const int32 BucketIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	FName GetClassScopeForPlayer(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	uint8 GetClassSlotForActor(const AActor* Actor, const bool bUseDeathInfo = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	uint8 GetClassSlotForPlayer(const AFortPlayerState* PlayerState, const bool bUseDeathInfo = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool GetClassSlotInventory(uint8 ClassSlotIndex, TArray<FItemAndCount>& InventoryItems) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	FText GetClassSlotName(uint8 ClassSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool GetClassSlotVisibleInUI(uint8 ClassSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	void GetColumnSortedScoreboardRows(TArray<FMinigameScoreboardBucketRow>& OutScoreboardRows, const TArray<UFortMinigameStatFilter*>& RowSortOrder, const TArray<UFortMinigameStatFilter*>& ColumnSortOrder, bool bGameTotal = false, bool bHighlighting = false, bool bCountWins = false, bool bIsCareerScoreboard = false, EMinigameScoreboardStates ScoreboardState = EMinigameScoreboardStates::Max) const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentRoundWinner() const;

	UFUNCTION(BlueprintPure)
	bool GetCurrentRoundWinnerName(FText& OutName) const;

	UFUNCTION(BlueprintPure, Category="UI")
	void GetCustomScoreboardSettings(bool& bOutCustomScoreboardEnabled, float& OutCustomScoreboardDisplayTime) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	uint8 GetDefaultClassSlot(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	bool GetEndConditionForStatIfAny(const uint8 TeamNumber, UFortMinigameStatFilter* InStat, FMinigameEndCondition& OutEndCondition);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	bool GetEndConditionValueForStatIfAny(const uint8 TeamNumber, UFortMinigameStatFilter* InStat, int32& OutValue);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	int32 GetMaxLivesForPlayer(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	void GetMinigameComponentsByTagQuery(TArray<UFortMinigameLogicComponent*>& OutComponents, const FGameplayTagQuery& TagQuery) const;

	UFUNCTION(BlueprintPure, Category="Minigame | MapPanel")
	EMinigameFullscreenMapWidgetType GetMinigameMapPanelDisplayType() const;

	UFUNCTION(BlueprintPure, Category="Minigame|Teams")
	int32 GetMinigameNumTeams() const;

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	bool GetOrderedMinigameStatsRows(TArray<FMinigameStatRow>& OutStats);

	UFUNCTION(BlueprintPure, Category="Minigame")
	void GetParticipatingPlayers(TArray<AFortPlayerState*>& OutPlayers) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Minigame", meta=(DisplayName="GetParticipatingPlayers_NotPure"))
	void GetParticipatingPlayersForMinigame(TArray<AFortPlayerState*>& OutPlayers) const;

	UFUNCTION(BlueprintPure, Category="Persistence")
	void GetPersistencePlayers(TArray<AFortPlayerState*>& PersistencePlayers) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	int32 GetPlayerCount(bool bIncludeSpectators = false) const;

	UFUNCTION(BlueprintPure)
	int32 GetPlayerPlacement(const APlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	const TArray<AFortPlayerState*> GetPlayersOrdered() const;

	UFUNCTION(BlueprintPure)
	const TArray<AActor*>& GetPlayerSpawnOverrideDevices() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	void GetPlayerStartComponentsByTagQuery(TArray<UFortMinigamePlayerStartComponent*>& OutPlayerStartComponents, const FGameplayTagQuery& TagQuery);

	UFUNCTION(BlueprintPure)
	void GetPlayersWithClassSlot(uint8 ClassSlot, TArray<AFortPlayerState*>& OutPlayers) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetPostGameResetDelay(EFortMinigameEnd EndMethod) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetPostGameTimeRemaining() const;

	UFUNCTION(BlueprintPure)
	int32 GetRoundBasedGameWinnerName(FText& OutName) const;

	UFUNCTION(BlueprintPure)
	int32 GetRoundBasedGameWinnerNameOrTeam(FText& OutName) const;

	UFUNCTION(BlueprintPure)
	int32 GetRoundWinner(int32 Round) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetRuntime() const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool GetScoreboardRowForPlayer(const AFortPlayerState* PlayerState, FMinigameScoreboardPlayerRow& OutScoreboardRow, const TArray<UFortMinigameStatFilter*>& SortOrder, bool bGameTotal = false, bool bHighlighting = false, bool bCountWins = false, EMinigameScoreboardStates ScoreboardState = EMinigameScoreboardStates::Max, bool bIncludeInactivePlayers = false) const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void GetScoreboardStateTimes(TArray<float>& OutStateTimes);

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool GetSpawnLocationByTag(FVector& OutLocation, FRotator& OutRotation, AFortPlayerStateAthena* PlayerState, const FGameplayTag& SpawnTag, bool bUseVolumeOnFail = true) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	EFortMinigamePlayerSpawnLocationSetting GetSpawnLocationSetting(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Minigame|Stats")
	int32 GetStandingsForPlayer(const AFortPlayerState* InPlayerState, UFortMinigameStatFilter* InFilter, TArray<FMinigameStatRow>& OutStatRows, int32 RowsReturned = 3);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	FGameplayTagQuery GetStartQueryForPlayer(APlayerState* Player);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	int32 GetTeamColorIndex(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	uint8 GetTeamIndexForCosmeticDetails(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	FText GetTeamName(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	uint8 GetTeamToSwapToWhenOutOfSpawns(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Teleporter")
	UFortCreativeTeleporterManagerComponent* GetTeleporterManagerComponent();

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetTimeRemaining() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetTimeRemainingUntilAutoStart() const;

	UFUNCTION(BlueprintPure)
	bool GetVehiclesDamageObjectsMiniGame() const;

	UFUNCTION(BlueprintPure)
	bool GetVehiclesDamageVehiclesMiniGame() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	float GetWarmupTimeRemaining() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	uint8 GetWinningTeamIndexFromTeamIndex(const uint8 InTeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool HasMinigameStarter() const;

	UFUNCTION(BlueprintNativeEvent, Category="Minigame | GameRules")
	bool HasPlayerStartPads(const AFortPlayerState* InPlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool HasStarted() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool HasTimeLimit() const;

	UFUNCTION(BlueprintCallable, Category="Minigame | Stats")
	static void HighlightTopStats(UPARAM(ref) TArray<FMinigameScoreboardBucketRow>& InOutScoreboardRows);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	bool IsActorPositionInsideTerrain(AActor* Actor, FHitResult& OutHit);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool IsAnyPlayerSpawnLimited() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsCuratedHub() const;

	UFUNCTION(BlueprintPure, Category="GameSession")
	bool IsGameSessionInBackfillMode() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsGameWinnerShown() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsHub() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsInPlayMode() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsInProgress() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsInSetup() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsInWarmup() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsLastRound() const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	bool IsLocationBlockedForTeleport(AFortPlayerState* PlayerState, FVector LocationToCheck, FRotator RotationToCheck);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	bool IsLocationInsideTerrain(FVector Location, FHitResult& OutHit);

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsMinigameActor(AActor* Actor) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsMinigameComponent(UFortMinigameLogicComponent* MinigameComponent) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsMinigameStarter(AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsMinigameStarting() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPlayerInMinigame(const AFortPlayerState* PlayerState, bool bCheckSpectatingPlayers = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPlayerInMinigameByNetId(const FUniqueNetIdRepl& UniqueNetId, bool bCheckSpectatingPlayers = false) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPlayerInOurVolume(AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	bool IsPlayerLocationBlockedForTeleport(AFortPlayerPawnAthena* PlayerPawn);

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool IsPlayerOnGameWinningTeam(AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool IsPlayerOnRoundWinningTeam(AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool IsPlayerOutOfLives(const AFortPlayerState* InPlayerState, const bool bOnlyMinigamePlayers = true) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPlayerSpectatingMinigame(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	FPlayerStartCompatibilityInfo IsPlayerStartCompatibleWithPlayer(AController* Player, AFortPlayerStartCreative* PlayerStart) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Minigame")
	bool IsPlayerTeleportingOrRespawningForGameplay(AFortPlayerStateAthena* PlayerToCheck) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPlayerUsingClassSlot(AFortPlayerState* PlayerState, uint8 ClassSlot) const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPostGame() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsPregame() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsTeamMinigame() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsTransitioning() const;

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool IsWaitingForCameras() const;

	UFUNCTION(BlueprintPure)
	bool IsWinningPlayerId(const FUniqueNetIdRepl& PlayerId) const;

	UFUNCTION(BlueprintPure)
	bool IsWinningPlayerState(const APlayerState* PlayerState) const;

	UFUNCTION(BlueprintCallable, Category="Minigame", meta=(DisplayName="Has Started", ExpandEnumAsExecs="OutExec"))
	void K2_HasStarted(EFortMinigameExec& OutExec);

	UFUNCTION(BlueprintCallable, Category="Minigame", meta=(DisplayName="Is In Progress", ExpandEnumAsExecs="OutExec"))
	void K2_IsInProgress(EFortMinigameExec& OutExec);

	UFUNCTION(BlueprintCallable, Category="Matchmaking")
	void LTMFlowSetMatchmakingBackfillAndJoinInProgress(bool bEnable = false, bool bDisableBeaconRequests = false);

	UFUNCTION()
	void MinigamePlayerNameReplicated(const FUniqueNetIdRepl& NetId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void MoveMinigamePlayerToSpectate(AFortPlayerState* PlayerState);

	UFUNCTION()
	void NativeEnteredVolumeEvent(AFortPlayerState* PlayerState);

	UFUNCTION()
	void NativeExitedVolumeEvent(AFortPlayerState* LeftPlayerState);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void OnMinigameStatChanged(AController* InStatOwner, UFortMinigameStatFilter* TrackedStatClass, int32 Count);

	UFUNCTION()
	void OnPawnTeleported(AFortPawn* FortPawn);

	UFUNCTION()
	void OnRep_AllowPartyMemberJoinInProgress();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	bool OverridePlayerSpawnLocation(APawn* PlayerPawn, AFortPlayerStateAthena* PlayerState, FVector& OutLocation, FRotator& OutRotation, bool& bOutRespawningOnGround);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void RefreshGameRulesPreview();

	UFUNCTION(BlueprintCallable)
	void RefreshIndicatorPlayersCache();

	UFUNCTION(BlueprintCallable)
	void RemoveExtensionWidget(const FUIExtension& ExtensionToRemove);

	UFUNCTION(BlueprintCallable)
	void RemoveFromFireVolumesForMinigame(const AGameplayVolume* FireVolume);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RemoveMinigameActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RemoveMinigameComponent(UFortMinigameLogicComponent* MinigameComponent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RemoveMinigamePlayer(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintCallable)
	void RemovePersistenceRequirement();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemovePlayerSpawnOverrideDevice(AActor* InOverrideDevice);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RestartMinigame(AFortPlayerController* InstigatorPC);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	bool SetClassSlotForPlayer(AFortPlayerState* PlayerState, uint8 NewClassSlot, FOnPlayerChangedClass OnComplete, bool bRespawnPlayer = false, bool bResetCurrentVitals = true, bool bClearAllItems = false, float ClassSwitchDelay = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetClassSlotInventory(uint8 ClassSlotIndex, const TArray<FItemAndCount>& InventoryItems);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetClassSlotName(uint8 ClassSlotIndex, const FText& ClassName);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetClassSlotVisibleInUI(uint8 ClassSlotIndex, const bool bVisibleInUI);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void SetLapTimeStat(AFortPlayerController* PlayerController, const float LapTimeSeconds);

	UFUNCTION(BlueprintCallable, Category="Minigame|Teams")
	void SetMinigameNumTeams(int32 InNumTeams);

	UFUNCTION(BlueprintCallable, Category="UI")
	void SetPipHudAdEnabled(const bool bInEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void SetPlayerHealthStat(AFortPlayerState* FortPlayerState, const int32 Health);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	bool SetPvPTeamForPlayer(AFortPlayerState* PlayerState, int32 Team, bool bTemporary = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void SetRaceProgressStat(AFortPlayerController* PlayerController, const float NormalizedRaceProgress);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void SetRaceTimeStat(AFortPlayerController* PlayerController, const float RaceTimeSeconds);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI")
	void SetRoundVictoryAnimation(const ERoundVictoryAnimation NewRoundVictoryAnimation);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="UI")
	void SetShouldShowPreGameCountdownBars(const bool bInShowPreGameCountdownBars);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetTeamColorIndexForTeam(uint8 TeamIndex, int32 TeamColorIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	bool SetTeamForPlayer(AFortPlayerState* PlayerState, uint8 NewTeam, bool bTemporary = true, bool bChangeTeamWithoutRespawn = false, bool bResetVitalsOnSwitch = false);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetUseTeamScore(uint8 TeamIndex, bool bUseTeamScore);

	UFUNCTION(BlueprintCallable)
	void SetVehiclesDamageObjectsMiniGame(const bool bInVehiclesDamageObjectsMinigame);

	UFUNCTION(BlueprintCallable)
	void SetVehiclesDamageVehiclesMiniGame(const bool bInVehiclesDamageVehiclesMinigame);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void SetWinningTeamIndex(const uint8 InWinningTeamIndex);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	bool ShouldDropOrDestroyItem(UPARAM(ref) bool& bShouldDrop, UPARAM(ref) bool& bShouldDestroy, AController* PC, const UFortWorldItemDefinition* ItemDef) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Teams")
	bool ShouldRotateTeams() const;

	UFUNCTION(BlueprintPure, Category="UI")
	bool ShouldShowPreGameCountdownBars() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void StartMinigame(AFortPlayerController* InstigatorPC);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void ToggleAutoRestartMinigame();

	UFUNCTION()
	void UpdateTimeAliveForAlivePlayers();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void UpdateTimeAliveStat(AController* PlayerController, const bool bAccumulate = false);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	bool UseTeamScore(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Stats")
	bool UseTeamScoring() const;

	UFUNCTION(BlueprintPure, Category="Minigame", meta=(DeprecatedFunction))
	bool WasInProgress() const;

	UPROPERTY(Transient)
	TSet<FUniqueNetIdRepl> PendingPlayers;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnStateChanged StateChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameHideHUD MinigameHideHUDDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate StatChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate OnPostGameResetUI;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameStatChanged FullStatChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigamePlayerSpawned OnMinigamePlayerSpawned;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigamePlayerOrBotSpawned OnMinigamePlayerOrBotSpawned;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnMinigameEndGame MinigameEndGameDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged PlayerAddedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPrePlayerJoinInProgress OnPrePlayerJoinInProgress;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged PlayerAddedPostResetDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged OnFinishedAddingMinigamePlayerDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged PlayerLastChanceToSave;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged PlayerPreRemovedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChanged PlayerRemovedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerChangedTeam PlayerChangedTeamDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerClassEvent OnPlayerClassApplied;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FRefreshIndicatorPlayersCache OnRefreshIndicatorPlayersCache;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerClassEvent OnPlayerClassRemoved;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayerJoinInProgress OnPlayerJoinInProgress;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnHealthIndicatorChanged OnCreativePlayerIndicatorRulesChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnBossInfoChanged OnCreativeBossInfoRulesChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate MinigameStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate PostMinigameStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate MinigameEndedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate MinigameTeamConfigUpdated;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate MinigameClassConfigUpdated;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPawnTeleportedEvent OnPawnTeleportedForMinigame;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnUIExtensionsChanged OnUIExtensionsChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnPlayModeChanged OnPlayModeChangedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FOnCurrentRoundChanged OnCurrentRoundChangedDelegate;

	UPROPERTY(BlueprintReadWrite, Category="Minigame|UI")
	TArray<FUIExtension> UIExtensions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_UIExtensionTags, Category="Minigame|UI")
	FGameplayTagContainer UIExtensionTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float TimeLimit;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentRound, Category="FortMinigame")
	int32 CurrentRound;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="FortMinigame")
	int32 TotalRounds;

	UPROPERTY(VisibleInstanceOnly, Transient, ReplicatedUsing=OnRep_MinigamePlayer, Category="Minigame")
	FMinigamePlayers PlayerArray;

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="Minigame")
	FMinigamePlayers InactivePlayerArray;

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="Minigame")
	FMinigamePlayers SpectatingPlayerArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="Minigame | Stats")
	TArray<FMinigameEndCondition> EndConditionArray;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Minigame")
	bool bRemovePawnOnDeath;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame|Last Man Standing")
	TSubclassOf<UFortMinigameStatFilter> PlayerDeathsStatFilter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	bool bKeepItemsBetweenRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	float PercentageOfResourcesKeptBetweenRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	bool bReloadAndRestockWeaponsEachRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	TMap<TObjectPtr<UFortWorldItemDefinition>, int32> RestockAmmoAmounts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	int32 DefaultRestockAmmoAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	bool bLastTeamStandingWinsThisRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	bool bAllowStandardEndGameConditions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame | Round Rules")
	bool bEndGameOnMatchPointWin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bIncludePlayersWhoLeftGameInScoreboard;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AllowPartyMemberJoinInProgress)
	bool bAllowPartyMemberJoinInProgress;

	UPROPERTY(BlueprintAssignable)
	FPlayerSpawnOverrideDevicesUpdated OnPlayerSpawnOverrideDevicesUpdated;

protected:
	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void AddOrOverrideEndCondition(const FFortMinigameStatQuery& StatQuery);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void AddOrOverrideEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ApplyMutatorsToPlayer(AFortPlayerState* PlayerState, bool bResetCurrentVitals = true);

	UFUNCTION()
	void CheckEndConditions();

	UFUNCTION()
	void CheckEndConditionsInternal();

	UFUNCTION()
	bool CheckRemainingLivingPlayersForEndCondition();

	UFUNCTION()
	void ClearPlayerInventory(AFortPlayerControllerAthena* PlayerController, bool bPreventDrop);

	UFUNCTION()
	void ClearTeleportForMinigame(AFortPlayerPawn* InPawn);

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	int32 GetInitTeamSizeWeight(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure, Category="Minigame | GameRules")
	int32 GetMaxInitTeamSize(uint8 TeamIndex) const;

	UFUNCTION(BlueprintPure)
	void GetTeamMembers(uint8 TeamIndex, TArray<AFortPlayerState*>& OutTeamMembers) const;

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameComponentAdded(UFortMinigameLogicComponent* MinigameComponent);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameComponentInPlayChanged(UFortMinigameLogicComponent* MinigameComponent);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameComponentRemoved(UFortMinigameLogicComponent* MinigameComponent);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameEnded();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameStarted();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandleMinigameWarmup();

	UFUNCTION(BlueprintNativeEvent, Category="Minigame")
	void HandlePostMinigameStarted();

	UFUNCTION()
	void HandleReplicationComplete(AFortPlayerControllerAthena* PlayerController);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame", meta=(DisplayName="Entering Volume Event", ScriptName="EnteringVolumeEvent"))
	void K2_EnteredVolumeEvent(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintNativeEvent, Category="Minigame", meta=(DisplayName="Exited Volume Event", ScriptName="ExitedVolumeEvent"))
	void K2_ExitedVolumeEvent(AFortPlayerState* LeftPlayerState);

	UFUNCTION(BlueprintImplementableEvent, Category="Minigame", meta=(DisplayName="Record Post Game Stats For Player"))
	void K2_RecordPostGameStatsForPlayer(UPARAM(ref) FMinigamePlayer& PlayerEntry);

	UFUNCTION()
	void OnAllMinigamePlayerBotsSpawned();

	UFUNCTION()
	void OnBeginSpectating(AFortPlayerStateZone* FPSZ);

	UFUNCTION()
	bool OnCheckIfClientIsSafeToRespawn(AFortPlayerControllerAthena* PlayerController);

	UFUNCTION()
	void OnClientFinishTeleportingForMinigame(AFortPlayerPawn* InPawn);

	UFUNCTION()
	void OnFortPlayerDied(AFortPlayerPawnAthena* FortPlayerPawnAthena);

	UFUNCTION()
	void OnInGameLoadScreenChanged(AFortPlayerControllerAthena* PlayerController, bool bEnableLoadScreen, FText HUDReasonText);

	UFUNCTION()
	void OnPlayerPawnPossessedDuringMinigame(APawn* PlayerPawn);

	UFUNCTION()
	void OnPlayerPawnPossessedDuringTransition(APawn* PlayerPawn);

	UFUNCTION()
	void OnRep_bRequestPostGameResetUI();

	UFUNCTION()
	void OnRep_ClassSlotArray();

	UFUNCTION()
	void OnRep_CurrentRound();

	UFUNCTION()
	void OnRep_CurrentState();

	UFUNCTION()
	void OnRep_MinigamePlayer();

	UFUNCTION()
	void OnRep_PlayerBuckets();

	UFUNCTION()
	void OnRep_PlayerSpawnOverrideDevices();

	UFUNCTION()
	void OnRep_ServerTime();

	UFUNCTION()
	void OnRep_StatsChanged();

	UFUNCTION()
	void OnRep_TeamArray();

	UFUNCTION()
	void OnRep_UIExtensionTags();

	UFUNCTION()
	void OnRep_Volume();

	UFUNCTION()
	void OnTimeLimitElapsed();

	UFUNCTION()
	void OnVolumeStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UFUNCTION()
	void PostGameReset_Guard(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext);

	UFUNCTION()
	void PostGameResetPlayers();

	UFUNCTION()
	void PutPlayerControllerIntoStasis(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void PutPlayerIntoStasis(APawn* PlayerPawn);

	UFUNCTION()
	void RecheckInventory(APawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RefreshVoiceForPlayer(AFortPlayerState* PlayerState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame")
	void RefreshVoiceForPlayers();

	UFUNCTION(BlueprintCallable)
	void ReleasePlayerFromStasis(APawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void RemoveEndCondition(const FFortMinigameStatQuery& StatQuery);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void RemoveEndConditionForTeam(uint8 TeamIndex, const FFortMinigameStatQuery& StatQuery);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Stats")
	void ResetStats();

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetInitTeamSizeWeightForTeam(uint8 TeamIndex, int32 TeamSizeWeight);

	UFUNCTION(BlueprintCallable, Category="Minigame | GameRules")
	void SetMaxInitTeamSizeForTeam(uint8 TeamIndex, int32 TeamSize);

	UFUNCTION(BlueprintImplementableEvent, Category="Minigame | GameRules")
	void SetupTeams();

	UPROPERTY(Transient)
	TArray<FFireVolumesForMinigame> FireVolumeArray;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> BuildingsWithCurieFXToDestroy;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FSimpleMinigameDelegate ServerTimeReplicatedDelegate;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerSpawnOverrideDevices)
	TArray<TObjectPtr<AActor>> PlayerSpawnOverrideDevices;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Replicated, Category="Minigame")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	int32 AutoStartDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	EFortMinigamePlayerSpawnLocationSetting SpawnLocationSetting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	EFortMinigamePostGameSpawnLocationSetting PostGameSpawnLocationSetting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	EFortMinigameSpawnPadSelection SpawnPadSelection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float WarmupDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float PostGameResetDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float GameWinnerDisplayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float GameScoreDisplayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float RoundWinnerDisplayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	float RoundScoreDisplayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Minigame")
	float ServerEndgameDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bTimerCountsDown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bSlowMotionOnEndOfRound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="Minigame | EndGame")
	ERoundVictoryAnimation RoundVictoryAnimation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TeamArray, Category="Minigame")
	TArray<FMinigameTeam> TeamArray;

	UPROPERTY(VisibleAnywhere, Transient, ReplicatedUsing=OnRep_ClassSlotArray, Category="Minigame")
	TArray<FMinigameClassSlot> ClassSlotArray;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Minigame | Stats")
	TArray<FFortMinigameStatQuery> BaseEndConditionArray;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentState, Category="Minigame")
	EFortMinigameState CurrentState;

	UPROPERTY(ReplicatedUsing=OnRep_bRequestPostGameResetUI)
	bool bRequestPostGameResetUI;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame")
	EFortMinigameState PreviousState;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | GameRules")
	TSubclassOf<UFortMinigameStatFilter> CompletionTimeStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> ScoreStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> RaceProgressStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> LapTimeStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> RaceTimeStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> TimeAliveStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> RoundWinsStatFilter;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Minigame | Stats")
	TSubclassOf<UFortMinigameStatFilter> PlayerLivesLeftStatFilter;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="Minigame | GameRules")
	uint8 DefaultClassSlot;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="Minigame | GameRules")
	EFortMinigameClassResetType ClassResetType;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Replicated, Category="Minigame|Last Man Standing")
	int32 MaxLivesForPlayer;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="Minigame|Last Man Standing")
	uint8 TeamToSwapToWhenOutOfSpawns;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="Minigame|Last Man Standing")
	int32 AutoEndTeamThreshold;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ServerTime)
	FFortMinigameTimes ServerTime;

	UPROPERTY(Transient)
	FFortMinigameTimes CachedTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bStopwatchMode;

	UPROPERTY(Transient)
	float LastRoundDuration;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMinigameLogicComponent>> MinigameComponents;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMinigamePlayerStartComponent>> PlayerStartComponents;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMinigamePlayerStartComponent>> CheckpointPlayerStartComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeCreatureManagerComponent> CreatureManagerComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeTeleporterManagerComponent> TeleporterManagerComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Export, Category="Minigame", meta=(EditInline="true"))
	TObjectPtr<UFortAIManagerMinigameComponent> AIManagerComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCreativePlayerHealthInfoComponent> CreativePlayerHealthComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_Volume, Category="Minigame")
	TObjectPtr<AActor> Volume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bSortScoreboardEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bTeamMinigame;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="Minigame")
	bool bTeamsAreStable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	int32 NumTeams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bAllowJoinInProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Minigame")
	EMinigamePlayerPersistence PlayerPersistence;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Minigame")
	TObjectPtr<AFortPlayerState> MinigameStarter;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="FortMinigame")
	int32 TeamRotationSetting;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Replicated, Category="FortMinigame")
	int32 TeamRotationCount;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="FortMinigame")
	bool bStableTeamCosmetics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	EMinigameFullscreenMapWidgetType MinigameMapWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bShowMapWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bShowScoreboardMapWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigame")
	TSoftClassPtr<UUserWidget> ScoreboardMapWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bShowCareerScoreboardMapWidget;

	UPROPERTY(EditDefaultsOnly, Category="FortMinigame")
	TSoftClassPtr<UUserWidget> CareerMapWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bShowPreGameCountdownBars;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	EMinigameWinCondition WinCondition;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	EMinigamePlayerPawnType MinigamePlayerPawnType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="FortMinigame")
	bool bAllTeamsMustMatchEndConditions;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="FortMinigame")
	bool bOnlyAllowRespawningIfPlayerStartPadsFound;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	EMinigameGameEndCallout GameEndCallout;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	int32 VictoryAudioIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	int32 DrawAudioIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	int32 DefeatAudioIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="UI")
	bool bShowCumulativeScoreboard;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	FMinigamePostGameSettings PostGameSettings;

	UPROPERTY(EditDefaultsOnly, Category="Minigame")
	FGameplayTagContainer ActionsAllowedInStasis;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortMinigame")
	FName MinigameStartCameraBehavior;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	FText ClientMinigameStartedText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortMinigame")
	FName MinigameEndCameraBehavior;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	FText ClientMinigameEndedText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	TMap<FGameplayTag, FUIExtension> AllowedUIExtensions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	TSet<EFortMinigameState> MinigameEditModeStates;

	UPROPERTY(Replicated)
	bool bIsSpawningBotsForMinigameStart;

	UPROPERTY()
	TSet<FUIExtension> AdditionalUIExtensions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bAllowFriendlyFire;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bForceIndividualScoresInTeamGame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bVehiclesDamageObjectsMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	bool bVehiclesDamageVehiclesMinigame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	bool bShowPlayersWhoQuitDuringPregameOnScoreboard;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	float MinigameDefaultAutostartTimeout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	int32 PreGameStartCameraFadeoutTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMinigame")
	bool bMinigameAllowAutoStart;

private:
	UFUNCTION()
	void BroadcastStatsChangedDelegate();

	UFUNCTION()
	void OnEndGameReturnPlayersFromMatchmaking();

	UFUNCTION()
	void OnPlayerStateTeamIndexChanged();

	UFUNCTION()
	void OnRep_bPipHudAdEnabled();

	UFUNCTION()
	void QueueAllAIForDespawn();

	UFUNCTION()
	void RegisterVolumeAsNavigationObserver();

	UFUNCTION()
	void ServerEventLogMinigameState(EFortMinigameState NewState, int32 Duration);

	UFUNCTION()
	void ServerEventLogRoundEnded(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod, EFortMinigameState NextState);

	UFUNCTION()
	void ServerEventLogScoreChanged(EFortQuestObjectiveStatEvent Type, UObject* TargetObject, AFortPlayerController* PlayerController, const FGameplayTagContainer& TargetTags, const FGameplayTagContainer& SourceTags, const FGameplayTagContainer& ContextTags, int32 Count);

	UFUNCTION()
	void UnregisterVolumeAsNavigationObserver(USceneComponent* RegisteredComponent);

	UPROPERTY(BlueprintAssignable, Category="Minigame", meta=(AllowPrivateAccess="true"))
	FOnAnyLocalPlayerChangedClass OnAnyLocalPlayerChangedClass;

	UPROPERTY(Replicated)
	int32 NumMinigameComponentsServer;

	UPROPERTY(Replicated)
	bool bVolumeNavigationHasBuilt;

	UPROPERTY(Transient, Replicated)
	TArray<int32> RoundWinHistory;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerBuckets)
	TArray<FMinigamePlayerBucket> PlayerBuckets;

	UPROPERTY()
	FGameplayTagContainer OldUIExtensionTags;

	UPROPERTY(ReplicatedUsing=OnRep_bPipHudAdEnabled)
	bool bPipHudAdEnabled;

	UPROPERTY(Transient)
	TArray<FMinigamePlayerPersistentStartPoint> PlayerPersistentStartPoints;

	UPROPERTY(Transient, Replicated)
	int32 PersistenceRequiredDevices;

};

